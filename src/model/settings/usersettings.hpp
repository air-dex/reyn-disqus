#ifndef USERSETTINGS_HPP
#define USERSETTINGS_HPP

#include <QObject>
#include "disqusapp.hpp"
#include "isettings.hpp"
#include "usertokens.hpp"
#include "../../connection/authenticator.hpp"

class UserSettings : public QObject, public ISettings
{
	Q_OBJECT

	public:
		/// @fn UserSettings();
		/// @brief Default constructor, with registered settings.
		UserSettings();

		UserSettings(const UserSettings & usets);
		const UserSettings & operator=(const UserSettings & usets);

		UserSettings(QString name, int id, DisqusApp app, UserTokens utokens);

		virtual void sync();
		bool isDefaultDisqusApp() const;
		bool isEmpty() const;
		Authenticator getAuthenticator() const;

		// Getters and setters
		QString getName() const;
		void setName(const QString & value);
		int getId() const;
		void setId(int value);
		DisqusApp getDisqusApp() const;
		void setDisqusApp(const DisqusApp & value);
		UserTokens getUserTokens() const;
		UserTokens & getUserTokensRef();
		void setUserTokens(const UserTokens & value);

	protected:
		QString name;
		int userID;
		DisqusApp disqusApp;
		UserTokens userTokens;

		void copy(const UserSettings & usets);
};

#endif // USERSETTINGS_HPP
