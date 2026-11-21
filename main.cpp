#include <iostream>

#include "Autor.h"
#include "Escolar.h"
#include "Fachada.h"
#include "Novela.h"
#include "Texto.h"
using namespace std;

/*
Codigo de prueba anterior, conservado como referencia

int main() {
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
    cout << "\nExiste 22222222: " << autores.Member(22222222) << endl;

    cout << "Existe 99999999: " << autores.Member(99999999) << endl;

    // PROBAR FIND
    Autor* encontrado = autores.Find(44444444);

    if (encontrado != NULL) {
        cout << "\nAutor encontrado: ";
        encontrado->getNombre().print();
        cout << endl;
    }

    // PROBAR LISTADO ORDENADO
    Iterador iterAutores;
    autores.listarEnOrden(iterAutores);

    cout << "\nAutores ordenados por cedula:" << endl;

    while (iterAutores.hayMasObjetos()) {
        Objeto* obj = iterAutores.proximoObjeto();

        if (obj->obtenerTipoObjeto() == AUTOR) {
            Autor* a = (Autor*)obj;

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
    libros.Insert(
        new Novela(101, "Cuentos Infantiles", "Planeta", 1000, "InFaNTIL"));

    libros.Insert(new Novela(202, "La noche", "Planeta", 1000, "Terror"));

    Fecha fecha1(15, 6, 2025);

    libros.Insert(new Texto(303, "Historia de Uruguay", "Santillana", 1000,
                            "Historia", fecha1));

    Fecha fecha2(10, 3, 2025);

    libros.Insert(new Escolar(404, "Ciencias Naturales", "Santillana", 1000,
                              "Ciencias", fecha2, 2));

    // PROBAR MEMBER
    cout << "\nExiste ISBN 101: " << libros.Member(101) << endl;

    cout << "Existe ISBN 999: " << libros.Member(999) << endl;

    // PROBAR FIND
    Libro* libro = libros.Find(101);

    if (libro != NULL) {
        cout << "\nLibro encontrado:" << endl;
        cout << "ISBN: " << libro->getIsbn() << endl;

        cout << "Titulo: ";
        libro->getTitulo().print();

        cout << "\nPrecio venta: " << libro->calcularPrecioVenta() << endl;
    }

    // PROBAR BUSQUEDA POR FRASE
    Iterador iterLibros;
    libros.buscarPorFrase("C", iterLibros);

    cout << "\n\nLibros que comienzan con C:" << endl;

    while (iterLibros.hayMasObjetos()) {
        Objeto* obj = iterLibros.proximoObjeto();

        if (obj->obtenerTipoObjeto() == LIBRO) {
            Libro* l = (Libro*)obj;

            cout << l->getIsbn() << " - ";
            l->getTitulo().print();
            cout << " - Tipo: " << l->obtenerTipo();
            cout << endl;
        }
    }

    // PROBAR RECAUDACION
    cout << "\nRecaudacion Planeta: " << libros.calcularRecaudacion("Planeta")
         << endl;

    cout << "Recaudacion Santillana: "
         << libros.calcularRecaudacion("Santillana") << endl;

    // PROBAR UNIDADES VENDIDAS
    int novelas = 0;
    int textos = 0;
    int escolares = 0;

    libros.calcularUnidadesVendidas(900, novelas, textos, escolares);

    cout << "\nUnidades vendidas (precio base > 900):" << endl;
    cout << "Novelas: " << novelas << endl;
    cout << "Textos: " << textos << endl;
    cout << "Escolares: " << escolares << endl;

    // PROBAR LIBRO MAS VENDIDO
    Libro* masVendido = libros.libroMasVendidoEditorial("Planeta");

    if (masVendido != NULL) {
        cout << "\nLibro mas vendido de Planeta: ";
        masVendido->getTitulo().print();
        cout << endl;
    }
}
*/

void imprimirError(TipoError error) {
    if (error != ERRORNULO) {
        ImprimirMensaje(error);
        cout << endl;
    }
}

