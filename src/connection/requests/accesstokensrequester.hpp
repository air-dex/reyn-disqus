#ifndef ACCESSTOKENSREQUESTER_HPP
#define ACCESSTOKENSREQUESTER_HPP

#include "../genericrequester.hpp"
#include <QUrl>

class AccessTokensRequester : public GenericRequester
{
	public:
		AccessTokensRequester(Authenticator authInfos, QUrl redirectURI, QString code);

	protected:
		/// @fn virtual ArgsMap buildPOSTParameters();
		/// @brief Virtual method building postParameters
		/// @return POST parameters that will be passed to the Communicator.
		virtual ArgsMap buildPOSTParameters();

		QString code;
		QUrl redirectURI;
};

#endif // ACCESSTOKENSREQUESTER_HPP
