#ifndef UTILS_HPP
#define UTILS_HPP

// Macro for getting app's settings.
#define BUILD_SETTINGS(VARSETTINGS) QSettings VARSETTINGS(QSettings::IniFormat, QSettings::UserScope, Constants::companyName(), Constants::appName())

// Macro for QML
#define DECLARE_QML(ACLASS, QML_NAME) \
	void ACLASS::declareQML() \
	{ \
		/* @uri RDCore */ \
		qmlRegisterType<ACLASS>("RDCore", Constants::majorVersion(), Constants::minorVersion(), QML_NAME); \
	}
// DECLARE_QML() macro end

/// @namespace ReynDisqus
namespace ReynDisqus {
	//QSettings getSettings();
}

#endif // UTILS_HPP
