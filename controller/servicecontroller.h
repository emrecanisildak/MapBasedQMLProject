#ifndef SERVICECONTROLLER_H
#define SERVICECONTROLLER_H

#include <QObject>

class ServiceController : public QObject
{
    Q_OBJECT
public:
    ServiceController(QObject* parent = nullptr);


public slots:
    void init();
    void closeServices();


private:
    void openMapService();
    void closeMapService();
};

#endif // SERVICECONTROLLER_H
