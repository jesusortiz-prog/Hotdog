#ifndef PAN_H
#define PAN_H

#include "Nodo.h"
// PILA SIMPLE LINEAL SIN ENCABEZADOS
class Pan{
    public:
        Pan();
        ~Pan();
        bool vacia();
        void ingresarPanFinal();
        void cargarPan();
        void mostrarPan();

        void eliminarPanFinal();

        Nodo* getInicio();

    protected:

    private:
        Nodo *inicio;
};

#endif // PAN_H
