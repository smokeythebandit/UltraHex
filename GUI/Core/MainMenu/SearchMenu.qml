import QtQuick
import UltraHex
import QtQuick.Controls

Menu {
    title: qsTr("&Search")
    Action { text: qsTr("&Find...") ; shortcut: "Ctrl+F"; onTriggered: searchOperations.findDialog.open()}
    Action { text: qsTr("&Replace...") ; shortcut: "Ctrl+R"}
    Action { text: qsTr("&Go to") ; shortcut: "Ctrl+F4" }

    SearchOperations {
        id: searchOperations
    }
}
