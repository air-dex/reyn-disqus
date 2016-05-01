import QtQuick 2.6
import RDCore 1.0

Rectangle {
	id: splashScreen

	Constants { id: constants }

	Text {
		id: title
		anchors.centerIn: parent
		text: constants.appName
		font.bold: true
	}
}
