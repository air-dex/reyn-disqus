#ifndef RESPONSEINFOS_HPP
#define RESPONSEINFOS_HPP

#include <QString>

/// @struct ResponseInfos
/// @brief Struct with an integer (field "code") and its meaning (field "message").
///
/// When used to store JSON parsing errors, "message" is the error message and
/// "code" the offset.
struct ResponseInfos {
	/// @brief Code
	int code;

	/// @brief Decription of the code
	QString message;

	/// @fn ResponseInfos(int codeNum = -1, QString msg = "");
	/// @brief Full constructor
	/// @param codeNum Value for code
	/// @param msg Value for message
	ResponseInfos(int codeNum = -1, QString msg = "") :
		code(codeNum),
		message(msg)
	{}
};

#endif // RESPONSEINFOS_HPP
