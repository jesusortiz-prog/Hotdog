#include "Hotdog.h" //para clase hotdog
#include "Nodo.h" //para clase nodo
#include "Empleado.h" //para clase empleado
#include "Gerente.h"
#include <string>
#include <iostream>


using namespace std;


int main() //menu del gerente
{
    int opcMain;
    Gerente inst;

    do{
        cout<<"Menu principal\n1)Gerente\n2)Empleado\n3)Terminar programa\n"<<endl;
        cin>>opcMain;
        system("cls");
        switch(opcMain)
        {
        case 1:
            inst.menuGerente();
            break;
        case 2:
            inst.empleado.menuEmpleado();
            inst.guardarInventario();

            break;
        case 3:
            cout<<"Saliendo...\n";
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
        }
    }while(opcMain!=3);

    return 0;
}

