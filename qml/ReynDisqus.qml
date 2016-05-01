import QtQuick 2.6
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
	}

	DisqusPanel {
		id: disqus
		anchors.fill: parent
		visible: false
	}

	SettingsControl {
		id: settingsControl
		onNeedAuth: reynDisqus.state = "auth"
		onAuthOK: reynDisqus.state = "regular"
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
		}
	]
}
