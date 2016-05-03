#include "accesstokensrequester.hpp"

#include "../../constants.hpp"

AccessTokensRequester::AccessTokensRequester(Authenticator authInfos, QUrl redirectURI, QString code) :
	GenericRequester(authInfos, HTTPRequestType::POST, ReynDisqus::disqusAPIOAuthAccessTokensURL),
	code(code)
{}

ArgsMap AccessTokensRequester::buildPOSTParameters()
{
	ArgsMap postParams = GenericRequester::buildPOSTParameters();

	postParams.insert("grant_type", "authorization_code");
	postParams.insert("client_id", authInfos.getAppPublicKey());
	postParams.insert("client_secret", authInfos.getAppSecretKey());
	postParams.insert("redirect_uri", redirectURI.toString());
	postParams.insert("code", code);

	return postParams;
}
