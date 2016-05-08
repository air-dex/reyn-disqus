import QtQuick 2.6
import QtQuick.Controls 1.4
import RDCore 1.0

DisqusTab {
	id: userTab
	title: qsTr("User")

	property DisqusUser user
	property int userID

	UserView {
		id: uview
		user: userTab.user
		userID: userTab.userID

		Component.onCompleted: {
			// Connections for refresh tokens and fatal errors
			uview.needRefresh.connect(userTab.needRefresh);
			uview.fatalError.connect(userTab.fatalError);
		}
	}
}
