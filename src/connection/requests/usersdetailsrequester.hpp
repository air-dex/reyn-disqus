#ifndef USERSDETAILSREQUESTER_HPP
#define USERSDETAILSREQUESTER_HPP

#include "../authrequester.hpp"

class UsersDetailsRequester : public AuthRequester
{
	public:
		UsersDetailsRequester(Authenticator authInfos, int userID);

	protected:
		int userID;
		ArgsMap buildGETParameters();
};

#endif // USERSDETAILSREQUESTER_HPP
