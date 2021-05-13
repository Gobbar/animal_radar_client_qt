import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //width: 800
    //height: 800
    //visible: true
    //title: qsTr("Curse")

    Rectangle{
        anchors.fill:parent
        color: "aqua"



    }
    Dialog{
        id: dialogwindow
        Button{
            onClicked: dialogwindow.close()
        }
    }

    //Plugin {
    //        id: mapPlugin
    //        name: "osm"
    //    }

    //Map {
    //        id: myMap
    //        height: 400
    //        width: 400
    //
    //        anchors.centerIn: parent
    //        plugin: mapPlugin
    //        center: QtPositioning.coordinate(64.52, 40.52)
    //        zoomLevel: 12
    //        copyrightsVisible: false
    //
    //        //щипок на карте (изменение масштаба)
    //        PinchArea{
    //            property double oldZoomLevel
    //            anchors.fill: parent
    //
    //            function calcZoomDel(z,p){
    //                return z + Math.log(p)/Math.log(2)
    //            }
    //            onPinchStarted: {
    //                oldZoomLevel = myMap.zoomLevel
    //            }
    //            onPinchUpdated: {
    //                myMap.zoomLevel = calcZoomDel(oldZoomLevel, pinch.scale)
    //            }
    //            onPinchFinished: {
    //                myMap.zoomLevel = calcZoomDel(oldZoomLevel, pinch.scale)
    //            }
    //        }
    //
    //}

    Connections{
        target: request
        onOpenDialogWindow:{
            dialogwindow.open()
    }
    }
    Button{
        x:10
        y:100
        text:qsTr("Олень!")


        onClicked: {
            //lab1.text = "121";
            //var res = "";
            //request.collectData();

            request.collectData();
            //lab1.text = res;

        }
    }
    //Button{
    //    x:10
    //    y:200
    //    text:qsTr("Обновить данные")
    //    onClicked: {
    //        //zad.Cv(2);
    //    }
    //}
    //Button{
    //    x:10
    //    y:300
    //    text:qsTr("B3")
    //    onClicked: {
    //       //zad.Cv(3);
    //    }
    //}
    Label{
        id:lab1
        x:10
        y:500
        width: 200
        height: 100
        text:qsTr("")
    }
    //Connections{
    //    target: zad
    //    onVC: lab1.text = s;
    //}

}
