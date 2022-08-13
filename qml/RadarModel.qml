import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12

MapItemView {
    model: radarModel
    delegate:
        MapCircle{
        radius: 10000
        color: "#808000"
        z:10
        center {
            latitude: latitude
            longitude: longitude
        }
        MouseArea {
            anchors.fill: parent
            onClicked: { parent.color = 'red' }
        }
    } // Radar Item
}
