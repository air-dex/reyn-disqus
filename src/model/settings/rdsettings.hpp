#ifndef RDSETTINGS_HPP
#define RDSETTINGS_HPP

#include "applicationsettings.hpp"
#include "usersettings.hpp"

class RDSettings : public ISettings
{
	public:
		/// @brief Default constructor, with registered settings
		RDSettings();

		RDSettings(ApplicationSettings asets, UserSettings usets);

		virtual void sync();

		bool hasNoSettings() const;

		void setDefaultAppSettings();

		ApplicationSettings getAppSettings() const;
		ApplicationSettings & getAppSettingsRef();
		UserSettings getUserSettings() const;
		UserSettings & getUserSettingsRef();

	protected:
		ApplicationSettings appSettings;
		UserSettings userSettings;
};

#endif // RDSETTINGS_HPP
