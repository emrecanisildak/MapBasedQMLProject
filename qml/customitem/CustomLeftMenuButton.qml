import QtQuick 2.4
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12
import QtCharts 2.3
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.3

Button {
    id: control
    property string imageSource : ""
    property string toolTipText : ""
    property bool   toolTipVisible : false
    property bool   expandFormTextVisible: false
    width:menuWidth/2
    height:menuWidth/2
    Layout.preferredWidth: width
    Layout.preferredHeight: height
    Layout.topMargin: menuWidth/4
    Layout.leftMargin: menuWidth/4

    Rectangle{
        id:toolTip
        color:"black"
        height: 3 * parent.height / 4
        width: menuWidth
        radius:width/10
        anchors.left: parent.right
        anchors.leftMargin:  menuWidth/4 + 2
        anchors.verticalCenter: parent.verticalCenter
        visible: toolTipVisible
        opacity:0.6

        Text {
            id: toolTipTextItem
            text:  toolTipText
            font.family: "Helvetica"
            font.pointSize: 13
            color: "white"
        }
    }

    Rectangle{
        id:expandTextBar
        height: 3 * parent.height / 4
        width: expandTextBarItem.contentWidth + 5
        anchors.left: parent.right
        anchors.leftMargin: 20
        visible: expandFormTextVisible
        color:  "transparent"
        opacity: control.hovered ? 0.3   : 1

        Text {
            id: expandTextBarItem
            text: toolTipText
            font.family: "Helvetica"
            font.pointSize: 20
            color:"white"
        }
    }

    background: Rectangle {
        color: "transparent"

    }

    Image {
        anchors.fill: parent
        source: imageSource
        fillMode: Image.Stretch
    }
}

