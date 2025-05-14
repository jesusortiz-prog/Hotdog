#include "Empleado.h"
#include "Hotdog.h"
#include "Gerente.h"

#include <cstdlib>
#include <string>
#include <iostream>

#include <string>
#include <fstream>

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
    }else{
        cout<<"Lista no ordenada: "<<endl;
        Nodo *aux=inicio;
        do{
            cout<<"Nombre del empleado: "<<aux->getNombre()<<endl;
            cout<<"Id del empleado: "<<aux->getId()<<endl;
            cout<<"----------------------"<<endl;
            aux=aux->sig;
        }while(aux!=inicio);
    }
    cout<<"Lista ordenada: "<<endl;
    quickSort();
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

void Empleado::guardarEmpleadosArchivo() {
    ofstream archivo("Empleados.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar." << endl;
    }else{
        Nodo* aux = inicio;
        do {
            archivo << aux->getId() << " " << aux->getNombre() << endl;
            aux = aux->sig;
        } while (aux != inicio);

        archivo.close();
        cout << "Empleados guardados correctamente en 'Empleados.txt'" << endl;
    }


}

void Empleado::cargarEmpleados() {
    ifstream archivo("Empleados.txt");
    if (!archivo.is_open()) {
        cout << "No se encontro el archivo de empleados. Se creara uno nuevo al guardar." << endl;
        return;
    }

    int id;
    string nombre;

    while (archivo >> id >> ws && getline(archivo, nombre)) {
        Nodo* nuevo = new Nodo(nombre, id);
        if (inicio == nullptr) {
            inicio = nuevo;
            nuevo->sig = nuevo;
            nuevo->ant = nuevo;
        } else {
            nuevo->sig = inicio;
            nuevo->ant = inicio->ant;
            inicio->ant->sig = nuevo;
            inicio->ant = nuevo;
        }
    }

    archivo.close();
    cout << "Empleados cargados correctamente desde 'Empleados.txt'" << endl;
}


void Empleado::quickSort(){
    Nodo *aux=inicio;
    int contador=0;

    int extizq = 0;
    int extder = contador - 1;
    int i = extizq;
    int j = extder;         //quick logica


    do{
        contador++;

        aux=aux->sig;
        cout<<"-------------"<<endl;
    }while(aux!=inicio);

    Nodo arreglo[contador];
    aux=inicio;

    do{
        aux=aux->sig;

        arreglo[contador].setNombre(aux->getNombre());
        arreglo[contador].setId(aux->getId());
    }while(aux!=inicio);


    for(int i=0; i<contador; i++){
        cout<<"Nombre del empleado: "<<arreglo[i].getNombre();
        cout<<"Id del empleado: "<<arreglo[i].getId();
    }

    /*
    while (i < j) {
        while (i < j && arreglo[i].getId() <= arreglo[extder].getId()) {
            i++;

        }
        while (i < j && arreglo[j].getId() >= arreglo[extder].getId()) {
            j--;
        }
        if (i != j) {
            int aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
            contadorIntercambios++;
        }
    }

    if (i != extder) {
        int aux = arreglo[i];
        arreglo[i] = arreglo[extder];
        arreglo[extder] = aux;

    }

*/
}
