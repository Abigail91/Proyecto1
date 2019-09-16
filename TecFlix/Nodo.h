//
// Created by abigail on 15/8/19.
//

#ifndef TAREA1_NODO_H
#define TAREA1_NODO_H


#include <clocale>

class Nodo {
    private:
        int valor;
        Nodo*Siguiente;
    public:

        Nodo(int v, Nodo*sig=nullptr){

            this->valor = v;
            this->Siguiente = sig;
        }
        friend class Lista_Enlazada;
};


#endif //TAREA1_NODO_H_INCLUDED
