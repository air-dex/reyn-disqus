#include "uris.hpp"

#include "../constants.hpp"

// API URLs
const QString ReynDisqus::FAKE_URL = "";
const QString ReynDisqus::disqusAPIBaseURLPattern = "https://disqus.com/api/3.0/%1";
const QString ReynDisqus::disqusAPIOAuthAuthorizeURL = "https://disqus.com/api/oauth/2.0/authorize/";
const QString ReynDisqus::disqusAPIOAuthAccessTokensURL = "https://disqus.com/api/oauth/2.0/access_token/";

// URIs
const QString ReynDisqus::USERS_DETAILS_URI = "users/details.json";

QString ReynDisqus::getEndpointURL(const QString uri)
{
	return ReynDisqus::disqusAPIBaseURLPattern.arg(uri);
}
