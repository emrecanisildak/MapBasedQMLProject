import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtQml 2.12
import QtQuick.Controls.Styles 1.4



TextField {
        id:textAreaLogin
        width:170
        height:39
        maximumLength: 15
        font.family: "Helvetica [Cronyx]"
        placeholderTextColor:"white"
        padding: 4
        background: Rectangle {
            color:"#21be2b"
            border.color: "white"
            border.width: 1
        }
}
