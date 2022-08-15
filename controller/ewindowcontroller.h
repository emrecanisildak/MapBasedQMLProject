#ifndef EWINDOWCONTROLLER_H
#define EWINDOWCONTROLLER_H

#include <QObject>
#include <map>
#include <QUrl>

class QQmlApplicationEngine;

class EWindowController : public QObject
{
    Q_OBJECT
public:
    explicit   EWindowController(QObject *parent = nullptr);
    void       init(QQmlApplicationEngine *qmlEngine);

public slots:
    bool       openWindow(const QString& windowName);
    bool       closeWindow(const QString& windowName);

    void       loginConfirm(const QString& pId, const QString& pPassWord);

signals:
     void loginSuccess();
     void loginUnsuccess();
     void pageLoaded(const QString& pName);

private:
    QQmlApplicationEngine* mQMLEngine;
    std::map<QString,QUrl> mWindows;


    QString mId = "admin";
    QString mPass = "admin";
};

#endif // EWINDOWCONTROLLER_H
