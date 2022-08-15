#include "econtroller.h"

#include <QQmlContext>
#include <QDebug>
#include <QMouseEvent>
#include <QTimer>
#include <QQuickStyle>

EController::EController(QObject* parent)
    : QObject(parent)
{
      QQuickStyle::setStyle("Material");


    qmlRegisterType<EController>("com.eciescompany.controller", 1, 0, "Controller");
    qmlRegisterType<ERadarModel>("com.eciescompany.radarmodel", 1, 0, "RadarModel");
    qmlRegisterType<EPlotModel>("com.eciescompany.plotmodel", 1, 0, "PlotModel");
    qmlRegisterType<EWindowController>("com.eciescompany.windowcontroller", 1, 0, "WindowController");


    mQMLEngine.rootContext()->setContextProperty("controller",  this);
    mQMLEngine.rootContext()->setContextProperty("radarModel", &mRadarModel);
    mQMLEngine.rootContext()->setContextProperty("plotModel",  &mPlotModel);
    mQMLEngine.rootContext()->setContextProperty("windowController",&mWindowController);



    mWindowController.init(&mQMLEngine);
    ERadarItem item1("Radar",1,QGeoCoordinate(39.32,34),"asdasd");
    mRadarModel.addRadarItem(item1);


}

void EController::onMapClicked(int pType, const QGeoCoordinate& pCoordinate)
{
    mMapController.onMapClicked(pType,pCoordinate);
}

void EController::onMapCursorPositionChanged(const QGeoCoordinate &pCoordinate)
{
    mMapController.onMapMouseCursorPositionChanged(pCoordinate);
}

