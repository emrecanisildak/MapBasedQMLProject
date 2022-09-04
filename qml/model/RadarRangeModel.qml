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
        radius: 100000
        color: "#556B2F"
        opacity:0.6
        z:0
        center {
            latitude: latitude
            longitude: longitude
        }
    } // Radar Item
}
