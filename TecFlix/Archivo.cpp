#include "Archivo.h"

#include "lista.h"
#include <iostream>
#include <cstring>
using namespace std;


Archivo::Archivo()
{

}

void Archivo::Leer(int zoom, int actual, int siguiente, int anterior){

    int cant;
     int columna_dinamica = 28;
    cant = -1;
    list<list<string>> ActualList;
    string **MatrizActual = new string *[columna_dinamica];
    string **MatrizAnterior= new string *[columna_dinamica];
    string **MatrizSiguiente= new string *[columna_dinamica];

        for(int i = 0; i <zoom;i++)   {
          MatrizActual[i] = new string[columna_dinamica];
          MatrizAnterior[i] = new string[columna_dinamica];
          MatrizSiguiente[i] = new string[columna_dinamica];
        }

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
                if(cant>= (anterior*zoom)+1 and cant<= (actual*zoom)  ){
                    int j = 0;

                    cout << cant << " Actual " <<endl;
                    for (QString item : line.split(",")) {
                        MatrizActual[cant%zoom][j] = item.toStdString();








                        //cout << MatrizActual[cant%zoom][j]<< " ";
                        j++;
                    }

                    cout <<endl;
                    // cout << (cant-1)%9 << " Actual " <<endl;
                   //  cout << line.toStdString()<<endl;
                }
                if(cant>= ((anterior-1)*zoom)+1 and cant<= (anterior*zoom) and cant>0  ){
                    int j = 0;
                    cout << cant << " Anterior " <<endl;
                    for (QString item : line.split(",")) {
                        MatrizAnterior[cant%zoom][j]  = item.toStdString();
                        cout << MatrizAnterior[cant%zoom][j]<<" ";
                        j++;
                    }
                     //cout << cant << " Anterior " <<endl;
                     //cout << line.toStdString()<<endl;
                }
                if(cant>= (actual*zoom)+1 and cant<= (siguiente*zoom)  ){
                    cout << cant << " Siguiente " << endl;
                    int j = 0;
                    for (QString item : line.split(",")) {
                        MatrizSiguiente[cant%zoom][j]  = item.toStdString();
                       cout << MatrizActual[cant%zoom][j]<<" ";
                        j++;
                    }
                     cout << endl;
                }

                // consider that the line separated by semicolons into columns

            }

            cout <<cant;
            }
            file.close();



}
