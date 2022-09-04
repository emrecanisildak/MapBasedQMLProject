#ifndef SERVICECONTROLLER_H
#define SERVICECONTROLLER_H

#include <QObject>

class EServiceController : public QObject
{
    Q_OBJECT
public:
    EServiceController(QObject* parent = nullptr);


public slots:
    void init();
    void closeServices();


private:
    void openMapService();
    void closeMapService();
};

#endif // SERVICECONTROLLER_H
