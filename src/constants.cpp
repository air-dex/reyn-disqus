#include "constants.hpp"

#include <QtQml>

// App constants that should NOT be exposed to QML.
//*
const QByteArray ReynDisqus::publicKey = "the Disqus app public key";
const QByteArray ReynDisqus::secretKey = "the Disqus app secret key";
const QString ReynDisqus::trustedDomain = QString::fromUtf8("A trusted domain of the app");
//*/

const QString ReynDisqus::publicKeySettingsKey = "public_key";
const QString ReynDisqus::secretKeySettingsKey = "secret_key";
const QString ReynDisqus::trustedDomainSettingsKey = "trusted_domain";


// App constants that should be exposed to QML.
Constants::Constants() : QObject() {}

void Constants::declareQML()
{
	qmlRegisterType<Constants>("RDCore", Constants::MAJOR_VERSION, Constants::MINOR_VERSION, "Constants");
}

QString Constants::appVersion()
{
	QString res("%1.%2.%3");
	res.arg(QString::number(Constants::MAJOR_VERSION), QString::number(Constants::MINOR_VERSION), QString::number(Constants::PATCH_VERSION));
	return res;
}

// Major version
int Constants::MAJOR_VERSION = 1;

int Constants::majorVersion()
{
	return Constants::MAJOR_VERSION;
}

// Minor version
int Constants::MINOR_VERSION = 0;

int Constants::minorVersion()
{
	return Constants::MINOR_VERSION;
}

// Patch version
int Constants::PATCH_VERSION = 0;

int Constants::patchVersion()
{
	return Constants::PATCH_VERSION;
}

// Company Name
QString Constants::COMPANY_NAME = "Romain Ducher";

QString Constants::companyName()
{
	return Constants::COMPANY_NAME;
}

// Application Name
QString Constants::APP_NAME = "Reyn Disqus";

QString Constants::appName()
{
	return Constants::APP_NAME;
}

// QML default margin
int Constants::DEFAULT_MARGIN = 5;

int Constants::getMargin()
{
	return DEFAULT_MARGIN;
}