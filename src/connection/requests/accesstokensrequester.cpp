#include "accesstokensrequester.hpp"

AccessTokensRequester::AccessTokensRequester(Authenticator authInfos, QUrl redirectURI, QString code) :
	OAuthAccessRequester(authInfos),
	redirectURI(redirectURI),
	code(code)
{}

ArgsMap AccessTokensRequester::buildPOSTParameters()
{
	ArgsMap postParams = OAuthAccessRequester::buildPOSTParameters();

	postParams.insert("grant_type", "authorization_code");
	postParams.insert("client_id", authInfos.getAPIKey());
	postParams.insert("client_secret", authInfos.getAPISecret());
	postParams.insert("redirect_uri", redirectURI.toString());
	postParams.insert("code", code);

	return postParams;
}
