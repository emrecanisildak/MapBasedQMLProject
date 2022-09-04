#include "etrackitem.h"
#include <chrono>

ETrackItem::ETrackItem(uint32_t pId, uint32_t pSourceRadarId, TrackStatus pTrackStatus, const QGeoCoordinate &pCoordinate, const AERInfo &pAER, int pSpeed):
    EAbstractItem(pId,pCoordinate),
    mSourceRadarId{pSourceRadarId},
    mAER{pAER},
    mSpeed{pSpeed},
    mTrackStatus{pTrackStatus}
{
    using namespace std::chrono;
    mTimeStamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

QString ETrackItem::getInfoText() const
{
    QString pInfoText;
    pInfoText += "Id: "        + QString::number(mId);
    pInfoText += "Azimuth: "   + QString::number(mAER.mAzimuth);
    pInfoText += "Elevation: " + QString::number(mAER.mElevation);
    pInfoText += "Range: "     + QString::number(mAER.mRange);
    return  pInfoText;
}
