#include <iostream>
#include <cstdlib> // PARA SYSTEM CLS
#include "Autor.h"
#include "Escolar.h"
#include "Fachada.h"
#include "Novela.h"
#include "Texto.h"
using namespace std;

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
    int opcion;
    bool ejecutar = true;
    do{
        system("cls");
        cout << "==============================================" << endl;
        cout << " _     ___ ____  ____  _____ ____  ___    _    " << endl;
        cout << "| |   |_ _| __ )|  _ \\| ____|  _ \\|_ _|  / \\   " << endl;
        cout << "| |    | ||  _ \\| |_) |  _| | |_) || |  / _ \\  " << endl;
        cout << "| |___ | || |_) |  _ <| |___|  _ < | | / ___ \\ " << endl;
        cout << "|_____|___|____/|_| \\_\\_____|_| \\_\\___/_/   \\_\\" << endl;
        cout << endl;
        cout << "==============================================" << endl;
        cout << "1. Registrar autor" << endl;
        cout << "2. Registrar libro" << endl;
        cout << "3. Asociar autor a novela" << endl;
        cout << "4. Listar autores" << endl;
        cout << "5. Listar libros" << endl;
        cout << "0. Salir" << endl;
        cout << "==============================================" << endl;
        cout << "   >Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion){
            case 1:{
                // ==================== REQUERIMIENTO 1 ====================
                system("cls");
                cout << "==============================================" << endl;
                cout << "             REGISTRAR AUTORES" << endl;
                cout << "==============================================" << endl;
                long int cedula;
                String nombre, apellido;
                cout << "   >Ingrese Cedula: ";
                cin >> cedula;
                cout << "   >Ingrese Nombre: ";
                nombre.scan();
                cout << "   >Ingrese Apellido: ";
                apellido.scan();
                Autor* au = new Autor(cedula, nombre, apellido);
                fachada.registrarAutor(au, error);
                cout << "==============================================" << endl;
                imprimirError(error);
                system("pause");
            break;
            }
            case 2:{
                // ==================== REQUERIMIENTO 2 ====================
                system("cls");
                cout << "==============================================" << endl;
                cout << "             REGISTRAR LIBROS" << endl;
                cout << "==============================================" << endl;
                long int isbn;
                String titulo, editorial;
                float precioBase;
                int tipo;

                cout << "   >Ingrese ISBN: ";
                cin >> isbn;
                cout << "   >Ingrese Titulo: ";
                titulo.scan();
                cout << "   >Ingrese Editorial: ";
                editorial.scan();
                cout << "   >Ingrese Precio Base: ";
                cin >> precioBase;

                cout << endl;
                cout << "==============================================" << endl;
                cout << "              TIPO DE LIBRO                   " << endl;
                cout << "==============================================" << endl;
                cout << "   1. Novela" << endl;
                cout << "   2. Texto" << endl;
                cout << "==============================================" << endl;
                cout << "   >Ingrese una opcion: ";
                cin >> tipo;
                switch(tipo){
                    case 1:{
                        String genero;
                        cout << "   >Ingrese Genero: ";
                        genero.scan();
                        Novela * nov = new Novela(isbn, titulo, editorial, precioBase, genero);
                        fachada.registrarLibro(nov, error);
                    break;
                    }
                    case 2:{
                        String materia;
                        int d, m, a;
                        int escolar;
                        cout << "   >Ingrese Materia: ";
                        materia.scan();
                        cout << "   >Ingrese Fecha de publicacion: " << endl;
                        cout << "   >Dia: ";
                        cin >> d;
                        cout << "   >Mes: ";
                        cin >> m;
                        cout << "   >Anio: ";
                        cin >> a;
                        Fecha f(d, m, a);
                        cout << "   >Es escolar: " << endl;
                        cout << "   1. Si" << endl;
                        cout << "   2. No" << endl;
                        cout << "   >Ingrese una opcion: ";
                        cin >> escolar;
                        if(escolar == 1){
                            int anio;
                            cout << "   >Ingrese Anio de escuela: ";
                            cin >> anio;
                            Escolar * es = new Escolar(isbn, titulo, editorial, precioBase, materia, f, anio);
                            fachada.registrarLibro(es, error);
                        }else{
                            Texto * tex = new Texto(isbn, titulo, editorial, precioBase, materia, f);
                            fachada.registrarLibro(tex, error);
                        }
                    break;
                    }
                    default:
                        cout << "   ERROR: no ha ingresado correctamente el tipo de libro";
                    break;
                }
                cout << "==============================================" << endl;
                imprimirError(error);
                system("pause");
            break;
            }

        }
    }while(ejecutar);


    /*

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
   */
}
