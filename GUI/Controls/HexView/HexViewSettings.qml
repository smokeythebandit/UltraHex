import QtQuick
import QtQml

QtObject {
    property font hexFont: Qt.font( {
        family: "Courier New",
        pointSize: 10
    })
    property bool fillWidth: false
    property int bytesPerRow: 8
}
