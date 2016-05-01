#include "disqusscopes.hpp"

#include <QtQml>
#include "../../constants.hpp"
#include "../../utils.hpp"

DisqusScopes::DisqusScopes() : QObject() {}

DECLARE_QML(DisqusScopes, "DisqusScopes")

QString DisqusScopes::getScopeStr(DisqusScopes::Scopes scope)
{
	switch (scope) {
		case READ:
			return "read";

		case WRITE:
			return "write";

		case ADMIN:
			return "admin";

		case EMAIL:
			return "email";

		case MISSINGNO:
		default:
			return "";
	}
}

DisqusScopes::Scopes DisqusScopes::scopeFromString(QString scope)
{
	if (scope == "read") {
		return READ;
	} else if (scope == "write") {
		return WRITE;
	} else if (scope == "admin") {
		return ADMIN;
	} else if (scope == "email") {
		return EMAIL;
	} else {
		return MISSINGNO;
	}
}
