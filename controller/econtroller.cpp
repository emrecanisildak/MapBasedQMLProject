#include "econtroller.h"

#include <QQmlContext>
#include <QRandomGenerator>
#include <QDebug>
#include <QMouseEvent>
EController::EController(QQmlApplicationEngine *qmlEngine, QObject* parent)
    : QObject(parent),
      mQmlEngine{qmlEngine}
{

    qmlRegisterType<EController>("com.eciescomany.controller", 1, 0, "Controller");
    qmlRegisterType<ERadarModel>("com.eciescomany.radarmodel", 1, 0, "RadarModel");
    qmlRegisterType<EPlotModel>("com.eciescomany.plotmodel", 1, 0, "PlotModel");



    EPlotItem item2("",1,QGeoCoordinate(39.37,34.6),"asdasd");
    mPlotModel.addPlot(item2);

    EPlotItem item3("",1,QGeoCoordinate(39.37,35.0),"asdasd");
    mPlotModel.addPlot(item3);


    EPlotItem item4("",1,QGeoCoordinate(39.37,35.3),"asdasd");
    mPlotModel.addPlot(item4);



    EPlotItem item5("",1,QGeoCoordinate(39.57,35.0),"asdasd");
    mPlotModel.addPlot(item5);



    EPlotItem item6("",1,QGeoCoordinate(39.17,35.0),"asdasd");
    mPlotModel.addPlot(item6);



    mTestTimer.start(100);

    ERadarItem item1("Radar",1,QGeoCoordinate(39.32,34),"asdasd");
    mRadarModel.addRadarItem(item1);






   mQmlEngine->rootContext()->setContextProperty("controller",  this);
   mQmlEngine->rootContext()->setContextProperty("radarModel", &mRadarModel);
   mQmlEngine->rootContext()->setContextProperty("plotModel",  &mPlotModel);
}

void EController::onMapClicked(int pType, const QGeoCoordinate& pCoordinate)
{
    if(pType == Qt::MidButton)
    {
        qDebug()<<"Orta butona tiklandi";
    }

    else if(pType == Qt::LeftButton)
    {
        qDebug()<<"Left Butona Tiklandi";
    }
    else
    {
        qDebug()<<"Right Button Clicked";
    }
}

