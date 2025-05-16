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
        Nodo(string nombre,int id);  //sobrecarga de operadores para el *inventario* y para *empleados*

        int getElemento();
        string getNombre();
        int getId();
        void setId(int id);
        void setNombre(string nombre);


        Nodo *sig;
        Nodo *ant;
    private:
        string nombre;
        int id;
        int elemento;
        string tipo;
};

#endif // NODO_H
