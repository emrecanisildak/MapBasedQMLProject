import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtQml 2.12
import QtCharts 2.3



PolarChartView {
    id:ppiScope
    title: "Two Series, Common Axes"
    anchors.fill: parent
    legend.visible: false
    antialiasing: true
    backgroundColor: "black"
    plotAreaColor: "black"
    opacity: 1

    ValueAxis {
        id: axisAngular
        min: 0
        max: 360
        tickCount: 9
        color:"green"
        gridLineColor: "green"
        labelsColor: "gray"
    }

    ValueAxis {
        id: axisRadial
        min: 0
        max: 100000
        color:"green"
        gridLineColor: "green"
        labelsColor: "gray"
        tickCount: 5

    }

    ScatterSeries {
        id: series2
        axisAngular: axisAngular
        axisRadial: axisRadial
        markerSize: 5
        color: "yellow"
        borderColor: "yellow"
    }

    VXYModelMapper {
                model: plotModel
                series: series2
                xColumn: 1
                yColumn: 2
            }


    Component.onCompleted: {
        for (var i = 0; i <= 20; i++) {
            series2.append(50,25000);
            series2.append(95,25000);
        }
    }
    Timer {
        id: refreshTimer
        interval: 1 / 60 * 1000 // 60 Hz
        running: true
        repeat: true
        onTriggered: {
          //  dataSource.update(chartView.series(0));
           // dataSource.update(chartView.series(1));
        }
    }
}

