#ifndef SETTINGSCONTROL_HPP
#define SETTINGSCONTROL_HPP

#include <QObject>

class SettingsControl : public QObject
{
	Q_OBJECT

	public:
		SettingsControl();
		static void declareQML();

		// Controls settings at launch
		Q_INVOKABLE void controlSettings();

		// Retrieve my ID (me = authenticated user)
		Q_INVOKABLE int getMyID();

	signals:
		void needAuth();
		void needRefresh();
		void authOK();
};

#endif // SETTINGSCONTROL_HPP
