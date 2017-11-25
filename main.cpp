#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <thread>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1280,720);

    w.show();
    return a.exec();
}
