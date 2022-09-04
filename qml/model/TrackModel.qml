import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12

MapItemView {
    model: trackModel
    delegate:
        MapCircle{
        radius: 5000
        color: "white"
        z:10
        center {
            latitude: latitude
            longitude: longitude
        }
    } // Track Item
}
