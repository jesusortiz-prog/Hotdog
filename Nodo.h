#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
/// /// ///

using namespace std;

class Nodo
{
    public:
        Nodo();
        Nodo(string nombre,int id);

        int getElemento();
        string getNombre();
        int getId();
        //Empleado *getEmpleado();

        //string getNombre(); //no jalo
        //string nombre;//chuy le puso nombre al nodo
        Nodo *sig;
        Nodo *ant;
    private:
        string nombre;
        int id;
        int elemento;
        string tipo;
};

#endif // NODO_H
