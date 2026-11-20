#ifndef DICCIONARIOLIBROS_H
#define DICCIONARIOLIBROS_H

#include "Libro.h"
#include "Iterador.h"

const int B = 500;

class DiccionarioLibros{
    private:
        struct Nodo{
            Libro* info;
            Nodo* sig;

            explicit Nodo(Libro* libro);
        };

    Nodo* tabla[B];
    int H(long int isbn); //funcion de dispersion hush

    public:
        //CONSTRUCTOR
        DiccionarioLibros();

        //PRIMITIVAS
        void Insert(Libro* libro);
        bool Member(long int isbn);
        Libro* Find(long int isbn);
        bool estaVacio();

        //METODOS
        void buscarPorFrase(String frase, Iterador &iter);
        float calcularRecaudacion(String editorial);
        void calcularUnidadesVendidas(float precio, int &novelas, int &textos, int &escolares);
        Libro* libroMasVendidoEditorial(String editorial);

        //DESTRUCTOR
        ~DiccionarioLibros();

};
#endif // DICCIONARIOLIBROS_H
