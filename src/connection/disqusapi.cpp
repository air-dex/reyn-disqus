#include "disqusapi.hpp"

#include "requests/alldisqusrequesters.hpp"

/*************
 * Internals *
 *************/

DisqusAPI::DisqusAPI(QObject * asker, Authenticator authInfos) :
	QObject(),
	asker(asker),
	authInfos(authInfos)
{}

DisqusAPI::~DisqusAPI()
{
	asker = NULL;
}

RequesterManager DisqusAPI::REQUESTER_MANAGER = RequesterManager();

void DisqusAPI::setAsker(QObject * value)
{
	asker = value;
}

void DisqusAPI::setAuthInfos(const Authenticator & value)
{
	authInfos = value;
}

void DisqusAPI::executeRequest(GenericRequester * requester)
{
	if (!requester) {
		// TODO: error null request
	}
	REQUESTER_MANAGER.addRequest(asker, requester);
	connect(requester, &GenericRequester::requestEnded, this, &DisqusAPI::endRequest);
	requester->executeRequest();
}

void DisqusAPI::endRequest(RequestResult requestResult)
{
	GenericRequester * requester = qobject_cast<GenericRequester *>(sender());
	disconnect(requester, &GenericRequester::requestEnded, this, &DisqusAPI::endRequest);
	REQUESTER_MANAGER.removeRequest(requester);
	emit sendResult(requestResult);
}

/*******************************
 * Disqus API wrapping methods *
 *******************************/

void DisqusAPI::accessTokens(QUrl redirectURI, QString code)
{
	AccessTokensRequester * requester = new AccessTokensRequester(authInfos, redirectURI, code);
	executeRequest(requester);
}
