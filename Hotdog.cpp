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
    do
    {
        aux=inicio;
        inicio=inicio->sig;
        delete(aux);
    }while (inicio!=nullptr);
}

bool Hotdog::vacia(){
    return(inicio==nullptr);
}

void Hotdog::insertarHotdogFinal()//Preparar hotdog
{
    if(ketchup.vacia()==false && pan.vacia()==false && salchicha.vacia()==false)
    {
        Nodo *nuevo=new Nodo();
        if(vacia()==true)
        {
            inicio=nuevo;
            final=nuevo;
            nuevo->sig=inicio;
        }
        else{
            final->sig=nuevo;
            nuevo->sig=inicio;
            final=nuevo;
        }
        ketchup.eliminarKetchupFinal();
        pan.eliminarPanFinal();
        salchicha.eliminarSalchicha();
    }
    else{
        cout<<"No hay ingredientes suficientes"<<endl;
        if(ketchup.vacia())
            cout<<"Falta ketchup"<<endl;
        if(pan.vacia())
            cout<<"Falta pan"<<endl;
        if(salchicha.vacia())
            cout<<"Faltan salchichas"<<endl;
    }
}
void Hotdog::cargarHotdog()//cargar desde el archivo
{
        Nodo *nuevo=new Nodo();
        if(vacia()==true)
        {
            inicio=nuevo;
            final=nuevo;
            nuevo->sig=inicio;
        }
        else{
            final->sig=nuevo;
            nuevo->sig=inicio;
            final=nuevo;
        }
}
void Hotdog::mostrarHotdogs()
{
    Nodo *aux=inicio;
    if(vacia()==true)
    {
        cout<<"No se han preparado HotDogs"<<endl;
        return;
    }
    cout<<"\n----------\n";
    int contador=0;
    do
    {
        aux=aux->sig;
        contador++;
    }while(aux!=inicio);
    cout<<"Hay "<<contador<<" salichas listas para vender."<<endl;
    return;
}
void Hotdog::eliminarHotdogInicio()
{
    if(vacia()==true)
    {
        cout<<"No hay HotDogs que vender."<<endl;
    }
    else{
        Nodo *aux=inicio;
        if(inicio==final)
        {
            inicio=nullptr;
            final=nullptr;
        }
        else{
            inicio=inicio->sig;
            final->sig=inicio;
        }
        delete(aux);
    }
}

void Hotdog::mostrarInventario(){
    salchicha.mostrarSalchicha();
    pan.mostrarPan();
    ketchup.mostrarKetchup();
}

Nodo* Hotdog::getInicio()
{
    return inicio;
}
