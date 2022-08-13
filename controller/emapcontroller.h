#ifndef EMAPCONTROLLER_H
#define EMAPCONTROLLER_H

#include <QObject>

#include <QGeoCoordinate>

class EMapController : public QObject
{
    Q_OBJECT
public:
    explicit EMapController(QObject *parent = nullptr);

public slots:
    void onMapClicked(int pType, const QGeoCoordinate& pCoordinate);
    void onMapMouseCursorPositionChanged(const QGeoCoordinate& pCoordinate);

signals:

};

#endif // EMAPCONTROLLER_H
