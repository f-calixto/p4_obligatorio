#include "Libro.h"

 //CONSTRUCTOR
Libro :: Libro(long int i, String t, String e, float p, int u){
    isbn = i;
    titulo = t;
    editorial = e;
    precioBase = p;
    unidadesVendidas = u;
}


//GETTERS
long int Libro :: getIsbn(){
    return isbn;
}

String Libro :: getTitulo(){
    return titulo;
}

String Libro :: getEditorial(){
    return editorial;
}

float Libro :: getPrecioBase(){
    return precioBase;
}

//METODOS
void Libro :: registrarVenta(){
    unidadesVendidas++;
}

TipoObjeto Libro :: obtenerTipoObjeto(){
    return LIBRO;
}

//DESTRUCTOR
Libro :: ~Libro(){
}
