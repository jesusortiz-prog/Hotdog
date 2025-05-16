#ifndef KETCHUP_H
#define KETCHUP_H

#include "Pan.h"
#include "Ketchup.h"


#define MAX 10

class Ketchup //pila doblemente ligada circular con encabezados
{
    public:
        Ketchup();
        ~Ketchup();
        bool vacia();
        void ingresarKetchupFinal();
        void cargarKetchup();
        void mostrarKetchup();

        void eliminarKetchupFinal();
        Nodo* getInicio();



    protected:

    private:
        Nodo *inicio;
        Nodo *final;
};

#endif // KETCHUP_H
