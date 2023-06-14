import QtQuick
import UltraHex
import QtQuick.Controls
import QtQuick.Controls.Material
Row {
    property FileHandle fileHandle
    property int rowNumber : 0
    property HexViewSettings settings
    property var intArray
    readonly property int offsetCharacterWidth: fileHandle.fileSize.toString(16).length

    onRowNumberChanged: updateDataRow()
    bottomPadding: 0
    topPadding: 0
    spacing: 10

    Connections {
        target: settings
        function onBytesPerRowChanged() {
            resizeDataRow()
        }
    }

    Component.onCompleted: resizeDataRow()

    function updateDataRow() {
        var data = fileHandle.fileReader.read(rowNumber * settings.bytesPerRow, settings.bytesPerRow)
        intArray = new Uint8Array(data);

        decodedText.text = fileHandle.fileReader.decodedString(rowNumber * settings.bytesPerRow, settings.bytesPerRow)
    }

    function resizeDataRow() {
        updateDataRow()
        while(rowModel.count < settings.bytesPerRow){
            rowModel.append({})
        }

        var descrepancy = rowModel.count - settings.bytesPerRow
        if(descrepancy>0){
            rowModel.remove(rowModel.count - descrepancy, descrepancy)
        }
    }

    ListModel {
        id: rowModel
    }

    Label {
        id: offsetLabel
        font.family: "Courier New"
        text: (rowNumber * settings.bytesPerRow).toString(16).padStart(offsetCharacterWidth, '0')
    }

    Row {
        id: dataRow
        spacing: 5
        Repeater  {
            model: rowModel
            Label {
                property bool odd: index % 2
                text: intArray[index].toString(16).padStart(2, '0')
                font.family: "Courier New"
                textFormat: Text.PlainText
                background: Rectangle {
                    color: odd ? Material.background : Material.primary
                    opacity: 0.25
                }
            }
        }
    }

    Label {
        id: decodedText
        font.family: "Courier New"

    }
}
