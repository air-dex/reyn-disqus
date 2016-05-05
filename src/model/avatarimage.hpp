#ifndef AVATARIMAGE_HPP
#define AVATARIMAGE_HPP

#include <QObject>
#include <QJsonObject>
#include <QUrl>

class AvatarImage : public QObject
{
	Q_OBJECT

	public:
		AvatarImage();
		AvatarImage(QJsonObject jsonAvatar);
		AvatarImage(const AvatarImage & avatar);
		const AvatarImage & operator=(const AvatarImage & avatar);

		static void declareQML();
		QJsonObject toJsonObject() const;

		bool getIsCustom() const;
		void setIsCustom(bool value);

		QUrl getPermalink() const;
		void setPermalink(const QUrl & value);

	signals:
		void isCustomChanged();
		void permalinkChanged();

	protected:
		void copy(const AvatarImage & avatar);

		// Has the user customed his profile picture?
		Q_PROPERTY(bool isCustom READ getIsCustom WRITE setIsCustom NOTIFY isCustomChanged)
		bool isCustom;
		static QString IS_CUSTOM_JSON_FIELDNAME;

		// Image permalink
		Q_PROPERTY(QUrl permalink READ getPermalink WRITE setPermalink NOTIFY permalinkChanged)
		QUrl permalink;
		static QString PERMALINK_JSON_FIELDNAME;
};

#endif // AVATARIMAGE_HPP
