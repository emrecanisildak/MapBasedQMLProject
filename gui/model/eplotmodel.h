#ifndef EPLOTMODEL_H
#define EPLOTMODEL_H

#include <QAbstractItemModel>
#include <vector>
#include <QHash>
#include <QTimer>
#include "gui/item/eplotitem.h"


class EPlotModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MyRoles {
        PlotIdRole,
        LatitudeRole,
        LongitudeRole,
    };


    EPlotModel(QObject* parent = nullptr);

    int                    rowCount(const QModelIndex& parent = QModelIndex()) const override;
    void                   addPlot(const EPlotItem& item);
    void                   removePlot();
    QVariant               data(const QModelIndex &index, int role) const override;
    QHash<int,QByteArray>  roleNames() const override;

private:
    std::vector<EPlotItem> mData;
    QHash<int,QByteArray> mRoles;
    QTimer mPlotTimer;

    static constexpr uint64_t PLOT_TIMEOUT_DURATION = 3500;
};

#endif // EPLOTMODEL_H
