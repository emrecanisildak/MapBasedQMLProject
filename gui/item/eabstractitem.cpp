#include "eabstractitem.h"

EAbstractItem::EAbstractItem(const QString &pName, int pId, const QGeoCoordinate &pCoordinate, const QString &pSourcePath):
    mName{pName},
    mId(pId),
    mCoordinate{pCoordinate},
    mSourcePath{pSourcePath}
{

}
