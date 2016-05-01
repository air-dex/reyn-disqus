import QtQuick 2.6
import QtWebView 1.1
import RDCore 1.0

Rectangle {
	id: authPanel

	Constants { id: constants }

	AuthControl {
		id: control
	}

	StartAuthForm {
		id: startAuthForm
		anchors.centerIn: parent
		onConnect: authPanel.state = "redeem_code";
	}

	WebView {
		id: redeemView
		visible: false
		anchors.fill: parent
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
			PropertyChanges {
				target: redeemView
				visible: false
			}
		},

		// State while redeeming a code
		State {
			name: "redeem_code"
			PropertyChanges {
				target: startAuthForm
				visible: false
			}
			PropertyChanges {
				target: redeemView
				visible: true
			}
			StateChangeScript {
				name: "redeem_begin"
				script: {
					var url = "";

					if (startAuthForm.useOther) {
						url = control.computeAuthorizeURL(
							startAuthForm.publicKey,
							startAuthForm.getScopes(),
							startAuthForm.domain
						);
					}
					else {
						url = control.computeDefaultAuthorizeURL();
					}

					redeemView.url = url;
				}
			}
		}
	]
}
