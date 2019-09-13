#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
using namespace std;


class Archivo
{
public:
    Archivo();

public: void Leer(){
        int *actual = new int ;
          *actual = 1;
          int *siguiente = new int ;
          *siguiente = 2;
          int *anterior = new int ;
          *anterior = 0;
          int cant;
          cant = -1;
          int zoom;
          zoom = 9;
          string MatrizActual[28];
          string MatrizAnterior[28];
          string MatrizSiguiente[28];
              // Abre el archivo
              QFile file("/home/abigail/Escritorio/TecFlix/movie_metadata.csv");
              if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
                  qDebug() << "File not exists";
              } else {
                  // Hilo para tomar informacion del archivo
                  QTextStream in(&file);
                  //Lee el archivo
                  while (!in.atEnd())
                  {
                       cant = cant +1;
                      QString line = in.readLine();
                      if(cant>= (*anterior*zoom)+1 and cant<= (*actual*zoom)  ){
                          int j = 0;
                          for (QString item : line.split(",")) {
                              MatrizActual[j] = item.toStdString();
                              cout << MatrizActual[j] << "  ";
                              j++;
                          }
                          cout <<endl;
                          // cout << (cant-1)%9 << " Actual " <<endl;
                         //  cout << line.toStdString()<<endl;
                      }
                      if(cant>= ((*anterior-1)*zoom)+1 and cant<= (*anterior*zoom) and cant>0  ){
                          int j = 0;
                          for (QString item : line.split(",")) {
                              MatrizAnterior[j] = item.toStdString();
                              //cout << MatrizAnterior[j] << "  ";
                              j++;
                          }
                           //cout << cant << " Anterior " <<endl;
                           //cout << line.toStdString()<<endl;
                      }
                      if(cant>= (*actual*zoom)+1 and cant<= (*siguiente*zoom)  ){
                          int j = 0;
                          for (QString item : line.split(",")) {
                              MatrizSiguiente[j] = item.toStdString();
                             // cout << MatrizSiguiente[j] << "  ";
                              j++;
                          }
                          // cout << cant << " Siguiente " <<endl;
                           //cout << line.toStdString()<<endl;
                      }

                      // consider that the line separated by semicolons into columns

                  }

                  cout <<cant;
                  }
                  file.close();

    }
};

#endif // ARCHIVO_H
