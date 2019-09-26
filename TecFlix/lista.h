#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Node.h"

using namespace std;

template <class T>

class Lista
{
    public:
        Lista();


        void add_end(T Data);
        void del_all();
        void print();
        void search(T Data);
        T get(int pos);
        Node<T> *head;
        int len;

    private:


};

template<typename T>
Lista<T>::Lista()
{
    len = 0;
    head = NULL;
}


// Insertar al final
template<typename T>
void Lista<T>::add_end(T data)
{
    Node<T> *new_node = new Node<T> (data);
    Node<T> *temp = head;

    if (head == nullptr) {
        head = new_node;
    } else {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    len++;

}


// Eliminar todos los nodos
template<typename T>
void Lista<T>::del_all()
{
    head->delete_all();
    head = 0;
}

// Buscar el dato de un nodo
template<typename T>
void Lista<T>::search(T data_)
{
    Node<T> *temp = head;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->data == data_) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->next;
        cont++;
    }

    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}
template<typename T>
T Lista<T>::get(int pos) {

       Node<T> *temp = this->head;

           for (int i = 0; i < pos; i++) {
               temp = temp->next;
           }
           return temp->Data;

   }
template<typename T>
void Lista<T>::print() {
        Node<T> *temp = this->head;
        while (temp != NULL) {
            std::cout << temp->Data << " ";
            temp = temp->next;
        }
    }






#endif // LIST_H
