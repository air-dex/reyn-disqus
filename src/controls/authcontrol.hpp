#ifndef AUTHCONTROL_HPP
#define AUTHCONTROL_HPP

#include <QObject>
#include <QUrl>
#include "../connection/disqusapi.hpp"

class AuthControl : public QObject
{
	Q_OBJECT

	public:
		AuthControl();
		static void declareQML();
		Q_INVOKABLE QUrl computeAuthorizeURL(QString publicKey, QString scopes, QUrl redirectURI);
		Q_INVOKABLE QUrl computeDefaultAuthorizeURL();
		Q_INVOKABLE QString trackOAuthCode(QUrl url, QUrl * redirectURI = NULL);
		Q_INVOKABLE void accessTokens(QString publicKey, QString secretKey, QUrl redirectURI, QString code);

	// TODO: control holds auth infos.

	protected:
		DisqusAPI disqus;
};

#endif // AUTHCONTROL_HPP
