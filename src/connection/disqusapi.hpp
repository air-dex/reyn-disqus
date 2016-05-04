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

	/*************
	 * Internals *
	 *************/

	public:
		DisqusAPI(QObject * asker, Authenticator authInfos = Authenticator());
		~DisqusAPI();

		void setAsker(QObject * value);
		void setAuthInfos(const Authenticator & value);

	signals:
		void sendResult(RequestResult requestResult);

	protected:
		/// @brief Requester manager
		static RequesterManager REQUESTER_MANAGER;

		QObject * asker;
		Authenticator authInfos;

		void executeRequest(GenericRequester * requester);

	protected slots:
		void endRequest(RequestResult requestResult);


	/**************************
	 * API endpoints wrappers *
	 **************************/

	public:
		void accessToken(QUrl redirectURI, QString code);
		void refreshToken(QByteArray refreshToken);
};

#endif // DISQUSAPI_HPP
