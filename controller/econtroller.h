#ifndef ECONTROLLER_H
#define ECONTROLLER_H

#include <QObject>
#include "gui/model/eradarmodel.h"
#include <QQmlApplicationEngine>


class EController : public QObject
{
    Q_OBJECT
public:
    EController(QQmlApplicationEngine* qmlEngine, QObject* parent = nullptr);


private:
    QQmlApplicationEngine* mQmlEngine;
    ERadarModel     mRadarModel;


};

#endif // ECONTROLLER_H
