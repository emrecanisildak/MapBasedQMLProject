#include "eplotitem.h"
#include <chrono>

EPlotItem::EPlotItem(uint32_t pId, uint32_t pSourceRadar, const QGeoCoordinate &pCoordinate, const AERInfo& pAER):
    EAbstractItem{pId,pCoordinate},
    mSourceRadarId{pSourceRadar},
    mAER{pAER}
{
    using namespace std::chrono;
    mTimeStamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
