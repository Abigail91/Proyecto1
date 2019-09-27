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



void Archivo::Leer(int zoom, int actual, int siguiente, int anterior,string modo){


    cant = -1;
 ActualMatriz = new  Lista<Lista<string>>();
 SiguienteMatriz = new  Lista<Lista<string>>();
  AnteriorMatriz = new  Lista<Lista<string>>();
// Abre el archivo
QFile file("/home/abigail/Escritorio/TecFlix/movie_metadata.csv");


        if (modo == "Paginado"){
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
        }else{
            if (MatrizNP == nullptr){
                MatrizNP = new Lista<Lista<string>>();
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


                            cout << cant << " NP " <<endl;
                            for (QString item : line.split(",")) {
                                temp.add_end(item.toStdString());

                    }
                            temp.print();
                            cout  <<endl;
                            MatrizNP->add_end(temp);
                    }
                    for (int i = 1; i<zoom+1;i++) {
                        Lista<string> temp = MatrizNP->get(((actual-1)*zoom)+i);
                        ActualMatriz->add_end(temp);
                        cout << "Actual"<<endl;
                        temp.print();
                        cout << endl;

                     }
                    for (int i = 1; i<zoom+1;i++) {
                        Lista<string> temp = MatrizNP->get(((siguiente-1)*zoom)+i);
                        SiguienteMatriz->add_end(temp);
                        cout << "Siguiente"<<endl;
                        temp.print();
                        cout << endl;

                     }
                    if (anterior>0){
                    for (int i = 1; i<zoom+1;i++) {
                        Lista<string> temp = MatrizNP->get(((anterior-1)*zoom)+i);
                        AnteriorMatriz->add_end(temp);
                        cout << "Anterior"<<endl;
                        temp.print();
                        cout << endl;

                     }
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

            } else{
                for (int i = 1; i<zoom+1;i++) {
                    Lista<string> temp = MatrizNP->get(((actual-1)*zoom)+i);
                    ActualMatriz->add_end(temp);
                    cout << "Actual"<<endl;
                    temp.print();
                    cout << endl;

                 }
                for (int i = 1; i<zoom+1;i++) {
                    Lista<string> temp = MatrizNP->get(((siguiente-1)*zoom)+i);
                    SiguienteMatriz->add_end(temp);
                    cout << "Siguiente"<<endl;
                    temp.print();
                    cout << endl;

                 }
                if (anterior>0){
                for (int i = 1; i<zoom+1;i++) {
                    Lista<string> temp = MatrizNP->get(((anterior-1)*zoom)+i);
                    AnteriorMatriz->add_end(temp);
                    cout << "Anterior"<<endl;
                    temp.print();
                    cout << endl;

                 }
                }

            }
        }





}
