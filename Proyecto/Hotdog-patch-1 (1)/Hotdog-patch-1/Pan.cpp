#include "Pan.h"
#include "Nodo.h"

Pan::Pan()
{
    inicio=nullptr;
}

Pan::~Pan()
{
    Nodo *aux=inicio;
    while (inicio!=nullptr)
    {
        aux=inicio;
        inicio=inicio->sig;
        delete(aux);
    }
}

bool Pan::vacia()
{
    return (inicio==NULL);
}
void Pan::ingresarPanFinal()
{
    int contador;
    cout<<"Ingresa la cantidad de panes que vas a agregar"<<endl;
    cin>>contador;
    cout<<"Se ingresaron "<<contador<<" panes!!!"<<endl;
    system("cls");
    while (contador!=0)
    {
        Nodo *nuevo=new Nodo();
        if(vacia()==true)
        {
            inicio=nuevo;
        }
        else{
            Nodo *aux=inicio;
            while(aux->sig!=NULL)
            {
                aux=aux->sig;
            }
            aux->sig=nuevo;
        }
        contador--;
    }
}
void Pan::cargarPan()
{
        Nodo *nuevo=new Nodo();
        if(vacia()==true)
        {
            inicio=nuevo;
        }
        else{
            Nodo *aux=inicio;
            while(aux->sig!=NULL)
            {
                aux=aux->sig;
            }
            aux->sig=nuevo;
        }
}

void Pan::mostrarPan()
{
    Nodo *aux=inicio;
    if(vacia()==true){
        cout<<"No hay panes para mostrar\n";
        cout<<"\n--------------\n";
    }else{
        int contador=0;
        while (aux!=nullptr)
        {
            contador++;
            aux=aux->sig;
        }
        cout<<"Total de panes en inventario: "<<contador<<endl;
        cout<<"\n--------------\n";
    }
}

void Pan::eliminarPanFinal()
{
    if(vacia()==true)
    {
        cout<<"No hay pan que eliminar"<<endl;
    }
    else{
        Nodo *aux=inicio;
        if(inicio->sig==nullptr)
        {
            inicio=nullptr;
        }
        else{
            Nodo *aux2;
            while(aux->sig!=NULL)
            {
                aux2=aux;
                aux=aux->sig;
            }
            aux2->sig=NULL;
        }
        delete(aux);
    }
}

Nodo* Pan::getInicio()
{
    return inicio;
}
