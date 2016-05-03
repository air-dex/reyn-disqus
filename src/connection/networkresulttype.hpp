#ifndef NETWORKRESULTTYPE_HPP
#define NETWORKRESULTTYPE_HPP

/// @enum NetworkResultType
/// @brief Enumeration which indicates if something bad happened during the
/// request.
enum NetworkResultType {
	/// @brief There was no error.
	NO_REQUEST_ERROR,

	/// @brief Code for an invalid request result.
	INVALID_RESULT,

	/// @brief There were an error while calling the API.
	API_CALL,

	/// @brief The service (ex. Twitter) has returned errors.
	SERVICE_ERRORS,

	/// @brief There was an error while parsing JSON.
	JSON_PARSING,

	/// @brief There was an error while parsing results under the form
	/// <code>arg1=val1&arg2=val2&...&argN=valN</code>.
	OAUTH_PARSING,

	/// @brief There was an error while parsing HTML.
	HTML_PARSING,

	/// @brief There was an error while parsing XML.
	XML_PARSING,

	/// @brief There is not any parsing.
	NO_PARSING
};

#endif // NETWORKRESULTTYPE_HPP
