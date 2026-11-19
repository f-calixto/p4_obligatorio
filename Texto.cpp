#include "Texto.h"

//CONSTRUCTOR
Texto :: Texto(long int i, String t, String e, float p, int u, String m, Fecha f) : Libro(i, t, e, p, u), fechaPublicado(f){
    materia = m;
}

//GETTERS
String Texto :: getMaterial(){
    return materia;
}

Fecha Texto :: getFechaPublicado(){
    return fechaPublicado;
}

//METODOS
float Texto :: calcularPrecioVenta(){
    Fecha limite(1, 1, 2026);

    if(fechaPublicado < limite)
        return getPrecioBase() * 0.75;
    else
        return getPrecioBase();
}

TipoLibro Texto :: obtenerTipo(){
    return TEXTO;
}

//DESTRUCTOR
Texto :: ~Texto(){

}
