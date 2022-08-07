import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12

Window {
    id:mainWindow
    width: 1920
    height: 1080
    visible: true
    visibility: "Windowed"    // Windowed  - FullScreen
    title: qsTr("Offline Map Example")

    Plugin {
           id: plugin_osm

           preferred: "osm"

           PluginParameter {
               name: "osm.mapping.custom.host"
               value: "http://localhost:4000/"
           }
           /*disable retrieval of the providers information from the remote repository.
             If this parameter is not set to true (as shown here), then while offline,
             network errors will be generated at run time*/

           PluginParameter {
               name: "osm.mapping.providersrepository.disabled"
               value: true
           }

           PluginParameter {
               name: "osm.mapping.cache.disk.size"
               value: "5000"
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
                       radius: 30000
                       color:"pink"
                       center {
                           latitude: latitude
                           longitude: longitude
                       }
                   }
               }
           }

}
