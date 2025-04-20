#include "Gerente.h"
#include "Empleado.h"

Gerente::Gerente()
{
    //ctor
}

Gerente::~Gerente()
{
    //dtor
}

void Gerente::menuGerente() //agregrar do while a cada case
{
    int opc,opc2;
    Empleado inst;
    cout<<"Menu gerente \n 1)Administrar empleados\n 2)Administrar inventario\n"<<endl;

    cin>>opc;
    switch(opc)
    {
    case 1:
            cout<<"1) Ingresar empleado\n 2) Despedir primer empleado\n 3) Mostrar"<<endl;
            cin>>opc2;
            switch(opc2)
            {
            case 1:
                //Agregar un empleado
                inst.ingresarEmpleadoFinal();
                break;
            case 2:
                //despedir a un emplead
                inst.eliminarEmpleadoInicio();
                break;
            case 3:
                inst.mostrarEmpleado();
                //mostrar el total de empleados
                break;
            }
        break;
    case 2:
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;
    }
}
