#include "ewindowcontroller.h"
#include <QQmlApplicationEngine>
#include <QDebug>
#include <algorithm>
#include <QTimer>

EWindowController::EWindowController(QObject *parent)
    : QObject{parent}

{
    mWindows.insert(std::make_pair(QString{"MainWindow"},QUrl{QStringLiteral("qrc:/qml/main.qml") } ));
    mWindows.insert(std::make_pair(QString{"LoginScreen"},QUrl{QStringLiteral("qrc:/qml/screen/LoginScreen.qml") } ));


}

void EWindowController::init(QQmlApplicationEngine *qmlEngine)
{
    mQMLEngine = qmlEngine;
    connect(mQMLEngine, &QQmlApplicationEngine::objectCreated,this,
            [&](QObject *, const QUrl &url)
    {
        qDebug()<<"[QMLEngine] Object created: "<<url;
        if(url == mWindows["MainWindow"])
        {
            emit pageLoaded("MainWindow");
        }
    });

    mQMLEngine->load(mWindows["MainWindow"]);
}

bool EWindowController::openWindow(const QString &windowName)
{
    const auto itr = mWindows.find(windowName);
    if(itr != mWindows.end())
    {
         mQMLEngine->load(itr->second);
    }
    return false;
}

bool EWindowController::closeWindow(const QString &windowName)
{
    const auto itr = mWindows.find(windowName);
    if(itr != mWindows.end())
    {
        return true;
    }
    return false;
}

void EWindowController::loginConfirm(const QString &pId, const QString &pPassword)
{
    if(mId == pId
            && mPass == pPassword)
    {
        QTimer::singleShot(3000,[this](){emit loginSuccess();});
    }
    else{
         QTimer::singleShot(3000,[this](){emit loginUnsuccess();});
    }
}
