#ifndef AUTOR_H
#define AUTOR_H

#include "Objeto.h"
#include "String.h"

class Autor : public Objeto {
   private:
    long int cedula;
    String nombre;
    String apellido;

   public:
    // CONSTRUCTOR
    Autor(long int c, String n, String a);

    // GETTERS
    long int getCedula();
    String getNombre();
    String getApellido();
    TipoObjeto obtenerTipoObjeto() override;

    // DESTRUCTOR
    ~Autor();
};

#endif  // AUTOR_H
