#ifndef GERENTE_H
#define GERENTE_H

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

        void menuGerente();

    protected:

    private:
        string nombre;
};

#endif // GERENTE_H
