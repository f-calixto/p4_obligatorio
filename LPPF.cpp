#include "LPPF.h"
#include <stdio.h>

//CONSTRUCTORES
LPPF::Nodo::Nodo(Objeto* d){ //Constructor de Nodo
    dato = d;
    sig = NULL;
}

LPPF::LPPF(){ //Constructor de la LPPF
    principio = NULL;
    fin = NULL;
}

//METODOS
bool LPPF::esVacia(){
    return principio == NULL;
}

void LPPF::insBack(Objeto* o){
    Nodo* nuevo = new Nodo(o);
    if(fin == NULL){
        principio = fin = nuevo; //LPPF vacia, asigna el inicio y el final al mismo nodo (nuevo)
    }else{
        fin->sig = nuevo;
        fin = nuevo;
    }
}

Objeto* LPPF::primero(){
    return principio->dato;
}

void LPPF::borrarPrimero(){
    Nodo* aux = principio;
    principio = principio->sig;
    if (principio == NULL)
        fin = NULL;
    delete aux;
}

//DESTRUCTOR
LPPF::~LPPF(){
    while(principio != NULL){
        Nodo* aux = principio;
        principio = principio->sig;
        delete aux; //Borra el noto, no el objeto, eliminar el objeto es responsabilidad del diccionario
    }
}

