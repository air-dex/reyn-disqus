import QtQuick 2.6
import QtQuick.Dialogs 1.2
import RDCore 1.0

Item {
	id: reynDisqus

	SplashScreen {
		id: splash
		anchors.fill: parent
		visible: true
	}

	AuthPanel {
		id: authScreen
		anchors.fill: parent
		visible: false
		onAuthEnded: reynDisqus.state = "regular"
		onFatalError: {
			abortDialog.setAbortMessage(errMsg);
			reynDisqus.state = "abort";
		}
	}

	DisqusPanel {
		id: disqus
		anchors.fill: parent
		visible: false
		onFatalError: {
			abortDialog.setAbortMessage(errMsg);
			reynDisqus.state = "abort";
		}
	}

	RefreshPanel {
		id: refreshWindow
		onRefreshEnded: reynDisqus.state = "regular"
		onFatalError: {
			abortDialog.setAbortMessage(errMsg);
			reynDisqus.state = "abort";
		}
	}

	SettingsControl {
		id: settingsControl
		onNeedAuth: reynDisqus.state = "auth"
		onAuthOK: reynDisqus.state = "regular"
		onNeedRefresh: reynDisqus.state = "refresh"
	}

	MessageDialog {
		id: abortDialog
		visible: false
		modality: Qt.ApplicationModal
		title: qsTr("Fatal error")
		text: qsTr("Reyn Disqus has to quit. Bye!")
		standardButtons: StandardButton.Close
		onRejected: Qt.quit();

		function setAbortMessage(msg) {
			abortDialog.detailedText = msg;
		}
	}

	Component.onCompleted:  {
		settingsControl.controlSettings()
	}

	states: [
		// Default state : while init

		// Auth state : when the apps needs to auth the user
		State {
			name: "auth"

			PropertyChanges {
				target: splash
				visible: false
			}

			PropertyChanges {
				target: authScreen
				visible: true
			}

			PropertyChanges {
				target: disqus
				visible: false
			}

			StateChangeScript {
				name: "authStart"
				script: {
					authScreen.startAuth();
				}
			}
		},

		// Refreshing access tokens
		State {
			name: "refresh"

			PropertyChanges {
				target: splash
				visible: false
			}

			PropertyChanges {
				target: authScreen
				visible: false
			}

			PropertyChanges {
				target: disqus
				visible: false
			}

			StateChangeScript {
				name: "refreshStart"
				script: {
					refreshWindow.startRefresh();
				}
			}
		},

		// State while using Disqus
		State {
			name: "regular"

			PropertyChanges {
				target: splash
				visible: false
			}

			PropertyChanges {
				target: authScreen
				visible: false
			}

			PropertyChanges {
				target: disqus
				visible: true
			}

			StateChangeScript {
				name: "regular"
				script: {
					disqus.allowToLoad();
				}
			}
		},

		// Abort
		State {
			name: "abort"
			StateChangeScript {
				name: "abort"
				script: {
					abortDialog.open();
				}
			}
		}
	]
}
