#include "eplotmodel.h"

#include <algorithm>
#include <chrono>
#include <QDebug>


EPlotModel::EPlotModel(QObject* parent )
{
    mRoles[PlotIdRole]        = "id";
    mRoles[LatitudeRole]      = "latitude";
    mRoles[LongitudeRole]     = "longitude";

    connect(&mPlotTimer,&QTimer::timeout,
            this,[&](){removePlot();}) ;

    mPlotTimer.start(100);
}

int EPlotModel::rowCount(const QModelIndex &parent) const
{
    return mData.size();
}

void EPlotModel::addPlot(const EPlotItem &item)
{
    beginInsertRows(QModelIndex(), 0, 0);
    mData.push_back(item);
    endInsertRows();
}

void EPlotModel::removePlot()
{
    using namespace std::chrono;
    auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    auto itr = std::remove_if(mData.begin(), mData.end(),
                 [=](EPlotItem item)
    {  return (now-item.mTimeStamp) > PLOT_TIMEOUT_DURATION;});

    if(itr != mData.end())
    {
        beginRemoveRows(QModelIndex(), std::distance(mData.begin(), itr), std::distance(itr, mData.end()));
        mData.erase(itr,mData.end());
        endRemoveRows();
    }
}

QVariant EPlotModel::data(const QModelIndex &index, int role) const
{
    if (!hasIndex(index.row(), index.column(), index.parent()))
        return {};

    const EPlotItem &item = mData.at(index.row());
    if (role == PlotIdRole) return item.mId;
    else if (role == LatitudeRole) return item.mCoordinate.latitude();
    else if (role == LongitudeRole ) return item.mCoordinate.longitude();
    else return QVariant{};
}

QHash<int, QByteArray> EPlotModel::roleNames() const
{
    return mRoles;
}

