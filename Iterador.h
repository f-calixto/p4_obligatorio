#ifndef ITERADOR_H
#define ITERADOR_H

#include "Objeto.h"
#include "LPPF.h"

class Iterador{
    private:
        LPPF iter;

    public:
        //CONSTRUCTOR
        Iterador();

        //PRIMITIVAS
        void insertar(Objeto* o);
        bool hayMasObjetos();
        Objeto* proximoObjeto();
};


#endif // ITERADOR_H
