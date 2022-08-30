#ifndef EPLOTITEM_H
#define EPLOTITEM_H

#include "eabstractitem.h"

class EPlotItem : public EAbstractItem
{
public:
      EPlotItem(uint32_t pId, uint32_t pSourceRadarId, const QGeoCoordinate& pCoordinate,const AERInfo& pAER);
      uint32_t mSourceRadarId;
      uint64_t mTimeStamp;
      AERInfo  mAER;
};

#endif // EPLOTITEM_H
