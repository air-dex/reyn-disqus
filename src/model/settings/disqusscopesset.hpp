#ifndef DISQUSSCOPESSET_HPP
#define DISQUSSCOPESSET_HPP

#include <QSet>
#include "disqusscopes.hpp"

typedef QSetIterator<DisqusScopes::Scopes> DisqusScopesSetIterator;

class DisqusScopesSet : public QSet<DisqusScopes::Scopes>
{
	public:
		DisqusScopesSet(QString scopes = "");
		QString toString() const;
};

#endif // DISQUSSCOPESSET_HPP
