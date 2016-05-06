#include "networkresponse.hpp"

#include "uris.hpp"

NetworkResponse::NetworkResponse(HTTPCode httpCode,
								 QString httpReason,
								 QByteArray response,
								 QString error,
								 QString repURL) :
	httpResponse(httpCode, httpReason),
	responseBody(response),
	requestError(error),
	replyURL(repURL)
{}

// Building a NetworkResponse with the content of a QNetworkReply.
NetworkResponse::NetworkResponse(QNetworkReply * reply) :
	httpResponse(extractHttpStatusesFromNetworkReply(reply)),
	responseBody(reply ? reply->readAll() : ""),
	requestError(reply ? reply->errorString() : "null reply"),
	replyURL(reply ? reply->url().toString() : ReynDisqus::FAKE_URL)
{}

// Extracting the HTTP code and the HTTP reason from an HTTP reply.
ResponseInfos NetworkResponse::extractHttpStatusesFromNetworkReply(QNetworkReply * reply) {
	ResponseInfos httpResponse;

	if (reply) {
		QVariant httpStatus;

		// Extract return code
		httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
		httpResponse.code = httpStatus.toInt();

		// Extract return reason
		httpStatus = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute);
		httpResponse.message = QString::fromLatin1(httpStatus.toByteArray());
	}


	return httpResponse;
}

/////////////
// Getters //
/////////////

// httpResponse
ResponseInfos NetworkResponse::getHttpResponse() {
	return httpResponse;
}

// responseBody
QByteArray NetworkResponse::getResponseBody() {
	return responseBody;
}

// requestError
QString NetworkResponse::getRequestError() {
	return requestError;
}

// replyURL
QString NetworkResponse::getReplyURL() {
	return replyURL;
}
