#ifndef AUTOR_H
#define AUTOR_H

#include "String.h"
#include "Objeto.h"

class Autor: public Objeto{
    private:
        long int cedula;
        String nombre;
        String apellido;

    public:
        //CONSTRUCTOR
        Autor(long int c, String n, String a);

        //GETTERS
        long int getCedula();
        String getNombre();
        String getApellido();

        //DESTRUCTOR
        ~Autor();
};

#endif // AUTOR_H_INCLUDED
