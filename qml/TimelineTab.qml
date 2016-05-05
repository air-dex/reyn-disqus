import QtQuick 2.6
import QtQuick.Controls 1.4

DisqusTab {
	id: timelineTab
	title: qsTr("Threads timeline")

	property string s: henri.text

	Text {
		id: henri
		text: "TODO: Timeline tab."
	}

	states: [
		State {
			name: "can_load"
			StateChangeScript {
				name: "can_load"
				script: {
					console.log("TODO: load threads")
					// TODO: Load threads
				}
			}
		},
		State {
			name: "regular"
		}
	]
}
