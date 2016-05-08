#include "usercontrol.hpp"

#include <QtQml>
#include "../constants.hpp"
#include "../utils.hpp"
#include "../model/settings/usersettings.hpp"

UserControl::UserControl() :
	QObject(), disqus(this, UserSettings().getAuthenticator()),
	disqusUser()
{}

DECLARE_QML(UserControl, "UserControl")

void UserControl::loadUserDetails(int userID)
{
	connect(&disqus, &DisqusAPI::sendResult,
			this, &UserControl::userDetailsRetrieved);

	disqus.userDetails(userID);
}

void UserControl::userDetailsRetrieved(RequestResult reqres)
{
	disconnect(&disqus, &DisqusAPI::sendResult,
			   this, &UserControl::userDetailsRetrieved);

	switch (reqres.resultType) {
		case NO_REQUEST_ERROR: {
			QJsonObject res = reqres.parsedResult.toJsonObject();

			if (!res["response"].isObject()) {
				// Unexpected response format. Error
				emit loadUsersDetailsFailed(QString(tr("The Disqus API cannot be parsed correctly: the expected response.response should be a JSON object")));
				break;
			}

			setDisqusUser(res["response"].toObject());
		} break;

		case API_CALL:
			// There was a problem while calling the API. Try again.
			emit loadUsersDetailsFailed(QString(tr("A problem occured why calling the Disqus API: %1")).arg(reqres.errorMessage));
			break;

		case SERVICE_ERROR:
			// A service error Try again.
			emit loadUsersDetailsFailed(QString(tr("The Disqus API has returned a service error: %1")).arg(reqres.serviceError.message));
			break;

		case JSON_PARSING:
			// Format error message Try again.
			emit loadUsersDetailsFailed(QString(tr("The Disqus API cannot be parsed correctly: %1")).arg(reqres.parsingErrors.message));
			break;

		default:
			// Unexpected error. Abort.
			emit fatalError(QString(tr("A problem occured why calling the Disqus API: %1")).arg(reqres.errorMessage));
			break;
	}
}

// Getters & Setters
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

void UserControl::setDisqusUser(const QJsonObject & value)
{
	setDisqusUser(DisqusUser(value));
}
