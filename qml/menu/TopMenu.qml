import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12

MenuBar {
    id: menuBar
    z:500

    Menu { title: qsTr("File") }
    Menu { title: qsTr("Edit") }
    Menu { title: qsTr("View") }
    Menu { title: qsTr("Help") }

    delegate: MenuBarItem {
        id: menuBarItem

        onTriggered: ()=>{
                         console.log("Clicked Menu Bar Item")
                     }

        contentItem: Text {
            text: menuBarItem.text
            font: menuBarItem.font
            opacity: enabled ? 1.0 : 0.3
            color: menuBarItem.highlighted ? "#ffffff" : "#21be2b"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideMiddle
        }

        background: Rectangle {
            implicitWidth: 40
            implicitHeight: 40
            opacity: enabled ? 1 : 0.3
            color: menuBarItem.highlighted ? "#21be2b" : "transparent"
        }
    }

    background: Rectangle {
        implicitWidth: 40
        implicitHeight: 40
        color: "#000000"

        Rectangle {
            color: "#21be2b"
            width: parent.width
            height: 1
            anchors.bottom: parent.bottom
        }
    }
}
