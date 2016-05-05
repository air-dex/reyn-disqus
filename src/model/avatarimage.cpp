#include "avatarimage.hpp"

#include <QtQml>
#include <QJsonObject>
#include "../constants.hpp"
#include "../utils.hpp"

AvatarImage::AvatarImage() : QObject(), isCustom(false), permalink("")
{}

AvatarImage::AvatarImage(QJsonObject jsonAvatar) :
	QObject(),
	isCustom(jsonAvatar[AvatarImage::IS_CUSTOM_JSON_FIELDNAME].toBool()),
	permalink(jsonAvatar[AvatarImage::PERMALINK_JSON_FIELDNAME].toString())
{}

AvatarImage::AvatarImage(const AvatarImage & avatar) : QObject()
{
	copy(avatar);
}

const AvatarImage &AvatarImage::operator=(const AvatarImage & avatar)
{
	copy(avatar);
	return *this;
}

void AvatarImage::copy(const AvatarImage & avatar)
{
	this->isCustom = avatar.isCustom;
	this->permalink = avatar.permalink;
}

QJsonObject AvatarImage::toJsonObject() const
{
	QJsonObject res;

	res.insert(AvatarImage::IS_CUSTOM_JSON_FIELDNAME, isCustom);
	res.insert(AvatarImage::PERMALINK_JSON_FIELDNAME, permalink.toString());

	return res;
}

DECLARE_QML(AvatarImage, "AvatarImage")

QString AvatarImage::IS_CUSTOM_JSON_FIELDNAME = "isCustom";
bool AvatarImage::getIsCustom() const
{
	return isCustom;
}

void AvatarImage::setIsCustom(bool value)
{
	isCustom = value;
	emit isCustomChanged();
}

QString AvatarImage::PERMALINK_JSON_FIELDNAME = "permalink";
QUrl AvatarImage::getPermalink() const
{
	return permalink;
}

void AvatarImage::setPermalink(const QUrl & value)
{
	permalink = value;
	emit permalinkChanged();
}
