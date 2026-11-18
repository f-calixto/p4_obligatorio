#ifndef TEXTO_H
#define TEXTO_H

#include "Libro.h"
#include "Fecha.h"

class Texto: public Libro{
    private:
        String materia;
        Fecha fechaPublicado;

    public:
        //CONSTRUCTOR
        Texto(long int i, String t, String e, float p, int u, String m, Fecha f);

        //GETTERS
        String getMaterial();
        Fecha getFechaPublicado();

        //METODOS
        float calcularPrecioVenta();
        TipoLibro obtenerTipo();

        //DESTRUCTOR
        ~Texto();
};

#endif // TEXTO_H
