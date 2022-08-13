import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12

Window {
    id:mainWindow
    width: 1000
    height: 500
    visible: true
    visibility: "Windowed"    // Windowed  - FullScreen
    title: qsTr("Offline Map Example")
    onXChanged: map.pan(100,200)



    Plugin {
        id: plugin_osm
        preferred: "osm"
        PluginParameter {
            name: "osm.mapping.custom.host"
            value: "http://localhost:4000/"
        }
        PluginParameter {
            name: "osm.mapping.providersrepository.disabled"
            value: true
        }

        PluginParameter {
            name: "osm.mapping.cache.disk.size"
            value: 99999999
        }

        PluginParameter {
            name: "osm.mapping.cache.directory"
            value: "cache"
        }

    }
    Map {
        id: map
        anchors.fill: parent
        plugin: plugin_osm
        zoomLevel: 8
        minimumZoomLevel: 0
        maximumZoomLevel: 15
        center: QtPositioning.coordinate(39,34)
        activeMapType: supportedMapTypes[supportedMapTypes.length - 1]

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
        } // End Radar Model

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
        } // End Radar Model

        // PLOT MODEL
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
        } // End PLOT Model

        MapPolyline {
            id: ruler
            line.color: 'green'
            line.width: 3
        }// Ruler Model

        Rectangle{
            id:infoText
            anchors.bottom: map.bottom
            anchors.left: map.left
            color: "black"
            width:map.width/10
            height:map.height/25
            TextArea{
                text:"Eci"
            }
        }

        MouseArea {
            anchors.fill: map
            acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MidButton
           // onMouseXChanged:
            onClicked: (mouse)=> {
                           controller.onMapClicked(mouse.button,map.toCoordinate(Qt.point(mouse.x,mouse.y)))

                       }// End Mouse area on Clicked
        }// End mousea area map
    }// Map End

}// Window end
