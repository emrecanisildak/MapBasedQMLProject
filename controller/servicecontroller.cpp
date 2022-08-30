#include "servicecontroller.h"
#include <QApplication>

#include <QDebug>

ServiceController::ServiceController(QObject *parent):
    QObject(parent)
{

}

void ServiceController::closeServices()
{
    closeMapService();
}

void ServiceController::init()
{
    openMapService();
}

void ServiceController::openMapService()
{
    qInfo() <<"Map Service Run!";


    std::string mapPath =  "cd "+ QApplication::applicationDirPath().toStdString();
    system(mapPath.c_str());
    system("cd ..");
    system("cd map");
    system("tessella mbtiles://./map.mbtiles --flip_y");
}

void ServiceController::closeMapService()
{
    system("Taskkill /F /IM node.exe");

}
