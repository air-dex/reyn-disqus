#include "global.hpp"

#include "constants.hpp"
#include "controls/settingscontrol.hpp"
#include "controls/authcontrol.hpp"
#include "model/settings/disqusscopes.hpp"
#include "model/settings/disqusapp.hpp"

void ReynDisqus::declareQML()
{
	Constants::declareQML();
	SettingsControl::declareQML();
	AuthControl::declareQML();
	DisqusScopes::declareQML();
	DisqusApp::declareQML();
}

void ReynDisqus::afterReynDisqus()
{
	// Nothing for the moment
}
