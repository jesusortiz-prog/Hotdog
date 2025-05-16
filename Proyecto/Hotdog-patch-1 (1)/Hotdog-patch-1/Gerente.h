#ifndef GERENTE_H
#define GERENTE_H

#include "Hotdog.h"
#include "Caja.h"
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
        Caja caja;

        void menuGerente();

        void subEmpleados();   //submenus agregados por chuy
        void subInventario();

        void guardarInventario();
        void cargarInventario();

        void quicksort();

        //cosas para grafo=
        static const int NUM_CIUDADES;
        string ciudades[4];         // Usamos valor fijo directamente aqui
        int grafo[4][4];                 // Tambien aqui
        void inicializarGrafo();
        void mostrarRutas();
        int obtenerIndiceCiudad(string& nombre);


    private:
        string nombre;
};

#endif // GERENTE_H

