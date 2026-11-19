#include "Iterador.h"

//CONSTRUCTOR
Iterador::Iterador(){}

//METODOS
void Iterador::insertar(Objeto* o){
    iter.insBack(o);
}

bool Iterador::hayMasObjetos(){
    return !iter.esVacia();
}

Objeto* Iterador::proximoObjeto(){
    Objeto* o = iter.primero();
    iter.borrarPrimero();
    return o;
}

//DESTRUCTOR
Iterador::~Iterador(){}


