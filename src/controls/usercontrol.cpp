#include "usercontrol.hpp"

#include <QtQml>
#include "../constants.hpp"
#include "../utils.hpp"

UserControl::UserControl() : QObject(), disqus(this), disqusUser() {}

DECLARE_QML(UserControl, "UserControl")

DisqusUser * UserControl::getDisqusUser()
{
	return &disqusUser;
}

void UserControl::setDisqusUser(const DisqusUser * value)
{
	if (value) {
		setDisqusUser(*value);
	}
}

void UserControl::setDisqusUser(const DisqusUser & value)
{
	disqusUser = value;
	emit disqusUserChanged();
}
