#include "econtroller.h"

#include <QQmlContext>


EController::EController(QQmlApplicationEngine *qmlEngine, QObject* parent)
    : QObject(parent),
      mQmlEngine{qmlEngine}
{

    qmlRegisterType<ERadarModel>("com.eciescomany.radaritem", 1, 0, "RadarModel");

    ERadarItem item1("Radar",1,QGeoCoordinate(39.32,34),"asdasd");
    ERadarItem item2("Radar",2,QGeoCoordinate(34.32,35),"asdasd");
    ERadarItem item3("Radar",3,QGeoCoordinate(36.32,37),"asdasd");
    ERadarItem item4("Radar",4,QGeoCoordinate(38.32,45),"asdasd");

    mRadarModel.addRadarItem(item1);
    mRadarModel.addRadarItem(item2);
    mRadarModel.addRadarItem(item3);
    mRadarModel.addRadarItem(item4);

   mQmlEngine->rootContext()->setContextProperty("radarModel", &mRadarModel);


}

