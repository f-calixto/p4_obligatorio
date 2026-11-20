#include "DiccionarioAutores.h"

//CONSTRUCTOR NODO
DiccionarioAutores :: Nodo::Nodo(Autor* autor){
    info = autor;
    altura = 1;
    izq = NULL;
    der = NULL;
}

//CONSTRUCTOR DICCIONARIO
DiccionarioAutores :: DiccionarioAutores(){
    raiz = NULL;
}

//OPERACIONES AUXILIARES AVL

void DiccionarioAutores :: RotacionSimpleIzquierda(Nodo* &a)
{
    Nodo* aux = a->izq;
    a->izq = aux->der;
    aux->der = a;
    a = aux;
    a->altura = a->altura + 1;
    a->der->altura = a->der->altura - 1;
}

void DiccionarioAutores :: RotacionSimpleDerecha(Nodo* &a)
{
    Nodo* aux = a->der;
    a->der = aux->izq;
    aux->izq = a;
    a = aux;
    a->altura = a->altura + 1;
    a->izq->altura = a->izq->altura - 1;
}

void DiccionarioAutores :: RotacionDobleIzquierda(Nodo* &a)
{
    RotacionSimpleDerecha(a->izq);
    RotacionSimpleIzquierda(a);
    a->altura = a->altura - 1;
    a->der->altura = a->der->altura - 1;
}

void DiccionarioAutores :: RotacionDobleDerecha(Nodo* &a)
{
    RotacionSimpleIzquierda(a->der);
    RotacionSimpleDerecha(a);
    a->altura = a->altura - 1;
    a->izq->altura = a->izq->altura - 1;
}

void DiccionarioAutores::Balancear(Nodo* &a){
    if(a != NULL){
        int hi = 0;
        int hd = 0;

        if(a->izq != NULL)
            hi = a->izq->altura;

        if(a->der != NULL)
            hd = a->der->altura;

        int balance = hi - hd;

        if(balance > 1){
            int hIzq = 0;
            int hDer = 0;

            if(a->izq->izq != NULL)
                hIzq = a->izq->izq->altura;

            if(a->izq->der != NULL)
                hDer = a->izq->der->altura;

            if(hIzq >= hDer)
                RotacionSimpleIzquierda(a);
            else
                RotacionDobleIzquierda(a);
        }
        else if(balance < -1){
            int hIzq = 0;
            int hDer = 0;

            if(a->der->izq != NULL)
                hIzq = a->der->izq->altura;

            if(a->der->der != NULL)
                hDer = a->der->der->altura;

            if(hDer >= hIzq)
                RotacionSimpleDerecha(a);
            else
                RotacionDobleDerecha(a);
        }
        else{
            if(hi > hd)
                a->altura = hi + 1;
            else
                a->altura = hd + 1;
        }
    }
}

void DiccionarioAutores::Insertar(Nodo* &a, Autor* autor){
    if(a == NULL)
        a = new Nodo(autor);
    else{
        if(autor->getCedula() < a->info->getCedula())
            Insertar(a->izq, autor);
        else if(autor->getCedula() > a->info->getCedula())
            Insertar(a->der, autor);
        else
            return;

        Balancear(a);
    }
}

Autor* DiccionarioAutores::Buscar(Nodo* a, long int cedula){
    if(a == NULL)
        return NULL;

    if(cedula == a->info->getCedula())
        return a->info;

    if(cedula < a->info->getCedula())
        return Buscar(a->izq, cedula);
    else
        return Buscar(a->der, cedula);
}

void DiccionarioAutores::RecorrerEnOrden(Nodo* a, Iterador &iter){
    if(a != NULL){
        RecorrerEnOrden(a->izq, iter);
        iter.insertar(a->info);
        RecorrerEnOrden(a->der, iter);
    }
}

void DiccionarioAutores::Destruir(Nodo* a){
    if(a != NULL){
        Destruir(a->izq);
        Destruir(a->der);

        delete a->info;
        delete a;
    }
}

//PRIMITIVAS
void DiccionarioAutores::Insert(Autor* autor){
    if(autor != NULL)
        Insertar(raiz, autor);
}

Autor* DiccionarioAutores::Find(long int cedula){
    return Buscar(raiz, cedula);
}

bool DiccionarioAutores::Member(long int cedula){
    return Find(cedula) != NULL;
}

bool DiccionarioAutores :: estaVacio(){
    return raiz == NULL;
}

//METODOS
void DiccionarioAutores::listarEnOrden(Iterador &iter){
    RecorrerEnOrden(raiz, iter);
}

//DESTRUCTOR
DiccionarioAutores::~DiccionarioAutores(){
    Destruir(raiz);
    raiz = NULL;
}
