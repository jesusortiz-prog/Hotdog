#include "Gerente.h"
#include "Empleado.h"

#include "Hotdog.h"//hotdog
#include "Pan.h"
#include "Ketchup.h"
#include <cstdlib>
#include <fstream>
#include <sstream>

#include <iomanip> // Necesario para setw() (el alineador)

const int Gerente::NUM_CIUDADES = 4;

Gerente::Gerente()
{
    empleado.setInventario(&hotdog);
    cargarInventario();
    empleado.cargarEmpleados();

    //inicializar grafo

    ciudades[0] = "GDL";
    ciudades[1] = "Zapopan";
    ciudades[2] = "Tlajoyork";
    ciudades[3] = "Tetlan";

    inicializarGrafo();
}

Gerente::~Gerente()
{
    //dtor
}

void Gerente::subEmpleados(){
    int opcEmp;
    do{
        cout<<"1)Ingresar empleado\n2)Despedir empleado con mas antiguedad\n3)Mostrar\n4)Buscar empleado por ID\n5)Volver"<<endl;
        cin>>opcEmp;
        system("cls");
        switch(opcEmp){
        case 1:
            //Agregar un empleado
            empleado.ingresarEmpleadoFinal();
            break;
        case 2:
            //despedir a un emplead
            empleado.eliminarEmpleadoInicio();
            break;
        case 3:
            empleado.mostrarEmpleado();
            empleado.guardarEmpleadosArchivo();
            break;
        case 4:
            empleado.busquedaBinaria();
            break;
        case 5:
            cout<<"Saliendo...\n";
            empleado.cargarEmpleados();
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
        }

    }while(opcEmp!=5);
}

void Gerente::subInventario(){
    int opc;
    do{
        cout<<"1)Mostrar cantidad de salchichas,\n\t\t\tPanes,\n\t\t\tSobres de ketchup.\n2)Ingresar salchicas\n3)Ingresar Pan\n4)Ingresar ketchup\n5)Volver\n";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            hotdog.mostrarInventario();
            break;
        case 2:
            hotdog.salchicha.ingresarSalchicha();
            break;
        case 3:
            hotdog.pan.ingresarPanFinal();
            break;
        case 4:
            hotdog.ketchup.ingresarKetchupFinal();
            break;
        case 5:
            cout<<"volviendo...\n";
            guardarInventario();
            break;
        default:
            cout<<"Opcion no valida...\n";
            break;
        }

    }while(opc!=5);

}
void Gerente::menuGerente() //agregrar do while a cada case
{
    int opc;
    do{
        cout<<"Menu gerente\n1)Administrar empleados\n2)Administrar inventario\n3)Mostrar rutas de ciudades\n4)Volver"<<endl;
        cin>>opc;
        system("cls");

        switch(opc){
        case 1:
            subEmpleados();
            break;
        case 2:
            subInventario();
            break;
        case 3:
            mostrarRutas();
            break;
        case 4:
            cout<<"...\n";
            break;

        default:
            cout<<"Opcion no valida"<<endl;
            break;
        }
    }while(opc!=4);

}


void Gerente::guardarInventario(){
    ofstream archivo("inventario.txt");

    if (!archivo.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    // Guardar salchichas
    Nodo* aux=hotdog.salchicha.getInicio();
    int contador=0;
    while (aux!=nullptr){
        contador++;
        aux=aux->sig;
    }
    archivo<<"Salchichas: "<<contador<<endl;

    // Guardar panes
    aux = hotdog.pan.getInicio();
    contador=0;
    while (aux!=nullptr){
        contador++;
        aux=aux->sig;
    }
    archivo<<"Panes: "<<contador<<endl;
    // Guardar ketchup
    aux = hotdog.ketchup.getInicio();
    contador = 0;
    if(!hotdog.ketchup.vacia()){
        do{
            contador++;
            aux=aux->sig;
        }while(aux!=hotdog.ketchup.getInicio());
    }
    archivo<<"Ketchup: "<<contador<<endl;
    // Guardar hotdog
    aux = hotdog.getInicio();
    contador=0;
    if(!hotdog.vacia()){
        do{
            contador++;
            aux=aux->sig;
        }while(aux!=hotdog.getInicio());
    }
    archivo<<"Hotdog: "<<contador<<endl;

    archivo.close();
    cout<<"Inventario guardado."<<endl;
}

void Gerente::cargarInventario() {
    ifstream archivo("inventario.txt");
    if(!archivo.is_open()) {
        cout<<"Error al abrir."<<endl;
        return;
    }

    string linea;
    int cantidad;

    //leer salchichas
    getline(archivo,linea);
    istringstream(linea.substr(linea.find(":") + 1))>>cantidad;
    for(int i=0;i<cantidad;i++){
        hotdog.salchicha.cargarSalchicha();
    }
    //leer panes
    getline(archivo,linea);
    istringstream(linea.substr(linea.find(":")+1))>>cantidad;
    for(int i=0;i<cantidad;i++) {
        hotdog.pan.cargarPan();
    }
    //leer ketchup
    getline(archivo,linea);
    istringstream(linea.substr(linea.find(":")+1))>>cantidad;
    for (int i=0;i<cantidad;i++){
        hotdog.ketchup.cargarKetchup();
    }
    //leer hotdog
    getline(archivo,linea);
    istringstream(linea.substr(linea.find(":")+1))>>cantidad;
    for (int i=0;i<cantidad;i++){
        hotdog.cargarHotdog();
    }

    archivo.close();
    cout << "Inventario cargado correctamente desde archivo." << endl;
}


//grafo
void Gerente::inicializarGrafo()
{
    // llena la matriz con ceros
    for (int i=0;i<NUM_CIUDADES;i++)
    {
        for(int j=0;j<NUM_CIUDADES;j++)
        {
            grafo[i][j]=0;
        }
    }

    grafo[0][1]=grafo[1][0]=10; // GDL - Zapopan
    grafo[0][2]=grafo[2][0]=20; // GDL - Tlajoyork
    grafo[0][3]=grafo[3][0]=8;  // GDL - Tetlan
    grafo[1][2]=grafo[2][1]=18; // Zapopan - Tlajoyork
    grafo[1][3]=grafo[3][1]=12; // Zapopan - Tetlan
    grafo[2][3]=grafo[3][2]=15; // Tlajoyork - Tetlan
    /*
    ciudades[0] = "GDL";
    ciudades[1] = "Zapopan";
    ciudades[2] = "Tlajoyork";
    ciudades[3] = "Tetlan";
    */
}

int Gerente::obtenerIndiceCiudad(string& nombre)
{
    for(int i=0;i<NUM_CIUDADES;++i)
    {
        if(ciudades[i]==nombre)
            return i;
    }
    return -1;
}

void Gerente::mostrarRutas()
{
    cout<<"\nDistancias entre ciudades (km):\n"<<endl;

    cout<<setw(12)<<" "; //hace que se alinee mejor
    for(int i=0;i<NUM_CIUDADES;i++)
    {
        cout<<setw(12)<<ciudades[i];
    }
    cout<<"\n";
    cout<<"\t----|---------------|---------|---------|-------------|"<<endl;

    for(int i=0;i<NUM_CIUDADES;i++)
    {
        cout<<setw(12)<<ciudades[i]<<"|";
        for(int j=0;j<NUM_CIUDADES;j++)
        {
            cout<<setw(8)<<grafo[i][j]<<"Km";
        }
        cout<<"\n";
        cout<<"\t----|---------------|---------|---------|-------------|"<<endl;
    }
}
