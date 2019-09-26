#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>

class Node
{
    public:
        Node();
        Node(T);
        ~Node();

        Node *next;
        T  Data;

};

template<typename T>
Node<T>:: Node(T data){

    Data = data;
    next = nullptr;
}

#endif // NODE_H
