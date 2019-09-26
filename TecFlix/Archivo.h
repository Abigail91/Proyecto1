#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <QApplication>
#include <QGridLayout>
#include <cstring>
#include "lista.h"

using namespace std;


class Archivo
{
public:
    Archivo();
    int cant;
    Lista<Lista<string>> *ActualMatriz;
    Lista<Lista<string>> *SiguienteMatriz;
    Lista<Lista<string>> *AnteriorMatriz;
    int cantPag;




public: void Leer(int zoom,int actual,int siguiente,int anterior);


};

#endif // ARCHIVO_H
