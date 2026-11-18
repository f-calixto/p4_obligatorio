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
