#ifndef USERTOKENS_HPP
#define USERTOKENS_HPP

#include <QByteArray>
#include <QDateTime>
#include <QObject>
#include <QSettings>
#include <QString>
#include "disqusscopesset.hpp"
#include "isettings.hpp"

/// @class UserTokens
/// @brief User tokens to auth
class UserTokens : public QObject, public ISettings
{
	Q_OBJECT

	public:
		/// @fn UserTokens();
		/// @brief Default constuctor: from settings
		UserTokens();

		UserTokens(QByteArray accessToken,
				   QDateTime expiresIn,
				   QString tokenType,
				   QString state,
				   DisqusScopesSet scopes,
				   QByteArray refreshToken);

		UserTokens(const UserTokens & tokens);
		const UserTokens & operator=(const UserTokens & tokens);

		virtual void sync();
		void setValuesInGroup(QSettings & settings);

		// Getter and setters
		QByteArray getAccessToken() const;
		void setAccessToken(const QByteArray & value);

		QDateTime getExpiresIn() const;
		void setExpiresIn(const QDateTime & value);

		QString getTokenType() const;
		void setTokenType(const QString & value);

		QString getState() const;
		void setState(const QString & value);

		DisqusScopesSet getScopes() const;
		void setScopes(const DisqusScopesSet & value);
		void setScopes(const QString & value);

		QByteArray getRefreshToken() const;
		void setRefreshToken(const QByteArray & value);

	protected:
		QByteArray accessToken;
		QDateTime expiresIn;
		QString tokenType;
		QString state;
		DisqusScopesSet scopes;
		QByteArray refreshToken;

		void copy(const UserTokens & tokens);
};

#endif // USERTOKENS_HPP
