#include "authenticator.hpp"

Authenticator::Authenticator(QByteArray appPublicKey, QByteArray appSecretKey, QByteArray userAccessToken) :
	apiKey(appPublicKey),
	apiSecret(appSecretKey),
	accessToken(userAccessToken)
{}

Authenticator::Authenticator(const Authenticator & authInfos)
{
	copy(authInfos);
}

const Authenticator &Authenticator::operator=(const Authenticator & authInfos)
{
	copy(authInfos);
	return *this;
}

void Authenticator::copy(const Authenticator & authInfos)
{
	this->apiKey = authInfos.apiKey;
	this->apiSecret = authInfos.apiSecret;
	this->accessToken = authInfos.accessToken;
}

QByteArray Authenticator::getAccessToken() const
{
	return accessToken;
}

void Authenticator::setAccessToken(const QByteArray & value)
{
	accessToken = value;
}

QByteArray Authenticator::getAPISecret() const
{
	return apiSecret;
}

void Authenticator::setAPISecret(const QByteArray & value)
{
	apiSecret = value;
}

QByteArray Authenticator::getAPIKey() const
{
	return apiKey;
}

void Authenticator::setAPIKey(const QByteArray & value)
{
	apiKey = value;
}
