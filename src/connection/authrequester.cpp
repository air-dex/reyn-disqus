#include "authrequester.hpp"

AuthRequester::AuthRequester(Authenticator authInfos, HTTPRequestType reqtype, QString uri) :
	GenericRequester(authInfos, reqtype, uri)
{}

ArgsMap AuthRequester::buildGETParameters()
{
	ArgsMap getParameters = GenericRequester::buildGETParameters();

	getParameters.insert("api_key", authInfos.getAPIKey());
	getParameters.insert("api_secret", authInfos.getAPISecret());
	getParameters.insert("access_token", authInfos.getAccessToken());

	return getParameters;
}
