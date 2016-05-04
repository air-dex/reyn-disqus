#include "genericrequester.hpp"

#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

GenericRequester::GenericRequester(Authenticator authInfos, HTTPRequestType reqtype, QString uri, QByteArray ctype) :
	QObject(),
	uuid(QUuid::createUuid()),
	authInfos(authInfos),
	httpRequestType(reqtype),
	requestURI(uri),
	contentType(ctype)
{}

QUuid GenericRequester::getUuid() const
{
	return uuid;
}

/////////////////////////////
// Communicator management //
/////////////////////////////

CommunicatorManager GenericRequester::COMMUNICATOR_MANAGER = CommunicatorManager();

// Removing a requester of the Communicator manager
void GenericRequester::removeCommunicator(Communicator * weblink) {
	if (weblink) {
		disconnect(weblink, &Communicator::requestDone,
				   this, &GenericRequester::treatResults);

		COMMUNICATOR_MANAGER.removeCommunicator(weblink);
	}
}

// Executing the low level network request.
void GenericRequester::executeNetworkRequest(HeadersMap headers,
											 ArgsMap getParameters,
											 ArgsMap postParameters)
{
	Communicator * weblink = new Communicator(
								requestURI,
								httpRequestType,
								headers,
								getParameters,
								postParameters
							);

	connect(weblink, &Communicator::requestDone,
			this, &GenericRequester::treatResults);

	COMMUNICATOR_MANAGER.addCommunicator(weblink);

	weblink->executeRequest();
}


///////////////////////////
// Executing the request //
///////////////////////////

// Building GET Parameters
ArgsMap GenericRequester::buildGETParameters() {
	return ArgsMap();
}

// Building POST Parameters
ArgsMap GenericRequester::buildPOSTParameters() {
	return ArgsMap();
}

// Building HTTP Headers
HeadersMap GenericRequester::buildHTTPHeaders(ArgsMap getParameters,
											  ArgsMap postParameters)
{
	Q_UNUSED(getParameters)
	Q_UNUSED(postParameters)

	HeadersMap headers;

	// Content type
	headers.insert("Content-Type", this->contentType);

	return headers;
}

// Executing the request
void GenericRequester::executeRequest() {
	ArgsMap getParameters = buildGETParameters();
	ArgsMap postParameters = buildPOSTParameters();
	HeadersMap headers = buildHTTPHeaders(getParameters, postParameters);

	// Request time !
	this->executeNetworkRequest(headers, getParameters, postParameters);
}


//////////////////////////
// Treatment of results //
//////////////////////////

// Slot executed when the Twitter Communicator has just finished its work.
void GenericRequester::treatResults(NetworkResponse netResponse) {
	// Deleting the Communicator
	this->removeCommunicator(qobject_cast<Communicator *>(sender()));

	RequestResult requestResult;

	// Looking the HTTP request
	ResponseInfos netHTTPRep = netResponse.getHttpResponse();
	requestResult.httpResponse = netHTTPRep;
	requestResult.errorMessage = netResponse.getRequestError();

	switch (netHTTPRep.code) {
		case INVALID_HTTP_CODE:
			// Invalid response => INVALID_RESULT
			requestResult.resultType = INVALID_RESULT;
			break;

		case TIMEOUT_HTTP_CODE:
			// No response (because of timeout) => API_CALL
			requestResult.resultType = API_CALL;
			break;

		default: {
			// Parsing results. A JSON object is expected.
			QJsonParseError parseErr;
			QJsonDocument doc = QJsonDocument::fromJson(netResponse.getResponseBody(), &parseErr);
			requestResult.parsingErrors.code = parseErr.error;
			requestResult.parsingErrors.message = parseErr.errorString();
			bool parseOK = (parseErr.error == QJsonParseError::NoError);

			QJsonObject parsedRep;
			if (parseOK && doc.isObject()) {
				parsedRep = doc.object();
				requestResult.resultType = NO_REQUEST_ERROR;
				requestResult.parsedResult = QVariant::fromValue<QJsonObject>(parsedRep);
			}
			else if (parseOK && !doc.isObject()) {
				QJsonObject rep = doc.object();
				requestResult.resultType = JSON_PARSING;
				requestResult.parsedResult = QVariant::fromValue<QByteArray>(netResponse.getResponseBody());
				requestResult.parsingErrors.message = tr("The JSON response is parsed correctly but an object was expected.");
			}
			else {
				// Parsing error
				requestResult.resultType = JSON_PARSING;
				requestResult.parsedResult = QVariant::fromValue<QByteArray>(netResponse.getResponseBody());
			}

			// Service errors
			if (requestResult.resultType == NO_REQUEST_ERROR) {
				bool serviceError = false;
				requestResult.serviceError = treatServiceErrors(parsedRep, serviceError);

				if (serviceError) {
					requestResult.resultType = SERVICE_ERROR;
				}
			}
		} break;
	}

	// Telling the Calls that the request is finished
	emit requestEnded(requestResult);
}

// TODO: improve when it's time to do it.
ResponseInfos GenericRequester::treatServiceErrors(QJsonObject parsedResults, bool & hasServiceError)
{
	ResponseInfos serviceError;
	serviceError.code = parsedResults["code"].toInt();
	serviceError.message = parsedResults["error"].toString();
	hasServiceError = (serviceError.code == 0);
	return serviceError;
}
