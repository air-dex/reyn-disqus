import QtQuick 2.6
import QtQuick.Controls 1.4
import RDCore 1.0

TabView {
	id: disqusPanel

	readonly property var tabsList: [timelineTab, notificationsTab, forumsTab, myPostsTab, accountTab]

	TimelineTab {
		id: timelineTab
	}

	NotificationsTab {
		id: notificationsTab
	}

	ForumsTab {
		id: forumsTab
	}

	UserPostsTab {
		id: myPostsTab
	}

	// My account. "Me" is the authenticated user.
	UserTab {
		id: accountTab
		title: qsTr("My account")
	}

	SettingsControl { id: settingsControl }

	Component.onCompleted: {
		// Connecting tabs for refreshing tokens and fatal errors
		for (var i in disqusPanel.tabsList) {
			disqusPanel.connectTab(disqusPanel.tabsList[i]);
		}
	}

	function connectTab(tabID) {
		tabID.needRefresh.connect(disqusPanel.refreshTokens);
		tabID.fatalError.connect(disqusPanel.fatalError);
	}

	function allowToLoad() {
		//timelineTab.state = "can_load";
		// TODO: allow other tabs to load.

		// Load my account
		accountTab.userID = settingsControl.getMyID();
	}

	function refreshTokens() {
		// TODO: refreshTokens in DisqusPanel
	}

	signal fatalError(string errMsg)
}
