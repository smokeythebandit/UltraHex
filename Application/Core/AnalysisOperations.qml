import QtQuick
import UltraHex
import QtQuick.Dialogs

Item {
    property FileHandle fileHandle
    property ChecksumDialog checksumDialog: ChecksumDialog {
        onAccepted: {
            console.log(checksumDialog.selectedAlgorithms)
        }
    }
}
