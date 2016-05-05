#include "disqususer.hpp"

#include <QtQml>
#include "../constants.hpp"
#include "../utils.hpp"

DisqusUser::DisqusUser() :
	QObject(),
	userID(0),
	username(""),
	name(""),
	about(""),
	url(),
	profileURL(),
	signedURL(),
	location(""),
	isPrivate(false),
	numLikesReceieved(0),
	numPosts(0),
	joinedAt(QDateTime::currentDateTimeUtc()),
	numFollowers(0),
	numFollowing(0),
	numForumsFollowing(0),
	anonymous(true),
	avatar()
{}

DisqusUser::DisqusUser(QJsonObject userObj) :
	QObject(),
	userID(userObj[DisqusUser::USER_ID_JSON_FIELDNAME].toString().toInt()),
	username(userObj[DisqusUser::USERNAME_JSON_FIELDNAME].toString()),
	name(userObj[DisqusUser::NAME_JSON_FIELDNAME].toString()),
	about(userObj[DisqusUser::ABOUT_JSON_FIELDNAME].toString()),
	url(userObj[DisqusUser::URL_JSON_FIELDNAME].toString()),
	profileURL(userObj[DisqusUser::PROFILE_URL_JSON_FIELDNAME].toString()),
	signedURL(userObj[DisqusUser::SIGNED_URL_JSON_FIELDNAME].toString()),
	location(userObj[DisqusUser::LOCATION_JSON_FIELDNAME].toString()),
	isPrivate(userObj[DisqusUser::IS_PRIVATE_JSON_FIELDNAME].toBool()),
	numLikesReceieved(userObj[DisqusUser::NUM_LIKES_RECEIVED_JSON_FIELDNAME].toInt()),
	numPosts(userObj[DisqusUser::NUM_POSTS_JSON_FIELDNAME].toInt()),
	joinedAt(QDateTime::fromString(userObj[DisqusUser::JOINED_AT_JSON_FIELDNAME].toString(), Qt::ISODate)),
	numFollowers(userObj[DisqusUser::NUM_FOLLOWERS_JSON_FIELDNAME].toInt()),
	numFollowing(userObj[DisqusUser::NUM_FOLLOWING_JSON_FIELDNAME].toInt()),
	numForumsFollowing(userObj[DisqusUser::NUM_FORUMS_FOLLOWING_JSON_FIELDNAME].toInt()),
	anonymous(userObj[DisqusUser::IS_ANONYMOUS_JSON_FIELDNAME].toBool()),
	avatar(userObj[DisqusUser::AVATAR_JSON_FIELDNAME].toObject())
{}

DisqusUser::DisqusUser(const DisqusUser & user) : QObject()
{
	copy(user);
}

const DisqusUser &DisqusUser::operator=(const DisqusUser & user)
{
	copy(user);
	return *this;
}

void DisqusUser::copy(const DisqusUser & user)
{
	this->userID = user.userID;
	this->username = user.username;
	this->name = user.name;
	this->about = user.about;
	this->url = user.url;
	this->profileURL = user.profileURL;
	this->signedURL = user.signedURL;
	this->location = user.location;
	this->isPrivate = user.isPrivate;
	this->numLikesReceieved = user.numLikesReceieved;
	this->numPosts = user.numPosts;
	this->joinedAt = user.joinedAt;
	this->numFollowers = user.numFollowers;
	this->numFollowing = user.numFollowing;
	this->numForumsFollowing = user.numForumsFollowing;
	this->anonymous = user.anonymous;
	this->avatar = user.avatar;
}

DECLARE_QML(DisqusUser, "DisqusUser")

QString DisqusUser::USER_ID_JSON_FIELDNAME = "id";
int DisqusUser::getUserID() const
{
	return userID;
}

void DisqusUser::setUserID(int value)
{
	userID = value;
	emit userIDChanged();
}

QString DisqusUser::getUserIDStr() const
{
	return QString::number(userID);
}

void DisqusUser::setUserIDStr(QString value)
{
	bool ok;
	int intval = value.toInt(&ok);

	if (ok) {
		setUserID(intval);
	}
}

QString DisqusUser::USERNAME_JSON_FIELDNAME = "username";
QString DisqusUser::getUsername() const
{
	return username;
}
void DisqusUser::setUsername(const QString & value)
{
	username = value;
	emit usernameChanged();
}

QString DisqusUser::NAME_JSON_FIELDNAME = "name";
QString DisqusUser::getName() const
{
	return name;
}
void DisqusUser::setName(const QString & value)
{
	name = value;
	emit nameChanged();
}

