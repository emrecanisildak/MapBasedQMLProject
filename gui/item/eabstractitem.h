#ifndef EABSTRACTITEM_H
#define EABSTRACTITEM_H

#include <QGeoCoordinate>

struct AERInfo {
    AERInfo():mAzimuth(0.0),mElevation{0.0}, mRange{0.0}{}
    AERInfo(double pAzimuth, double pElevation, double pRange) :
        mAzimuth{pAzimuth},
        mElevation{pElevation},
        mRange{pRange}
    {

    }
    double mAzimuth;
    double mElevation;
    double mRange;
};


class EAbstractItem
{
public:
    EAbstractItem(uint32_t pId, const QGeoCoordinate& pCoordinate);
    uint32_t            mId;
    QGeoCoordinate mCoordinate;

};

#endif // EABSTRACTITEM_H
