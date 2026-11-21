#ifndef TEXTO_H
#define TEXTO_H

#include "Fecha.h"
#include "Libro.h"

class Texto : public Libro {
   private:
    String materia;
    Fecha fechaPublicado;

   public:
    // CONSTRUCTOR
    Texto(long int i, String t, String e, float p, String m, Fecha f);

    // GETTERS
    String getMaterial();
    Fecha getFechaPublicado();

    // METODOS
    float calcularPrecioVenta() override;
    TipoLibro obtenerTipo() override;

    // DESTRUCTOR
    ~Texto();
};

#endif  // TEXTO_H
