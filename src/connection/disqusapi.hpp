#ifndef DISQUSAPI_HPP
#define DISQUSAPI_HPP

#include <QObject>
#include <QString>
#include <QUrl>

#include "requestermanager.hpp"
#include "authenticator.hpp"

/// @class DisqusAPI
/// @brief C++ front for DisqusAPI.
///
/// Inspired by libRT: https://launchpad.net/librt
class DisqusAPI : public QObject
{
	Q_OBJECT

	public:
		DisqusAPI(QObject * asker, Authenticator authInfos = Authenticator());
		~DisqusAPI();

		void accessTokens(QUrl redirectURI, QString code);

		void setAsker(QObject * value);
		void setAuthInfos(const Authenticator & value);

	signals:
		void sendResult(RequestResult requestResult);

	/*************
	 * Internals *
	 *************/

	protected:
		/// @brief Requester manager
		static RequesterManager REQUESTER_MANAGER;

		QObject * asker;
		Authenticator authInfos;

		void executeRequest(GenericRequester * requester);

	protected slots:
		void endRequest(RequestResult requestResult);
};

#endif // DISQUSAPI_HPP
