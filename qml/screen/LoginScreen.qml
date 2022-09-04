import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12
import QtQuick.Layouts 1.0

import "../customitem"


Window{
    id:loginScreen
    width: 1000
    height: 500
    visible: true
    visibility: "FullScreen"    // Windowed  - FullScreen
    title: qsTr("Ecies Company Map")
    color:"black"

    Rectangle
    {
        id:loginScreenItems
        color:"black"
        width: loginScreen/2
        height: loginScreen/2
        anchors.fill: parent

        Column{
            id:columnLoginScreen
            spacing:15
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter



            CustomTextField{
                id:idTextBox
                placeholderText: "<i>ID</i>"


            }

            CustomTextField{
                id:passwordTextBox
                echoMode: TextInput.Password
                placeholderText: "<i>Password</i>"
            }
        }

        Button{
            id:loginButton
            text:qsTr("Login")
            anchors.top: columnLoginScreen.bottom
            anchors.left: columnLoginScreen.left
            anchors.topMargin: 30
            width:passwordTextBox.width
            height:passwordTextBox.height
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                color: loginButton.down ? "#d6d6d6" : "#f6f6f6"
                border.color: "#26282a"
                border.width: 1
                radius: 4
            }

            onClicked:{
                loginConfirmationWait()
            }
        }

        Image{
            id:logo
            source:"qrc:/images/logo.png"
            anchors.top: columnLoginScreen.top
            anchors.left: columnLoginScreen.left
            anchors.leftMargin: 50
            anchors.topMargin: 25
            visible:false
            rotation: 1

        }
    }

    PropertyAnimation { id: animationLogo;
        target: logo;
        property: "rotation";
        to: 359;
        duration: 1500 }


    Connections{
        target:animationLogo
        function onFinished(){
            logo.rotation = 0
            animationLogo.start()
        }
    }

    Connections{
        target:windowController
        function onLoginSuccess()
        {
            windowController.openWindow("MainWindow")
        }
        function onLoginUnsuccess()
        {
            animationLogo.stop()
            loginConfirmationAbort()
        }
        function onPageLoaded(name)
        {
            if(name === "MainWindow")
            {
                animationLogo.stop()
                loginScreen.close()
            }

        }
    }

    function loginConfirmationWait()
    {
        windowController.loginConfirm(idTextBox.text,passwordTextBox.text)
        columnLoginScreen.visible = false
        logo.visible = true
        loginButton.visible = false
        animationLogo.start()
    }
    function loginConfirmationAbort(){
        columnLoginScreen.visible = true
        logo.visible = false
        loginButton.visible = true
    }


}
