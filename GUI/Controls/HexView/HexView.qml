import UltraHex
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Material

Item {
    id: hexView
    readonly property int rowsNotInView: Math.max(0, totalRows - rowsInView)
    readonly property int rowsInView: (hexRowLayout.height / textMetrics.height)
    readonly property int rowsToDisplay: Math.min(totalRows, rowsInView)
    readonly property int totalRows: fileHandle.fileSize / settings.bytesPerRow
    readonly property int firstRowIndex: hexScrollBar.position /  (1.0 - hexScrollBar.size) * rowsNotInView
    property FileHandle fileHandle
    property HexViewSettings settings : HexViewSettings {

    }

    WheelHandler {
        onWheel: (wheel)=> {
            //Calculate new position
            var amount = wheel.angleDelta.y / 120
            var newPos = hexScrollBar.position
            if(amount > 0){
                newPos -= hexScrollBar.stepSize * Math.abs(amount)
            } else {
                newPos += hexScrollBar.stepSize * Math.abs(amount)
            }
            // Check if position is not out of bounds
            if(newPos > 1) newPos = 1
            else if(newPos < 0) newPos = 0
            hexScrollBar.position = newPos
        }
    }

    onRowsToDisplayChanged: {
        while(rowModel.count < rowsToDisplay){
            rowModel.append({})
        }

        var descrepancy = rowModel.count - rowsToDisplay
        if(descrepancy>0){
            rowModel.remove(rowModel.count - descrepancy, descrepancy)
        }
    }

    ListModel {
        id: rowModel
    }

    ColumnLayout {
        id: hexRowLayout
        spacing: 0
        anchors.fill: parent
        Repeater  {
            model: rowModel
            HexViewRow{
                fileHandle: hexView.fileHandle
                settings: hexView.settings
                rowNumber: index + firstRowIndex
            }
        }
    }

    TextMetrics {
        id: textMetrics
        font: hexView.settings.hexFont
        text: "00"
    }

    ScrollBar {
        id: hexScrollBar
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        policy: ScrollBar.AlwaysOn
        visible: rowsNotInView > 0
        snapMode: ScrollBar.SnapAlways
        stepSize: 1 / rowsNotInView
        size: 1 / Math.max(2, rowsNotInView)
    }
}
