#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Nodo.h"
#include "Hotdog.h"

#include <string>
#include <iostream>

using namespace std;

class Empleado
{
    public:
        Empleado();
        ~Empleado();

        Hotdog instancia;

        bool vacia();

        bool id_unico(int id);

        void ingresarEmpleadoFinal();

        void mostrarEmpleado();

        void eliminarEmpleadoInicio();

        void menuEmpleado();

        void quicksort();

        Nodo *inicio;
};

#endif // EMPLEADO_H

