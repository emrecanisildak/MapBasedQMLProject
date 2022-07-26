#ifndef ECONTROLLER_H
#define ECONTROLLER_H

#include <QObject>
#include <QThread>


#include "gui/model/eradarmodel.h"
#include "gui/model/eplotmodel.h"
#include "gui/model/etrackmodel.h"
#include <QQmlApplicationEngine>
#include "emapcontroller.h"
#include "ewindowcontroller.h"
#include "servicecontroller.h"

class QApplication;

class EController : public QObject
{
    Q_OBJECT
public:
    EController(QObject* parent = nullptr);
    ~EController();


private:
    QApplication*          mApplication;

    QQmlApplicationEngine  mQMLEngine;
    EMapController         mMapController;

    ERadarModel            mRadarModel;
    EPlotModel             mPlotModel;
    ETrackModel            mTrackModel;

    EWindowController      mWindowController;


    // Service handler
    QThread                mServiceThread;
    EServiceController*    mServiceController;
};

#endif // ECONTROLLER_H
