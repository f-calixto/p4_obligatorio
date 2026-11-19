#include "Autor.h"

Autor::Autor(long int c, String n, String a) {
    cedula = c;
    nombre = n;
    apellido = a;
}

long int Autor::getCedula() { return cedula; }

String Autor::getNombre() { return nombre; }

String Autor::getApellido() { return apellido; }

TipoObjeto Autor::obtenerTipoObjeto() { return AUTOR; }

Autor::~Autor() {}