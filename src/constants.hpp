#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <QObject>
#include <QColor>

namespace ReynDisqus {
	/*****************
	 * App constants *
	 *****************/

	extern const QByteArray publicKey;
	extern const QByteArray secretKey;
	extern const QString scopes;
	extern const QString trustedDomain;

	// app/auth and user/auth/app settings key
	extern const QString publicKeySettingsKey;
	extern const QString secretKeySettingsKey;
	extern const QString trustedDomainSettingsKey;
	extern const QString appScopesSettingsKey;

	// user/auth/user settings key
	extern const QString accessTokenSettingsKey;
	extern const QString expiresInSettingsKey;
	extern const QString tokenTypeSettingsKey;
	extern const QString stateSettingsKey;
	extern const QString userScopeSettingsKey;
	extern const QString refreshTokenSettingsKey;

	// user/infos settings key
	extern const QString usernameSettingsKey;
	extern const QString idSettingsKey;

	// Version
	extern const int MAJOR_VERSION;
	extern const int MINOR_VERSION;
	extern const int PATCH_VERSION;

	// App names
	extern const QString COMPANY_NAME;
	extern const QString APP_NAME;

	// For UI purposes
	extern const int DEFAULT_MARGIN;
	extern const QColor ERROR_COLOR;

	// Font sizes
	extern const int XS_FONT_SIZE;
	extern const int S_FONT_SIZE;
	extern const int M_FONT_SIZE;
	extern const int L_FONT_SIZE;
	extern const int XL_FONT_SIZE;
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

	protected:
		// Major version
		Q_PROPERTY(int majorVersion READ majorVersion NOTIFY majorVersionChanged)

		// Minor version
		Q_PROPERTY(int minorVersion READ minorVersion NOTIFY minorVersionChanged)

		// Patch version
		Q_PROPERTY(int patchVersion READ patchVersion NOTIFY patchVersionChanged)

		// Company name
		Q_PROPERTY(QString companyName READ companyName NOTIFY companyNameChanged)

		// Application name
		Q_PROPERTY(QString appName READ appName NOTIFY appNameChanged)

		// Default margin
		Q_PROPERTY(int margin READ getMargin NOTIFY marginChanged)

		// Red color
		Q_PROPERTY(QColor errorColor READ getErrorColor NOTIFY errorColorChanged)

		// Font sizes
		Q_PROPERTY(int xsFontSize READ xsFontSize NOTIFY xsFontSizeChanged)
		Q_PROPERTY(int sFontSize READ sFontSize NOTIFY sFontSizeChanged)
		Q_PROPERTY(int mFontSize READ mFontSize NOTIFY mFontSizeChanged)
		Q_PROPERTY(int lFontSize READ lFontSize NOTIFY lFontSizeChanged)
		Q_PROPERTY(int xlFontSize READ xlFontSize NOTIFY xlFontSizeChanged)

	public:
		// Property getters
		static int majorVersion();
		static int minorVersion();
		static int patchVersion();
		static QString companyName();
		static QString appName();
		static int getMargin();
		static QColor getErrorColor();
		static int xsFontSize();
		static int sFontSize();
		static int mFontSize();
		static int lFontSize();
		static int xlFontSize();

	signals:
		// Useless property signals
		void majorVersionChanged();
		void minorVersionChanged();
		void patchVersionChanged();
		void companyNameChanged();
		void appNameChanged();
		void marginChanged();
		void errorColorChanged();
		void xsFontSizeChanged();
		void sFontSizeChanged();
		void mFontSizeChanged();
		void lFontSizeChanged();
		void xlFontSizeChanged();
};

#endif // CONSTANTS_HPP
