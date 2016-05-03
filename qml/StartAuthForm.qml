import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import RDCore 1.0

ColumnLayout {
	id: startAuthForm
	spacing: constants.margin

	property alias useOther: useOtherApp.checked
	property alias publicKey: publicKeyField.text
	property alias secretKey: secretKeyField.text
	property alias domain: domainField.text
	property alias errorMessage: errorAuth.text

	function getScopes() {
		var scopes = [];
		var cbs = [readScope, writeScope, adminScope, emailScope];

		for (var i in cbs) {
			var cb = cbs[i];
			if (cb.checked) {
				scopes.push(scopesUtil.getScopeStr(cb.scope));
			}
		}

		return scopes.join(",");
	}

	signal connect

	Constants { id: constants }

	DisqusScopes { id: scopesUtil }

	Text {
		id: errorAuth

		// FIXME: Text wrap when it is too long
		text: ""
		color: constants.errorColor
		font.bold: true
		wrapMode: Text.Wrap
		visible: errorAuth.text != ""
	}

	Text {
		id: connectLabel
		text: qsTr("Connect to Disqus")
	}

	CheckBox {
		id: useOtherApp
		text: qsTr("Use a custom Disqus app.")
	}

	GridLayout {
		id: otherAppCreds
		rows: 4
		columns: 2
		enabled: useOther
		width: startAuthForm.width
		visible: startAuthForm.useOther

		property int labelWidth: Math.max(publicKeyLabel.width, secretKeyLabel.width, domainLabel.width)

		anchors {
			top: useOtherApp.bottom
			bottom: parent.bottom
		}

		// Public key
		Label {
			id: publicKeyLabel
			text: qsTr("Public key")
		}

		TextField {
			id: publicKeyField
			placeholderText: qsTr("Disqus app's public key")
			anchors {
				left: scopesField.left
				right: scopesField.right
			}
		}

		// Secret key
		Label {
			id: secretKeyLabel
			text: qsTr("Secret key")
		}

		TextField {
			id: secretKeyField
			placeholderText: qsTr("Disqus app's secret key")
			anchors {
				left: scopesField.left
				right: scopesField.right
			}
		}

		// Trusted domain
		Label {
			id: domainLabel
			text: qsTr("Domain")
		}

		TextField {
			id: domainField
			placeholderText: qsTr("An app's trusted domain")
			anchors {
				left: scopesField.left
				right: scopesField.right
			}
		}

		// Scopes
		Label {
			id: scopesLabel
			text: qsTr("Scopes")
		}

		RowLayout {
			id: scopesField
			spacing: constants.margin

			CheckBox {
				id: readScope
				text: qsTr("Read")
				readonly property int scope: DisqusScopes.READ
			}

			CheckBox {
				id: writeScope
				text: qsTr("Write")
				readonly property int scope: DisqusScopes.WRITE
			}

			CheckBox {
				id: adminScope
				text: qsTr("Admin")
				readonly property int scope: DisqusScopes.ADMIN
			}

			CheckBox {
				id: emailScope
				text: qsTr("Email")
				readonly property int scope: DisqusScopes.EMAIL
			}
		}
	}

	Button {
		id: connectButton
		text: qsTr("Connect")
		onClicked: startAuthForm.connect();
	}
}
