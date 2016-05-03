#include "authcontrol.hpp"

#include "../utils.hpp"
#include "../constants.hpp"
#include <QtQml>
#include <QJsonObject>
#include <QUrl>
#include "../model/settings/applicationsettings.hpp"

AuthControl::AuthControl() : QObject() {}

DECLARE_QML(AuthControl, "AuthControl")

QUrl AuthControl::computeDefaultAuthorizeURL()
{
	ApplicationSettings appSets;
	DisqusApp disqusApp = appSets.getDisqusApp();

	return computeAuthorizeURL(
		disqusApp.getPublicKey(),
		disqusApp.getScopes().toString(),
		disqusApp.getTrustedDomain()
	);
}

QUrl AuthControl::computeAuthorizeURL(QString publicKey, QString scopes, QUrl redirectURI)
{
	// Compute query
	QUrlQuery authQuery;
	authQuery.addQueryItem("client_id", publicKey);
	authQuery.addQueryItem("scopes", scopes);
	authQuery.addQueryItem("response_type", "code");
	authQuery.addQueryItem("redirect_uri", redirectURI.toString());

	// Compute URL
	QUrl authURL(ReynDisqus::disqusAPIOAuthAuthorizeURL);
	authURL.setQuery(authQuery);

	return authURL;
}

QString AuthControl::trackOAuthCode(QUrl url, QUrl * redirectURI)
{
	QUrl domain;

	if (redirectURI == NULL) {
		ApplicationSettings appSets;
		domain = QUrl(appSets.getDisqusApp().getTrustedDomain());
	}
	else {
		domain = *redirectURI;
	}

	// What it should llook like : <domain URL>?code=<the code>

	// url's authority has to end with domain's authority
	QUrl domainURL;
	domainURL.setAuthority(url.authority());
	domainURL.setScheme(url.scheme());

	if (!url.host().endsWith(domain.host())) {
		// It is not our URL. Keep on tracking.
		return "";
	}

	// It is our domain. Now let's retrieve the code.
	if (!url.hasQuery()) {
		// No query, no code. Keep on tracking.
		return "";
	}

	QUrlQuery query(url.query());

	if (!query.hasQueryItem("code")) {
		// No code in the query. Keep on tracking.
		return "";
	}

	return query.queryItemValue("code");
}
