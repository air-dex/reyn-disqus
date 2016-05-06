#include "usersdetailsrequester.hpp"

#include "../uris.hpp"

UsersDetailsRequester::UsersDetailsRequester(Authenticator authInfos, int userID) :
	AuthRequester(authInfos, GET, ReynDisqus::getEndpointURL(ReynDisqus::USERS_DETAILS_URI)),
	userID(userID)
{}

ArgsMap UsersDetailsRequester::buildGETParameters()
{
	ArgsMap res = AuthRequester::buildGETParameters();
	res.insert("user", QString::number(userID));
	return res;
}
