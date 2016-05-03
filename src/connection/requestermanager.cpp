#include "requestermanager.hpp"

// Constructor
RequesterManager::RequesterManager() :
	QMap<QUuid, RequestInfos>()
{}

// Adding a request to the manager
void RequesterManager::addRequest(QObject * asker, GenericRequester * requester) {
	if (requester != NULL) {
		RequestInfos reqinf;

		reqinf.asker = asker;
		reqinf.request = requester;

		insert(requester->getUuid(), reqinf);
	}
}

// Removing a request to the manager
void RequesterManager::removeRequest(GenericRequester * requester) {
	if (requester) {
		remove(requester->getUuid());
		delete requester;
	}
}

// Getting informations on a request
RequestInfos & RequesterManager::getRequestInfos(QUuid requestUuid) {
	return (*this)[requestUuid];
}

// Getting the QObject which asked for the request
QObject * RequesterManager::getAsker(GenericRequester * requester) {
	return requester ? getRequestInfos(requester->getUuid()).asker : NULL;
}
