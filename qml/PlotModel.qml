import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12

MapItemView {
    model: plotModel
    delegate:
        MapCircle{
        radius: 3000
        color: "#FFFF00"
        z:15
        center {
            latitude: latitude
            longitude: longitude
        }
        MouseArea {
            anchors.fill: parent
            onClicked: { parent.color = 'red' }
        }
    } // PLOT Item
}
