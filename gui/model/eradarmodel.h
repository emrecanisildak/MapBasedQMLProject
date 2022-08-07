#ifndef ERADARMODEL_H
#define ERADARMODEL_H

#include <QAbstractItemModel>
#include <vector>
#include <QHash>
#include "gui/item/eradaritem.h"

enum MyRoles {
    RadarNameRole = Qt::UserRole + 1,
    RadarIdRole,
    LatitudeRole,
    LongitudeRole,
    SourcePathRole,
};



class ERadarModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ERadarModel(QObject* parent = nullptr);

    int                    rowCount(const QModelIndex& parent = QModelIndex()) const override;
    void                   addRadarItem(const ERadarItem& item);
    void                   removeRadarItem(int pId);
    QVariant               data(const QModelIndex &index, int role) const override;
    QHash<int,QByteArray>  roleNames() const override;

private:
    std::vector<ERadarItem> mData;
    QHash<int,QByteArray> mRoles;

};

#endif // ERADARMODEL_H
