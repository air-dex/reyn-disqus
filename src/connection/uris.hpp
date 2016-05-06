#ifndef URIS_HPP
#define URIS_HPP

#include <QString>

namespace ReynDisqus {
	QString getEndpointURL(const QString uri);

	// API URLs
	extern const QString FAKE_URL;
	extern const QString disqusAPIBaseURLPattern;
	extern const QString disqusAPIOAuthAuthorizeURL;
	extern const QString disqusAPIOAuthAccessTokensURL;

	extern const QString USERS_DETAILS_URI;
}

#endif // URIS_HPP
