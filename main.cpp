#include "Fachada.h"

#include "Novela.h"
#include "Texto.h"
#include "Escolar.h"
#include "Autor.h"
#include <iostream>
using namespace std;
int main()
{
    //PRUEBA OBJETO LIBRO (NOVELA, TEXTO, ESCOLAR)
        // NOVELA
        Novela novela(12345, "El Principito", "Planeta", 1000, 0, "InFaNTIL");

        cout << "=== NOVELA ===" << endl;
        cout << "ISBN: " << novela.getIsbn() << endl;
        cout << "Genero: "; novela.getGenero().print();
        cout << "\nPrecio venta: " << novela.calcularPrecioVenta() << endl;


        // TEXTO
        Fecha fecha1(15, 6, 2025);

        Texto texto(23456, "Matematica", "Santillana", 1000, 0, "Matematica", fecha1);

        cout << "\n=== TEXTO ===" << endl;
        cout << "ISBN: " << texto.getIsbn() << endl;
        cout << "Precio venta: "
             << texto.calcularPrecioVenta() << endl;


        // ESCOLAR
        Fecha fecha2(10, 3, 2025);

        Escolar escolar(34567, "Ciencias Naturales", "Santillana", 1000, 0, "Ciencias", fecha2, 2);

        cout << "\n=== ESCOLAR ===" << endl;
        cout << "ISBN: " << escolar.getIsbn() << endl;
        cout << "Anio escolar: " << escolar.getAnioEscuela() << endl;
        cout << "Precio venta: " << escolar.calcularPrecioVenta() << endl;

    // PRUEBA OBJETO AUTOR
        // CREAR AUTOR
        Autor* autor = new Autor(12345678, "Juan", "Perez");

        // PROBAR GETTERS
        cout << "\n=== AUTOR ===" << endl;

        cout << "Cedula: " << autor->getCedula() << endl;

        cout << "Nombre: ";
        autor->getNombre().print();

        cout << "\nApellido: ";
        autor->getApellido().print();

        // PROBAR POLIMORFISMO
        Objeto* obj = autor;

        if (obj->obtenerTipoObjeto() == AUTOR)
            cout << "\nTipo de objeto: AUTOR" << endl;
        else
            cout << "\nERROR: Tipo incorrecto" << endl;

        // LIBERAR MEMORIA
        delete autor;

}
