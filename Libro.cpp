#include "Libro.h"

// CONSTRUCTOR
Libro::Libro(long int i, String t, String e, float p)
    : titulo(t), editorial(e) {
    isbn = i;
    precioBase = p;
    unidadesVendidas = 0;
}

// GETTERS
long int Libro::getIsbn() { return isbn; }

String Libro::getTitulo() { return titulo; }

String Libro::getEditorial() { return editorial; }

float Libro::getPrecioBase() { return precioBase; }

int Libro::getUnidadesVendidas() { return unidadesVendidas; }

// METODOS
void Libro::registrarVenta() { unidadesVendidas++; }

TipoObjeto Libro::obtenerTipoObjeto() { return LIBRO; }

void Libro::mostrarLibroBasico() {
    cout << isbn << " - ";
    titulo.print();
    cout << " - ";

    switch (obtenerTipo()) {
        case NOVELA:
            cout << "NOVELA";
            break;

        case TEXTO:
            cout << "TEXTO";
            break;

        case ESCOLAR:
            cout << "ESCOLAR";
            break;
    }
    cout << endl;
}

// DESTRUCTOR
Libro::~Libro() {}
