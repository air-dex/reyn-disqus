#include "authrequester.hpp"

AuthRequester::AuthRequester(Authenticator authInfos, HTTPRequestType reqtype, QString uri) :
	GenericRequester(authInfos, reqtype, uri)
{}

ArgsMap AuthRequester::buildGETParameters()
{
	ArgsMap getParameters = GenericRequester::buildGETParameters();

	// TODO : add more
	return getParameters;
}
