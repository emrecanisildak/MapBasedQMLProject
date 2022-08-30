#include "eabstractitem.h"

EAbstractItem::EAbstractItem(uint32_t pId, const QGeoCoordinate &pCoordinate):
    mId(pId),
    mCoordinate{pCoordinate}
{

}
