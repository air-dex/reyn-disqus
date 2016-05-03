#ifndef HTTPMAPS_HPP
#define HTTPMAPS_HPP

#include <QByteArray>
#include <QMap>
#include <QString>

/// @typedef QMap<QByteArray, QByteArray> ArgsMap
/// @brief Convinience to designate QMaps that contains GET and POST arguments
typedef QMap<QString, QString> ArgsMap;

/// @typedef QMap<QString, QString> HeadersMap
/// @brief Convinience to designate QMaps that contains HTTP headers
typedef QMap<QByteArray, QByteArray> HeadersMap;

#endif // HTTPMAPS_HPP
