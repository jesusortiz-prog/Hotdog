#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>

using namespace std;

class Nodo
{
    public:
        Nodo();
        int getElemento();
        Nodo *sig;
        Nodo *ant;
        char nombre[20];

    private:
        int elemento;

};

#endif // NODO_H
