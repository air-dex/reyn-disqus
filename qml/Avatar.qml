import QtQuick 2.6
import RDCore 1.0

SquareImage {
	id: avatar
	width: height
	source: imageInfos.permalink

	// Disqus image
	property alias disqusAvatar: imageInfos
	AvatarImage { id: imageInfos }
}
