#include<iostream>
#include "Caja.h"

using namespace std;


Caja::Caja()//Cola estatica circular
{
    F=-1;
    I=-1;
    numticket=0;
    //ctor
}

Caja::~Caja()
{
    //dtor
}

void Caja::insertar()
{
    if((I==0&&F==99)||(F==I-1))
    {
        cout<<"Limite de tickets alcanzado, favor de retirar tickets"<<endl;
    }
    else{
            if((I==0&&F==99)||(F==I-1)) //si esta lleno
    {
        cout<<"Lleno"<<endl;
    }
    else
    {
        if(I==-1&&F==-1) //si es el primero
        {
            I++;
            F++;
        }
        else{
            if(F==99) //si final esta al final
            {
                F=-1;
            }
        F++;
        }
        numticket++;
        tickets[F]=numticket;
        costoticket[F]=14.99;
        total+=costoticket[F];
    }
    }
}
void Caja::mostrar()
{
    int x;
    if(I==-1)
    {
            cout<<"Vacio"<<endl;
        }
        else{
            if(F>=I)
            {
                cout<<"Mostrando tickets:"<<endl;
                for(x=I;x<=F;x++)
                {
                    cout<<"Numero de ticket: "<<tickets[x]<<endl;
                    cout<<"Total del ticket: "<<costoticket[x]<<endl;
                    cout<<"------------------"<<endl;
                }
            }
            else if(F<I)
            {
                cout<<endl<<"Mostrar:"<<endl;
                for(x=I;x<100;x++)
                {
                    cout<<"Numero de ticket: "<<tickets[x]<<endl;
                    cout<<"Total del ticket: "<<costoticket[x]<<endl;
                    cout<<"------------------"<<endl;
                }
                for(x=0;x<=F;x++)
                {
                    cout<<"Numero de ticket: "<<tickets[x]<<endl;
                    cout<<"Total del ticket: "<<costoticket[x]<<endl;
                    cout<<"------------------"<<endl;
                }
            }
            cout<<"Total vendido: "<<total<<endl;
            cout<<endl;
    }
}
void Caja::eliminar()
{
    int cantidad;
    cout<<"Ingrese la cantidad de tickets a eliminar: ";
    cin>>cantidad;
    for(int i=0;i<cantidad;i++)
    {
        if(I==-1)
        {
            cout<<"Vacio"<<endl;
        }
        else
        {
            if(I==F)
            {
                I=-1;
                F=-1;
            }
            else
            {
                if(I==99)
                {
                    I=-1;
                }
                I++;
            }
        }
    }
}
