#include "disqusscopesset.hpp"

#include "disqusscopes.hpp"
#include <QStringList>

DisqusScopesSet::DisqusScopesSet(QString scopes) : QSet<DisqusScopes::Scopes>()
{
	QStringList list = scopes.split(",");

	for (auto it = list.begin(); it != list.end(); ++it) {
		DisqusScopes::Scopes scope = DisqusScopes::scopeFromString(*it);

		if (scope != DisqusScopes::MISSINGNO) {
			this->insert(scope);
		}
	}
}

QString DisqusScopesSet::toString() const
{
	QStringList scopes;

	for (auto it = begin(); it != end(); ++it) {
		if (*it != DisqusScopes::MISSINGNO) {
			scopes.append(DisqusScopes::getScopeStr(*it));
		}
	}

	return scopes.join(",");
}
