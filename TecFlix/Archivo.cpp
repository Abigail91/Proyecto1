#include "Archivo.h"

#include "lista.h"
#include <iostream>
using namespace std;


Archivo::Archivo()
{
    cant = -1;
    ActualMatriz = new  Lista<Lista<string>>();
    SiguienteMatriz = new  Lista<Lista<string>>();
     AnteriorMatriz = new  Lista<Lista<string>>();


}



void Archivo::Leer(int zoom, int actual, int siguiente, int anterior){


    cant = -1;
 ActualMatriz = new  Lista<Lista<string>>();
 SiguienteMatriz = new  Lista<Lista<string>>();
  AnteriorMatriz = new  Lista<Lista<string>>();


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
                Lista<string> temp;
                if(cant>= (anterior*zoom)+1 and cant<= (actual*zoom)  ){

                    cout << cant << " Actual " <<endl;
                    for (QString item : line.split(",")) {
                        temp.add_end(item.toStdString());

                    }
                    temp.print();
                    ActualMatriz->add_end(temp);
                    cout <<endl;
                }
                if(cant>= ((anterior-1)*zoom)+1 and cant<= (anterior*zoom) and cant>0  ){
                    cout << cant << " Anterior " <<endl;
                    for (QString item : line.split(",")) {

                        temp.add_end(item.toStdString());

                    }
                    temp.print();
                    AnteriorMatriz->add_end(temp);
                    cout <<endl;

                }
                if(cant>= (actual*zoom)+1 and cant<= (siguiente*zoom)  ){
                    cout << cant << " Siguiente " << endl;
                    for (QString item : line.split(",")) {
                        temp.add_end(item.toStdString());

                    }
                    temp.print();
                    SiguienteMatriz->add_end(temp);
                    cout <<endl;

                }

                // consider that the line separated by semicolons into columns

            }
            if(cant%9 == 0){
            cantPag = cant/9;

            }else{
               cantPag = (cant/9)+1;
            }
            cout <<cant;
            cout <<cantPag;

            }
            file.close();





}
