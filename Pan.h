#ifndef PAN_H
#define PAN_H

#include "Nodo.h"

class Pan //pila doblemente ligada circular con encabezados por pepe
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
        Nodo *final;
};

#endif // PAN_H
