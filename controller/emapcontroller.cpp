#include "emapcontroller.h"
#include <QDebug>
#include <QDir>

EMapController::EMapController(QObject *parent)
    : QObject{parent}
{
    // Cache folder create
    QDir::current().mkdir("cache");
}

void EMapController::onMapClicked(int pType, const QGeoCoordinate &cordinate)
{
    if(pType == Qt::MidButton)
    {
        //qDebug()<<"Orta butona tiklandi";
    }

    else if(pType == Qt::LeftButton)
    {
        //qDebug()<<"Left Butona Tiklandi";
    }
    else
    {
       // qDebug()<<"Right Button Clicked";
    }
}

void EMapController::onMapMouseCursorPositionChanged(const QGeoCoordinate &pCoordinate)
{
    //qDebug()<<"Mouse cursor position"<<pCoordinate;
}
