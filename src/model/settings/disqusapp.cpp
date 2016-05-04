#include "disqusapp.hpp"

#include <QtQml>
#include <QByteArray>
#include <QUrl>
#include <QSettings>
#include "../../constants.hpp"
#include "../../utils.hpp"

DisqusApp::DisqusApp(QByteArray pkey, QByteArray skey, QUrl trdom, DisqusScopesSet scopesSet) :
	QObject(),
	publicKey(pkey),
	secretKey(skey),
	trustedDomain(trdom),
	scopes(scopesSet)
{}

DisqusApp::DisqusApp(const DisqusApp & disqus) : QObject()
{
	copy(disqus);
}

const DisqusApp & DisqusApp::operator=(const DisqusApp & disqus)
{
	copy(disqus);
	return *this;
}

DECLARE_QML(DisqusApp, "DisqusApp")

bool DisqusApp::operator==(const DisqusApp & disqus) const
{
	return this->publicKey == disqus.publicKey
		&& this->secretKey == disqus.secretKey
		&& this->trustedDomain == disqus.trustedDomain
		&& this->scopes == disqus.scopes
	;
}

bool DisqusApp::isDefaultApp() const
{
	return *this == DisqusApp();
}

void DisqusApp::copy(const DisqusApp & disqus)
{
	this->publicKey = disqus.publicKey;
	this->secretKey = disqus.secretKey;
	this->trustedDomain = disqus.trustedDomain;
	this->scopes = disqus.scopes;
}

QByteArray DisqusApp::getPublicKey() const
{
	return publicKey;
}

void DisqusApp::setPublicKey(const QByteArray & value)
{
	publicKey = value;
	emit publicKeyChanged();
}

QByteArray DisqusApp::getSecretKey() const
{
	return secretKey;
}

void DisqusApp::setSecretKey(const QByteArray & value)
{
	secretKey = value;
	emit secretKeyChanged();
}

QUrl DisqusApp::getTrustedDomain() const
{
	return trustedDomain;
}

void DisqusApp::setTrustedDomain(const QUrl & value)
{
	trustedDomain = value;
	emit trustedDomainChanged();
}

DisqusScopesSet DisqusApp::getScopes() const
{
	return scopes;
}

QString DisqusApp::getScopesStr() const
{
	return scopes.toString();
}

void DisqusApp::setScopes(const DisqusScopesSet & value)
{
	scopes = value;
	emit scopesChanged();
}

void DisqusApp::setScopes(const QString & value)
{
	setScopes(DisqusScopesSet(value));
}
