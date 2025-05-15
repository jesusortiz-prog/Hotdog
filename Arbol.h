#ifndef ARBOL_H
#define ARBOL_H

class NodoArbol
{
    public:
        NodoArbol(float hora,int id);
        ~NodoArbol();
        float hora;
        int id;
        NodoArbol *izquierdo;
        NodoArbol *derecho;

};

class Arbol {
     public:
        NodoArbol* raiz;

        NodoArbol* insertar(NodoArbol* nodo,float hora,int id);
        void recorridoInOrder(NodoArbol* nodo);


        Arbol();
        ~Arbol();
        void insertar(float hora,int id);
        void recorridoInOrder();
        void imprimirArbol(NodoArbol* nodo,int espacio,int incremento);
};

#endif // ARBOL_H
