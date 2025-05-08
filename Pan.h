#ifndef PAN_H
#define PAN_H

#include "Nodo.h"
// HACERLO PILA SIMPLE LINEAL SIN ENCABEZADOS
class Pan //pila doblemente ligada circular con encabezados
{
    public:
        Pan();
        ~Pan();
        bool vacia();
        void ingresarPanFinal();

        void mostrarPan();

        void eliminarPanFinal();

    protected:

    private:
        Nodo *inicio;
};

#endif // PAN_H
