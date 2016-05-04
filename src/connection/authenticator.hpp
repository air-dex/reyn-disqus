#ifndef AUTHENTICATOR_HPP
#define AUTHENTICATOR_HPP

#include <QByteArray>
#include <QUrl>

class Authenticator
{
	public:
		Authenticator(QByteArray appPublicKey = "", QByteArray appSecretKey = "", QByteArray userAccessToken = "");
		Authenticator(const Authenticator & authInfos);
		const Authenticator & operator=(const Authenticator & authInfos);

		QByteArray getAppPublicKey() const;
		void setAppPublicKey(const QByteArray & value);

		QByteArray getAppSecretKey() const;
		void setAppSecretKey(const QByteArray & value);

		QByteArray getUserAccessToken() const;
		void setUserAccessToken(const QByteArray & value);

	protected:
		QByteArray appPublicKey;
		QByteArray appSecretKey;
		QByteArray userAccessToken;

		void copy(const Authenticator & authInfos);
};

#endif // AUTHENTICATOR_HPP