void imprimirLibroBasico(Libro* libro) {
    cout << libro->getIsbn() << " - ";
    libro->getTitulo().print();
    cout << " - ";

    switch (libro->obtenerTipo()) {
        case NOVELA:
            cout << "Novela";
            break;
        case TEXTO:
            cout << "Texto";
            break;
        case ESCOLAR:
            cout << "Escolar";
            break;
    }

    cout << endl;
}

void imprimirDetalleLibro(Libro* libro) {
    cout << "ISBN: " << libro->getIsbn() << endl;
    cout << "Titulo: ";
    libro->getTitulo().print();
    cout << endl;
    cout << "Editorial: ";
    libro->getEditorial().print();
    cout << endl;
    cout << "Precio base: " << libro->getPrecioBase() << endl;
    cout << "Precio de venta: " << libro->calcularPrecioVenta() << endl;
    cout << "Unidades vendidas: " << libro->getUnidadesVendidas() << endl;

    switch (libro->obtenerTipo()) {
        case NOVELA: {
            Novela* novela = (Novela*)libro;
            cout << "Tipo: Novela" << endl;
            cout << "Genero: ";
            novela->getGenero().print();
            cout << endl;

            Autor* autor = novela->getAutor();
            if (autor != nullptr) {
                cout << "Autor: " << autor->getCedula() << " - ";
                autor->getNombre().print();
                cout << " ";
                autor->getApellido().print();
                cout << endl;
            }
            break;
        }
        case TEXTO: {
            Texto* texto = (Texto*)libro;
            Fecha fecha = texto->getFechaPublicado();
            cout << "Tipo: Texto" << endl;
            cout << "Materia: ";
            texto->getMaterial().print();
            cout << endl;
            cout << "Fecha de publicacion: " << fecha.GetDia() << "/"
                 << fecha.GetMes() << "/" << fecha.GetAnio() << endl;
            break;
        }
        case ESCOLAR: {
            Escolar* escolar = (Escolar*)libro;
            Fecha fecha = escolar->getFechaPublicado();
            cout << "Tipo: Escolar" << endl;
            cout << "Materia: ";
            escolar->getMaterial().print();
            cout << endl;
            cout << "Fecha de publicacion: " << fecha.GetDia() << "/"
                 << fecha.GetMes() << "/" << fecha.GetAnio() << endl;
            cout << "Anio escolar: " << escolar->getAnioEscuela() << endl;
            break;
        }
    }
}

