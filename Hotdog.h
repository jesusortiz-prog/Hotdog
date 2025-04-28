#ifndef HOTDOG_H
#define HOTDOG_H

#include "Nodo.h" //para referenciar la clase nodo
#include "Pan.h"
#include "Ketchup.h"
#include "Salchicha.h"

class Hotdog
{
    public:
        Hotdog();
        ~Hotdog();
        Salchicha salchicha;
        Pan pan;
        Ketchup ketchup;

        bool vacia();//primero intentare con este

        void mostrarInventario(); //pienso mandar a llamar a todos los mostrar()

        void venderHotdog(); //revisar si hay suficientes ingredientes antes de vender

    private:
        Nodo *inicio;
};

#endif // HOTDOG_H
