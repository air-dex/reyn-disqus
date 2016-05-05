import QtQuick 2.6
import QtQuick.Controls 1.4
import RDCore 1.0

Item {
	id: userView

	// User ID
	property int userID

	onUserIDChanged: {
		console.log("TODO: load user with userID")
	}

	Text {
		text: "ta mère !"
	}

	// property DisqusUser, alias the control's one.

	// UserControl

	// Widgets for the view.

	signal needRefresh
	signal fatalError(string errMsg)
}
