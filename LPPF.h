#ifndef LPPF_H
#define LPPF_H

#include "Objeto.h"

class LPPF{
    private:
        struct Nodo{
            Objeto* dato;
            Nodo* sig;
            Nodo(Objeto* d);
        };

        Nodo* principio;
        Nodo* fin;

    public:
        LPPF();
        bool esVacia();
        void insBack(Objeto* o);
        Objeto* primero();
        void borrarPrimero();
        ~LPPF();

};

#endif // LPPF_H_INCLUDED
