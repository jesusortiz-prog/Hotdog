#include "Empleado.h"
#include "Hotdog.h"
#include "Gerente.h"
#include "Arbol.h"
#include <cstdlib>
#include <string>
#include <iostream>

#include <string>
#include <fstream>

using namespace std;
Empleado::Empleado() //cola doble ligada circular- Sin encabezados
{
    inicio=nullptr;
    arbol = new Arbol;
}

Empleado::~Empleado()
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
    delete arbol;
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

void Empleado::ingresarEmpleadoFinal()//cola doble ligada circular- Sin encabezados
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
void Empleado::eliminarEmpleadoInicio() //elimina el inicio
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
    shellsort();
}

void Empleado::menuEmpleado()
{
    int opc;
    do{
        cout<<"Menu de carrito de perritos calientes\n1)Preparar HotDog (insertar)\n2)Mostrar inventario y HotDogs preparados\n3)Vender HotDog (eliminar)\n4)Ingresar hora de entrada\n5)Mostrar arbol\n6)Salir."<<endl;
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
                caja->insertar();
                break;
            }
            case 4:{
                float hora;
                int id;
                cout<<"Ingrese la hora de entrada: "<<endl;
                cin>>hora;
                cout<<"Ingrese id del empleado: "<<endl;
                cin>>id;
                if(!id_unico(id))
                {
                    arbol->insertar(hora,id);
                    arbol->recorridoInOrder();
                }
                else
                {
                    cout<<"Id no encontrado en el sistema"<<endl;
                }

                break;
            }
            case 5:
                arbol->imprimirArbol(arbol->raiz,0,5);
                break;
            case 6:{
                cout<<"Saliendo...\n";
                break;
            }
            default:{
                cout<<"Opcion no valida\n";
                break;
            }
        }
    }while(opc!=6);
}

void Empleado::setInventario(Hotdog *inventarioCompartido,Caja *caja)
{
    instancia=inventarioCompartido;
    this->caja=caja;
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


void Empleado::shellsort()
{
    if(inicio==nullptr)
    {
        cout<<"Lista vacia."<<endl;
        return;
    }

    // contar nodos para saber el maximo
    int contador=1;
    Nodo* aux=inicio->sig;
    while(aux!=inicio)
    {
        contador++;
        aux=aux->sig;
    }
    //crear arreglo de punteros a Nodo
    Nodo** nodos=new Nodo*[contador];
    aux=inicio;
    for(int i=0;i<contador;i++)
    {
        nodos[i]=aux;
        aux=aux->sig;
    }
    //shell Sort por id
    for(int gap=contador/2;gap>0;gap/= 2)
    {
        for(int i=gap;i<contador;i++)
        {
            Nodo* temp=nodos[i];
            int j;
            for(j=i;j>=gap&&nodos[j-gap]->getId()>temp->getId();j-=gap)
            {
                nodos[j]=nodos[j-gap];
            }
            nodos[j]=temp;
        }
    }
    //reconstruir sig y ant
    for(int i=0;i<contador;i++)
    {
        nodos[i]->sig=nodos[(i+1)%contador];
        nodos[i]->ant=nodos[(i-1+contador)%contador];
    }
    //actualizar inicio
    inicio=nodos[0];
    //liberar memoria del arreglo
    delete[] nodos;
    cout<<"Lista ordenada exitosamente por ID (Shell Sort)"<<endl;
     Nodo* temp=inicio;
    do{
        cout<<"ID: "<<temp->getId()<<", Nombre: "<<temp->getNombre()<<endl;
        temp=temp->sig;
    }while(temp!=inicio);

}

void Empleado::busquedaBinaria()
{
    if(inicio==nullptr)
    {
        cout<<"Lista vacia"<<endl;
        return;
    }
    //contar los nodos para saber el maximo
    int contador = 1;
    Nodo* aux=inicio->sig;
    while(aux!=inicio)
    {
        contador++;
        aux=aux->sig;
    }

    //crear arreglo de punteros
    Nodo** nodos=new Nodo*[contador];
    aux=inicio;
    for(int i=0;i<contador;i++)
    {
        nodos[i]=aux;
        aux=aux->sig;
    }

    // shell Sort
    for(int gap=contador/2;gap>0;gap/= 2)
    {
        for(int i=gap;i<contador;i++)
        {
            Nodo* temp=nodos[i];
            int j;
            for(j=i;j>=gap&&nodos[j-gap]->getId()>temp->getId();j-=gap)
            {
                nodos[j]=nodos[j-gap];
            }
            nodos[j]=temp;
        }
    }

    //reconstruir los enlaces
    for(int i=0;i<contador;i++)
    {
        nodos[i]->sig=nodos[(i+1)%contador];
        nodos[i]->ant=nodos[(i-1+contador)%contador];
    }

    //actualizar inicio
    inicio=nodos[0];
    int numeroBuscado=0;
    cout<<"Ingrese el ID a buscar: ";
    cin>>numeroBuscado;

    int i=0;
    while(i<=contador){
        int medio=(i+contador)/2;
        if(nodos[medio]->getId()==numeroBuscado){
            cout<<"Empleado encontrado: "<<nodos[medio]->getId()<<" en la posicion: "<<medio+1<<endl;
            cout<<"Empleado encontrado: "<<nodos[medio]->getNombre()<<endl;
            return;
        }else if(numeroBuscado<nodos[medio]->getId()){
            contador=medio-1;
        }else{
            i=medio+1;
        }
    }
    cout<<"Numero no encontrado, busque por otro"<<endl;
}
