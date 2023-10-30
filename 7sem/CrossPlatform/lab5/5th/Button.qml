import QtQuick 2.15

Rectangle {
    id: button

    property int buttonHeight: 40
    property int buttonWidth: 88

    property string label
    property color textColor: buttonLabel.color

    property color buttonColor: "#0000ff"

    property real labelSize: 14
    width: buttonWidth; height: buttonHeight

    Text {
        id: buttonLabel
        anchors.centerIn: parent
        text: label
        color: "#000000"
        font.pointSize: labelSize
    }

    signal buttonClick()

    MouseArea {
        id: buttonMouseArea
        anchors.fill: parent
        onClicked: buttonClick()
    }

    color: buttonMouseArea.pressed ? Qt.darker(buttonColor, 1.5) : buttonColor

}
