import QtQuick 2.6

Image {
	id: avatar

	property int side
	width: side
	height: side

	fillMode: Image.PreserveAspectFit
}
