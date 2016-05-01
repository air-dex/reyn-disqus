#include "disqusapp.hpp"

#include <QByteArray>
#include <QUrl>
#include <QSettings>
#include "../../constants.hpp"

DisqusApp::DisqusApp(QByteArray pkey, QByteArray skey, QString trdom, DisqusScopesSet scopesSet) :
	publicKey(pkey),
	secretKey(skey),
	trustedDomain(trdom),
	scopes(scopesSet)
{}

DisqusApp::DisqusApp(const DisqusApp & disqus)
{
	copy(disqus);
}

const DisqusApp & DisqusApp::operator=(const DisqusApp & disqus)
{
	copy(disqus);
	return *this;
}

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
}

QByteArray DisqusApp::getSecretKey() const
{
	return secretKey;
}

void DisqusApp::setSecretKey(const QByteArray & value)
{
	secretKey = value;
}

QUrl DisqusApp::getTrustedDomain() const
{
	return trustedDomain;
}

void DisqusApp::setTrustedDomain(const QUrl & value)
{
	trustedDomain = value;
}

DisqusScopesSet DisqusApp::getScopes() const
{
	return scopes;
}

void DisqusApp::setScopes(const DisqusScopesSet & value)
{
	scopes = value;
}
