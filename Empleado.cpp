#include "Empleado.h"
#include "Hotdog.h"
#include "Gerente.h"

#include <cstdlib>
#include <string>
#include <iostream>

#include <string>

using namespace std;

Empleado::Empleado() //cola doble ligada circular- Sin encabezados
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

bool Empleado::id_unico(int id)
{
    Nodo *aux=inicio;
    if(vacia())
    {
        return true;
    }
    else{
        do{
            if(aux->getId()==id)
            {
                return false;
            }
            aux=aux->sig;
        }while(aux!=inicio);
    }
    return true;
}

void Empleado::ingresarEmpleadoFinal()
{
    int id;
    cout<<"Ingresa la ID: "<<endl;
    cin>>id;
    if(!id_unico(id))
    {
        cout<<"ID repetido, porfavor intenta otro"<<endl;
    }
    else
    {
        string nombre;
        cout<<"Ingrese el nombre: "<<endl;
        cin>>nombre;
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
    int opc;
    do{/*
        aqui mejor vender "Hotdog"
            */
        cout<<"Menu de carrito de perritos calientes\n1)Preparar HotDog (insertar)\n2)Mostrar inventario y HotDogs preparados\n3)Vender HotDog (eliminar)\n4)Salir."<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:{
                cout<<"Ingresando una salchicha..."<<endl;
                instancia->insertarHotdogFinal();
                break;
            }
            case 2:{
                instancia->mostrarInventario();
                instancia->mostrarHotdogs();
                break;
            }
            case 3:{
                instancia->eliminarHotdogInicio();
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

void Empleado::setInventario(Hotdog *inventarioCompartido)
{
    instancia = inventarioCompartido;
}

void Empleado::quicksort()
{
    //pendiente para hacerlo con texto chuy
}
