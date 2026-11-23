#include "Fachada.h"

#include "Novela.h"

Fachada::Fachada() : libros(), autores() {}

void Fachada::registrarAutor(Autor* autor, TipoError& error) {
    error = ERRORNULO;

    if (autores.Member(autor->getCedula())) {
        error = AUTORREGISTRADO;
    } else
        autores.Insert(autor);
}

void Fachada::registrarLibro(Libro* libro, TipoError& error) {
    error = ERRORNULO;

    if (libros.Member(libro->getIsbn())) {
        error = LIBROREGISTRADO;
    } else
        libros.Insert(libro);
}

void Fachada::asociarAutorNovela(long int ci, long int isbn, TipoError& error) {
    error = ERRORNULO;

    if (!libros.Member(isbn)) {
        error = LIBRONOEXISTE;
    } else{
        Autor* autor = autores.Find(ci);
        if (autor == NULL) {
            error = AUTORNOEXISTE;
        } else{
            Libro* libro = libros.Find(isbn);
            if (libro->obtenerTipo() != NOVELA) {
                error = NOESNOVELA;
            } else{
                Novela* novela = (Novela*)libro;
                novela->setAutor(autor);
            }
        }
    }
}

void Fachada::listarPorFrase(String frase, TipoError& error, Iterador& iter) {
    error = ERRORNULO;
    libros.buscarPorFrase(frase, iter);
    if (!iter.hayMasObjetos()) {
        error = LIBROSFRASE;
    }
}

void Fachada::listarLibro(long int isbn, TipoError& error, Libro*& libro) {
    error = ERRORNULO;
    libro = NULL;
    if (!libros.Member(isbn)) {
        error = LIBRONOEXISTE;
    } else{
        libro = libros.Find(isbn);
    }
}

void Fachada::listarAutores(TipoError& error, Iterador& iter) {
    error = ERRORNULO;

    if (autores.estaVacio()) {
        error = AUTORESVACIO;
    } else{
        autores.listarEnOrden(iter);
    }
}

void Fachada::registrarVenta(long int isbn, TipoError& error, float &venta) {
    error = ERRORNULO;
    if (!libros.Member(isbn)) {
        error = LIBRONOEXISTE;
    } else{
        Libro* libro = libros.Find(isbn);
        libro->registrarVenta();
        venta = libro->calcularPrecioVenta();
    }
}

float Fachada::recaudacionEditorial(String editorial) {
    return libros.calcularRecaudacion(editorial);
}

void Fachada::unidadesVendidasPorTipo(float precio, int& novelas, int& textos, int& escolares) {
    libros.calcularUnidadesVendidas(precio, novelas, textos, escolares);
}

void Fachada::listarMasVendidoEditorial(String editorial, TipoError& error, Libro*& libro) {
    error = ERRORNULO;
    libro = libros.libroMasVendidoEditorial(editorial);

    if (libro == NULL) {
        error = EDITORIALSINLIBROS;
    }
}

Fachada::~Fachada() {}
