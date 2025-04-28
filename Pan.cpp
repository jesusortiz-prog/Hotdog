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
    }while (inicio!=final);
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
        contador--;
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
        do{
        contador++;
        aux=aux->sig;
        }while(aux!=inicio);
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
