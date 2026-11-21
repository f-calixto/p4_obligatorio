#include "Escolar.h"

// CONSTRUCTOR
Escolar::Escolar(long int i, String t, String e, float p, String m, Fecha f,
                 int a)
    : Texto(i, t, e, p, m, f) {
    anioEscuela = a;
}

// GETTERS
int Escolar::getAnioEscuela() { return anioEscuela; }

float Escolar::calcularPrecioVenta() {
    if (anioEscuela >= 1 && anioEscuela <= 3)
        return Texto::calcularPrecioVenta() * 0.90;
    else
        return Texto::calcularPrecioVenta();
}

// METODOS
TipoLibro Escolar::obtenerTipo() { return ESCOLAR; }

// DESTRUCTOR
Escolar::~Escolar() {}
