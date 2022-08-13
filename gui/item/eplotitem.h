#ifndef EPLOTITEM_H
#define EPLOTITEM_H

#include "eabstractitem.h"

class EPlotItem : public EAbstractItem
{
public:
      EPlotItem(const QString& pName,int pId, const QGeoCoordinate& pCoordinate, const QString& pSourcePath);
      uint64_t mTimeStamp;
};

#endif // EPLOTITEM_H
