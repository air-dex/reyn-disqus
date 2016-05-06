import QtQuick 2.6
import RDCore 1.0

SquareImage {
	id: avatar
	width: height
	source: disqusAvatar.permalink

	// Disqus image
	property AvatarImage disqusAvatar
}
