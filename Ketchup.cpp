#include "Ketchup.h"
#include "Nodo.h"

Ketchup::Ketchup()
{
    inicio=nullptr;
    final=nullptr;
}

Ketchup::~Ketchup()
{
    Nodo *aux=inicio;
    do
    {
        aux=inicio;
        inicio=inicio->sig;
        delete(aux);
    }while (inicio!=final);
}

bool Ketchup::vacia()
{
    return (inicio==NULL);
}
void Ketchup::ingresarKetchupFinal()
{
    int contador;
    cout<<"Ingresa la cantidad de sobres de Ketchup que vas a agregar"<<endl;
    cin>>contador;
    cout<<"Se ingresaron "<<contador<<" sobres de Ketchup!!!"<<endl;
    system("cls");
    while(contador!=0)
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

void Ketchup::cargarKetchup()
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

void Ketchup::mostrarKetchup()
{
      Nodo *aux=inicio;
    if(vacia()==true){
        cout<<"No hay ketchup para mostrar\n";
        cout<<"\n--------------\n";
    }else{
        int contador=0;
        do{
        contador++;
        aux=aux->sig;
        }while(aux!=inicio);
        cout<<"Total de ketchup en inventario: "<<contador<<endl;
        cout<<"\n--------------\n";
    }
}

void Ketchup::eliminarKetchupFinal()
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

Nodo* Ketchup::getInicio()
{
    return inicio;
}


