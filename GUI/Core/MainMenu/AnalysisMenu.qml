import QtQuick
import UltraHex
import QtQuick.Controls

Menu {
    title: qsTr("&Analysis")
    Action { text: qsTr("&Checksums.."); onTriggered: analysisOperations.checksumDialog.open() }

    AnalysisOperations {
        id: analysisOperations
    }
}
