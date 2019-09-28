#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Node.h"

using namespace std;

template <class T>

/**
 * @brief Estructura de datos para guardar las peliculas
 *
 */
class Lista
{
    public:
        /**
         * @brief Constructor por defecto
         *
         */
        Lista();


        /**
         * @brief Agrega datos a la lista
         *
         * @param Data Datos a guardar en la lista
         */
        void add_end(T Data);
        /**
         * @brief  Borra todos los datos de la lista
         *
         */
        void del_all();
        /**
         * @brief Muestra la lista en consola
         *
         */
        void print();
        /**
         * @brief Busca un dato en la lista
         *
         * @param Data Dato a buscar
         */
        void search(T Data);
        /**
         * @brief Busca un dato por indice
         *
         * @param pos indice a buscar
         * @return T Dato buscado
         */
        T get(int pos);
        Node<T> *head; /**Primer nodo de la lista*/
        int len; /**Largo de la lista*/

    private:


};

template<typename T>
/**
 * @brief 
 *
 */
Lista<T>::Lista()
{
    len = 0;
    head = NULL;
}


// Insertar al final
template<typename T>
/**
 * @brief 
 *
 * @param data
 */
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
/**
 * @brief 
 *
 */
void Lista<T>::del_all()
{
    head->next = nullptr;
    head = 0;
}

// Buscar el dato de un nodo
template<typename T>
/**
 * @brief 
 *
 * @param data_
 */
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
/**
 * @brief 
 *
 * @param pos
 * @return T Lista<T>
 */
T Lista<T>::get(int pos) {

       Node<T> *temp = this->head;

           for (int i = 0; i < pos; i++) {
               temp = temp->next;
           }
           return temp->Data;

   }
template<typename T>
/**
 * @brief 
 *
 */
void Lista<T>::print() {
        Node<T> *temp = this->head;
        while (temp != NULL) {
            std::cout << temp->Data << " ";
            temp = temp->next;
        }
    }






#endif // LIST_H
