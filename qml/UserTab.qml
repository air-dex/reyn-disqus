import QtQuick 2.6
import QtQuick.Controls 1.4

DisqusTab {
	id: userTab
	title: qsTr("User")

	property int userID

	UserView {
		id: uview
		userID: userTab.userID

		Component.onCompleted: {
			// Connections for refresh tokens and fatal errors
			uview.needRefresh.connect(userTab.needRefresh);
			uview.fatalError.connect(userTab.fatalError);
		}
	}
}
