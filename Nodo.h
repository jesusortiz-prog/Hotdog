#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>

using namespace std;

class Nodo
{
    public:
        Nodo(int elemento);
        int getElemento();
        Nodo *sig;
    private:
        int elemento;

};

#endif // NODO_H
