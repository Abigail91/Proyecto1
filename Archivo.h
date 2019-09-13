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
          *actual = 9;
          int *siguiente = new int ;
          *siguiente = 10;
          int *anterior = new int ;
          *anterior = 8;
          int cant;
          cant = 0;
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
                      if(cant>= (*anterior*9)+1 and cant<= (*actual*9)  ){
                           //cout << cant << " Actual " <<endl;
                         //  cout << line.toStdString()<<endl;
                      }
                      if(cant>= ((*anterior-1)*9)+1 and cant<= (*anterior*9)  ){
                           //cout << cant << " Anterior " <<endl;
                           //cout << line.toStdString()<<endl;
                      }
                      if(cant>= (*actual*9)+1 and cant<= (*siguiente*9)  ){
                          // cout << cant << " Siguiente " <<endl;
                           //cout << line.toStdString()<<endl;
                      }
                      // consider that the line separated by semicolons into columns
                      for (QString item : line.split(",")) {
                      }
                  }
                  cout <<cant;
                  }
                  file.close();

    }
};

#endif // ARCHIVO_H
