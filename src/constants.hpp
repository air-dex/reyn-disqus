#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <QObject>
#include <QColor>

// App constants that should NOT be exposed to QML.
namespace ReynDisqus {
	extern const QByteArray publicKey;
	extern const QByteArray secretKey;
	extern const QString scopes;
	extern const QString trustedDomain;

	extern const QString publicKeySettingsKey;
	extern const QString secretKeySettingsKey;
	extern const QString trustedDomainSettingsKey;
	extern const QString usernameSettingsKey;
	extern const QString scopesSettingsKey;

	// API URLs
	extern const QString disqusAPIBaseURLPattern;
	extern const QString disqusAPIOAuthAuthorizeURL;
	extern const QString disqusAPIOAuthAccessTokensURL;
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
		static int getMargin();

		static QColor getErrorColor();

	protected:
		// Major version
		Q_PROPERTY(int majorVersion READ majorVersion NOTIFY majorVersionChanged)
		static int MAJOR_VERSION;

		// Minor version
		Q_PROPERTY(int minorVersion READ minorVersion NOTIFY minorVersionChanged)
		static int MINOR_VERSION;

		// Patch version
		Q_PROPERTY(int patchVersion READ patchVersion NOTIFY patchVersionChanged)
		static int PATCH_VERSION;

		// Company name
		Q_PROPERTY(QString companyName READ companyName NOTIFY companyNameChanged)
		static QString COMPANY_NAME;

		// Application name
		Q_PROPERTY(QString appName READ appName NOTIFY appNameChanged)
		static QString APP_NAME;

		// Default margin
		Q_PROPERTY(int margin READ getMargin NOTIFY marginChanged)
		static int DEFAULT_MARGIN;

		// Red color
		Q_PROPERTY(QColor errorColor READ getErrorColor NOTIFY errorColorChanged)
		static QColor ERROR_COLOR;

	signals:
		// Useless property signals
		void majorVersionChanged();
		void minorVersionChanged();
		void patchVersionChanged();
		void companyNameChanged();
		void appNameChanged();
		void marginChanged();
		void errorColorChanged();
};

#endif // CONSTANTS_HPP
