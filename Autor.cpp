#include "Autor.h"

//CONSTRUCTOR
Autor::Autor(long int c, String n, String a): nombre(n), apellido(a){
    cedula = c;
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

//DESTRUCTOR
Autor::~Autor(){
}
