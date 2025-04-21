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
        void ingresarPan(); //falta
        void ingresarKetchup(); //falta

        void mostrarInventario(); //pienso mandar a llamar a todos los mostrar()
        void mostrarSalchicas();
        void mostrarPan();
        void mostrarKetchup();

        void eliminarSalchicas();
        void eliminarPan(); //falta
        void eliminarKetchup(); //falta


    private:
        Nodo *inicio;
};

#endif // HOTDOG_H
