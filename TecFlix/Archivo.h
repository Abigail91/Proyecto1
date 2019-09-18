#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include <QGridLayout>
#include <cstring>

using namespace std;


class Archivo
{
public:
    Archivo();
    int can = -1;
    int columna_dinamica = 28;
    string **MatrizActual = new string *[columna_dinamica];
    string **MatrizAnterior= new string *[columna_dinamica];
    string **MatrizSiguiente= new string *[columna_dinamica];



public: void Leer(int zoom,int actual,int siguiente,int anterior);


};

#endif // ARCHIVO_H
