#include <QApplication>
#include <QQmlApplicationEngine>

#include "global.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	ReynDisqus::declareQML();

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

	int res = app.exec();

	ReynDisqus::afterReynDisqus();

	return res;
}
