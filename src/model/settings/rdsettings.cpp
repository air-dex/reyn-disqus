#include "rdsettings.hpp"

#include "../../utils.hpp"
#include <QSettings>

RDSettings::RDSettings() :
	appSettings(),
	userSettings()
{}

RDSettings::RDSettings(ApplicationSettings asets, UserSettings usets) :
	appSettings(asets),
	userSettings(usets)
{}

void RDSettings::sync()
{
	appSettings.sync();
	userSettings.sync();
}

bool RDSettings::hasNoSettings() const
{
	BUILD_SETTINGS(settings);

	return settings.allKeys().count() == 0;
}

void RDSettings::setDefaultAppSettings()
{
	appSettings.setDefault();
}

ApplicationSettings RDSettings::getAppSettings() const
{
	return appSettings;
}

ApplicationSettings & RDSettings::getAppSettingsRef()
{
	return appSettings;
}

UserSettings RDSettings::getUserSettings() const
{
	return userSettings;
}

UserSettings & RDSettings::getUserSettingsRef()
{
	return userSettings;
}
