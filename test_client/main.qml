import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button{
        onClicked: {
        a.set_time()
        database.setAnimal(a.get_longitude(), a.get_latitude(), a.get_time())

        }
    }

}
