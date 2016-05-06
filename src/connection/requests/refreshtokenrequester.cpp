#include "refreshtokenrequester.hpp"

RefreshTokenRequester::RefreshTokenRequester(Authenticator authInfos, QByteArray refreshToken) :
	OAuthAccessRequester(authInfos),
	refreshToken(refreshToken)
{}

ArgsMap RefreshTokenRequester::buildPOSTParameters()
{
	ArgsMap postParams = OAuthAccessRequester::buildPOSTParameters();

	postParams.insert("grant_type", "refresh_token");
	postParams.insert("client_id", authInfos.getAPIKey());
	postParams.insert("client_secret", authInfos.getAPISecret());
	postParams.insert("refresh_token", refreshToken);

	return postParams;
}
