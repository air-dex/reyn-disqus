#include "usersettings.hpp"

#include <QSettings>
#include "disqusapp.hpp"
#include "../../utils.hpp"

UserSettings::UserSettings() : QObject(), ISettings(), userTokens()
{
	BUILD_SETTINGS(settings);

	settings.beginGroup("user");

	// Account name & id
	name = settings.value(ReynDisqus::usernameSettingsKey, "").toString();
	userID = settings.value(ReynDisqus::idSettingsKey, 0).toInt();

	// Auth entities
	settings.beginGroup("auth");

	// Disqus app
	settings.beginGroup("app");
	disqusApp.setPublicKey(QByteArray::fromBase64(settings.value(ReynDisqus::publicKeySettingsKey).toByteArray()));
	disqusApp.setSecretKey(QByteArray::fromBase64(settings.value(ReynDisqus::secretKeySettingsKey).toByteArray()));
	disqusApp.setTrustedDomain(settings.value(ReynDisqus::trustedDomainSettingsKey).toUrl());
	disqusApp.setScopes(DisqusScopesSet(settings.value(ReynDisqus::appScopesSettingsKey).toString()));
	settings.endGroup();

	// OAuth tokens are already loaded in userTokens.

	settings.endGroup();	// End auth

	settings.endGroup();	// End read
}

UserSettings::UserSettings(QString name, int id, DisqusApp app, UserTokens utokens) :
	QObject(),
	name(name),
	userID(id),
	disqusApp(app),
	userTokens(utokens)
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
	setUserTokens(usets.userTokens);
}

void UserSettings::sync()
{
	BUILD_SETTINGS(settings);
	settings.beginGroup("user");

	// User infos
	settings.setValue(ReynDisqus::usernameSettingsKey, name);
	settings.setValue(ReynDisqus::idSettingsKey, userID);

	// Auth infos
	settings.beginGroup("auth");

	// Disqus app used by the user
	settings.beginGroup("app");
	settings.setValue(ReynDisqus::publicKeySettingsKey, disqusApp.getPublicKey().toBase64());
	settings.setValue(ReynDisqus::secretKeySettingsKey, disqusApp.getSecretKey().toBase64());
	settings.setValue(ReynDisqus::trustedDomainSettingsKey, disqusApp.getTrustedDomain());
	settings.setValue(ReynDisqus::appScopesSettingsKey, disqusApp.getScopes().toString());
	settings.endGroup();

	// User OAuth tokens
	settings.beginGroup("user");
	userTokens.setValuesInGroup(settings);
	settings.endGroup();

	settings.endGroup();	// Close auth

	// Close group and end.
	settings.endGroup();
	settings.sync();
}

bool UserSettings::isDefaultDisqusApp() const
{
	return disqusApp.isDefaultApp();
}

bool UserSettings::isEmpty() const
{
	return name == "";
}

DisqusApp UserSettings::getDisqusApp() const
{
	return disqusApp;
}

void UserSettings::setDisqusApp(const DisqusApp & value)
{
	disqusApp = value;
}

UserTokens UserSettings::getUserTokens() const
{
	return userTokens;
}

UserTokens & UserSettings::getUserTokensRef()
{
	return userTokens;
}

void UserSettings::setUserTokens(const UserTokens & value)
{
	userTokens = value;
}

QString UserSettings::getName() const
{
	return name;
}

void UserSettings::setName(const QString & value)
{
	name = value;
}

int UserSettings::getId() const
{
	return userID;
}

void UserSettings::setId(int value)
{
	userID = value;
}
