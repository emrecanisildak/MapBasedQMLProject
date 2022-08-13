import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12

Rectangle{
    id:infoText
    anchors.bottom: map.bottom
    anchors.left: map.left
    anchors.bottomMargin: 5
    anchors.leftMargin: 5
    width:coordinateInfoTextArea.contentWidth + 15
    height:coordinateInfoTextArea.contentHeight + 10
    color: "black"
    TextArea{
        id:coordinateInfoTextArea
        text: ""+ map.toCoordinate(Qt.point(mapMouseArea.mouseX,mapMouseArea.mouseY))
        color: "#21be2b"
    }
}
