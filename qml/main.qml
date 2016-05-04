import QtQuick 2.6
import QtQuick.Controls 1.5

ApplicationWindow {
	visible: true
	width: 800
	height: 640
	title: qsTr("Reyn Disqus")

	menuBar: MenuBar {
		Menu {
			title: qsTr("File")
			MenuItem {
				text: qsTr("&Open")
				onTriggered: console.log("Open action triggered");
			}
			MenuItem {
				text: qsTr("Exit")
				onTriggered: Qt.quit();
			}
		}
	}

	ReynDisqus {
		id: reynDisqus
		anchors.fill: parent
		visible: true
	}
}
