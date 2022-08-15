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
    visibility: "FullScreen"    // Windowed  - FullScreen
    title: qsTr("Ecies Company Map")
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
        center: QtPositioning.coordinate(39.32,34)
        activeMapType: supportedMapTypes[supportedMapTypes.length - 1]



        RadarModel {
        } // End Radar Model

        RadarRangeModel {
        } // End Radar Model

        // PLOT MODEL
        PlotModel {
        } // End PLOT Model

        Ruler {
            id: ruler
        }// Ruler Model

        CoordinateInfoBox {
            id: infoText
        }

        MapMouseArea {
            id: mapMouseArea
        }// End mousea area map
    }// Map End

    TopMenu {
        id: topMenu
    }


    RightMenu {
        id: rightMenu
    }

}// Window end


