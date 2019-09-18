//
// Created by abigail on 15/8/19.
//

#ifndef TAREA1_LISTA_ENLAZADA_H
#define TAREA1_LISTA_ENLAZADA_H


#include "Nodo.h"
#include <iostream>
template <class T>

class Lista_Enlazada {
private:
    Nodo<T> *primero;
    Nodo<T> *actual;
    int len;

    bool ListaVacia() {
        return (this->primero == NULL);
    }

public:
    Lista_Enlazada() {
        this->primero = NULL;
        this->actual = NULL;
        this->len = 0;

    };

    void Insertar(T v) {
        Nodo *nuevo = new Nodo(v);
        if (ListaVacia()) {
            this->primero = nuevo;
            this->actual = nuevo;
        } else {
            Nodo *temp = this->primero;
            this->primero = nuevo;
            this->primero->Siguiente = temp;
        }
        this->len++;
    }

    void print() {
        Nodo *temp = this->primero;
        while (temp != NULL) {
            std::cout << temp->valor << "\n";
            temp = temp->Siguiente;
        }
    }

    void edit_pos(int pos, int valor) {
        Nodo *temp = this->primero;
        if (pos < this->len) {
            for (int i = 0; i < pos; i++) {
                temp = temp->Siguiente;
            }
            temp->valor = valor;
        } else {
            std::cout << "Out or range! \n";
        }
    }

    void get(int pos) {
        Nodo *temp = this->primero;
        if (pos < this->len) {
            for (int i = 0; i < pos; i++) {
                temp = temp->Siguiente;
            }
            std::cout << temp->valor << "   ";
        } else {
            std::cout << "Out or range!";
        }
    }

    void eliminar() {
        Nodo *temp = this->primero->Siguiente;
        this->primero = temp;


    }
};


#endif //TAREA1_LISTA_ENLAZADA_H
