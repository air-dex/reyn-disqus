import QtQuick 2.6
import QtQuick.Controls 1.4

// Base for regular tabs
Tab {
	id: disqusTab
	active: true

	signal needRefresh
	signal fatalError(string errMsg)
}
