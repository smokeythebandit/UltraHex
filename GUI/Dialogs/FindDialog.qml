import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Material

Dialog   {
    width: 550
    height: 400
    parent: Overlay.overlay
    anchors.centerIn: parent
    TabBar {
        id: bar
        width: parent.width
        background: Rectangle {
            color: "transparent"
        }
        TabButton {
            text: qsTr("Text")
        }
        TabButton {
            text: qsTr("Binary")
        }
        TabButton {
            text: qsTr("Numeric")
        }
    }

    SwipeView {
        clip: true
        topPadding: 10
        width: parent.width
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: bar.bottom
        currentIndex: bar.currentIndex
        Item {
            id: textTab
            ColumnLayout {
                anchors.fill: parent
                Text {
                    text: qsTr("Search for")
                    font.pixelSize: 15
                    color: Material.foreground
                }
                TextField {
                    Layout.fillWidth: true
                }
                Text {
                    text: qsTr("Text encoding")
                    font.pixelSize: 15
                    color: Material.foreground
                }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["ASCII", "UTF-8"]
                }
                Text {
                    text: qsTr("Search direction")
                    font.pixelSize: 15
                    color: Material.foreground
                }
                RowLayout {
                    Layout.fillWidth: true
                    RadioButton {
                        text: qsTr("All")
                    }
                    RadioButton {
                        checked: true
                        text: qsTr("Forward")
                    }
                    RadioButton {
                        text: qsTr("Backward")
                    }
                }
            }
        }
        Item {
            id: discoverTab
            ColumnLayout {
                anchors.fill: parent
                Text {
                    text: qsTr("Search for")
                    font.pixelSize: 15
                    color: Material.foreground
                }
                TextField {
                    Layout.fillWidth: true
                    validator: RegularExpressionValidator {
                        regularExpression: /^([0-9A-Fa-f]{2}\s*)+$/
                    }
                }
                Text {
                    text: qsTr("Input format")
                    font.pixelSize: 15
                    color: Material.foreground
                }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["Hexadecimal", "Octal"]
                }
                Text {
                    text: qsTr("Search direction")
                    font.pixelSize: 15
                    color: Material.foreground
                }
                RowLayout {
                    Layout.fillWidth: true
                    RadioButton {
                        text: qsTr("All")
                    }
                    RadioButton {
                        checked: true
                        text: qsTr("Forward")
                    }
                    RadioButton {
                        text: qsTr("Backward")
                    }
                }
            }
        }
        Item {
            id: activityTab
            ColumnLayout {
                anchors.fill: parent
                Text {
                    text: qsTr("Search for")
                    font.pixelSize: 15
                    color: Material.foreground
                }
                TextField {
                    Layout.fillWidth: true
                    validator: IntValidator {
                    }
                }
                Text {
                    text: qsTr("Input format")
                    font.pixelSize: 15
                    color: Material.foreground
                }
                ComboBox {
                    Layout.fillWidth: true
                    model: ["Integer", "Float"]
                }
                Text {
                    text: qsTr("Search direction")
                    font.pixelSize: 15
                    color: Material.foreground
                }
                RowLayout {
                    Layout.fillWidth: true
                    RadioButton {
                        text: qsTr("All")
                    }
                    RadioButton {
                        checked: true
                        text: qsTr("Forward")
                    }
                    RadioButton {
                        text: qsTr("Backward")
                    }
                }
            }
        }



    }

    footer: DialogButtonBox {
        id: dialogButtons
        standardButtons: DialogButtonBox.Cancel
        Button {
            text: qsTr("Search")
            flat: true
            DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
        }
        onAccepted: console.log("Ok clicked")
    }
}
