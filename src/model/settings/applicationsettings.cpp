#include "applicationsettings.hpp"

#include "../../utils.hpp"
#include "disqusapp.hpp"
#include <QSettings>
#include <QVariant>

ApplicationSettings::ApplicationSettings()
{
	BUILD_SETTINGS(settings);

	settings.beginGroup("app");

	// Disqus app
	settings.beginGroup("auth");
	disqusApp.setPublicKey(QByteArray::fromBase64(settings.value(ReynDisqus::publicKeySettingsKey).toByteArray()));
	disqusApp.setSecretKey(QByteArray::fromBase64(settings.value(ReynDisqus::secretKeySettingsKey).toByteArray()));
	disqusApp.setTrustedDomain(settings.value(ReynDisqus::trustedDomainSettingsKey).toUrl());
	settings.endGroup();	// End auth

	settings.endGroup();	// End read
}

ApplicationSettings::ApplicationSettings(DisqusApp app) :
	disqusApp(DisqusApp())
{}

void ApplicationSettings::setDefault()
{
	disqusApp = DisqusApp();
}

bool ApplicationSettings::isDefaultDisqusApp() const
{
	return disqusApp.isDefaultApp();
}

void ApplicationSettings::sync()
{
	BUILD_SETTINGS(settings);
	settings.beginGroup("app");

	settings.beginGroup("auth");
	settings.setValue(ReynDisqus::publicKeySettingsKey, QVariant::fromValue<QByteArray>(disqusApp.getPublicKey().toBase64()));
	settings.setValue(ReynDisqus::secretKeySettingsKey, QVariant::fromValue<QByteArray>(disqusApp.getSecretKey().toBase64()));
	settings.setValue(ReynDisqus::trustedDomainSettingsKey, QVariant::fromValue<QUrl>(disqusApp.getTrustedDomain()));
	settings.endGroup();

	// Close group and sync.
	settings.endGroup();
	settings.sync();
}
