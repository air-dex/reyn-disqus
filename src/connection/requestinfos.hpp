#ifndef REQUESTINFOS_HPP
#define REQUESTINFOS_HPP

#include <QObject>
#include "genericrequester.hpp"

/// Inspired by libRT: https://launchpad.net/librt
struct RequestInfos {
	QObject * asker;
	GenericRequester * request;
};

#endif // REQUESTINFOS_HPP
