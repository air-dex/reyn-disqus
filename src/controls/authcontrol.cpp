#include "authcontrol.hpp"

#include "../utils.hpp"
#include "../constants.hpp"
#include "../model/settings/applicationsettings.hpp"
#include "../model/settings/usersettings.hpp"
#include "../model/settings/usertokens.hpp"
#include "../connection/authenticator.hpp"
#include <QtQml>
#include <QJsonObject>
#include <QUrl>

AuthControl::AuthControl() :
	QObject(),
	disqus(this),
	disqusApp("", "", QUrl(), DisqusScopesSet("")),
	oauthCode("")
{}

DECLARE_QML(AuthControl, "AuthControl")

void AuthControl::resetAuthData()
{
	setDisqusApp(DisqusApp("", "", QUrl(), DisqusScopesSet("")));
	setOauthCode("");
}

void AuthControl::setDefaultAuthData()
{
	ApplicationSettings appSets;
	setDisqusApp(appSets.getDisqusApp());
}

QUrl AuthControl::computeAuthorizeURL()
{
	// Compute query
	QUrlQuery authQuery;
	authQuery.addQueryItem("client_id", disqusApp.getPublicKey());
	authQuery.addQueryItem("scopes", disqusApp.getScopesStr());
	authQuery.addQueryItem("response_type", "code");
	authQuery.addQueryItem("redirect_uri", disqusApp.getTrustedDomain().toString());

	// Compute URL
	QUrl authURL(ReynDisqus::disqusAPIOAuthAuthorizeURL);
	authURL.setQuery(authQuery);

	return authURL;
}

QString AuthControl::trackOAuthCode(QUrl url)
{
	// url's authority has to end with domain's authority
	QUrl domainURL;
	domainURL.setAuthority(url.authority());
	domainURL.setScheme(url.scheme());

	if (!url.host().endsWith(disqusApp.getTrustedDomain().host())) {
		// It is not our URL. URL Tracker
		return "";
	}

	// It is our domain. Now let's retrieve the code.
	if (!url.hasQuery()) {
		// No query, no code. What r u doin?
		return "";
	}

	QUrlQuery query(url.query());

	if (!query.hasQueryItem("code")) {
		// No code in the query. URL Tracker
		return "";
	}

	// STAHP!
	return query.queryItemValue("code");
}

void AuthControl::accessTokens()
{
	Authenticator auth(disqusApp.getPublicKey(), disqusApp.getSecretKey());
	disqus.setAuthInfos(auth);
	connect(&disqus, &DisqusAPI::sendResult,
			this, &AuthControl::accessTokensObtained);
	disqus.accessTokens(disqusApp.getTrustedDomain(), oauthCode);
}

void AuthControl::accessTokensObtained(RequestResult reqres)
{
	disconnect(&disqus, &DisqusAPI::sendResult,
			   this, &AuthControl::accessTokensObtained);

	switch (reqres.resultType) {
		case NO_REQUEST_ERROR: {
			// All is ok. End the process.
			QJsonObject res = reqres.parsedResult.toJsonObject();

			// Fill user settings
			UserSettings userSettings;

			userSettings.setDisqusApp(disqusApp);
			userSettings.setName(res["username"].toString());
			userSettings.setId(res["user_id"].toInt());

			UserTokens & userTokens = userSettings.getUserTokensRef();
			userTokens.setAccessToken(res["access_token"].toString().toLatin1());
			userTokens.setTokenType(res["token_type"].toString());
			userTokens.setScopes(res["scope"].toString());
			userTokens.setRefreshToken(res["refresh_token"].toString().toLatin1());

			// Compute new expiresIn
			QDateTime expiresIn = userTokens.getExpiresIn().addSecs(res["expires_in"].toInt());
			userTokens.setExpiresIn(expiresIn);

			if (res["state"].isNull()) {
				userTokens.setState("");
			}
			// TODO: else

			// Update settings
			userSettings.sync();

			// Tell the system it is the end of auth
			emit authEnded();
		} break;

		case API_CALL:
			// There was a problem while calling the API. Try again.
			emit tryAgain(QString(tr("A problem occured why calling the Disqus API: %1")).arg(reqres.errorMessage));
			break;

		case SERVICE_ERROR:
			// A service error Try again.
			emit tryAgain(QString(tr("The Disqus API has returned a service error: %1")).arg(reqres.serviceError.message));
			break;

		case JSON_PARSING:
			// Format error message Try again.
			emit tryAgain(QString(tr("The Disqus API cannot be parsed correctly: %1")).arg(reqres.parsingErrors.message));
			break;

		default:
			// Unexpected error. Abort.
			emit fatalError(QString(tr("A problem occured why calling the Disqus API: %1")).arg(reqres.errorMessage));
			break;
	}
}

// Properties stuff
DisqusApp * AuthControl::getDisqusApp()
{
	return &disqusApp;
}

void AuthControl::setDisqusApp(const DisqusApp * value)
{
	if (value) {
		setDisqusApp(*value);
	}
}

void AuthControl::setDisqusApp(const DisqusApp & value)
{
	disqusApp = value;
	emit disqusAppChanged();
}

QByteArray AuthControl::getOauthCode() const
{
	return oauthCode;
}

void AuthControl::setOauthCode(const QByteArray & value)
{
	oauthCode = value;
	emit oauthCodeChanged();
}
