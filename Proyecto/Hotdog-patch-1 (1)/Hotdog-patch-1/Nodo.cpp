#include "Nodo.h"
#include <iostream>

//using namespace std;

Nodo::Nodo(){
    sig=nullptr;
    ant=nullptr;


}
int Nodo::getElemento(){
    return elemento;
}

Nodo::Nodo(string nombre, int id){
    sig=nullptr;
    ant=nullptr;

    this->nombre=nombre; //los this es para que sepa cual es atributo y cual es parametro del constructor
    this->id=id;

}
string Nodo::getNombre(){
    return(nombre);
}
int Nodo::getId(){
    return(id);
}

void Nodo::setId(int id){
    this->id=id;

}
void Nodo::setNombre(string nombre){
    this->nombre=nombre;
}
