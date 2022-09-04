#ifndef ETRACKITEM_H
#define ETRACKITEM_H

#include "eabstractitem.h"

enum class TrackStatus
{
    VERIFIED       = 0,
    COASTING       = 1,
    FALL           = 2
};


class ETrackItem : public EAbstractItem
{
public:
    ETrackItem(uint32_t pId, uint32_t pSourceRadarId,TrackStatus pTrackStatus,
               const QGeoCoordinate& pCoordinate,const AERInfo& pAER, int pSpeed);

    QString getInfoText() const;

    uint32_t    mSourceRadarId;
    uint64_t    mTimeStamp;
    AERInfo     mAER;
    int         mSpeed;
    TrackStatus mTrackStatus;

};

#endif // ETRACKITEM_H