int main() {
    Fachada fachada;
    TipoError error = ERRORNULO;

    // ==================== REQUERIMIENTO 1 ====================
    cout << "\n=== REQUERIMIENTO 1: REGISTRAR AUTORES ===" << endl;
    fachada.registrarAutor(new Autor(44444444, "Juan", "Perez"), error);
    imprimirError(error);
    fachada.registrarAutor(new Autor(22222222, "Maria", "Lopez"), error);
    imprimirError(error);
    fachada.registrarAutor(new Autor(55555555, "Pedro", "Gomez"), error);
    imprimirError(error);

    // ==================== REQUERIMIENTO 2 ====================
    cout << "\n=== REQUERIMIENTO 2: REGISTRAR LIBROS ===" << endl;
    fachada.registrarLibro(
        new Novela(101, "Cuentos Infantiles", "Planeta", 1000, "Infantil"),
        error);
    imprimirError(error);
    fachada.registrarLibro(
        new Novela(202, "Cuentos de terror", "Planeta", 1200, "Terror"), error);
    imprimirError(error);

    Fecha fechaTexto(15, 6, 2025);
    fachada.registrarLibro(new Texto(303, "Ciencia para todos", "Santillana",
                                     900, "Ciencias", fechaTexto),
                           error);
    imprimirError(error);

    Fecha fechaEscolar(10, 3, 2025);
    fachada.registrarLibro(new Escolar(404, "Ciencias escolares", "Santillana",
                                       800, "Ciencias", fechaEscolar, 2),
                           error);
    imprimirError(error);

    // ==================== REQUERIMIENTO 3 ====================
    cout << "\n=== REQUERIMIENTO 3: ASOCIAR AUTOR A NOVELA ===" << endl;
    fachada.asociarAutorNovela(44444444, 101, error);
    if (error == ERRORNULO) {
        cout << "Autor asociado a la novela 101." << endl;
    } else {
        imprimirError(error);
    }

    // ==================== REQUERIMIENTO 4 ====================
    cout << "\n=== REQUERIMIENTO 4: LISTAR LIBROS POR FRASE ===" << endl;
    Iterador librosPorFrase;
    fachada.listarPorFrase("C", error, librosPorFrase);
    if (error != ERRORNULO) {
        imprimirError(error);
    } else {
        while (librosPorFrase.hayMasObjetos()) {
            Libro* libro = (Libro*)librosPorFrase.proximoObjeto();
            imprimirLibroBasico(libro);
        }
    }

    // ==================== REQUERIMIENTO 5 ====================
    cout << "\n=== REQUERIMIENTO 5: LISTAR LIBRO POR ISBN ===" << endl;
    Libro* libro = nullptr;
    fachada.listarLibro(101, error, libro);
    if (error != ERRORNULO) {
        imprimirError(error);
    } else {
        imprimirDetalleLibro(libro);
    }

    // ==================== REQUERIMIENTO 6 ====================
    cout << "\n=== REQUERIMIENTO 6: LISTAR AUTORES ===" << endl;
    Iterador autores;
    fachada.listarAutores(error, autores);
    if (error != ERRORNULO) {
        imprimirError(error);
    } else {
        while (autores.hayMasObjetos()) {
            Autor* autor = (Autor*)autores.proximoObjeto();
            cout << autor->getCedula() << " - ";
            autor->getNombre().print();
            cout << " ";
            autor->getApellido().print();
            cout << endl;
        }
    }

    // ==================== REQUERIMIENTO 7 ====================
    cout << "\n=== REQUERIMIENTO 7: REGISTRAR VENTAS ===" << endl;
    float importe = fachada.registrarVenta(101, error);
    if (error != ERRORNULO) {
        imprimirError(error);
    } else {
        cout << "Importe de la venta del libro 101: " << importe << endl;
    }

    importe = fachada.registrarVenta(101, error);
    if (error != ERRORNULO) {
        imprimirError(error);
    } else {
        cout << "Importe de la venta del libro 101: " << importe << endl;
    }

    importe = fachada.registrarVenta(202, error);
    if (error != ERRORNULO) {
        imprimirError(error);
    } else {
        cout << "Importe de la venta del libro 202: " << importe << endl;
    }

    importe = fachada.registrarVenta(303, error);
    if (error != ERRORNULO) {
        imprimirError(error);
    } else {
        cout << "Importe de la venta del libro 303: " << importe << endl;
    }

    // ==================== REQUERIMIENTO 8 ====================
    cout << "\n=== REQUERIMIENTO 8: RECAUDACION POR EDITORIAL ===" << endl;
    cout << "Recaudacion de Planeta: "
         << fachada.recaudacionEditorial("Planeta") << endl;

    // ==================== REQUERIMIENTO 9 ====================
    cout << "\n=== REQUERIMIENTO 9: UNIDADES VENDIDAS POR TIPO ===" << endl;
    int novelas = 0;
    int textos = 0;
    int escolares = 0;
    fachada.unidadesVendidasPorTipo(850, novelas, textos, escolares);
    cout << "Novelas: " << novelas << endl;
    cout << "Textos comunes: " << textos << endl;
    cout << "Textos escolares: " << escolares << endl;

    // ==================== REQUERIMIENTO 10 ====================
    cout << "\n=== REQUERIMIENTO 10: LIBRO MAS VENDIDO POR EDITORIAL ==="
         << endl;
    Libro* masVendido = nullptr;
    fachada.listarMasVendidoEditorial("Planeta", error, masVendido);
    if (error != ERRORNULO) {
        imprimirError(error);
    } else {
        imprimirDetalleLibro(masVendido);
    }
}
