#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>

/**
 * @brief  Conforma la lista.
 *
 */
class Node
{
    public:
        /**
         * @brief Constructor por defecto
         *
         */
        Node();
        /**
         * @brief 
         *
         * @param T
         */
        Node(T);
        /**
         * @brief Destructor por defecto
         *
         */
        ~Node();

        Node *next; /**< TODO: describe */
        T  Data; /**< TODO: describe */

};

template<typename T>
/**
 * @brief Constructor
 *
 * @param data
 */
Node<T>:: Node(T data){

    Data = data;
    next = nullptr;
}

#endif // NODE_H
