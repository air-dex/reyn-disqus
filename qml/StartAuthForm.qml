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

	signal connect

	Constants { id: constants }

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
		rows: 3
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
			width: 3 * otherAppCreds.labelWidth
			placeholderText: qsTr("Disqus app's public key")
		}

		// Secret key
		Label {
			id: secretKeyLabel
			width: 3 * otherAppCreds.labelWidth
			text: qsTr("Secret key")
		}

		TextField {
			id: secretKeyField
			placeholderText: qsTr("Disqus app's secret key")
		}

		// Trusted domain
		Label {
			id: domainLabel
			text: qsTr("Domain")
		}

		TextField {
			id: domainField
			width: 3 * otherAppCreds.labelWidth
			placeholderText: qsTr("An app's trusted domain")
		}


	}

	Button {
		id: connectButton
		text: qsTr("Connect")
		onClicked: startAuthForm.connect();
	}
}
