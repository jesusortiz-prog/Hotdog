#ifndef CAJA_H
#define CAJA_H


class Caja
{
    public:
        Caja();
        ~Caja();

        int F;
        int I;
        float total=0;
        int tickets[100];
        int numticket;
        float costoticket[100];

        void insertar();
        void mostrar();
        void eliminar();

};

#endif // CAJA_H
