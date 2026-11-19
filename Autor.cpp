#include "Autor.h"

//CONSTRUCTOR
Autor::Autor(long int c, String n, String a) {
    cedula = c;
    nombre = n;
    apellido = a;
}

//GETTERS
long int Autor::getCedula() {
    return cedula;
}

String Autor::getNombre() {
    return nombre;
}

String Autor::getApellido() {
    return apellido;
}

//METODOS
TipoObjeto Autor::obtenerTipoObjeto() {
    return AUTOR;
}

Autor::~Autor(){
}
