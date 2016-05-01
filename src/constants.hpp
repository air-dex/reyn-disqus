#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <QObject>

// App constants that should NOT be exposed to QML.
namespace ReynDisqus {
	extern const QByteArray publicKey;
	extern const QByteArray secretKey;
	extern const QString trustedDomain;

	extern const QString publicKeySettingsKey;
	extern const QString secretKeySettingsKey;
	extern const QString trustedDomainSettingsKey;
}

/// @class Constants
/// @brief App constants that should be exposed to QML.
class Constants : public QObject
{
	Q_OBJECT

	public:
		Constants();
		static void declareQML();
		Q_INVOKABLE static QString appVersion();

		// Property getters
		static int majorVersion();
		static int minorVersion();
		static int patchVersion();
		static QString companyName();
		static QString appName();

	protected:
		// Major version
		Q_PROPERTY(int majorVersion READ majorVersion)
		static int MAJOR_VERSION;

		// Minor version
		Q_PROPERTY(int minorVersion READ minorVersion)
		static int MINOR_VERSION;

		// Patch version
		Q_PROPERTY(int patchVersion READ patchVersion)
		static int PATCH_VERSION;

		// Company name
		Q_PROPERTY(QString companyName READ companyName)
		static QString COMPANY_NAME;

		// Application name
		Q_PROPERTY(QString appName READ appName)
		static QString APP_NAME;
};

#endif // CONSTANTS_HPP
