import QtQuick 2.4
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12
import QtCharts 2.3
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.3

import "../customitem"

Item{       
    id:leftMenu
    property string menuColor    : "black"
    property int    menuWidth    :  100
    property bool   isMenuExpand : false

    Rectangle{
        id:leftMenuMain
        color: menuColor
        width: isMenuExpand  ? menuWidth * 3  :  menuWidth
        height:parent.height
        opacity:0.93
        anchors.top: parent.top
        anchors.left: parent.left

        ColumnLayout{
            id:leftMenuLayout
            spacing: 15
            visible: true

            CustomLeftMenuButton {
                id: leftMenuOpen
                imageSource:"qrc:/images/leftmenuexpand.png"
                toolTipText : qsTr("Expand")
                toolTipVisible: control.hovered && !isMenuExpand
                onClicked:() =>{
                              isMenuExpand = !isMenuExpand
                          }
            }// End LeftMenuOpenButton



            CustomLeftMenuButton {
                id: leftMenuRadarButton
                imageSource:"qrc:/images/leftmenuradar.png"
                toolTipText : qsTr("Radar")
                toolTipVisible: leftMenuRadarButton.hovered && !isMenuExpand
                expandFormTextVisible : isMenuExpand




            }

            CustomLeftMenuButton {
                id: leftMenuMapButton
                imageSource:"qrc:/images/leftmenumap.png"
                toolTipText : qsTr("Map")
                toolTipVisible: leftMenuMapButton.hovered && !isMenuExpand
                expandFormTextVisible : isMenuExpand




            }

            CustomLeftMenuButton {
                id: leftMenuSettingsButton
                imageSource:"qrc:/images/leftmenusettings.png"
                toolTipText : qsTr("Settings")
                toolTipVisible: leftMenuSettingsButton.hovered && !isMenuExpand
                expandFormTextVisible : isMenuExpand




            }

            CustomLeftMenuButton {
                id: leftMenuLogOutButton
                imageSource:"qrc:/images/leftmenulogout.png"
                toolTipText : qsTr("Log Out")
                toolTipVisible: leftMenuLogOutButton.hovered && !isMenuExpand
                expandFormTextVisible : isMenuExpand

            }


        }


    }



    //    OpacityAnimator {
    //        id:leftMenuAnim1
    //        target: leftMenuMain;
    //        from: 0;
    //        to: 1;
    //        duration: 600
    //        running: false
    //    }

    //    OpacityAnimator {
    //        id:leftMenuAnim2
    //        target: leftMenuMain;
    //        from: 1;
    //        to: 0;
    //        duration: 600
    //        running: false
    //    }
}
