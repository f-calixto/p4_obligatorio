#include "LPPF.h"

//CONSTRUCTORES
LPPF::Nodo::Nodo(Objeto* d){ //Constructor de Nodo
    dato = d;
    sig = nullptr;
}

LPPF::LPPF(){ //Constructor de la LPPF
    principio = nullptr;
    fin = nullptr;
}

//METODOS
bool LPPF::esVacia(){
    return principio == nullptr;
}

void LPPF::insBack(Objeto* o){
    Nodo* nuevo = new Nodo(o);
    if(fin == nullptr){
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
    if (principio == nullptr)
        fin = nullptr;
    delete aux;
}

//DESTRUCTOR
LPPF::~LPPF(){
    while(principio != nullptr){
        Nodo* aux = principio;
        principio = principio->sig;
        delete aux; //Borra el noto, no el objeto, eliminar el objeto es responsabilidad del diccionario
    }
}

