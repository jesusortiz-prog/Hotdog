#ifndef SALCHICHA_H
#define SALCHICHA_H

#include "Nodo.h"

class Salchicha //cola simplemente ligada lineal sin encabezados
{
    public:
        Salchicha();
       ~Salchicha();
       bool vacia();

       void ingresarSalchicha();
       void cargarSalchicha(); //para cuando se carga el archivo
       void mostrarSalchicha();
       void eliminarSalchicha();

       Nodo* getInicio();

    protected:

    private:
        Nodo *inicio;
};

#endif // SALCHICHA_H
