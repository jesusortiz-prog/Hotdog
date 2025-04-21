#include "Nodo.h"
#include <iostream>

using namespace std;

Nodo::Nodo(){ //capaz en lugar de tener int elemento, mejor string name;
    sig=nullptr;
    ant=nullptr;
}
int Nodo::getElemento(){
    return elemento;
}


