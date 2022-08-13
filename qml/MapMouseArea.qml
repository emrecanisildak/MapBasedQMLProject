import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12

MouseArea {
    id:mapMouseArea
    anchors.fill: map
    hoverEnabled: true
    propagateComposedEvents: true
    acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MidButton
    onPositionChanged:()=>{
                          controller.onMapCursorPositionChanged(map.toCoordinate(Qt.point(mapMouseArea.mouseX,mapMouseArea.mouseY)))
                      }
    onClicked: (mouse)=> {
                   controller.onMapClicked(mouse.button,map.toCoordinate(Qt.point(mouse.x,mouse.y)))
               }// End Mouse area on Clicked
}
