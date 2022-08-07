import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

Row{

    Button {
        id: menu1Button
        text: "Menu1"
        onClicked: menu1.open()

        Menu {
            id: menu1
            y: menu1Button.height


            MenuItem {
                text: "New."
            }
            MenuItem {
                text: "Open"
            }
            MenuItem {
                text: "Save"
            }
        }


    }
    Button {
        id: menu2Button
        text: "menu2"
        onClicked: menu2.open()

        Menu {
            id: menu2
            y: menu2Button.height

            MenuItem {
                text: "Open"
            }
            MenuItem {
                text: "Close"
            }
            MenuItem {
                text: "Save"
            }
        }
    }
}







