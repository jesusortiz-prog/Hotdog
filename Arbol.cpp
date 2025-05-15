#include "Arbol.h"
#include <iostream>

using namespace std;

NodoArbol::NodoArbol(float hora)
{
    this->hora=hora;
    izquierdo=nullptr;
    derecho=nullptr;
}

Arbol::~Arbol()
{
    //dtor
}

Arbol::Arbol() {
    raiz=nullptr;
}

NodoArbol* Arbol::insertar(NodoArbol* nodo, float hora) {
    if(nodo==nullptr)
    {
        return new NodoArbol(hora);
    }

    if(hora<nodo->hora)
    {
        nodo->izquierdo=insertar(nodo->izquierdo,hora);
    }else if(hora>nodo->hora){
        nodo->derecho=insertar(nodo->derecho,hora);
    }
    return nodo;
}

void Arbol::insertar(float hora) {
    raiz=insertar(raiz,hora);
}

void Arbol::recorridoInOrder(NodoArbol* nodo) {
    if (nodo!=nullptr) {
        recorridoInOrder(nodo->izquierdo);
        cout <<"Hora de entrada: "<<nodo->hora<<endl;
        recorridoInOrder(nodo->derecho);
    }
}

void Arbol::recorridoInOrder() {
    if (raiz==nullptr)
    {
        cout<<"Árbol vacío, no se puede hacer el recorrido"<<endl;
    }
    else{
        recorridoInOrder(raiz);
    }
}
