#ifndef ECONTROLLER_H
#define ECONTROLLER_H

#define TEST
#include <QObject>
#include "gui/model/eradarmodel.h"
#include "gui/model/eplotmodel.h"
#include <QQmlApplicationEngine>
#include "emapcontroller.h"
#include "ewindowcontroller.h"


class EController : public QObject
{
    Q_OBJECT
public:
    EController(QObject* parent = nullptr);

public slots:
    void onMapClicked(int pType, const QGeoCoordinate& cordinate);
    void onMapCursorPositionChanged(const QGeoCoordinate& pCoordinate);

private:
    EMapController         mMapController;
    QQmlApplicationEngine  mQMLEngine;
    ERadarModel            mRadarModel;
    EPlotModel             mPlotModel;
    EWindowController      mWindowController;
};

#endif // ECONTROLLER_H
