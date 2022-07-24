#include "mainwindow.h"

#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qDebug()<<"Deneme commit 2";

    return a.exec();
}
