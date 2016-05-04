#ifndef OAUTHACCESSREQUESTER_HPP
#define OAUTHACCESSREQUESTER_HPP

#include "../genericrequester.hpp"

class OAuthAccessRequester : public GenericRequester
{
	public:
		OAuthAccessRequester(Authenticator authInfos);
		virtual ResponseInfos treatServiceErrors(QJsonObject parsedResults, bool & hasServiceError);
};

#endif // OAUTHACCESSREQUESTER_HPP
