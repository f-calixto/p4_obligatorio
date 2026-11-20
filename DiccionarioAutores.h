#ifndef DICCIONARIOAUTORES_H
#define DICCIONARIOAUTORES_H

#include "Autor.h"
#include "Iterador.h"

class DiccionarioAutores{
    private:
        struct Nodo{
        Autor* info;
        int altura; //por AVL
        Nodo* izq;
        Nodo* der;

        explicit Nodo(Autor* autor); //constructor de nodo
        };

        Nodo* raiz;

        //OPERACIONES AUXILIARES AVL
        void RotacionSimpleIzquierda(Nodo* &a);
        void RotacionSimpleDerecha(Nodo* &a);
        void RotacionDobleIzquierda(Nodo* &a);
        void RotacionDobleDerecha(Nodo* &a);

        void Balancear(Nodo* &a);
        void Insertar(Nodo* &a, Autor* autor);

        Autor* Buscar(Nodo* a, long int cedula);
        void RecorrerEnOrden(Nodo* a, Iterador &iter);
        void Destruir(Nodo* a);


    public:
        //CONSTRUCTOR
        DiccionarioAutores();

        //PRIMITIVAS
        void Insert(Autor* autor);
        bool Member(long int cedula);
        Autor* Find(long int cedula);
        bool estaVacio();

        //METODOS
        void listarEnOrden(Iterador &iter);

        //DESTRUCTOR
        ~DiccionarioAutores();
};

#endif // DICCIONARIOAUTORES_H
