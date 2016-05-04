#ifndef AUTHCONTROL_HPP
#define AUTHCONTROL_HPP

#include <QObject>
#include <QUrl>
#include "../connection/disqusapi.hpp"
#include "../connection/requestresult.hpp"
#include "../model/settings/disqusapp.hpp"

class AuthControl : public QObject
{
	Q_OBJECT

	public:
		AuthControl();
		static void declareQML();
		Q_INVOKABLE void resetAuthData();
		Q_INVOKABLE void setDefaultAuthData();
		Q_INVOKABLE QUrl computeAuthorizeURL();
		Q_INVOKABLE QString trackOAuthCode(QUrl url);
		Q_INVOKABLE void accessTokens();
		Q_INVOKABLE void refreshTokens();

	protected slots:
		void accessTokensObtained(RequestResult reqres);
		void accessTokensRefreshed(RequestResult reqres);

	signals:
		void authEnded();
		void refreshEnded();
		void tryAgain(QString error);
		void fatalError(QString error);

		// NOTIFY properties
		void disqusAppChanged();
		void oauthCodeChanged();

	protected:
		DisqusAPI disqus;
		void syncTokens(QJsonObject res);

		// Authentication data
		Q_PROPERTY(DisqusApp * disqusApp READ getDisqusApp WRITE setDisqusApp NOTIFY disqusAppChanged)
		DisqusApp disqusApp;
		DisqusApp * getDisqusApp();
		void setDisqusApp(const DisqusApp & value);
		void setDisqusApp(const DisqusApp * value);

		Q_PROPERTY(QByteArray oauthCode READ getOauthCode WRITE setOauthCode NOTIFY oauthCodeChanged)
		QByteArray oauthCode;
		QByteArray getOauthCode() const;
		void setOauthCode(const QByteArray & value);

};

#endif // AUTHCONTROL_HPP
