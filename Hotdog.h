#ifndef HOTDOG_H
#define HOTDOG_H

#include "Nodo.h" //para referenciar la clase nodo
#include "Pan.h"
#include "Ketchup.h"
#include "Salchicha.h"
//Cola simplemente ligada circular con encabezados
class Hotdog
{
    public:
        Hotdog();
        ~Hotdog();
        Salchicha salchicha;
        Pan pan;
        Ketchup ketchup;

        bool vacia();
        void insertarHotdogFinal();
        void cargarHotdog();
        void mostrarHotdogs();
        void eliminarHotdogInicio();

        void mostrarInventario(); //pienso mandar a llamar a todos los mostrar()

        void venderHotdog(); //revisar si hay suficientes ingredientes antes de vender

        Nodo* getInicio();
    private:
        Nodo *inicio;
        Nodo *final;
};

#endif // HOTDOG_H
