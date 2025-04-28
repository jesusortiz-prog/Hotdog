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
       void mostrarSalchicha();
       void eliminarSalchicha();

    protected:

    private:
        Nodo *inicio;
};

#endif // SALCHICHA_H
