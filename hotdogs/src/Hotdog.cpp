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
    cout<<"Ingresado correctamente!"<<endl;
}
void Hotdog::mostrarSalchicas(){
    Nodo *aux=inicio;
    int contador=0;
    if(vacia()==true){
        cout<<"No hay salchicas para mostrar\n";
        return;
    }
    cout<<"\n--------------\n";
    while(aux!=NULL){
        contador++;
        //cout<<aux->getElemento()<<endl;
        aux=aux->sig;
    }
    cout<<"Salchichas actualmente en el inventario: "<<contador<<endl;

}

void Hotdog::eliminarSalchicas(){
    Nodo *aux=inicio;
    if(vacia()==true){
        cout<<"No hay salchicas para eliminar\n";
        return;
    }else{
        cout<<"\n--------------\n";
        if(inicio->sig==NULL){
            inicio=NULL;
            cout<<"Ultima salchicha eliminada, no hay inventario\n";
            delete(aux);
        }else{
            Nodo *aux2=aux;
            while(aux->sig!=NULL){
                aux2=aux;
                aux=aux->sig;
            }
            aux2->sig=NULL;
            cout<<"Elemento eliminado de la cola"<<endl;
            delete(aux);
        }
    }
}
