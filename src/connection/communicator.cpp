#include "communicator.hpp"
#include <QNetworkRequest>

#ifdef QT_DEBUG
	#include <QtDebug>	// For debugging purposes
#endif

// Network manager
// TODO: What about Android?
#ifdef Q_OS_WIN
	QNetworkAccessManager RD_NETWORK_MANAGER = QNetworkAccessManager();
#elif defined(Q_OS_LINUX)
	QNetworkAccessManager RD_NETWORK_MANAGER;
#endif

/////////////
// Coplien //
/////////////

// Constructor
Communicator::Communicator(QString &url,
						   HTTPRequestType type,
						   HeadersMap headersParam,
						   ArgsMap getArgs,
						   ArgsMap postArgs) :
	QObject(),
	timeoutTimer(),
	serviceURL(url),
	requestType(type),
	getParameters(getArgs),
	postParameters(postArgs),
	headers(headersParam)
{
	// Setting the timer
	timeoutTimer.setInterval(10*1000); // 10 seconds
	timeoutTimer.setSingleShot(true);
	connect(&timeoutTimer, &QTimer::timeout,
			this, &Communicator::timeout);
}

// Destructor
Communicator::~Communicator() {
	disconnect(&timeoutTimer, &QTimer::timeout,
			   this, &Communicator::timeout);
}


///////////////////////////
// Executing the request //
///////////////////////////

// Preparing the request
QNetworkRequest * Communicator::prepareRequest() {
	// GET arguments
	QUrlQuery getArgs = buildGetDatas();

	QUrl reqURL(serviceURL);
	reqURL.setQuery(getArgs);

	QNetworkRequest * request = new QNetworkRequest(reqURL);

	// Adding the headers
	for (HeadersMap::Iterator it = headers.begin();
		 it != headers.end();
		 ++it)
	{
	   request->setRawHeader(it.key(), it.value());
	}

	// Tag of the request with the originatingObject to identify the reply
	request->setOriginatingObject(this);

	return request;
}

// Executing the request
void Communicator::executeRequest() {
	// Preparing the request
	QNetworkRequest * request = prepareRequest();

	// Connection for receiving the response
	connect(&RD_NETWORK_MANAGER, &QNetworkAccessManager::finished,
			this, &Communicator::endRequest);

	switch (requestType) {
		case GET:
			// GET request
			RD_NETWORK_MANAGER.get(*request);
			break;

		case POST:
			// POST request
			RD_NETWORK_MANAGER.post(*request, buildPostDatas());
			break;

		default:
			// Should not happen
			// TODO : error case
			break;
	}

	timeoutTimer.start();
}


//////////
// Slot //
//////////

// Treatments that have to be done at the end of the request
void Communicator::endRequest(QNetworkReply * response) {
	// Treating the response

	// Is it the response of that precise request ?
	if (!response || this != response->request().originatingObject()) {
		// Null reply or bad sender -> No -> doing nothing
		return;
	}

	// That's our request. Let's do the treatments !

	// No timeout : stop the timer.
	timeoutTimer.stop();

	// Unwiring
	disconnect(&RD_NETWORK_MANAGER, &QNetworkAccessManager::finished,
			   this, &Communicator::endRequest);

	// Extracting informations
	NetworkResponse netrep(response);
	response->deleteLater();

	#ifdef QT_DEBUG
		qDebug() << "responseBuffer :" << '\n'
				 << netrep.getResponseBody() << '\n';
	#endif

	// Ending the request
	emit requestDone(netrep);
}

// Network timeout
void Communicator::timeout() {
	// It seems that no response will arrive. That's enough ! Stop it !

	// Unwiring
	disconnect(&RD_NETWORK_MANAGER, &QNetworkAccessManager::finished,
			   this, &Communicator::endRequest);

	NetworkResponse response(TIMEOUT_HTTP_CODE,
							 "timeout",
							 "",
							 "timeout",
							 serviceURL);

	// Ending the request
	emit requestDone(response);
}


/////////////////////
// Buiding ArgMaps //
/////////////////////

// Building a string that will contain all the GET arguments
QUrlQuery Communicator::buildGetDatas() {
	return buildDatas(getParameters);
}

// Building a QByteArray that will contain all the POST arguments
QByteArray Communicator::buildPostDatas() {
	QUrlQuery postQuery = buildDatas(postParameters);
	return QByteArray().append(postQuery.toString());
}

// Building the string that will contain all the arguments
// of the given ArgsMap just like in an URL.
QUrlQuery Communicator::buildDatas(ArgsMap argsMap) {
	QUrlQuery query;

	// Writing the arguments
	for (ArgsMap::iterator argsIterator = argsMap.begin();
		 argsIterator != argsMap.end();
		 ++argsIterator)
	{
		query.addQueryItem(argsIterator.key(), argsIterator.value());
	}

	return query;
}
