#include "Pan.h"
#include "Nodo.h"

Pan::Pan()
{
    inicio=nullptr;
    final=nullptr;
}

Pan::~Pan()
{
    Nodo *aux=inicio;
    do
    {
        aux=inicio;
        inicio=inicio->sig;
        delete(aux);
    }while (inicio!=NULL);
}

bool Pan::vacia()
{
    return (inicio==NULL);
}
void Pan::ingresarPanFinal()
{
    Nodo *nuevo=new Nodo();
    if(vacia()==true)
    {
        inicio=nuevo;
        final=nuevo;
        nuevo->sig=inicio;
        nuevo->ant=inicio;
    }
    else{
        final->sig=nuevo;
        nuevo->sig=inicio;
        nuevo->ant=final;
        inicio->ant=nuevo;
        final=nuevo;
    }
}

void Pan::mostrarPan()
{
    Nodo *aux=inicio;
    int contador=-1;
    if(vacia()==true)
    {
        cout<<"No hay pan en el inventario."<<endl;
        return;
    }
    cout<<"\n----------<\n";
    do
    {
        contador++;
        aux=aux->sig;
    }while(aux!=inicio);
    return;
}

void Pan::eliminarPanFinal()
{
    if(vacia()==true)
    {
        cout<<"No hay pan que eliminar"<<endl;
    }
    else{
        Nodo *aux=final;
        if(inicio->sig==inicio)
        {
            inicio=nullptr;
            final=nullptr;
        }
        else{
            final=final->ant;
            final->sig=inicio;
            inicio->ant=final;
        }
        delete(aux);
    }
}
