import QtQuick 2.6
import QtQuick.Controls 1.4

TabView {
	id: disqusPanel
	anchors.fill: parent
	tabsVisible: true

	Tab {
		id: timelineTab
		title: qsTr("Timeline")

		Text {
			text: "TODO: Timeline tab."
		}
	}

	Tab {
		id: notificationsTab
		title: qsTr("Notifications")

		Text {
			text: "TODO: Notifications tab."
		}
	}

	Tab {
		id: forumsTab
		title: qsTr("Forums")

		Text {
			text: "TODO: Forums tab."
		}
	}

	Tab {
		id: myMessagesTab
		title: qsTr("My messages")

		Text {
			text: "TODO: My messages tab."
		}
	}

	Tab {
		id: accountTab
		title: qsTr("My account")

		Text {
			text: "TODO: My account tab."
		}
	}

	signal needRefreshToken;
	signal fatalError(string errMsg)
}
