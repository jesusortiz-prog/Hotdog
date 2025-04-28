#include "Hotdog.h"
#include "Nodo.h"
#include "Pan.h"
#include "Ketchup.h"

Hotdog::Hotdog()
{
    inicio=nullptr;
}

Hotdog::~Hotdog()
{
    Nodo *aux=inicio;
    while(aux!=NULL){
        aux=inicio;
        inicio=inicio->sig;
        delete(aux);
    }
}

bool Hotdog::vacia(){
    return(inicio==NULL);
}

void Hotdog::mostrarInventario(){
    salchicha.mostrarSalchicha();
    pan.mostrarPan();
    ketchup.mostrarKetchup();
}
