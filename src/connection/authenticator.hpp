#ifndef AUTHENTICATOR_HPP
#define AUTHENTICATOR_HPP

#include <QByteArray>
#include <QUrl>

class Authenticator
{
	public:
		Authenticator(QByteArray apiKey = "", QByteArray apiSecret = "", QByteArray accessToken = "");
		Authenticator(const Authenticator & authInfos);
		const Authenticator & operator=(const Authenticator & authInfos);

		QByteArray getAPIKey() const;
		void setAPIKey(const QByteArray & value);

		QByteArray getAPISecret() const;
		void setAPISecret(const QByteArray & value);

		QByteArray getAccessToken() const;
		void setAccessToken(const QByteArray & value);

	protected:
		/// @brief Application's public key
		QByteArray apiKey;

		/// @brief Application's secret key
		QByteArray apiSecret;

		/// @brief User's access token
		QByteArray accessToken;

		void copy(const Authenticator & authInfos);
};

#endif // AUTHENTICATOR_HPP
