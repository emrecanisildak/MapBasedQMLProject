#include <QApplication>
#include <QQmlApplicationEngine>
#include <QDir>

#include "controller/econtroller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);
    EController controller;
    return app.exec();
}
