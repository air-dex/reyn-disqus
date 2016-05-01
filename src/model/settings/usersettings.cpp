#include "usersettings.hpp"

#include <QSettings>
#include "disqusapp.hpp"
#include "../../utils.hpp"

UserSettings::UserSettings() : QObject()
{
	BUILD_SETTINGS(settings);

	settings.beginGroup("user");

	// Auth entities
	settings.beginGroup("auth");

	// Disqus app
	settings.beginGroup("app");
	disqusApp.setPublicKey(QByteArray::fromBase64(settings.value(ReynDisqus::publicKeySettingsKey).toByteArray()));
	disqusApp.setSecretKey(QByteArray::fromBase64(settings.value(ReynDisqus::secretKeySettingsKey).toByteArray()));
	disqusApp.setTrustedDomain(settings.value(ReynDisqus::trustedDomainSettingsKey).toUrl());
	defaultDisqusApp = disqusApp.isDefaultApp();
	settings.endGroup();

	// OAuth tokens
	// TODO

	settings.endGroup();	// End auth

	settings.endGroup();	// End read
}

UserSettings::UserSettings(DisqusApp app) :
	QObject(),
	disqusApp(app),
	defaultDisqusApp(app.isDefaultApp())
{}

UserSettings::UserSettings(const UserSettings & usets) : QObject()
{
	copy(usets);
}

const UserSettings &UserSettings::operator=(const UserSettings & usets)
{
	copy(usets);
	return *this;
}

void UserSettings::copy(const UserSettings & usets)
{
	setDisqusApp(usets.disqusApp);
}

void UserSettings::sync()
{
	BUILD_SETTINGS(settings);
	settings.beginGroup("user");

	settings.beginGroup("auth");

	// Disqus app used by the user
	settings.beginGroup("app");
	settings.setValue(ReynDisqus::publicKeySettingsKey, QVariant::fromValue<QByteArray>(disqusApp.getPublicKey().toBase64()));
	settings.setValue(ReynDisqus::secretKeySettingsKey, QVariant::fromValue<QByteArray>(disqusApp.getSecretKey().toBase64()));
	settings.setValue(ReynDisqus::trustedDomainSettingsKey, QVariant::fromValue<QUrl>(disqusApp.getTrustedDomain()));
	settings.endGroup();

	// User OAuth tokens
	// TODO

	settings.endGroup();

	// Close group and end.
	settings.endGroup();
	settings.sync();
}

DisqusApp UserSettings::getDisqusApp() const
{
	return disqusApp;
}

void UserSettings::setDisqusApp(const DisqusApp & value)
{
	disqusApp = value;
	defaultDisqusApp = disqusApp.isDefaultApp();
}
