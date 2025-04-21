#include "Empleado.h"
#include "Hotdog.h"
#include "Gerente.h"

#include <cstdlib>
#include <string>
#include <iostream>

#include <string> //segun eso se necesita para los nombres

using namespace std;

Empleado::Empleado() //empleado es lista doble ligada circular- Sin encabezados COLA
{
    inicio=nullptr;
}

Empleado::~Empleado() /////////////////chuy le agrego el destructor
{
    Nodo* aux = inicio;
    Nodo* aux2 = nullptr;

    do {
        aux2 = aux->sig;
        cout << "Elemento eliminado: " << aux->getElemento() << endl;
        delete aux;
        aux = aux2;
    } while (aux != inicio);

    inicio = nullptr;
}
bool Empleado::vacia()
{
    return(inicio==nullptr);
}
void Empleado::ingresarEmpleadoFinal()
{
    Nodo* nuevo=new Nodo();
    cout<<"Ingrese nombre: "<<endl;
    cin>>nuevo->nombre; //NO QUIERE EL HDP

    if(vacia())
    {

        nuevo->sig=inicio;
        nuevo->ant=inicio->ant;
        inicio->ant=nuevo;
        nuevo->ant->sig=nuevo;
        cout<<"Empleado contratado correctamente"<<endl;
    }
    else{
        inicio=nuevo;
        inicio->sig=inicio;
        inicio->ant=inicio;


        cout<<"Empleado contratado correctamente"<<endl;
    }
}
void Empleado::eliminarEmpleadoInicio()//eliminarInicio
{
    if(vacia())
    {
        cout<<"No hay empleados para despedir"<<endl;
    }
    else{
        Nodo *aux=inicio;
        if(inicio->sig==inicio)
        {
            inicio=NULL;
        }
        else{
            inicio=inicio->sig;
            inicio->ant=aux->ant;
            aux->ant->sig=inicio;
        }
        cout<<"Empleado despedido"<<endl;
        delete (aux);
    }
}
void Empleado::mostrarEmpleado()
{
    if(vacia()==true)
    {
        cout<<"No hay empleados para mostrar"<<endl;
    }
    else{
        Nodo *aux=inicio;
        do
        {
            cout<<aux->getElemento()<<endl;
            cout<<"Nombre del empleado: "<<aux->nombre<<endl;
            aux=aux->sig;
        }while(aux!=inicio);
    }
}

void Empleado::menuEmpleado()
{
    Hotdog instancia;
    int opc;
    do{/*
        aqui mejor vender "Hotdog"
            */
        cout<<"Menu de carrito de perritos calientes\n1)Insertar\n2)Mostrar\n3)Eliminar\n4)salir."<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:{
                cout<<"Ingresando una salchicha..."<<endl;
                instancia.ingresarSalchicas();
                break;
            }
            case 2:{
                instancia.mostrarSalchicas();
                break;
            }
            case 3:{
                instancia.eliminarSalchicas();
                break;
            }
            case 4:{
                cout<<"Saliendo...\n";
                break;
            }
            default:{
                cout<<"Opcion no valida\n";
                break;
            }
        }
    }while(opc!=4);
}

