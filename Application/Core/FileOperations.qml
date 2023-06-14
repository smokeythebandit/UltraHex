import QtQuick
import UltraHex
import QtQuick.Dialogs

QtObject {
    property FileDialog openFileDialog: FileDialog {
        title: "Open"
        onAccepted: {
            FileManager.open(openFileDialog.currentFile)
        }
    }
}
