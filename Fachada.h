#ifndef FACHADA_H
#define FACHADA_H

#include "DiccionarioAutores.h"
#include "DiccionarioLibros.h"
#include "TipoError.h"

class Fachada{
    private:
        DiccionarioAutores autores;
        DiccionarioLibros libros;

    public:
        //CONSTRUCTOR
        Fachada();

        //METODOS
        void registrarAutor(Autor* autor, TipoError &error);
        void registrarLibro(Libro* libro, TipoError &error);
        void asociarAutorNovela(long int ci, long int isbn, TipoError &error);
        void listarPorFrase (String frase, TipoError &error, Iterador &iter);
        void listarLibro(long int isbn, TipoError &error, Libro* &libro);
        void listarAutores(TipoError &error, Iterador &iter);
        void registrarVenta(long int isbn, TipoError &error);
        float recaudacionEditorial(String editorial);
        void unidadesVendidasPorTipo(float precio, int &novelas, int &textos, int &escolares);
        void listarMasVendidoEditorial(String editorial, TipoError &error, Libro* &libro);

        //DESTRUCTOR
        ~Fachada();
};

#endif // FACHADA_H
