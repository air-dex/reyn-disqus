#ifndef NETWORKRESPONSE_HPP
#define NETWORKRESPONSE_HPP

#include <QString>
#include <QByteArray>
#include <QNetworkReply>
#include "httpcode.hpp"
#include "responseinfos.hpp"
#include "uris.hpp"

class NetworkResponse
{
	public:
		/// @fn NetworkResponse(LibRT::HTTPCode httpCode = INVALID_HTTP_CODE,
		///						QString httpReason = "",
		///						QByteArray response = "",
		///						QString error = "",
		///						QString repURL = ReynDisqus::FAKE_URL);
		/// @brief Full constructor
		/// @param httpCode Value for httpResponse.code.
		/// @param httpReason Value for httpResponse.message.
		/// @param response Value for responseBody.
		/// @param error Value for requestError.
		/// @param repURL Value for replyURL.
		NetworkResponse(HTTPCode httpCode = INVALID_HTTP_CODE,
						QString httpReason = "",
						QByteArray response = "",
						QString error = "",
						QString repURL = ReynDisqus::FAKE_URL);

		/// @fn NetworkResponse(QNetworkReply * reply);
		/// @brief Building a NetworkResponse with the content of a QNetworkReply.
		/// @param reply the QNetworkReply
		NetworkResponse(QNetworkReply * reply);


		/////////////
		// Getters //
		/////////////

		/// @fn ResponseInfos getHttpResponse();
		/// @brief Getter on httpResponse.
		/// @return httpResponse
		ResponseInfos getHttpResponse();

		/// @fn QByteArray getResponseBody();
		/// @brief Getter on responseBody.
		/// @return responseBody
		QByteArray getResponseBody();

		/// @fn QString getRequestError();
		/// @brief Getter on requestError.
		/// @return requestError
		QString getRequestError();

		/// @fn QString getReplyURL();
		/// @brief Getter on replyURL.
		/// @return replyURL
		QString getReplyURL();

	protected:
		/// @brief HTTP rsponse code and reason
		ResponseInfos httpResponse;

		/// @brief Content of the response
		QByteArray responseBody;

		/// @brief Error which happened in the request
		QString requestError;

		/// @brief Reply URL
		QString replyURL;

		/// @fn ResponseInfos extractHttpStatusesFromNetworkReply(QNetworkReply * reply);
		/// @brief Extracting the HTTP code and the HTTP reason from an HTTP reply.
		/// @param reply The QNetworkReply containing the reply of the HTTP request.
		/// @return A ResponseInfos with the code and the reason.
		ResponseInfos extractHttpStatusesFromNetworkReply(QNetworkReply * reply);
};

#endif // NETWORKRESPONSE_HPP
