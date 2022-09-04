#include "econtroller.h"

#include <QQmlContext>
#include <QApplication>

EController::EController(QObject* parent)
    : QObject(parent)
{
    qmlRegisterType<EController>("com.eciescompany.controller", 1, 0, "Controller");
    qmlRegisterType<ERadarModel>("com.eciescompany.radarmodel", 1, 0, "RadarModel");
    qmlRegisterType<EPlotModel>("com.eciescompany.plotmodel", 1, 0, "PlotModel");
    qmlRegisterType<ETrackModel>("com.eciescompany.trackcontrol", 1, 0, "TrackModel");
    qmlRegisterType<EWindowController>("com.eciescompany.windowcontroller", 1, 0, "WindowController");
    qmlRegisterType<EMapController>("com.eciescompany.mapcontroller", 1, 0, "MapController");


    mQMLEngine.rootContext()->setContextProperty("controller",  this);
    mQMLEngine.rootContext()->setContextProperty("radarModel", &mRadarModel);
    mQMLEngine.rootContext()->setContextProperty("plotModel",  &mPlotModel);
    mQMLEngine.rootContext()->setContextProperty("trackModel",&mTrackModel);
    mQMLEngine.rootContext()->setContextProperty("mapController",&mMapController);
    mQMLEngine.rootContext()->setContextProperty("windowController",&mWindowController);

    // Threads
    mServiceController = new EServiceController;
    mServiceController->moveToThread(&mServiceThread);
    connect(&mServiceThread, &QThread::started, mServiceController, &EServiceController::init);
    connect(&mServiceThread, &QThread::finished, mServiceController, &QObject::deleteLater);
    //mServiceThread.start();

    mWindowController.init(&mQMLEngine);
    ERadarItem item1(1,QGeoCoordinate(39.32,34));
    mRadarModel.addRadarItem(item1);


    ETrackItem track1(1,1,TrackStatus::VERIFIED,QGeoCoordinate(39.22,34.13),{120,20,30},25);
    mTrackModel.updateTrack(track1);

    EPlotItem plot(15,12,QGeoCoordinate(39.12,34.15),{120,12,31});
    mPlotModel.addPlot(plot);
}

EController::~EController()
{
    mServiceController->closeServices();
    mServiceThread.quit();
    mServiceThread.wait();
}

