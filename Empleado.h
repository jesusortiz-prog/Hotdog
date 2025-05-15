#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Nodo.h"
#include "Hotdog.h"
#include "Arbol.h"
#include "Caja.h"
#include <string>
#include <iostream>

using namespace std;

class Empleado
{
    public:
        Empleado();
        ~Empleado();

        Hotdog *instancia;
        Arbol *arbol;
        Caja *caja;

        bool vacia();

        bool id_unico(int id);

        void ingresarEmpleadoFinal();
        void mostrarEmpleado();
        void eliminarEmpleadoInicio();

        void menuEmpleado();

        void setInventario(Hotdog*,Caja*);

        void guardarEmpleadosArchivo();
        void cargarEmpleados();

        void shellsort();
        void busquedaBinaria();


        Nodo *inicio;
};

#endif // EMPLEADO_H

