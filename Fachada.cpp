#include "Fachada.h"

#include "Novela.h"

Fachada::Fachada() : libros(), autores() {}

void Fachada::registrarAutor(Autor* autor, TipoError& error) {
    error = ERRORNULO;

    if (autores.Member(autor->getCedula())) {
        error = AUTORREGISTRADO;
        return;
    }

    autores.Insert(autor);
}

void Fachada::registrarLibro(Libro* libro, TipoError& error) {
    error = ERRORNULO;

    if (libros.Member(libro->getIsbn())) {
        error = LIBROREGISTRADO;
        return;
    }

    libros.Insert(libro);
}

void Fachada::asociarAutorNovela(long int ci, long int isbn, TipoError& error) {
    error = ERRORNULO;

    if (!libros.Member(isbn)) {
        error = LIBRONOEXISTE;
        return;
    }

    Autor* autor = autores.Find(ci);
    if (autor == nullptr) {
        error = AUTORNOEXISTE;
        return;
    }

    Libro* libro = libros.Find(isbn);
    if (libro->obtenerTipo() != NOVELA) {
        error = NOESNOVELA;
        return;
    }

    Novela* novela = (Novela*)libro;
    novela->setAutor(autor);
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
    libro = nullptr;

    if (!libros.Member(isbn)) {
        error = LIBRONOEXISTE;
        return;
    }

    libro = libros.Find(isbn);
}

void Fachada::listarAutores(TipoError& error, Iterador& iter) {
    error = ERRORNULO;

    if (autores.estaVacio()) {
        error = AUTORESVACIO;
        return;
    }

    autores.listarEnOrden(iter);
}

float Fachada::registrarVenta(long int isbn, TipoError& error) {
    error = ERRORNULO;

    if (!libros.Member(isbn)) {
        error = LIBRONOEXISTE;
        return 0;
    }

    Libro* libro = libros.Find(isbn);
    libro->registrarVenta();
    return libro->calcularPrecioVenta();
}

float Fachada::recaudacionEditorial(String editorial) {
    return libros.calcularRecaudacion(editorial);
}

void Fachada::unidadesVendidasPorTipo(float precio, int& novelas, int& textos,
                                      int& escolares) {
    libros.calcularUnidadesVendidas(precio, novelas, textos, escolares);
}

void Fachada::listarMasVendidoEditorial(String editorial, TipoError& error,
                                        Libro*& libro) {
    error = ERRORNULO;
    libro = libros.libroMasVendidoEditorial(editorial);

    if (libro == nullptr) {
        error = EDITORIALSINLIBROS;
    }
}

Fachada::~Fachada() {}