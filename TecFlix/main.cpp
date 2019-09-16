#include "mainwindow.h"
#include <QApplication>
#include<QtGui>
#include<QtCore>
#include<QLayout>
#include<QLabel>
#include "Archivo.h"
#include <math.h>
#include<QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = new MainWindow;
    w->recargar();


    w->show();

    return a.exec();
}
