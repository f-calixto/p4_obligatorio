#ifndef NOVELA_H
#define NOVELA_H

#include "Autor.h"
#include "Libro.h"

class Novela : public Libro {
   private:
    String genero;
    Autor* autor;

   public:
    // CONSTRUCTOR
    Novela(long int i, String t, String e, float p, String g);

    // GETTERS Y SET
    Autor* getAutor();
    String getGenero();
    void setAutor(Autor* a);

    // METODOS
    float calcularPrecioVenta() override;
    TipoLibro obtenerTipo() override;

    // DESTRUCTOR
    ~Novela();
};

#endif  // NOVELA_H_INCLUDED
