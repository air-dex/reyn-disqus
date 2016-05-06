import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import RDCore 1.0

Item {
	id: userView

	property int userID
	property alias user: control.disqusUser

	readonly property var leftSide: avatar.left
	readonly property var rightSide: name.right

	Constants { id: constants }

	// Backend
	UserControl {
		id: control

		onLoadUsersDetailsFailed: {
			infoDialog.text = qsTr("Loading user's details failed.");
			infoDialog.informativeText = infos;
			infoDialog.open();
		}
		onFatalError: userView.fatalError(error);
		onNeedRefresh: userView.needRefresh();
	}

	onUserIDChanged: control.loadUserDetails(userView.userID);

	// Widgets for the view.

	//User's profile picture
	Avatar {
		id: avatar
		disqusAvatar: user.avatar
		side: name.height + constants.margin + username.height

		anchors {
			top: parent.top
			topMargin: constants.margin
			left: parent.left
			leftMargin: constants.margin
		}
	}

	// User name
	Text {
		id: name
		text: user.name
		elide: Text.ElideRight

		anchors {
			top: avatar.top
			left: avatar.left
			leftMargin: constants.margin
			right: parent.right
			rightMargin: constants.margin
		}

		font {
			bold: true
			pointSize: constants.lFontSize
		}
	}

	// User username
	Text {
		id: username
		text: "@%1".arg(user.username)
		color: constants.gray
		elide: Text.ElideRight

		font {
			pointSize: constants.sFontSize
		}

		anchors {
			top: name.bottom
			topMargin: constants.margin
			left: name.left
			right: name.right
		}
	}

	// About the user
	Text {
		id: description
		text: user.about
		textFormat: Text.RichText
		wrapMode: Text.Wrap

		font {
			pointSize: constants.mFontSize
		}

		anchors {
			top: avatar.bottom
			topMargin: constants.margin
			left: avatar.left
			right: name.right
		}
	}

	// User location
	SquareImage {
		id: mapMarker
		source: "qrc:/res/mapmarker.svg"
		side: location.height

		anchors {
			top: description.bottom
			topMargin: constants.margin
			left: avatar.left
		}
	}

	Text {
		id: location
		text: user.location
		wrapMode: Text.Wrap

		font {
			pointSize: constants.mFontSize
		}

		anchors {
			top: mapMarker.top
			left: mapMarker.right
			leftMargin: constants.margin
			right: name.right
		}
	}

	// When did the user join Disqus?
	SquareImage {
		id: clock
		source: "qrc:/res/clock.svg"
		side: joinedAt.height

		anchors {
			top: mapMarker.bottom
			topMargin: constants.margin
			left: avatar.left
		}
	}

	Text {
		id: joinedAt
		text: qsTr("On Disqus since %1.").arg(user.joinedAt.toLocaleString())
		wrapMode: Text.Wrap

		font {
			pointSize: constants.mFontSize
		}

		anchors {
			top: clock.top
			left: clock.left
			leftMargin: constants.margin
			right: name.right
		}
	}

	TabView {
		id: detailsView

		anchors {
			top: joinedAt.bottom
			topMargin: constants.margin
			left: avatar.left
			right: name.right
			bottom: parent.bottom
			bottomMargin: constants.margin
		}
	}

	MessageDialog {
		id: infoDialog
		modality: Qt.ApplicationModal
		icon: StandardIcon.Information
		visible:false
	}

	// Signals
	signal needRefresh
	signal fatalError(string errMsg)
}
