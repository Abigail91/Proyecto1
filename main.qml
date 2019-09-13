import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 1500
    height: 1000
    property alias button1: button1

    property alias scrollView: scrollView
    title: qsTr("TecFlix")

    Image {
        id: image1
        x: 0
        y: 0
        width: 1500
        height: 1000
        z: -1
        fillMode: Image.PreserveAspectFit
        source: "file:/home/abigail/Escritorio/TecFlix/Wallpaper.jpg"
    }

    ScrollView {
        id: scrollView
        x: 0
        y: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: -126
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent


        Button {
            id: button1
            x: 1430
            y: 30
            width: 50
            height: 50
            text: qsTr("")
            highlighted: true
            autoRepeat: false
            autoExclusive: false
            checked: false
            checkable: false
            font.underline: false
            font.italic: false
            font.pointSize: 40
            font.capitalization: Font.AllUppercase
            focusPolicy: Qt.WheelFocus
            anchors.top: parent.top
            anchors.topMargin: 50

            Image {
                id: image
                x: 0
                y: 0
                width: 50
                height: 50
                z: 1
                fillMode: Image.PreserveAspectFit
                source: "file:/home/abigail/Escritorio/TecFlix/Zoom+.png"
            }


        }


        Button {
            id: button
            x: 1325
            y: 4
            width: 160
            height: 21
            text: qsTr("Modo de no paginacion")
            highlighted: true
            autoRepeat: false
            autoExclusive: false
            checked: false
            checkable: false
            flat: false
            font.pointSize: 10
        }

        Button {
            id: button2
            x: 1430
            y: 110
            width: 50
            height: 50
            text: qsTr("")
            highlighted: true
            autoRepeat: false
            autoExclusive: false
            checked: false
            checkable: false
            font.pointSize: 61

        Image {
            id: image2
            x: 0
            y: 0
            width: 50
            height: 50
            fillMode: Image.PreserveAspectFit
            source: "file:/home/abigail/Escritorio/TecFlix/Zoom-.png"
        }
        }

        RoundButton {
            id: roundButton
        x: 10
        y: 970
        width: 25
        height: 25
        text: "1"
    }

    RoundButton {
        id: roundButton1
        x: 40
        y: 970
        width: 25
        height: 25
        text: "2"
    }

    RoundButton {
        id: roundButton2
        x: 70
        y: 970
        width: 25
        height: 25
        text: "3"
    }

    RoundButton {
        id: roundButton3
        x: 100
        y: 970
        width: 25
        height: 25
        text: "4"
    }

    RoundButton {
        id: roundButton4
        x: 130
        y: 970
        width: 25
        height: 25
        text: "5"
    }

    RoundButton {
        id: roundButton5
        x: 160
        y: 970
        width: 25
        height: 25
        text: ">"
        font.underline: false
        font.italic: false
        font.bold: true
        font.pointSize: 15
    }
    }

}
