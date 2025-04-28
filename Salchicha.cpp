#include "Salchicha.h"
#include "Nodo.h"

Salchicha::Salchicha()
{
    inicio=nullptr;
}

Salchicha::~Salchicha()
{
    //dtor
}

bool Salchicha::vacia()
{
    return(inicio==nullptr);
}

void Salchicha::ingresarSalchicha()
{
    int contador;
    cout<<"Ingresa la cantidad de salchichas a agregar"<<endl;
    cin>>contador;
    cout<<"Se ingresaron "<<contador<<" salchichas!!!"<<endl;
    while(contador!=0)
    {
        Nodo *temporal=new Nodo();
        if(vacia()){
            inicio=temporal;
        }else{
            Nodo *aux=inicio;
            while(aux->sig!=NULL){
                aux=aux->sig;
            }
            aux->sig=temporal;
        }
        contador--;
    }

}
void Salchicha::mostrarSalchicha()
{
    Nodo *aux=inicio;
    if(vacia()==true){
        cout<<"No hay salchicas para mostrar\n";
        cout<<"\n--------------\n";
    }else{
        int contador=0;

        while(aux!=NULL){
        contador++;
        aux=aux->sig;
        }
        cout<<"Total de salchicas en inventario: "<<contador<<endl;
        cout<<"\n--------------\n";
    }
}
void Salchicha::eliminarSalchicha()
{
    Nodo *aux=inicio;
    if(vacia()){
        cout<<"No hay salchicas para eliminar\n";
        cout<<"\n--------------\n";
    }else{
        cout<<"\n--------------\n";
        if(inicio->sig==NULL){
            inicio=NULL;
            cout<<"Salchica eliminada de la cola\n";
            cout<<"\n--------------\n";
            delete(aux);
        }else{
            Nodo *aux2=aux;
            while(aux->sig!=NULL){
                aux2=aux;
                aux=aux->sig;
            }
            aux2->sig=NULL;
            cout<<"Elemento eliminado de la cola."<<endl;
            delete(aux);
        }
    }
}
