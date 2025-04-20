#include "Hotdog.h" //para clase hotdog
#include "Nodo.h" //para clase nodo
#include "Empleado.h" //para clase empleado
#include "Gerente.h"
#include <string>
#include <iostream>


using namespace std;


int main() //menu del gerente
{
    int opc;
    Gerente inst;
    do
    {
        cout<<"Menu principal\n 1)Gerente\n 2)empleado\n 3)Salir\n"<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            inst.menuGerente();
            break;
        case 2:
            inst.empleado.menuEmpleado();
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
        }
    }while(opc!=3);
}
