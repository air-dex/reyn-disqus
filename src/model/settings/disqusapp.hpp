#ifndef DISQUSAPP_HPP
#define DISQUSAPP_HPP

#include <QByteArray>
#include <QString>
#include <QUrl>
#include <QSet>

#include "../../constants.hpp"
#include "disqusscopesset.hpp"

class DisqusApp
{
	public:
		// Default constructor : default credentials
		DisqusApp(
			QByteArray pkey = QByteArray::fromBase64(ReynDisqus::publicKey),
			QByteArray skey = QByteArray::fromBase64(ReynDisqus::secretKey),
			QString trdom = ReynDisqus::trustedDomain,
			DisqusScopesSet scopesSet = DisqusScopesSet(ReynDisqus::scopes)
		);

		DisqusApp(const DisqusApp & disqus);
		const DisqusApp & operator=(const DisqusApp & disqus);

		bool operator==(const DisqusApp & other) const;
		bool isDefaultApp() const;

		QByteArray getPublicKey() const;
		void setPublicKey(const QByteArray & value);

		QByteArray getSecretKey() const;
		void setSecretKey(const QByteArray & value);

		QUrl getTrustedDomain() const;
		void setTrustedDomain(const QUrl & value);

		DisqusScopesSet getScopes() const;
		void setScopes(const DisqusScopesSet & value);

	protected:
		QByteArray publicKey;
		QByteArray secretKey;
		QUrl trustedDomain;
		DisqusScopesSet scopes;

		void copy(const DisqusApp & disqus);
};

#endif // DISQUSAPP_HPP
