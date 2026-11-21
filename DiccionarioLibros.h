#ifndef DICCIONARIOLIBROS_H
#define DICCIONARIOLIBROS_H

#include "Iterador.h"
#include "Libro.h"

// Habran aproximadamente 500 libros. Se eligen un numero primo para aprovechar
// todos los digitos del isbn y distribuir mejor en las cubetas desde un
// principio
const int B = 701;

class DiccionarioLibros {
   private:
    struct Nodo {
        Libro* info;
        Nodo* sig;

        explicit Nodo(Libro* libro);
    };

    Nodo* tabla[B];
    int H(long int isbn);  // funcion de dispersion hash

   public:
    // CONSTRUCTOR
    DiccionarioLibros();

    // PRIMITIVAS
    void Insert(Libro* libro);
    bool Member(long int isbn);
    Libro* Find(long int isbn);
    bool estaVacio();

    // METODOS
    void buscarPorFrase(String frase, Iterador& iter);
    float calcularRecaudacion(String editorial);
    void calcularUnidadesVendidas(float precio, int& novelas, int& textos,
                                  int& escolares);
    Libro* libroMasVendidoEditorial(String editorial);

    // DESTRUCTOR
    ~DiccionarioLibros();
};
#endif  // DICCIONARIOLIBROS_H
