#ifndef HOTDOG_H
#define HOTDOG_H

#include "Nodo.h" //para referenciar la clase nodo

class Hotdog
{
    public:
        Hotdog();
        ~Hotdog();
        bool vacia();
        void ingresarSalchicas(); //primero intentare con este

        void ingresarPan();
        void ingresarKetchup();

        void mostrarInventario(); //pienso mandar a llamar a todos los mostrar()
        void mostrarSalchicas();
        void mostrarKetchup();
        void mostrarPan();

        void eliminarSalchicas();
        void eliminarPan();
        void eliminarKetchup();


    private:
        Nodo *inicio;
};

#endif // HOTDOG_H
