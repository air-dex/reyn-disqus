#include "usertokens.hpp"

#include "../../constants.hpp"
#include "../../utils.hpp"
#include <QSettings>

UserTokens::UserTokens() : QObject(), ISettings()
{
	BUILD_SETTINGS(settings);

	settings.beginGroup("user");
	settings.beginGroup("auth");
	settings.beginGroup("user");

	this->accessToken = QByteArray::fromBase64(settings.value(ReynDisqus::accessTokenSettingsKey).toByteArray());
	this->expiresIn = settings.value(ReynDisqus::expiresInSettingsKey).toDateTime();
	this->tokenType = settings.value(ReynDisqus::tokenTypeSettingsKey).toString();
	this->state = settings.value(ReynDisqus::stateSettingsKey).toString();
	this->scopes = DisqusScopesSet(settings.value(ReynDisqus::userScopeSettingsKey).toString());
	this->refreshToken = QByteArray::fromBase64(settings.value(ReynDisqus::refreshTokenSettingsKey).toByteArray());

	settings.endGroup();
	settings.endGroup();
	settings.endGroup();
}

UserTokens::UserTokens(QByteArray accessTokens, QDateTime expiresIn, QString tokenType, QString state, DisqusScopesSet scopes, QByteArray refreshToken) :
	QObject(),
	ISettings(),
	accessToken(accessTokens),
	expiresIn(expiresIn),
	tokenType(tokenType),
	state(state),
	scopes(scopes),
	refreshToken(refreshToken)
{}

UserTokens::UserTokens(const UserTokens & tokens)
{
	copy(tokens);
}

const UserTokens &UserTokens::operator=(const UserTokens & tokens)
{
	copy(tokens);
	return *this;
}

void UserTokens::copy(const UserTokens & tokens)
{
	this->accessToken = tokens.accessToken;
	this->expiresIn = tokens.expiresIn;
	this->tokenType = tokens.tokenType;
	this->state = tokens.state;
	this->scopes = tokens.scopes;
	this->refreshToken = tokens.refreshToken;
}

void UserTokens::sync()
{
	BUILD_SETTINGS(settings);

	settings.beginGroup("user");
	settings.beginGroup("auth");
	settings.beginGroup("user");

	setValuesInGroup(settings);

	settings.endGroup();
	settings.endGroup();
	settings.endGroup();

	settings.sync();
}

void UserTokens::setValuesInGroup(QSettings & settings)
{
	settings.setValue(ReynDisqus::accessTokenSettingsKey, accessToken.toBase64());
	settings.setValue(ReynDisqus::expiresInSettingsKey, QVariant::fromValue<QDateTime>(expiresIn));
	settings.setValue(ReynDisqus::tokenTypeSettingsKey, tokenType);
	settings.setValue(ReynDisqus::stateSettingsKey, state);
	settings.setValue(ReynDisqus::userScopeSettingsKey, scopes.toString());
	settings.setValue(ReynDisqus::refreshTokenSettingsKey, refreshToken.toBase64());
}

QByteArray UserTokens::getAccessToken() const
{
	return accessToken;
}

void UserTokens::setAccessToken(const QByteArray & value)
{
	accessToken = value;
}

QDateTime UserTokens::getExpiresIn() const
{
	return expiresIn;
}

void UserTokens::setExpiresIn(const QDateTime & value)
{
	expiresIn = value;
}

QString UserTokens::getTokenType() const
{
	return tokenType;
}

void UserTokens::setTokenType(const QString & value)
{
	tokenType = value;
}

QString UserTokens::getState() const
{
	return state;
}

void UserTokens::setState(const QString & value)
{
	state = value;
}

DisqusScopesSet UserTokens::getScopes() const
{
	return scopes;
}

void UserTokens::setScopes(const DisqusScopesSet & value)
{
	scopes = value;
}

void UserTokens::setScopes(const QString & value)
{
	setScopes(DisqusScopesSet(value));
}

QByteArray UserTokens::getRefreshToken() const
{
	return refreshToken;
}

void UserTokens::setRefreshToken(const QByteArray & value)
{
	refreshToken = value;
}
