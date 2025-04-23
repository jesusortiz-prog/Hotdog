#ifndef KETCHUP_H
#define KETCHUP_H

#include "Nodo.h"

class Ketchup
{
    public:
        Ketchup();
        ~Ketchup();
        bool vacia();
        void ingresarKetchupFinal();

        void mostrarKetchup();

        void eliminarKetchupFinal();

    protected:

    private:
        Nodo *inicio;
        Nodo *final;
};

#endif // KETCHUP_H
