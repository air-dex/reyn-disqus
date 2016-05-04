#ifndef REFRESHTOKENREQUESTER_HPP
#define REFRESHTOKENREQUESTER_HPP

#include "oauthaccessrequester.hpp"

class RefreshTokenRequester : public OAuthAccessRequester
{
	public:
		RefreshTokenRequester(Authenticator authInfos, QByteArray refreshToken);

	protected:
		QByteArray refreshToken;
		ArgsMap buildPOSTParameters();
};

#endif // REFRESHTOKENREQUESTER_HPP
