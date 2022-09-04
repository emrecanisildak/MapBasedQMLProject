#ifndef ETRACKMODEL_H
#define ETRACKMODEL_H

#include <QAbstractItemModel>
#include <vector>
#include <QHash>
#include <QTimer>
#include "gui/item/etrackitem.h"


class ETrackModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MyRoles {
        TrackIdRole,
        SourceRadarIdRole,
        LatitudeRole,
        LongitudeRole,
        AzimuthRole,
        ElevationRole,
        RangeRole,
        SpeedRole,
        InfoTextRole
    };


    ETrackModel(QObject* parent = nullptr);

    int                    rowCount(const QModelIndex& parent = QModelIndex()) const override;
    void                   updateTrack(const ETrackItem& item);
    QVariant               data(const QModelIndex &index, int role) const override;
    QHash<int,QByteArray>  roleNames() const override;

private:
    std::vector<ETrackItem> mData;
    QHash<int,QByteArray> mRoles;

};

#endif // ETRACKMODEL_H
