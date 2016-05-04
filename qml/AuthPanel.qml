import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtWebView 1.1
import RDCore 1.0

Rectangle {
	id: authPanel

	// Emitted when an OAuth code cannot be found
	signal noOAuthCode(string errMsg)

	// Emitted when a fatal error occurs
	signal fatalError(string errMsg)

	// Emitted when auth ends
	signal authEnded

	AuthControl {
		id: control
		onAuthEnded: authPanel.authEnded();
		onFatalError: authPanel.fatalError(error);
	}

	StartAuthForm {
		id: startAuthForm
		anchors.centerIn: parent
		visible: true
		onConnect: {
			// Start OAuth process.
			if (startAuthForm.useOther) {
				control.disqusApp = startAuthForm.disqusApp;
			}
			else {
				control.setDefaultAuthData();
			}

			authPanel.state = "redeem_code";
		}
	}

	WebView {
		id: redeemView
		visible: false
		anchors.fill: parent

		property url authURL

		// Better if possible
		Component.onCompleted: clearWebViewCookies()
		onLoadingChanged: {
			// "hidden" arg : loadRequest

			switch (loadRequest.status) {
				case WebView.LoadFailedStatus:
				case WebView.LoadSucceededStatus:
					if (loadRequest.url == redeemView.authURL) {
						if (loadRequest.status == WebView.LoadSucceededStatus) {
							mostAnnoyingThingEver.visible = false;
							redeemView.visible = true;
						}
						else {
							// loadRequest.status == WebView.LoadFailedStatus
							noOAuthCode(qsTr("The page to authorize the app has failed failed loading. The domain should not be convenient. Try again."));
						}

						break;
					}

					// track URL
					control.oauthCode = control.trackOAuthCode(loadRequest.url);

					if (control.oauthCode == "") {
						// No code. Tell and restart auth
						noOAuthCode(qsTr("A code necessary to the authentication process cannot be retrieved. The domain might not be convenient. Try again."))
						break;
					}

					authPanel.state = "access_tokens";
					break;

				case WebView.LoadStoppedStatus:
					fatalError(qsTr("A page loading was unexpectedly stopped. Abort."));
					break;

				// Nothing to do here
				case WebView.LoadStartedStatus:
				default:
					break;
			}
		}
	}

	BusyIndicator {
		id: mostAnnoyingThingEver
		width: parent.width / 2
		height: parent.height / 2
		anchors.fill: parent
		visible: false
		running: visible
	}

	onNoOAuthCode: {
		// errMsg: error message
		// Write the message in the start auth panel and restart auth.
		startAuthForm.errorMessage = errMsg;
		authPanel.state = "";
	}

	function startAuth() {
		authPanel.state = "";
	}

	function clearWebViewCookies() {
		// source: http://stackoverflow.com/questions/179355/clearing-all-cookies-with-javascript
		// Run javascript to clear cookies as defined in the SO question.
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
			PropertyChanges {
				target: mostAnnoyingThingEver
				visible: false
			}
			StateChangeScript {
				name: "init_auth"
				script: {
					control.resetAuthData();
					clearWebViewCookies();
				}
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
				visible: false
			}
			PropertyChanges {
				target: mostAnnoyingThingEver
				visible: true
			}
			StateChangeScript {
				name: "redeem_begin"
				script: {
					var url = control.computeAuthorizeURL();
					redeemView.authURL = url;
					redeemView.url = url;
				}
			}
		},
		State {
			name: "access_tokens"
			PropertyChanges {
				target: startAuthForm
				visible: false
			}
			PropertyChanges {
				target: redeemView
				visible: false
			}
			PropertyChanges {
				target: mostAnnoyingThingEver
				visible: true
			}
			StateChangeScript {
				name: "access_tokens"
				script: {
					control.accessTokens();
				}
			}
		}
	]
}