QString DisqusUser::ABOUT_JSON_FIELDNAME = "about";
QString DisqusUser::getAbout() const
{
	return about;
}

void DisqusUser::setAbout(const QString & value)
{
	about = value;
	emit aboutChanged();
}

QString DisqusUser::URL_JSON_FIELDNAME = "url";
QUrl DisqusUser::getUrl() const
{
	return url;
}

void DisqusUser::setUrl(const QUrl & value)
{
	url = value;
	emit urlChanged();
}

QString DisqusUser::PROFILE_URL_JSON_FIELDNAME = "profileUrl";
QUrl DisqusUser::getProfileURL() const
{
	return profileURL;
}

void DisqusUser::setProfileURL(const QUrl & value)
{
	profileURL = value;
	emit profileURLChanged();
}

QString DisqusUser::SIGNED_URL_JSON_FIELDNAME = "signedUrl";
QUrl DisqusUser::getSignedURL() const
{
	return signedURL;
}

void DisqusUser::setSignedURL(const QUrl & value)
{
	signedURL = value;
	emit signedURLChanged();
}

QString DisqusUser::LOCATION_JSON_FIELDNAME = "location";
QString DisqusUser::getLocation() const
{
	return location;
}

void DisqusUser::setLocation(const QString & value)
{
	location = value;
	emit locationChanged();
}

QString DisqusUser::IS_PRIVATE_JSON_FIELDNAME = "isPrivate";
bool DisqusUser::getIsPrivate() const
{
	return isPrivate;
}

void DisqusUser::setIsPrivate(bool value)
{
	isPrivate = value;
	emit isPrivateChanged();
}

QString DisqusUser::NUM_LIKES_RECEIVED_JSON_FIELDNAME = "numLikesReceieved";
int DisqusUser::getNumLikesReceieved() const
{
	return numLikesReceieved;
}

void DisqusUser::setNumLikesReceieved(int value)
{
	numLikesReceieved = value;
	emit numLikesReceievedChanged();
}

QString DisqusUser::NUM_POSTS_JSON_FIELDNAME = "numPosts";
int DisqusUser::getNumPosts() const
{
	return numPosts;
}

void DisqusUser::setNumPosts(int value)
{
	numPosts = value;
	emit numPostsChanged();
}

QString DisqusUser::JOINED_AT_JSON_FIELDNAME = "joinedAt";
QDateTime DisqusUser::getJoinedAt() const
{
	return joinedAt;
}
QString DisqusUser::getJoinedAtStr() const
{
	return joinedAt.toString(Qt::ISODate);
}

void DisqusUser::setJoinedAt(const QDateTime & value)
{
	joinedAt = value;
	emit joinedAtChanged();
}

void DisqusUser::setJoinedAt(const QString & value)
{
	setJoinedAt(QDateTime::fromString(value, Qt::ISODate));
}

QString DisqusUser::NUM_FOLLOWERS_JSON_FIELDNAME = "numFollowers";
int DisqusUser::getNumFollowers() const
{
	return numFollowers;
}

void DisqusUser::setNumFollowers(int value)
{
	numFollowers = value;
	emit numFollowersChanged();
}

QString DisqusUser::NUM_FOLLOWING_JSON_FIELDNAME = "numFollowing";
int DisqusUser::getNumFollowing() const
{
	return numFollowing;
}

void DisqusUser::setNumFollowing(int value)
{
	numFollowing = value;
	emit numFollowingChanged();
}

QString DisqusUser::NUM_FORUMS_FOLLOWING_JSON_FIELDNAME = "numForumsFollowing";
int DisqusUser::getNumForumsFollowing() const
{
	return numForumsFollowing;
}

void DisqusUser::setNumForumsFollowing(int value)
{
	numForumsFollowing = value;
	emit numForumsFollowingChanged();
}

QString DisqusUser::IS_ANONYMOUS_JSON_FIELDNAME = "isAnonymous";
bool DisqusUser::isAnonymous() const
{
	return anonymous;
}

void DisqusUser::setAnonymous(bool value)
{
	anonymous = value;
	emit isAnonymousChanged();
}

QString DisqusUser::AVATAR_JSON_FIELDNAME = "avatar";
AvatarImage DisqusUser::getAvatar() const
{
	return avatar;
}

AvatarImage * DisqusUser::getAvatarPtr()
{
	return &avatar;
}

void DisqusUser::setAvatar(const AvatarImage & value)
{
	avatar = value;
	emit avatarChanged();
}

void DisqusUser::setAvatar(const AvatarImage * value)
{
	if (value) {
		setAvatar(*value);
	}
}
