#include "eradarmodel.h"

#include <algorithm>

ERadarModel::ERadarModel(QObject* parent )
{
    mRoles[RadarNameRole]     = "name";
    mRoles[RadarIdRole]       = "id";
    mRoles[LatitudeRole]      = "latitude";
    mRoles[LongitudeRole]     = "longitude";
    mRoles[SourcePathRole]    = "source";
}

int ERadarModel::rowCount(const QModelIndex &parent) const
{
    return mData.size();
}

void ERadarModel::addRadarItem(const ERadarItem &item)
{
    beginInsertRows(QModelIndex(), 0, 0);
    mData.push_back(item);
    endInsertRows();
}

void ERadarModel::removeRadarItem(int pId)
{
    auto itr = std::find_if(mData.begin(), mData.end(),
                 [pId](ERadarItem item)
    {return item.mId == pId;});

    if(itr != mData.end())
    {
        int row = std::distance(mData.begin(), itr);
        beginRemoveRows(QModelIndex(), row, row);
        mData.erase(itr);
        endRemoveRows();
    }
}

QVariant ERadarModel::data(const QModelIndex &index, int role) const
{
    if (!hasIndex(index.row(), index.column(), index.parent()))
        return {};

    const ERadarItem &item = mData.at(index.row());
    if (role == RadarNameRole) return item.mName;
    else if (role == RadarIdRole) return item.mId;
    else if (role == LatitudeRole) return item.mCoordinate.latitude();
    else if (role == LongitudeRole ) return item.mCoordinate.longitude();
    else return QVariant{};
}

QHash<int, QByteArray> ERadarModel::roleNames() const
{
    return mRoles;
}
