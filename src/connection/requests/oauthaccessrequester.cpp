#include "oauthaccessrequester.hpp"

#include <QJsonObject>
#include "../uris.hpp"

OAuthAccessRequester::OAuthAccessRequester(Authenticator authInfos) :
	GenericRequester(authInfos, HTTPRequestType::POST, ReynDisqus::disqusAPIOAuthAccessTokensURL)
{}

ResponseInfos OAuthAccessRequester::treatServiceErrors(QJsonObject parsedResults, bool & hasServiceError)
{
	ResponseInfos res;

	hasServiceError = parsedResults.contains("error");
	res.code = hasServiceError;
	res.message = hasServiceError ?
		  QString("%1: %2.").arg(
			parsedResults["error"].toString(),
			parsedResults["error_description"].toString()
		  )
		: tr("No service error.")
	;

	return res;
}
