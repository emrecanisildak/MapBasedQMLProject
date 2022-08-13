#include "eplotitem.h"
#include <chrono>



EPlotItem::EPlotItem(const QString &pName, int pId, const QGeoCoordinate &pCoordinate, const QString &pSourcePath):
    EAbstractItem{pName,pId,pCoordinate,pSourcePath}
{
    using namespace std::chrono;
    mTimeStamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
