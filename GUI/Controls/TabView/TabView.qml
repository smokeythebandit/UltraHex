import QtQuick
import UltraHex
import QtQuick.Layouts
import QtQuick.Controls

Item {
    readonly property Item currentItem: stackview.currentItem

    Shortcut {
        sequence: "Ctrl+F4"
        onActivated: console.log('dsdsadsa')
        context: Qt.WindowShortcut
    }

    Component {
        id: newTabButton
        TabButton {
            property TabViewItem tabViewItem
            text: tabViewItem.title
            ToolButton {
                flat: true
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                icon.source: "qrc:/Icons/GUI/Icons/Close.svg"
                onClicked: {
                    removeItem(tabViewItem)
                }
            }
        }
    }

    function addItem(item : TabViewItem) {
        newTabButton.incubateObject(bar, {tabViewItem: item})
        stackview.addItem(item.content)
    }

    function removeItem(item : TabViewItem) {
        for(var i = 0; i < bar.count; i++) {
            if(bar.itemAt(i).tabViewItem === item) {
                bar.removeItem(bar.itemAt(i))
            }
        }
        stackview.removeItem(item.content)
        stackview.currentIndex = bar.currentIndex
    }

    TabBar {
        id: bar
        width: parent.width
        currentIndex: stackview.currentIndex
    }

    SwipeView {
        id: stackview
        interactive: false
        currentIndex: bar.currentIndex
        anchors.top: bar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}
