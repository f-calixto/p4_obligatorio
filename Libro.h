#ifndef LIBRO_H
#define LIBRO_H

#include "TipoLibro.h"
#include "Objeto.h"
#include "String.h"

class Libro: public Objeto{
    private:
        long int isbn;
        String titulo;
        String editorial;
        float precioBase;
        int unidadesVendidas;

    public:
        //CONSTRUCTOR
        Libro(long int i, String t, String e, float p, int u);

        //GETTERS
        long int getIsbn();
        String getTitulo();
        String getEditorial();
        float getPrecioBase();

        //METODOS
        void registrarVenta();
        TipoObjeto obtenerTipoObjeto();

        //VIRTUALES
        virtual float calcularPrecioVenta() = 0;
        virtual TipoLibro obtenerTipo() = 0;

        //DESTRUCTOR
        ~Libro();

};
#endif // LIBRO_H
