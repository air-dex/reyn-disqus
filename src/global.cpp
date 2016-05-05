#include "global.hpp"

#include "constants.hpp"
#include "controls/settingscontrol.hpp"
#include "controls/authcontrol.hpp"
#include "model/settings/disqusscopes.hpp"
#include "model/settings/disqusapp.hpp"
#include "model/disqususer.hpp"
#include "model/avatarimage.hpp"

void ReynDisqus::declareQML()
{
	Constants::declareQML();
	SettingsControl::declareQML();
	AuthControl::declareQML();
	DisqusScopes::declareQML();
	DisqusApp::declareQML();
	DisqusUser::declareQML();
	AvatarImage::declareQML();
}

void ReynDisqus::afterReynDisqus()
{
	// Nothing for the moment
}
