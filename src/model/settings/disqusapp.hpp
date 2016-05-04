#ifndef DISQUSAPP_HPP
#define DISQUSAPP_HPP

#include <QByteArray>
#include <QObject>
#include <QString>
#include <QUrl>
#include <QSet>

#include "../../constants.hpp"
#include "disqusscopesset.hpp"

class DisqusApp : public QObject
{
	Q_OBJECT

	public:
		// Default constructor : default credentials
		DisqusApp(
			QByteArray pkey = QByteArray::fromBase64(ReynDisqus::publicKey),
			QByteArray skey = QByteArray::fromBase64(ReynDisqus::secretKey),
			QUrl trdom = QUrl(ReynDisqus::trustedDomain),
			DisqusScopesSet scopesSet = DisqusScopesSet(ReynDisqus::scopes)
		);

		DisqusApp(const DisqusApp & disqus);
		const DisqusApp & operator=(const DisqusApp & disqus);

		static void declareQML();

		bool operator==(const DisqusApp & other) const;
		bool isDefaultApp() const;

		QByteArray getPublicKey() const;
		void setPublicKey(const QByteArray & value);

		QByteArray getSecretKey() const;
		void setSecretKey(const QByteArray & value);

		QUrl getTrustedDomain() const;
		void setTrustedDomain(const QUrl & value);

		DisqusScopesSet getScopes() const;
		QString getScopesStr() const;
		void setScopes(const DisqusScopesSet & value);
		void setScopes(const QString & value);

	protected:
		Q_PROPERTY(QByteArray publicKey READ getPublicKey WRITE setPublicKey NOTIFY publicKeyChanged)
		QByteArray publicKey;

		Q_PROPERTY(QByteArray secretKey READ getSecretKey WRITE setSecretKey NOTIFY secretKeyChanged)
		QByteArray secretKey;

		Q_PROPERTY(QUrl trustedDomain READ getTrustedDomain WRITE setTrustedDomain NOTIFY trustedDomainChanged)
		QUrl trustedDomain;

		Q_PROPERTY(QString scopes READ getScopesStr WRITE setScopes NOTIFY scopesChanged)
		DisqusScopesSet scopes;

		void copy(const DisqusApp & disqus);

	signals:
		// NOTIFY properties
		void publicKeyChanged();
		void secretKeyChanged();
		void trustedDomainChanged();
		void scopesChanged();
};

#endif // DISQUSAPP_HPP
