#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"
#include "Autor.h"

class Novela: public Libro{
    private:
        String genero;
        Autor* autor;

    public:
        //CONSTRUCTOR
        Novela(long int i, String t, String e, float p, int u, String g);

        //GETTERS Y SET
        Autor* getAutor();
        String getGenero();
        void setAutor(Autor * a);

        //METODOS
        float calcularPrecioVenta();
        TipoLibro obtenerTipo();

        //DESTRUCTOR
        ~Novela();
};

#endif // NOVELA_H_INCLUDED
