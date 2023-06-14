import UltraHex
import QtQuick 2.15

TabViewItem {
    id: hexViewTab
    property FileHandle fileHandle
    title: fileHandle.fileName
    content: HexView {
        fileHandle: hexViewTab.fileHandle
    }
}
