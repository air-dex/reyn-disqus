#ifndef AUTHREQUESTER_HPP
#define AUTHREQUESTER_HPP

#include "genericrequester.hpp"

class AuthRequester : public GenericRequester
{
	public:
		AuthRequester(Authenticator authInfos, HTTPRequestType reqtype, QString uri);

	protected:
		/// @fn virtual ArgsMap buildGETParameters();
		/// @brief Virtual method building getParameters
		/// @return GET parameters that will be passed to the Communicator.
		virtual ArgsMap buildGETParameters();
};

#endif // AUTHREQUESTER_HPP
