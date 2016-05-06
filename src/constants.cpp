#include "constants.hpp"

#include <QtQml>

// App constants that should NOT be exposed to QML.
//*
const QByteArray ReynDisqus::publicKey = "the Disqus app public key";
const QByteArray ReynDisqus::secretKey = "the Disqus app secret key";
const QString ReynDisqus::trustedDomain = QString::fromUtf8("A trusted domain of the app");
const QString ReynDisqus::scopes = "App scopes";
//*/

// app/auth and user/auth/app settings key
const QString ReynDisqus::publicKeySettingsKey = "public_key";
const QString ReynDisqus::secretKeySettingsKey = "secret_key";
const QString ReynDisqus::trustedDomainSettingsKey = "trusted_domain";
const QString ReynDisqus::appScopesSettingsKey = "scopes";

// user/auth/user settings key
const QString ReynDisqus::accessTokenSettingsKey = "access_token";
const QString ReynDisqus::expiresInSettingsKey = "expires_in";
const QString ReynDisqus::tokenTypeSettingsKey = "token_type";
const QString ReynDisqus::stateSettingsKey = "state";
const QString ReynDisqus::userScopeSettingsKey = "scope";
const QString ReynDisqus::refreshTokenSettingsKey = "refresh_token";

// user/infos settings key
const QString ReynDisqus::usernameSettingsKey = "name";
const QString ReynDisqus::idSettingsKey = "id";

// Version
const int ReynDisqus::MAJOR_VERSION = 1;
const int ReynDisqus::MINOR_VERSION = 0;
const int ReynDisqus::PATCH_VERSION = 0;

// App names
const QString ReynDisqus::COMPANY_NAME = "Romain Ducher";
const QString ReynDisqus::APP_NAME = "Reyn Disqus";

// For UI purposes
const int ReynDisqus::DEFAULT_MARGIN = 5;
const QColor ReynDisqus::ERROR_COLOR = QColor::fromRgb(0xff, 0x00, 0x00);

// Font sizes
const int ReynDisqus::XS_FONT_SIZE = 8;
const int ReynDisqus::S_FONT_SIZE = 10;
const int ReynDisqus::M_FONT_SIZE = 12;
const int ReynDisqus::L_FONT_SIZE = 14;
const int ReynDisqus::XL_FONT_SIZE = 16;


// App constants that should be exposed to QML.
Constants::Constants() : QObject() {}

void Constants::declareQML()
{
	qmlRegisterType<Constants>("RDCore", ReynDisqus::MAJOR_VERSION, ReynDisqus::MINOR_VERSION, "Constants");
}

QString Constants::appVersion()
{
	return QString("%1.%2.%3").arg(
		QString::number(ReynDisqus::MAJOR_VERSION),
		QString::number(ReynDisqus::MINOR_VERSION),
		QString::number(ReynDisqus::PATCH_VERSION)
	);
}

// Major version
int Constants::majorVersion()
{
	return ReynDisqus::MAJOR_VERSION;
}

// Minor version
int Constants::minorVersion()
{
	return ReynDisqus::MINOR_VERSION;
}

// Patch version
int Constants::patchVersion()
{
	return ReynDisqus::PATCH_VERSION;
}

// Company Name
QString Constants::companyName()
{
	return ReynDisqus::COMPANY_NAME;
}

// Application Name
QString Constants::appName()
{
	return ReynDisqus::APP_NAME;
}

// QML default margin
int Constants::getMargin()
{
	return ReynDisqus::DEFAULT_MARGIN;
}

// Error color
QColor Constants::getErrorColor()
{
	return ReynDisqus::ERROR_COLOR;
}

// Font sizes
int Constants::xsFontSize()
{
	return ReynDisqus::XS_FONT_SIZE;
}

int Constants::sFontSize()
{
	return ReynDisqus::S_FONT_SIZE;
}

int Constants::mFontSize()
{
	return ReynDisqus::M_FONT_SIZE;
}

int Constants::lFontSize()
{
	return ReynDisqus::L_FONT_SIZE;
}

int Constants::xlFontSize()
{
	return ReynDisqus::XL_FONT_SIZE;
}
