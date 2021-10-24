#include "mainwindow.h"

#include <QApplication>

int puntos = 0 ;        //Variable global para los puntos

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
