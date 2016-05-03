#ifndef GENERICREQUESTER_HPP
#define GENERICREQUESTER_HPP

#include <QObject>
#include <QUuid>
#include "communicatormanager.hpp"
#include "httprequesttype.hpp"
#include "httpmaps.hpp"
#include "networkresponse.hpp"
#include "requestresult.hpp"
#include "authenticator.hpp"

class GenericRequester : public QObject
{
	Q_OBJECT
	public:
		GenericRequester(
			Authenticator authInfos,
			HTTPRequestType reqtype,
			QString uri,
			QByteArray ctype = "application/x-www-form-urlencoded"
		);

		virtual void executeRequest();

		QUuid getUuid() const;

	public slots:

	protected:
		QUuid uuid;
		Authenticator authInfos;
		HTTPRequestType httpRequestType;
		QString requestURI;

		/// @brief Request content type
		QByteArray contentType;

		/// @fn virtual ArgsMap buildGETParameters();
		/// @brief Virtual method building getParameters
		/// @return GET parameters that will be passed to the Communicator.
		virtual ArgsMap buildGETParameters();

		/// @fn virtual ArgsMap buildPOSTParameters();
		/// @brief Virtual method building postParameters
		/// @return POST parameters that will be passed to the Communicator.
		virtual ArgsMap buildPOSTParameters();

		/// @fn virtual HeadersMap buildHTTPHeaders(ArgsMap getParameters,
		///											ArgsMap postParameters);
		/// @brief Virtual method building headers
		/// @param getParameters GET parameters for the Communicator.
		/// @param postParameters POST parameters for the Communicator.
		/// @return HTTP headers that will be passed to the Communicator.
		virtual HeadersMap buildHTTPHeaders(ArgsMap getParameters,
											ArgsMap postParameters);

		/***************************
		 * Communicator management *
		 ***************************/

		static CommunicatorManager COMMUNICATOR_MANAGER;

		/// @fn void removeCommunicator(Communicator * weblink);
		/// @brief Removing a requester of the Communicator manager
		/// @param weblink Communicator to remove
		void removeCommunicator(Communicator * weblink);

		/// @fn void executeNetworkRequest(HeadersMap headers, ArgsMap getParameters, ArgsMap postParameters);
		/// @brief Executing the low level request.
		void executeNetworkRequest(HeadersMap headers, ArgsMap getParameters, ArgsMap postParameters);

		//////////////////////////
		// Treatment of results //
		//////////////////////////

		public slots:
			/// @fn void treatResults(NetworkResponse netResponse);
			/// @brief Slot that is executed when the Twitter Communicator has just
			/// finished its work.
			/// @param netResponse Struct with response elements
			void treatResults(NetworkResponse netResponse);

		protected:
//			/// @fn virtual QVariant parseResult(NetworkResponse results,
//			///									 bool & parseOK,
//			///									 QVariantMap & parsingErrors) = 0;
//			/// @brief Method that will parse the raw results of the request.
//			/// @param results Results to parse. Most of the time the method only
//			/// uses the responseBody field.
//			/// @param parseOK Boolean whose value will be set to true if there was
//			/// no problem while parsing, false otherwise.
//			/// @param parsingErrors QVariantMap that may contain information about
//			/// errors that may occur while parsing.
//			/// @return Parsed results
//			virtual QVariant parseResult(NetworkResponse results,
//										 bool & parseOK,
//										 QVariantMap & parsingErrors) = 0;

//			/// @fn virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
//			///														NetworkResponse netResponse) = 0;
//			/// @brief Treating parsed results
//			/// @param parsedResults Parsed results to analyse in order to retrieve
//			/// service errors.
//			/// @param netResponse Other network response elements, if needed.
//			/// @return The list of service errors
//			virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
//															NetworkResponse netResponse) = 0;

		signals:
			/// @fn void requestDone(RequestResult requestResult);
			/// @brief Signal sent when the results of the request received by
			/// the Twitter Communicator have been treated.
			/// @param requestResult Result of the request.
			void requestEnded(RequestResult requestResult);
};

#endif // GENERICREQUESTER_HPP
