#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Nodo.h"

#include <string>
#include <iostream>

#include "Nodo.h"
using namespace std;

class Empleado
{
    public:
        Empleado();
        ~Empleado();
        bool vacia();

        void ingresarEmpleadoFinal();

        void mostrarEmpleado();

        void eliminarEmpleadoInicio();

        void menuEmpleado();

/*
        int fechaIngreso;
        float nomina;
        int idEmpleado;
        string nombre;
*/
        Nodo *inicio;
};

#endif // EMPLEADO_H

