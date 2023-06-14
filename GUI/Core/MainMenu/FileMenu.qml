import QtQuick
import UltraHex
import QtQuick.Controls


Menu {
    title: qsTr("&File")
    Action { text: qsTr("&New...") ; shortcut: "Ctrl+N"; }
    Action { text: qsTr("&Open...") ; shortcut: "Ctrl+O"; onTriggered: fileOperations.openFileDialog.open()}
    Action { text: qsTr("&Close") ; shortcut: "Ctrl+F4" }
    Action { text: qsTr("&Save") ; shortcut: "Ctrl+S"}
    Action { text: qsTr("Save &As...") }
    MenuSeparator { }
    Action { text: qsTr("&Quit"); shortcut: "Ctrl+Q"; onTriggered: Qt.exit(0) }

    FileOperations {
        id: fileOperations
    }
}
