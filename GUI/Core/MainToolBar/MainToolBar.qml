import QtQuick
import UltraHex
import QtQuick.Layouts
import QtQuick.Controls

ToolBar {
    property TabView tabView

    Connections {
        target: tabView
        function onCurrentItemChanged()  {
            if(tabView.currentItem instanceof HexView) {
                bytesPerRowInput.editText = tabView.currentItem.settings.bytesPerRow
            }
        }
    }

    RowLayout {
        spacing: 1
        anchors.fill: parent
        ToolButton {
            hoverEnabled: true
            icon.source: "qrc:/Icons/GUI/Icons/Draft.svg"
            ToolTip.visible: hovered
            ToolTip.text: qsTr("New")
        }
        ToolButton {
            hoverEnabled: true
            icon.source: "qrc:/Icons/GUI/Icons/Folder.svg"
            ToolTip.visible: hovered
            ToolTip.text: qsTr("Open")
            onClicked: fileOperations.openFileDialog.open()
        }
        ToolButton {
            hoverEnabled: true
            icon.source: "qrc:/Icons/GUI/Icons/Save.svg"
            ToolTip.visible: hovered
            ToolTip.text: qsTr("Save")
        }
        ToolSeparator {}
        ToolButton {
            hoverEnabled: true
            icon.source: "qrc:/Icons/GUI/Icons/FillWidth.svg"
            ToolTip.visible: hovered
            ToolTip.text: qsTr("Fill width")
        }
        ComboBox {
            id: bytesPerRowInput
            editable: true
            hoverEnabled: true
            enabled: tabView.currentItem instanceof HexView
            model: [8, 16, 24, 32, 48, 64]
            validator: IntValidator {
                bottom: 1
            }
            ToolTip.visible: hovered
            ToolTip.text: qsTr("Bytes per row")
            onCurrentValueChanged: {
                if(tabView.currentItem instanceof HexView) {
                    tabView.currentItem.settings.bytesPerRow = bytesPerRowInput.currentValue
                }
            }
        }
        ToolSeparator {}
        TextField  {
            id: searchInput
            placeholderText: qsTr("Search...")
            Layout.rowSpan: 3
            Layout.preferredWidth: 200
        }

        Item {
            Layout.fillWidth: true
        }
    }
    FileOperations {
        id: fileOperations
    }
}
