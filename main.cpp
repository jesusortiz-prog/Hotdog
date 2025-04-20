#include "Hotdog.h" //para clase hotdog
#include "Nodo.h" //para clase nodo
#include <string>
#include <iostream>


using namespace std;


int main()
{
    Hotdog instancia;
    int opc, cantidadSalchicas;
    do{
        cout<<"Menu de carrito de perritos calientes\n1)Insertar\n2)Mostrar\n3)Eliminar\n4)salir."<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:{
                cout<<"Ingrese la cantidad de salchicas para poner en el inventario: "<<endl;
                cin>>cantidadSalchicas;
                instancia.ingresarSalchicas(cantidadSalchicas);
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
    }while(opc!=3);

    return 0;
}
