#include "global.hpp"

#include "constants.hpp"
#include "controls/settingscontrol.hpp"

void ReynDisqus::declareQML()
{
	Constants::declareQML();
	SettingsControl::declareQML();
}

void ReynDisqus::afterReynDisqus()
{
	// Nothing for the moment
}
