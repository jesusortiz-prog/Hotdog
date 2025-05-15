#include "Arbol.h"
#include <iostream>

using namespace std;

NodoArbol::NodoArbol(float hora,int id)
{
    this->hora=hora;
    this->id=id;
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

NodoArbol* Arbol::insertar(NodoArbol* nodo, float hora,int id)
{
    if(nodo==nullptr)
    {
        return new NodoArbol(hora,id);
    }

    if(hora<nodo->hora)
    {
        nodo->izquierdo=insertar(nodo->izquierdo,hora,id);
    }else if(hora>nodo->hora){
        nodo->derecho=insertar(nodo->derecho,hora,id);
    }
    return nodo;
}

void Arbol::insertar(float hora,int id)
{
    raiz=insertar(raiz,hora,id);
}

void Arbol::recorridoInOrder(NodoArbol* nodo)
{
    if(nodo!=nullptr)
    {
        recorridoInOrder(nodo->izquierdo);
        cout<<"Hora de entrada: "<<nodo->hora<<endl;
        cout<<"Id del empleado: "<<nodo->id<<endl;
        recorridoInOrder(nodo->derecho);
    }
}

void Arbol::recorridoInOrder() {
    if (raiz==nullptr)
    {
        cout<<"�rbol vac�o, no se puede hacer el recorrido"<<endl;
    }
    else{
        recorridoInOrder(raiz);
    }
}
void Arbol::imprimirArbol(NodoArbol* nodo,int espacio,int incremento)
{
    if(raiz==nullptr)
    {
        cout<<"�rbol vac�o"<<endl;
    }else{
        if(nodo==nullptr)
            return;
        //incrementa el espacio entre niveles
        espacio += incremento;
        //sub�rbol derecho
        imprimirArbol(nodo->derecho,espacio,incremento);
        //imprimir el nodo actual
        cout<<endl;
        for(int i=incremento;i<espacio;i++)
            cout<<" ";
        cout<<nodo->hora<<" (ID: "<<nodo->id<<")"<<endl;
        //sub�rbol izquierdo
        imprimirArbol(nodo->izquierdo,espacio,incremento);
    }
}
