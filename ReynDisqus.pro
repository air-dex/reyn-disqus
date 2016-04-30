TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

# C++ sources
include(src/sources.pri)

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
	bin/Android/debug/.gitkeep \
	bin/Android/release/.gitkeep \
	bin/Android/profile/.gitkeep \
	bin/Desktop/debug/.gitkeep \
	bin/Desktop/release/.gitkeep \
	bin/Desktop/profile/.gitkeep \
	README.md
