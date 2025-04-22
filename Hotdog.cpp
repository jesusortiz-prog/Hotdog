#include "Hotdog.h"
#include "Nodo.h"

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

void Hotdog::ingresarSalchicas(){
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
    cout<<"Salchica ingresada!"<<endl;

}
void Hotdog::mostrarSalchicas(){
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
void Hotdog::eliminarSalchicas(){
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

void Hotdog::ingresarPan(){
    cout<<"pan\n";
}
void Hotdog::mostrarPan(){
    cout<<"pan\n";
}
void Hotdog::eliminarPan(){
    cout<<"pan\n";
}

void Hotdog::ingresarKetchup(){
    cout<<"ketchup\n";
}
void Hotdog::mostrarKetchup(){
    cout<<"ketchup\n";
}
void Hotdog::eliminarKetchup(){
    cout<<"ketchup\n";
}


void Hotdog::mostrarInventario(){
    mostrarSalchicas();
    mostrarPan();
    mostrarKetchup();
}

