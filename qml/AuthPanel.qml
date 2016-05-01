import QtQuick 2.6
import RDCore 1.0

Rectangle {
	id: authPanel

	Constants { id: constants }

	StartAuthForm {
		id: startAuthForm
		anchors.centerIn: parent
		onConnect: authPanel.state = "redeem_code";
	}

	function startAuth() {
		authPanel.state = "";
	}

	states: [
		// Default state : init
		State {
			name: ""
			PropertyChanges {
				target: startAuthForm
				visible: true
			}
		},

		// State while redeeming a code
		State {
			name: "redeem_code"
			PropertyChanges {
				target: startAuthForm
				visible: false
			}
		}
	]
}
