import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Material
import UltraHex

Dialog   {
    id: dialog
    width: 550
    height: 400
    parent: Overlay.overlay
    anchors.centerIn: parent
    property list<string> selectedAlgorithms

    onAboutToShow: {
        for (var i = 0; i < grid.contentItem.children.length; i++) {
            grid.contentItem.children[i].checkState = Qt.Unchecked
        }
    }

    ColumnLayout {
        anchors.fill: parent
        Label {
            text: qsTr("Available algorithms")
        }
        GridView {
            id: grid
            clip: true
            model: ChecksumCalculatorFactory.availableAlgorithms
            Layout.fillWidth: true
            Layout.fillHeight: true
            cellHeight: 40
            cellWidth: grid.width/3
            delegate: CheckBox {
                id: checkbox
                text: modelData
                onCheckStateChanged: {
                    if (checked) {
                        selectedAlgorithms.push(modelData)
                    } else {
                        const index = selectedAlgorithms.indexOf(modelData)
                        selectedAlgorithms.splice(index, 1)
                    }
                }
            }
        }
        CheckBox {
            text: qsTr("Select all")
            checkState: selectedAlgorithms.length === ChecksumCalculatorFactory.availableAlgorithms.length ? Qt.Checked : selectedAlgorithms.length > 0 ? Qt.PartiallyChecked : Qt.Unchecked
            onCheckStateChanged: {
                if(checkState == Qt.Checked) {
                    for (var i = 0; i < grid.contentItem.children.length; i++) {
                        grid.contentItem.children[i].checkState = Qt.Checked
                    }
                } else if(checkState == Qt.Unchecked) {
                    for (var i = 0; i < grid.contentItem.children.length; i++) {
                        grid.contentItem.children[i].checkState = Qt.Unchecked
                    }
                }
            }
        }
        Button {
            text: qsTr("Calculate")
            Layout.fillWidth: true
            Material.background: Material.accent
            onClicked: dialog.accept()
        }
    }
}
