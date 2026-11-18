#include "Novela.h"


//CONSTRUCTOR
Novela :: Novela(long int i, String t, String e, float p, int u, String g) : Libro(i, t, e, p, u){
    genero = g;
    autor = NULL;
}

//GETTERS Y SET
Autor* Novela :: getAutor(){
    return autor;
}

String Novela :: getGenero(){
    return genero;
}

void Novela :: setAutor(Autor * a){
    autor = a;
}

//METODOS
float Novela :: calcularPrecioVenta(){
    String aux = genero;
    aux.aMinuscula();
    if (aux == "infantil")
        return getPrecioBase() * 0.80;
    else
        return getPrecioBase();
}

TipoLibro Novela :: obtenerTipo(){
    return NOVELA;
}

Novela :: ~Novela(){

}
