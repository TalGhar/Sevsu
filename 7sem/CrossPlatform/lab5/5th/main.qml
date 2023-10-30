import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("lab 5")

    function buttonClicked(button) {
        var buttons = [but1, but2, but3, but4, but5, but6, but7, but8, but9, but10, but11, but12];

        if(button.color == "#ff0000")
        {
            button.color = "#0000ff";
            var rand = Math.floor(Math.random() * buttons.length);
            var rand_button = buttons[rand];
            rand_button.color = "#ff0000";
            file.set_state(rand);
        }

    }

    function loadStates(id)
    {
        var buttons = [but1, but2, but3, but4, but5, but6, but7, but8, but9, but10, but11, but12];

        for (let i = 0; i < buttons.length; i++)
        {
            if (i === id)
            {
                buttons[i].color="#ff0000";
            } else
                buttons[i].color = "#0000ff";
        }
    }

    Grid {
        columns: 3
        rows: 5

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        columnSpacing: 10
        rowSpacing: 10


        Button {
            id: but1
            color: "#ff0000"
            onButtonClick:
                buttonClicked(but1)
        }
        Button {
            id: but2
            onButtonClick:
                buttonClicked(but2)
        }
        Button {
            id: but3
            onButtonClick:
                buttonClicked(but3)

        }

        Button {
            id: but4
            onButtonClick:
                buttonClicked(but4)
        }
        Button {
            id: but5
            onButtonClick:
                buttonClicked(but5)
        }
        Button {
            id: but6
            onButtonClick:
                buttonClicked(but6)
        }

        Button {
            id: but7
            onButtonClick:
                buttonClicked(but7)
        }
        Button {
            id: but8
            onButtonClick:
                buttonClicked(but8)
        }
        Button {
            id: but9
            onButtonClick:
                buttonClicked(but9)
        }

        Button {
            id: but10
            onButtonClick:
                buttonClicked(but10)
        }
        Button {
            id: but11
            onButtonClick:
                buttonClicked(but11)
        }
        Button {
            id: but12
            onButtonClick:
                buttonClicked(but12)
        }

        Button {
            label: "Save"
            color: "#f0f0f0"
            onButtonClick:
                file.save_state(file.get_state());
        }

        Button {
            label: "Load"
            color: "#f0f0f0"
            onButtonClick:
                loadStates(file.load_state());
        }

    }
}
