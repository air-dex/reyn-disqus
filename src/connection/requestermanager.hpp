#ifndef REQUESTERMANAGER_HPP
#define REQUESTERMANAGER_HPP

#include <QMap>
#include <QUuid>
#include "requestinfos.hpp"

/// Inspired by libRT: https://launchpad.net/librt
class RequesterManager : protected QMap<QUuid, RequestInfos>
{
	public:
		/// @fn RequesterManager();
		/// @brief Constructs an empty map
		RequesterManager();

		/// @fn RequestInfos & getRequestInfos(QUuid requestUuid);
		/// @brief Getter on request informations
		/// @param requestUuid UUID of the requester
		RequestInfos & getRequestInfos(QUuid requestUuid);

		/// @fn void addRequest(QObject * asker, GenericRequester * requester);
		/// @brief Storing a request
		/// @param asker Entity that asks for the request
		/// @param requester Entity that executing the request
		void addRequest(QObject * asker, GenericRequester * requester);

		/// @fn void removeRequest(GenericRequester * requester);
		/// @brief Removing a request from the manager
		/// @param requester Requester to remove
		void removeRequest(GenericRequester * requester);

		/// @fn QObject * getAsker(GenericRequester * requester);
		/// @brief Getting the QObject which asked for the request
		/// @param requester The requester which executes the request
		/// @return The QObject which asked for the process. It should be
		/// a Process.
		QObject * getAsker(GenericRequester * requester);
};

#endif // REQUESTERMANAGER_HPP
