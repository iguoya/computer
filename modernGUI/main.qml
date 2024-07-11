import QtQuick 2.14
import QtQuick.Controls 2.14
import design.pattern 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Qt Quick Design Pattern"

    Bridge {
        id: bridge
        Component.onCompleted: {
            bridge.name = "John Doe";
            bridge.age = 30;
        }
    }

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "New"
                onTriggered: {

                    bridge.name = "tiger"
                    console.log("New file")
                }
            }
            MenuItem {
                text: "Open"
                onTriggered: {
                    console.log("Open file")
                }
            }
            MenuItem {
                text: "Save"
                onTriggered: {
                    console.log("Save file")
                }
            }
            MenuSeparator {}
            MenuItem {
                text: "Exit"
                onTriggered: {
                    Qt.quit()
                }
            }
        }
        Menu {
            title: "Edit"
            MenuItem {
                text: "Undo"
                onTriggered: {
                    console.log("Undo action")
                }
            }
            MenuItem {
                text: "Redo"
                onTriggered: {
                    console.log("Redo action")
                }
            }
            MenuSeparator {}
            MenuItem {
                text: "Cut"
                onTriggered: {
                    console.log("Cut action")
                }
            }
            MenuItem {
                text: "Copy"
                onTriggered: {
                    console.log("Copy action")
                }
            }
            MenuItem {
                text: "Paste"
                onTriggered: {
                    console.log("Paste action")
                }
            }
        }
        Menu {
            title: "Help"
            MenuItem {
                text: "About"
                onTriggered: {
                    console.log("About dialog")
                }
            }
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "white"
        Text {
            anchors.centerIn: parent
            text: "Hello, World!" + bridge.name
            font.pixelSize: 24
        }
    }
}
