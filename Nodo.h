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
        //string getNombre(); //no jalo
        string nombre;//chuy le puso nombre al nodo
        Nodo *sig;
        Nodo *ant;
    private:
        int elemento;



};

#endif // NODO_H
