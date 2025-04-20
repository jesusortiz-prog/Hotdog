#include "Nodo.h"

#include <iostream>

Nodo::Nodo(int element)
{
    elemento=element;
    sig=NULL;
}

int Nodo::getElemento(){
    return elemento;
}


