#include "etrackmodel.h"

ETrackModel::ETrackModel(QObject *parent)
{
    mRoles[TrackIdRole]        = "id";
    mRoles[SourceRadarIdRole]  = "radarSource";
    mRoles[LatitudeRole]       = "latitude";
    mRoles[LongitudeRole]      = "longitude";
    mRoles[AzimuthRole]        = "azimuth";
    mRoles[ElevationRole]      = "elevation";
    mRoles[RangeRole]          = "range";
    mRoles[SpeedRole]          = "speed";
    mRoles[InfoTextRole]       = "infotext";
}

int ETrackModel::rowCount(const QModelIndex &parent) const
{
    return mData.size();
}

void ETrackModel::updateTrack(const ETrackItem &pItem)
{
    const auto& it = std::find_if(mData.begin(), mData.end(),[&](const ETrackItem &item){return item.mId == pItem.mId;});

    // UPDATE DATA
    if(it != mData.end())
    {
        TrackStatus pStatus = pItem.mTrackStatus;
        if(pStatus == TrackStatus::FALL)
        {
            // Düşür
            beginRemoveRows(QModelIndex(), std::distance(mData.begin(), it), std::distance(it, mData.end()));
            mData.erase(it,mData.end());
            endRemoveRows();
        }
        else{
            // Update
            QVector<int> roles = {TrackIdRole,SourceRadarIdRole, LatitudeRole, LongitudeRole,AzimuthRole,ElevationRole,RangeRole,SpeedRole,InfoTextRole};
            emit dataChanged(index(std::distance(mData.begin(), it), 0), index(std::distance(mData.begin(), it), 0), roles); // only change the index(row,column)
        }
    }
    // ADD NEW Track Data
    else{
        beginInsertRows(QModelIndex(), 0, 0);
        mData.push_back(pItem);
        endInsertRows();
    }
}

QVariant ETrackModel::data(const QModelIndex &index, int role) const
{
    if (!hasIndex(index.row(), index.column(), index.parent()))
        return {};

    const ETrackItem &item = mData.at(index.row());
    if (role == TrackIdRole) return item.mId;
    else if(role == SourceRadarIdRole) return item.mSourceRadarId;
    else if(role == AzimuthRole) return item.mAER.mAzimuth;
    else if(role == ElevationRole) return item.mAER.mElevation;
    else if(role == RangeRole) return item.mAER.mRange;
    else if(role == SpeedRole) return item.mSpeed;
    else if (role == LatitudeRole) return item.mCoordinate.latitude();
    else if (role == LongitudeRole ) return item.mCoordinate.longitude();
    else if (role == InfoTextRole ) return item.getInfoText();
    else return QVariant{};
}

QHash<int, QByteArray> ETrackModel::roleNames() const
{
    return mRoles;
}
