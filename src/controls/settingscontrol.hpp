#ifndef SETTINGSCONTROL_HPP
#define SETTINGSCONTROL_HPP

#include <QObject>

class SettingsControl : public QObject
{
	Q_OBJECT

	public:
		SettingsControl();
		static void declareQML();
		Q_INVOKABLE void controlSettings();

	signals:
		void needAuth();
		void authOK();
};

#endif // SETTINGSCONTROL_HPP
