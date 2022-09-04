#include "servicecontroller.h"
#include <QApplication>

#include <QDebug>

EServiceController::EServiceController(QObject *parent):
    QObject(parent)
{

}

void EServiceController::closeServices()
{
    closeMapService();
}

void EServiceController::init()
{
    openMapService();
}

void EServiceController::openMapService()
{
    qInfo() <<"Map Service Run! "<<QApplication::applicationDirPath();


//    std::string mapPath =  "cd "+ QApplication::applicationDirPath().toStdString();
//    system(mapPath.c_str());
//    system("cd ..");
//    system("cd map");
//    system("tessella mbtiles://./map.mbtiles --flip_y");
}

void EServiceController::closeMapService()
{
  //  system("Taskkill /F /IM node.exe");

}
