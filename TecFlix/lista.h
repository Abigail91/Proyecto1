#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Node.h"
#include "Node.cpp"

using namespace std;

template <class T>

class Lista
{
    public:
        Lista();
        ~Lista();

        void add_end(T Data);
        void del_all();
        void print();
        void search(T Data);
        void get(int pos);

    private:
        Node<T> *head;
        int len;
};

#endif // LIST_H
