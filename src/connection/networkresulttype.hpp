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

	/// @brief Disqus has returned errors.
	SERVICE_ERROR,

	/// @brief There was an error while parsing JSON.
	JSON_PARSING,

	/// @brief There was an error while parsing HTML.
	HTML_PARSING
};

#endif // NETWORKRESULTTYPE_HPP
