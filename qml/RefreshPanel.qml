import QtQuick 2.6
import QtQuick.Dialogs 1.2
import RDCore 1.0

// FIXME: "nested" stage changes.
Item {
	id: refreshPanel
	visible: true

	function startRefresh() {
		refreshPanel.state = "refresh"
	}

	MessageDialog {
		id: refreshWindow
		visible: false
		modality: Qt.ApplicationModal
		title: qsTr("OAuth token has expired")
		text: qsTr("Refreshing OAuth token...")
		standardButtons: StandardButton.NoButton
		onVisibleChanged: {
			if (!visible && refreshPanel.state == "refresh")  {
				brutalAbort();
			}
		}
	}

	AuthControl {
		id: control
		onRefreshEnded: {
			refreshPanel.state = "";
			refreshPanel.refreshEnded();
		}
		onTryAgain: {
			errMsg = error;
			refreshPanel.state = "try_again";
		}
		onFatalError: {
			errMsg = error;
			refreshPanel.state = "abort";
		}

		property string errMsg
	}

	MessageDialog {
		id: tryAgainWindow
		visible: false
		modality: Qt.ApplicationModal
		title: qsTr("Refresh again?")
		text: qsTr("OAuth token cannot be refreshed. Try again?")
		standardButtons: StandardButton.Yes | StandardButton.No

		onYes: refreshPanel.state = "refresh";

		onNo: brutalAbort();

		onVisibleChanged: {
			if (!visible && refreshPanel.state == "try_again")  {
				tryAgainWindow.no();
			}
		}
	}

	function brutalAbort() {
		control.errMsg = qsTr("It is impossible to use Reyn Disqus with outdated tokens. Good bye!");
		refreshPanel.state = "abort"
	}

	function cleanAll() {
		tryAgainWindow.detailedText = "";
		refreshWindow.close();
		tryAgainWindow.close();
	}

	signal fatalError(string error)
	signal refreshEnded

	states: [
		State {
			name: ""
			StateChangeScript {
				name: "norefresh"
				script: {
					cleanAll();
				}
			}
		},
		State {
			name: "refresh"
			StateChangeScript {
				name: "refresh"
				script: {
					tryAgainWindow.close();
					refreshWindow.open();
					control.refreshTokens();
				}
			}
		},
		State {
			name: "try_again"
			StateChangeScript {
				name: "try_again"
				script: {
					refreshWindow.close();
					tryAgainWindow.detailedText = control.errMsg;
					tryAgainWindow.open();
				}
			}
		},
		State {
			name: "abort"
			StateChangeScript {
				name: "abort"
				script: {
					cleanAll();
					refreshPanel.fatalError(control.errMsg);
				}
			}
		}
	]
}
