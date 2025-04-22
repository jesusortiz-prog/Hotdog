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
{   string nombre;
    int id;
    cout<<"Ingrese el nombre: "<<endl;
    cin>>nombre;
    cout<<"Ingresa la ID: "<<endl;
    cin>>id;

    Nodo* nuevo=new Nodo(nombre,id);

    if(inicio==nullptr)
    {
        inicio = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    }else{
        nuevo->sig = inicio;
        nuevo->ant = inicio->ant;  //esta logica la tenia mal antes hehe, se me hace chistoso que si me jala en el codigo que hicimos en la clase

        inicio->ant->sig = nuevo;
        inicio->ant = nuevo;
        }
    cout<<"Empleado contratado correctamente, nombre: "<<nombre<<",Id: "<<id<<endl;
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
        do{
            cout<<"Nombre del empleado: "<<aux->getNombre()<<endl;
            cout<<"Id del empleado: "<<aux->getId()<<endl;
            cout<<"----------------------"<<endl;
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

