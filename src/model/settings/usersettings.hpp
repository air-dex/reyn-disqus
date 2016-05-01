#ifndef USERSETTINGS_HPP
#define USERSETTINGS_HPP

#include <QObject>
#include "disqusapp.hpp"
#include "isettings.hpp"

class UserSettings : public QObject, public ISettings
{
	Q_OBJECT

	public:
		/// @fn UserSettings();
		/// @brief Default constructor, with registered settings.
		UserSettings();
		UserSettings(const UserSettings & usets);
		const UserSettings & operator=(const UserSettings & usets);

		UserSettings(DisqusApp app);

		virtual void sync();

		DisqusApp getDisqusApp() const;
		void setDisqusApp(const DisqusApp & value);

	protected:
		DisqusApp disqusApp;
		bool defaultDisqusApp;
		void copy(const UserSettings & usets);
};

#endif // USERSETTINGS_HPP
