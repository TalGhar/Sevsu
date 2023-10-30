import QtQuick
import QtQuick.Controls 2.5

Window {

    width: 640
    height: 480
    visible: true
    title: qsTr("Tiles")

    property int setColor: 1

    function buttonClicked(id)
    {
        if (id === setColor) {
         setColor = Math.floor(Math.random() * (12-1+1)+1);
        }
    }

    Grid {
        columns: 3
        rows: 4

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        columnSpacing: 10
        rowSpacing: 10


        Button {

            id: but1
            height: 40
            width: 88
            background: Rectangle
            {
                color: setColor === 1 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(1);
            }

        }
        Button {
            id: but2
            height: 40
            width: 88
            background: Rectangle
            {
                color: setColor === 2 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(2);
            }
        }
        Button {
            id: but3
            height: 40
            width: 88
            background: Rectangle
            {
                color: setColor === 3 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(3);
            }
        }

        Button {
            id: but4
            height: 40
            width: 88
            background: Rectangle
            {
                color: setColor === 4 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(4);
            }
        }
        Button {
            id: but5
            height: 40
            width: 88
            background: Rectangle
            {
               color: setColor === 5 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(5);
            }
        }
        Button {
            id: but6
            height: 40
            width: 88
            background: Rectangle
            {
                color: setColor === 6 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(6);
            }
        }

        Button {
            id: but7
            height: 40
            width: 88
            background: Rectangle
            {
                color: setColor === 7 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(7);
            }
        }
        Button {
            id: but8
            height: 40
            width: 88
            background: Rectangle
            {
               color: setColor === 8 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(8);
            }
        }
        Button {
            id: but9
            height: 40
            width: 88
            background: Rectangle
            {
                color: setColor === 9 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(9);
            }
        }

        Button {
            id: but10
            height: 40
            width: 88
            background: Rectangle
            {
               color: setColor === 10 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(10);
            }
        }
        Button {
            id: but11
            height: 40
            width: 88
            background: Rectangle
            {
                color: setColor === 11 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(11);
            }
        }
        Button {
            id: but12
            height: 40
            width: 88
            background: Rectangle
            {
                color: setColor === 12 ? "#ff0000" : "#0000ff"
            }
            onClicked: {
                buttonClicked(12);
            }
        }



    }

}
