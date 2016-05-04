#ifndef REQUESTRESULT_HPP
#define REQUESTRESULT_HPP

#include <QVariant>
#include "httpcode.hpp"
#include "responseinfos.hpp"

#include "networkresulttype.hpp"

/// @struct RequestResult
/// @brief Results of a request
struct RequestResult {
		/// @brief Code indicating whether an error occured during the request.
		NetworkResultType resultType;

		/// @brief Parsed results.
		QVariant parsedResult;

		/// @brief HTTP response (code and reason)
		ResponseInfos httpResponse;

		/// @brief Services (ex. Twitter) error response (code and reason)
		ResponseInfos serviceError;

		/// @brief Potential errors that can occur while parsing results.
		///
		/// The message field is the error message while the code field is the
		/// number of the line where the error occured.
		ResponseInfos parsingErrors;

		/// @brief Error message
		QString errorMessage;

		/// @fn RequestResult();
		/// @brief Constructor
		RequestResult() :
			resultType(INVALID_RESULT),
			parsedResult(),
			httpResponse(),
			serviceError(),
			parsingErrors(),
			errorMessage("")
		{}

		/// @fn LibRT::HTTPCode getHTTPCode();
		/// @brief HTTP response code (shortcut)
		/// @return The HTTP response code as a LibRT::HTTPCode.
		HTTPCode getHTTPCode() {
			return HTTPCode(httpResponse.code);
		}
};
#endif // REQUESTRESULT_HPP
