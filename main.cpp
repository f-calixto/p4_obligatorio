#include "Fachada.h"

#include "Novela.h"
#include "Texto.h"
#include "Escolar.h"
#include "Autor.h"
#include <iostream>
using namespace std;
int main()
{
    // CREAR DICCIONARIOS
    DiccionarioAutores autores;
    DiccionarioLibros libros;

    // ====================================
    // PRUEBA DICCIONARIO AUTORES (AVL)
    // ====================================

    cout << "=== DICCIONARIO AUTORES ===" << endl;

    cout << "Esta vacio: " << autores.estaVacio() << endl;

    // INSERTAR AUTORES DESORDENADOS
    autores.Insert(new Autor(44444444, "Juan", "Perez"));
    autores.Insert(new Autor(22222222, "Maria", "Lopez"));
    autores.Insert(new Autor(55555555, "Pedro", "Gomez"));
    autores.Insert(new Autor(11111111, "Ana", "Silva"));
    autores.Insert(new Autor(33333333, "Luis", "Rodriguez"));

    // PROBAR MEMBER
    cout << "\nExiste 22222222: "
         << autores.Member(22222222) << endl;

    cout << "Existe 99999999: "
         << autores.Member(99999999) << endl;

    // PROBAR FIND
    Autor* encontrado = autores.Find(44444444);

    if(encontrado != NULL){
        cout << "\nAutor encontrado: ";
        encontrado->getNombre().print();
        cout << endl;
    }

    // PROBAR LISTADO ORDENADO
    Iterador iterAutores;
    autores.listarEnOrden(iterAutores);

    cout << "\nAutores ordenados por cedula:" << endl;

    while(iterAutores.hayMasObjetos()){
        Objeto* obj = iterAutores.proximoObjeto();

        if(obj->obtenerTipoObjeto() == AUTOR){
            Autor* a = (Autor*) obj;

            cout << a->getCedula() << " - ";
            a->getNombre().print();
            cout << " ";
            a->getApellido().print();
            cout << endl;
        }
    }

    // ====================================
    // PRUEBA DICCIONARIO LIBROS (HASH)
    // ====================================

    cout << "\n=== DICCIONARIO LIBROS ===" << endl;

    cout << "Esta vacio: " << libros.estaVacio() << endl;

    // INSERTAR LIBROS
    libros.Insert(new Novela(101, "Cuentos Infantiles",
                 "Planeta", 1000, 2, "InFaNTIL"));

    libros.Insert(new Novela(202, "La noche",
                 "Planeta", 1000, 3, "Terror"));

    Fecha fecha1(15, 6, 2025);

    libros.Insert(new Texto(303, "Historia de Uruguay",
                 "Santillana", 1000, 4,
                 "Historia", fecha1));

    Fecha fecha2(10, 3, 2025);

    libros.Insert(new Escolar(404, "Ciencias Naturales",
                 "Santillana", 1000, 5,
                 "Ciencias", fecha2, 2));

    // PROBAR MEMBER
    cout << "\nExiste ISBN 101: "
         << libros.Member(101) << endl;

    cout << "Existe ISBN 999: "
         << libros.Member(999) << endl;

    // PROBAR FIND
    Libro* libro = libros.Find(101);

    if(libro != NULL){
        cout << "\nLibro encontrado:" << endl;
        cout << "ISBN: " << libro->getIsbn() << endl;

        cout << "Titulo: ";
        libro->getTitulo().print();

        cout << "\nPrecio venta: "
             << libro->calcularPrecioVenta() << endl;
    }

    // PROBAR BUSQUEDA POR FRASE
    Iterador iterLibros;
    libros.buscarPorFrase("C", iterLibros);

    cout << "\n\nLibros que comienzan con C:" << endl;

    while(iterLibros.hayMasObjetos()){
        Objeto* obj = iterLibros.proximoObjeto();

        if(obj->obtenerTipoObjeto() == LIBRO){
            Libro* l = (Libro*) obj;

            cout << l->getIsbn() << " - ";
            l->getTitulo().print();
            cout << " - Tipo: " << l->obtenerTipo();
            cout << endl;
        }
    }

    // PROBAR RECAUDACION
    cout << "\nRecaudacion Planeta: "
         << libros.calcularRecaudacion("Planeta") << endl;

    cout << "Recaudacion Santillana: "
         << libros.calcularRecaudacion("Santillana") << endl;

    // PROBAR UNIDADES VENDIDAS
    int novelas = 0;
    int textos = 0;
    int escolares = 0;

    libros.calcularUnidadesVendidas(
        900, novelas, textos, escolares
    );

    cout << "\nUnidades vendidas (precio base > 900):" << endl;
    cout << "Novelas: " << novelas << endl;
    cout << "Textos: " << textos << endl;
    cout << "Escolares: " << escolares << endl;

    // PROBAR LIBRO MAS VENDIDO
    Libro* masVendido =
        libros.libroMasVendidoEditorial("Planeta");

    if(masVendido != NULL){
        cout << "\nLibro mas vendido de Planeta: ";
        masVendido->getTitulo().print();
        cout << endl;
    }

}
