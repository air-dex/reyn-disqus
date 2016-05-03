#include "authenticator.hpp"

Authenticator::Authenticator(QByteArray appPublicKey, QByteArray appSecretKey, QByteArray userAccessToken) :
	appPublicKey(appPublicKey),
	appSecretKey(appSecretKey),
	userAccessToken(userAccessToken)
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
	this->appPublicKey = authInfos.appPublicKey;
	this->appSecretKey = authInfos.appSecretKey;
	this->userAccessToken = authInfos.userAccessToken;
}

QByteArray Authenticator::getUserAccessToken() const
{
	return userAccessToken;
}

void Authenticator::setUserAccessToken(const QByteArray & value)
{
	userAccessToken = value;
}

QByteArray Authenticator::getAppSecretKey() const
{
	return appSecretKey;
}

void Authenticator::setAppSecretKey(const QByteArray & value)
{
	appSecretKey = value;
}

QByteArray Authenticator::getAppPublicKey() const
{
	return appPublicKey;
}

void Authenticator::setAppPublicKey(const QByteArray & value)
{
	appPublicKey = value;
}
