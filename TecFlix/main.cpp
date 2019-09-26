#include "mainwindow.h"
#include <QApplication>
#include<QtGui>
#include<QtCore>
#include "Archivo.h"
#include "lista.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = new MainWindow;

    w->recargar();
    w->MostrarPaginas();

    w->show();


    return a.exec();
}
