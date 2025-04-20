#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Nodo.h"

#include <string>
#include <iostream>


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

    protected:

    private:

        int fechaIngreso;
        float nomina;
        int idEmpleado;
        Nodo* inicio;
};

#endif // EMPLEADO_H
