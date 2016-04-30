TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

# C++ sources
include(src/sources.pri)

# QML sources
include(qml/qml.pri)

RESOURCES += qml.qrc

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
	bin/Android/.gitkeep \
	bin/Android/debug/.gitkeep \
	bin/Android/release/.gitkeep \
	bin/Android/profile/.gitkeep \
	bin/Desktop/.gitkeep \
	bin/Desktop/debug/.gitkeep \
	bin/Desktop/release/.gitkeep \
	bin/Desktop/profile/.gitkeep \
	README.md
