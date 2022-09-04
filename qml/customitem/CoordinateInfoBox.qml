import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12

Rectangle{
    id:infoText
    property string infoBoxColor : "#16213E"
    property string infoBoxTextColor : "white"
    anchors.bottom: map.bottom
    anchors.right: map.right
    anchors.bottomMargin: 5
    anchors.rightMargin: 5
    width:coordinateInfoTextArea.contentWidth + 15
    height:coordinateInfoTextArea.contentHeight + 10
    color: infoBoxColor
    TextArea{
        id:coordinateInfoTextArea
        text: ""+ map.toCoordinate(Qt.point(mapMouseArea.mouseX,mapMouseArea.mouseY))
        color: infoBoxTextColor
    }
}
