#ifndef ACCESSTOKENSREQUESTER_HPP
#define ACCESSTOKENSREQUESTER_HPP

#include "oauthaccessrequester.hpp"
#include <QUrl>

class AccessTokensRequester : public OAuthAccessRequester
{
	public:
		AccessTokensRequester(Authenticator authInfos, QUrl redirectURI, QString code);

	protected:
		/// @fn virtual ArgsMap buildPOSTParameters();
		/// @brief Virtual method building postParameters
		/// @return POST parameters that will be passed to the Communicator.
		virtual ArgsMap buildPOSTParameters();

		QUrl redirectURI;
		QString code;
};

#endif // ACCESSTOKENSREQUESTER_HPP
