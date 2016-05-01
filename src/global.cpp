#include "global.hpp"

#include "constants.hpp"
#include "controls/settingscontrol.hpp"
#include "controls/authcontrol.hpp"
#include "model/settings/disqusscopes.hpp"

void ReynDisqus::declareQML()
{
	Constants::declareQML();
	SettingsControl::declareQML();
	AuthControl::declareQML();
	DisqusScopes::declareQML();
}

void ReynDisqus::afterReynDisqus()
{
	// Nothing for the moment
}
