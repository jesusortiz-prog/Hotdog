#ifndef ARBOL_H
#define ARBOL_H

class NodoArbol
{
    public:
        NodoArbol(float hora);
        ~NodoArbol();
        float hora;
        NodoArbol *izquierdo;
        NodoArbol *derecho;

};

class Arbol {
     public:
        NodoArbol* raiz;

        NodoArbol* insertar(NodoArbol* nodo,float hora);
        void recorridoInOrder(NodoArbol* nodo);


        Arbol();
        ~Arbol();
        void insertar(float hora);
        void recorridoInOrder();
};

#endif // ARBOL_H
