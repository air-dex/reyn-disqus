#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include <QNetworkAccessManager>
#include <QObject>
#include <QTimer>
#include <QUrlQuery>
#include "httprequesttype.hpp"
#include "httpmaps.hpp"
#include "networkresponse.hpp"

extern QNetworkAccessManager RD_NETWORK_MANAGER;

class Communicator: public QObject {
	Q_OBJECT

	public:
		/// @fn Communicator(QString &url,
		///					 LibRT::HTTPRequestType type,
		///					 HeadersMap headersParam = HeadersMap(),
		///					 ArgsMap getArgs = ArgsMap(),
		///					 ArgsMap postArgs = ArgsMap());
		/// @brief Constructor
		/// @param url String representation of the URL
		/// @param type Type of the request (GET ou POST).
		/// @param headersParam HTTP headers
		/// @param getArgs GET arguments
		/// @param postArgs POST arguments
		/// @param netManager Entity managing low level network tasks.
		/// Dependency injection for custom network accesses just like
		/// mocks for tests.
		Communicator(QString & url,
					 HTTPRequestType type,
					 HeadersMap headersParam = HeadersMap(),
					 ArgsMap getArgs = ArgsMap(),
					 ArgsMap postArgs = ArgsMap());

		/// @fn ~Communicator();
		/// @brief Destructor
		~Communicator();

		/// @fn QNetworkRequest * prepareRequest();
		/// @brief Preparing the request. It builds the parameters for GET
		/// and POST and the Authorization header if needed.
		/// @return A pointer on the request
		QNetworkRequest * prepareRequest();

		/// @fn virtual void executeRequest();
		/// @brief Executing the request
		virtual void executeRequest();


	signals:
		/// @fn void requestDone(NetworkResponse result);
		/// @brief Signal indicating the end of a request
		void requestDone(NetworkResponse result);


	protected slots:
		/// @fn void endRequest(QNetworkReply * response);
		/// @brief Slot called at the end of the request.
		/// @param response The network reply.
		void endRequest(QNetworkReply * response);

		/// @fn void timeout();
		/// @brief Slot called it there is a network timeout.
		void timeout();

	protected:
		/// @brief Timer to avoid to wait for responses ad vitam aeternam.
		QTimer timeoutTimer;

		// Entities for request

		/// @brief URL of the service
		QString & serviceURL;

		/// @brief Request type
		HTTPRequestType requestType;

		/// @brief GET datas
		ArgsMap getParameters;

		/// @brief POST datas
		ArgsMap postParameters;

		/// @brief HTTP headers
		HeadersMap headers;


	private:
		/// @fn QUrlQuery buildGetDatas();
		/// @brief Building the string that will contain all the GET arguments
		/// and go through the Internet
		/// @return A QString containing all the GET arguments or an empty
		/// string if there is no GET arguments. This string will be appended
		/// at the end of the URL with a '?' between the URL and the string.
		QUrlQuery buildGetDatas();

		/// @fn QByteArray buildPostDatas();
		/// @brief Building the array that will contain all the POST arguments
		/// and go through the Internet
		/// @return A QByteArray containing all the POST arguments or an empty
		/// string if there is no POST arguments. If the string is not empty,
		/// it will be passed to the post method of the QNetworkAccessManager
		QByteArray buildPostDatas();

		/// @fn QUrlQuery buildDatas(ArgsMap argsMap);
		/// @brief Building the string that will contain all the arguments
		/// of the given ArgsMap just like in an URL.
		/// @param argsMap The argument map
		/// @return A QString representation looks like val1=arg1&val2=arg2...
		QUrlQuery buildDatas(ArgsMap argsMap);
	};
#endif // COMMUNICATOR_HPP
