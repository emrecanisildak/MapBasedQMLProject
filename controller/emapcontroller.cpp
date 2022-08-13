#include "emapcontroller.h"
#include <QDebug>

EMapController::EMapController(QObject *parent)
    : QObject{parent}
{

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
