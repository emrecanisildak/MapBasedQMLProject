#ifndef EABSTRACTITEM_H
#define EABSTRACTITEM_H

#include <QGeoCoordinate>

class EAbstractItem
{
public:
    EAbstractItem(const QString& pName,int pId, const QGeoCoordinate& pCoordinate, const QString& pSourcePath);
    QString        mName;
    int            mId;
    QGeoCoordinate mCoordinate;
    QString        mSourcePath;

};

#endif // EABSTRACTITEM_H
