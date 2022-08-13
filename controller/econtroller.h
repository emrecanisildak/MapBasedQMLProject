#ifndef ECONTROLLER_H
#define ECONTROLLER_H

#define TEST


#include <QObject>
#include "gui/model/eradarmodel.h"
#include "gui/model/eplotmodel.h"
#include <QQmlApplicationEngine>


#include <QTimer>


class EController : public QObject
{
    Q_OBJECT
public:
    EController(QQmlApplicationEngine* qmlEngine = nullptr, QObject* parent = nullptr);

public slots:
    void onMapClicked(int pType, const QGeoCoordinate& cordinate);


private:
    QQmlApplicationEngine* mQmlEngine;
    ERadarModel            mRadarModel;
    EPlotModel             mPlotModel;

    QTimer                 mTestTimer;






};

#endif // ECONTROLLER_H
