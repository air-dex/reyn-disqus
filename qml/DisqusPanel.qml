import QtQuick 2.6
import QtQuick.Controls 1.4

Rectangle {
	id: disqusPanel

	signal needRefreshToken;
	signal fatalError(string errMsg)

	TabView {
		//
	}
}
