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


/**
 * @brief Esta clase se encarga de gestionar los datos del programa.
 */
class Archivo
{
public:
    /**
     * @brief Constructor por defecto
     *
     */
    Archivo();
    int cant; /**Cantidad de peliculas*/
    Lista<Lista<string>> *ActualMatriz; /**Datos de pagina actual */
    Lista<Lista<string>> *SiguienteMatriz; /**Datos de pagina siguiente */
    Lista<Lista<string>> *AnteriorMatriz; /**Datos de pagina anterior */
    Lista<Lista<string>> *MatrizNP = nullptr; /**Datos de modo no paginado */
    int cantPag; /**Cantidad de paginas */





    /**
     * @brief Lee el archivo e incluye los datos a la memoria del programa.
     * @param Zoom cantidad de datos por pagina.
     * @param actual numero de la pagina actual.
     * @param siguiente numero de la pagina siguiente.
     * @param anterior numero de la pagina anterior.
     * @param modo forma en la que el cliente quiere ver los datos, paginados o no paginados.
     */
public: void Leer(int zoom,int actual,int siguiente,int anterior,string modo);


};

#endif // ARCHIVO_H
