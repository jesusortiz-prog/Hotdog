#ifndef GERENTE_H
#define GERENTE_H

#include "Hotdog.h"

#include "Nodo.h"
#include "Empleado.h"

#include <string>
#include <iostream>


using namespace std;

class Gerente
{
    public:
        Gerente();
        ~Gerente();
        Empleado empleado;
        Hotdog hotdog;

        void menuGerente();

        void subEmpleados();   //submenus agregados por chuy
        void subInventario();

        void guardarInventario();
        void cargarInventario();

        void quicksort();

    private:
        string nombre;
};

#endif // GERENTE_H

