import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import RDCore 1.0

Item {
	id: userView

	property int userID
	property alias user: control.disqusUser
	readonly property int bigMargin: 2 * constants.margin

	readonly property var leftSide: avatar.left
	readonly property var rightSide: reloadButton.right

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
	SquareImage {
		id: avatar
		source: user.avatar.permalink
		side: name.height + 2*bigMargin + username.height + website.height

		anchors {
			top: parent.top
			topMargin: constants.margin
			left: parent.left
			leftMargin: constants.margin
			bottom: website.bottom
		}
	}

	// User name
	Text {
		id: name
		text: user.name
		elide: Text.ElideRight

		anchors {
			top: avatar.top
			left: avatar.right
			leftMargin: bigMargin
			right: reloadButton.left
			rightMargin: bigMargin
		}

		font {
			bold: true
			pointSize: constants.xlFontSize
		}
	}

	// Reload button
	Button {
		id: reloadButton
		iconSource: "qrc:/res/reload.svg"
		width: name.height

		anchors {
			top: name.top
			right: parent.right
			rightMargin: constants.margin
			bottom: name.bottom
		}

		onClicked: control.loadUserDetails(userView.userID);
	}

	// User username
	Text {
		id: username
		text: "@%1".arg(user.username)
		color: constants.gray
		elide: Text.ElideRight

		font {
			pointSize: constants.mFontSize
		}

		anchors {
			top: name.bottom
			topMargin: bigMargin
			left: name.left
			right: rightSide
		}
	}

	// User Website
	SquareImage {
		id: websiteIcon
		visible: website.visible
		side: website.height
		source: "qrc:/res/desktopbrowser.svg"

		anchors {
			top: username.bottom
			topMargin: bigMargin
			left: name.left
		}
	}

	Text {
		id: website
		text: '<a href="%1">%1</a>'.arg(user.url)
		textFormat: Text.RichText
		elide: Text.ElideRight

		font {
			pointSize: constants.mFontSize
		}

		anchors {
			top: websiteIcon.top
			left: websiteIcon.right
			leftMargin: bigMargin
			right: rightSide
		}

		onLinkActivated: Qt.openUrlExternally(link);
	}

	// About the user
	Text {
		id: description
		text: user.about
		textFormat: Text.RichText
		wrapMode: Text.Wrap
		visible: user.about !== ""

		font {
			pointSize: constants.mFontSize
		}

		anchors {
			top: website.bottom
			topMargin: bigMargin
			left: leftSide
			right: rightSide
		}
	}

	// User location
	SquareImage {
		id: mapMarker
		source: "qrc:/res/mapmarker.svg"
		side: location.height
		visible: location.visible

		anchors {
			top: description.bottom
			topMargin: bigMargin
			left: leftSide
		}
	}

	Label {
		id: location
		text: user.location
		wrapMode: Text.Wrap
		visible: user.location !== ""

		font {
			pointSize: constants.mFontSize
		}

		anchors {
			top: mapMarker.top
			left: mapMarker.right
			leftMargin: bigMargin
			right: rightSide
		}
	}

	// When did the user join Disqus?
	SquareImage {
		id: clock
		source: "qrc:/res/clock.svg"
		side: joinedAt.height

		anchors {
			top: mapMarker.bottom
			topMargin: bigMargin
			left: leftSide
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
			left: clock.right
			leftMargin: bigMargin
			right: rightSide
		}
	}

	Button {
		id: viewOnDisqus
		text: qsTr("View on Disqus")

		anchors {
			top: joinedAt.bottom
			topMargin: bigMargin
			left: leftSide
		}

		onClicked: Qt.openUrlExternally(user.profileURL)
	}

	TabView {
		id: detailsView

		anchors {
			top: viewOnDisqus.bottom
			topMargin: constants.margin
			left: leftSide
			right: rightSide
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
