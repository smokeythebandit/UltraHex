import QtQuick
import UltraHex
import QtQuick.Controls.Material

ApplicationWindow  {
    width: 640
    height: 480
    visible: true
    Material.accent: Material.Indigo
    Material.primary: Material.Indigo
    Material.theme: Material.System

    menuBar: MainMenu {

    }

    header: MainToolBar {
        tabView: mainTabView
    }

    TabView {
        id: mainTabView
        anchors.fill: parent
    }

    Component {
        id: hexViewTab
        HexViewTab {

        }
    }

    Connections {
        target: FileManager
        function onNewFileOpened(handle) {
            var newItem = hexViewTab.createObject(mainTabView, {fileHandle: handle})
            mainTabView.addItem(newItem)
        }
    }
}
