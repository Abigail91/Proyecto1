#include "lista.h"

using namespace std;

// Constructor por defecto
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

    if (!head) {
        head = new_node;
    } else {
        while (temp->next != NULL) {
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
void Lista<T>::get(int pos) {

       Node<T> *temp = this->primero;
       if (pos < this->len) {
           for (int i = 0; i < pos; i++) {
               temp = temp->Siguiente;
           }
           std::cout << temp->valor << "   ";
       } else {
           std::cout << "Out or range!";
       }
   }


template<typename T>
Lista<T>::~Lista() {}
