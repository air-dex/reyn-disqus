#ifndef DISQUSSCOPES_HPP
#define DISQUSSCOPES_HPP

#include <QObject>

class DisqusScopes : public QObject
{
	Q_OBJECT

	public:
		// Scopes enum
		enum Scopes {
			MISSINGNO,
			READ,
			WRITE,
			ADMIN,
			EMAIL
		};

		Q_ENUMS(Scopes)

		DisqusScopes();
		static void declareQML();
		Q_INVOKABLE static QString getScopeStr(Scopes scope);
		Q_INVOKABLE static Scopes scopeFromString(QString scope);
};

#endif // DISQUSSCOPES_HPP
