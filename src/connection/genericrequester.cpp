#include "genericrequester.hpp"

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

//	RequestResult requestResult;

//	// Looking the HTTP request
//	ResponseInfos netHTTPRep = netResponse.getHttpResponse();
//	requestResult.httpResponse = netHTTPRep;
//	requestResult.errorMessage = netResponse.getRequestError();

//	switch (netHTTPRep.code) {
//		case INVALID_HTTP_CODE:
//			// Invalid response => INVALID_RESULT
//			requestResult.resultType = INVALID_RESULT;
//			break;

//		case TIMEOUT_HTTP_CODE:
//			// No response (because of timeout) => API_CALL
//			requestResult.resultType = API_CALL;
//			break;

//		default: {
//			// Parsing the response and filling requestResult
//			bool parseOK;
//			QVariantMap parseErrorMap;
//			requestResult.parsedResult = this->parseResult(netResponse,
//														   parseOK,
//														   parseErrorMap);
//			requestResult.parsingErrors.code = parseErrorMap.value("lineError").toInt();
//			requestResult.parsingErrors.message = parseErrorMap.value("errorMsg").toString();

//			if (parseOK) {
//				// Other treatments related to the service
//				requestResult.serviceErrors = this->treatServiceErrors(requestResult.parsedResult,
//																	   netResponse);
//				// Updating the NetworkResultType with service errors
//				requestResult.resultType = requestResult.serviceErrors.isEmpty() ?
//							NO_REQUEST_ERROR
//						  : SERVICE_ERRORS;
//			} else {
//				requestResult.resultType = parsingErrorType;

//				// Giving the response just in case the user would like to do sthg with it.
//				requestResult.parsedResult = QVariant::fromValue(netResponse.getResponseBody());
//			}
//		} break;
//	}

//	// Telling the Calls that the request is finished
//	emit requestDone(requestResult);
}
