#include "settingscontrol.hpp"

#include <QtQml>
#include <QDateTime>
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
	else if (rdSettings.getUserSettings().isEmpty()) {
		// No user account. Create one.
		emit needAuth();
	}
	else if (rdSettings.getUserSettings().getUserTokens().getExpiresIn() <= QDateTime::currentDateTimeUtc()) {
		// The current access token has expired. Refresh it.
		// FIXME : laisser comme ça pendant le dev du refresh, corriger la comp ensuite
		emit needRefresh();
	}
	// TODO: control user?
	else {
		// All looks OK. Let's Disqus.
		emit authOK();
	}
}

int SettingsControl::getMyID()
{
	return UserSettings().getId();
}
