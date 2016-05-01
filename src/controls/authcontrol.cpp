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
