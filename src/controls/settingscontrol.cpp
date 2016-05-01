#include "settingscontrol.hpp"

#include <QtQml>
#include "../constants.hpp"
#include "../utils.hpp"
#include "../model/settings/rdsettings.hpp"

SettingsControl::SettingsControl() : QObject() {}

DECLARE_QML(SettingsControl, "SettingsControl")

void SettingsControl::controlSettings() {
	RDSettings rdSettings;

	if (rdSettings.hasNoSettings()) {
		// No settings on the machine at all. Let's init them!
		rdSettings.setDefaultAppSettings();
		rdSettings.sync();

		// Obviously the user has no OAuth tokens. Get them!
		emit needAuth();
	}
	else if (!rdSettings.getAppSettings().isDefaultDisqusApp()) {
		// It should be default app settings. Write them.
		rdSettings.setDefaultAppSettings();
		rdSettings.sync();

		// Getting new tokens with better settings.
		emit needAuth();
	}
	else {
		// TODO: check user's settings
		qDebug("TODO: check user's settings");
	}//*/

	rdSettings.sync();
}
