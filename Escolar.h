#ifndef ESCOLAR_H
#define ESCOLAR_H

#include "Texto.h"

class Escolar : public Texto {
   private:
    int anioEscuela;

   public:
    // CONSTRUCTOR
    Escolar(long int i, String t, String e, float p, int u, String m, Fecha f,
            int a);

    // GETTERS
    int getAnioEscuela();
    float calcularPrecioVenta() override;

    // METODOS
    TipoLibro obtenerTipo() override;

    // DESTRUCTOR
    ~Escolar();
};

#endif  // ESCOLAR_H
