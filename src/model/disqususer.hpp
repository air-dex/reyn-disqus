#ifndef DISQUSUSER_HPP
#define DISQUSUSER_HPP

#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include <QUrl>
#include "avatarimage.hpp"

class DisqusUser : public QObject
{
	Q_OBJECT

	public:
		DisqusUser();
		DisqusUser(QJsonObject userObj);
		DisqusUser(const DisqusUser & user);
		const DisqusUser & operator=(const DisqusUser & user);
		static void declareQML();

	protected:
		void copy(const DisqusUser & user);

		// Properties
		Q_PROPERTY(int userID READ getUserID WRITE setUserID NOTIFY userIDChanged)
		Q_PROPERTY(QString userIDStr READ getUserIDStr WRITE setUserIDStr NOTIFY userIDChanged)
		int userID;
		static QString USER_ID_JSON_FIELDNAME;

		Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameChanged)
		QString username;
		static QString USERNAME_JSON_FIELDNAME;

		Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
		QString name;
		static QString NAME_JSON_FIELDNAME;

		Q_PROPERTY(QString about READ getAbout WRITE setAbout NOTIFY aboutChanged)
		QString about;
		static QString ABOUT_JSON_FIELDNAME;

		Q_PROPERTY(QUrl url READ getUrl WRITE setUrl NOTIFY urlChanged)
		QUrl url;
		static QString URL_JSON_FIELDNAME;

		Q_PROPERTY(QUrl profileURL READ getProfileURL WRITE setProfileURL NOTIFY profileURLChanged)
		QUrl profileURL;
		static QString PROFILE_URL_JSON_FIELDNAME;

		Q_PROPERTY(QUrl signedURL READ getSignedURL WRITE setSignedURL NOTIFY signedURLChanged)
		QUrl signedURL;
		static QString SIGNED_URL_JSON_FIELDNAME;

		Q_PROPERTY(QString location READ getLocation WRITE setLocation NOTIFY locationChanged)
		QString location;
		static QString LOCATION_JSON_FIELDNAME;

		Q_PROPERTY(bool isPrivate READ getIsPrivate WRITE setIsPrivate NOTIFY isPrivateChanged)
		bool isPrivate;
		static QString IS_PRIVATE_JSON_FIELDNAME;

		Q_PROPERTY(int numLikesReceieved READ getNumLikesReceieved WRITE setNumLikesReceieved NOTIFY numLikesReceievedChanged)
		int numLikesReceieved;
		static QString NUM_LIKES_RECEIVED_JSON_FIELDNAME;

		Q_PROPERTY(int numPosts READ getNumPosts WRITE setNumPosts NOTIFY numPostsChanged)
		int numPosts;
		static QString NUM_POSTS_JSON_FIELDNAME;

		Q_PROPERTY(QDateTime joinedAt READ getJoinedAt WRITE setJoinedAt NOTIFY joinedAtChanged)
		Q_PROPERTY(QString joinedAtStr READ getJoinedAtStr WRITE setJoinedAt NOTIFY joinedAtChanged)
		QDateTime joinedAt;
		static QString JOINED_AT_JSON_FIELDNAME;

		Q_PROPERTY(int numFollowers READ getNumFollowers WRITE setNumFollowers NOTIFY numFollowersChanged)
		int numFollowers;
		static QString NUM_FOLLOWERS_JSON_FIELDNAME;

		Q_PROPERTY(int numFollowing READ getNumFollowing WRITE setNumFollowing NOTIFY numFollowingChanged)
		int numFollowing;
		static QString NUM_FOLLOWING_JSON_FIELDNAME;

		Q_PROPERTY(int numForumsFollowing READ getNumForumsFollowing WRITE setNumForumsFollowing NOTIFY numForumsFollowingChanged)
		int numForumsFollowing;
		static QString NUM_FORUMS_FOLLOWING_JSON_FIELDNAME;

		Q_PROPERTY(bool isAnonymous READ isAnonymous WRITE setAnonymous NOTIFY isAnonymousChanged)
		bool anonymous;
		static QString IS_ANONYMOUS_JSON_FIELDNAME;

		Q_PROPERTY(AvatarImage * avatar READ getAvatarPtr WRITE setAvatar NOTIFY avatarChanged)
		AvatarImage avatar;
		static QString AVATAR_JSON_FIELDNAME;

	public:
		int getUserID() const;
		void setUserID(int value);
		QString getUserIDStr() const;
		void setUserIDStr(QString value);

		QString getUsername() const;
		void setUsername(const QString & value);

		QString getName() const;
		void setName(const QString & value);

		QString getAbout() const;
		void setAbout(const QString & value);

		QUrl getUrl() const;
		void setUrl(const QUrl & value);

		QUrl getProfileURL() const;
		void setProfileURL(const QUrl & value);

		QUrl getSignedURL() const;
		void setSignedURL(const QUrl & value);

		QString getLocation() const;
		void setLocation(const QString & value);

		bool getIsPrivate() const;
		void setIsPrivate(bool value);

		int getNumLikesReceieved() const;
		void setNumLikesReceieved(int value);

		int getNumPosts() const;
		void setNumPosts(int value);

		QDateTime getJoinedAt() const;
		QString getJoinedAtStr() const;
		void setJoinedAt(const QDateTime & value);
		void setJoinedAt(const QString & value);

		int getNumFollowers() const;
		void setNumFollowers(int value);

		int getNumFollowing() const;
		void setNumFollowing(int value);

		int getNumForumsFollowing() const;
		void setNumForumsFollowing(int value);

		bool isAnonymous() const;
		void setAnonymous(bool value);

		AvatarImage getAvatar() const;
		AvatarImage * getAvatarPtr();
		void setAvatar(const AvatarImage & value);
		void setAvatar(const AvatarImage * value);

	signals:
		// NOTIFY signals
		void userIDChanged();
		void usernameChanged();
		void nameChanged();
		void aboutChanged();
		void urlChanged();
		void profileURLChanged();
		void signedURLChanged();
		void locationChanged();
		void isPrivateChanged();
		void numLikesReceievedChanged();
		void numPostsChanged();
		void joinedAtChanged();
		void numFollowersChanged();
		void numFollowingChanged();
		void numForumsFollowingChanged();
		void isAnonymousChanged();
		void avatarChanged();
};

#endif // DISQUSUSER_HPP
