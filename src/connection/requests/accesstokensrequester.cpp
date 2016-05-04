#include "accesstokensrequester.hpp"

#include "../../constants.hpp"
#include <QJsonObject>

AccessTokensRequester::AccessTokensRequester(Authenticator authInfos, QUrl redirectURI, QString code) :
	GenericRequester(authInfos, HTTPRequestType::POST, ReynDisqus::disqusAPIOAuthAccessTokensURL),
	redirectURI(redirectURI),
	code(code)
{}

ArgsMap AccessTokensRequester::buildPOSTParameters()
{
	ArgsMap postParams = GenericRequester::buildPOSTParameters();

	postParams.insert("grant_type", "authorization_code");
	postParams.insert("client_id", authInfos.getAppPublicKey());
	postParams.insert("client_secret", authInfos.getAppSecretKey());
	postParams.insert("redirect_uri", redirectURI.toString());
	postParams.insert("code", code);

	return postParams;
}

ResponseInfos AccessTokensRequester::treatServiceErrors(QJsonObject parsedResults, bool & hasServiceError)
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
