#include <iostream>
#include <cstdlib> // PARA SYSTEM CLS
#include "Autor.h"
#include "Escolar.h"
#include "Fachada.h"
#include "Novela.h"
#include "Texto.h"
using namespace std;

//PROCEDIMIENTOS CAPA GRAFICA
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
            if (autor != NULL) {
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

//PROGRAMA MAIN

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
                if(error == ERRORNULO)
                    cout << "Se ha ingresado el autor correctamente" << endl;
                else
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
                        if(f.esValida()){
                            cout << "   >Es escolar: " << endl;
                            cout << "   1. Si" << endl;
                            cout << "   2. No" << endl;
                            cout << "   >Ingrese una opcion: ";
                            cin >> escolar;
                            if(escolar >= 1 && escolar <= 2){
                                if(escolar == 1){
                                    int anio;
                                    cout << "   >Ingrese Anio de escuela (1-6): ";
                                    cin >> anio;
                                    if(anio >= 1 && anio <= 6){
                                        Escolar * es = new Escolar(isbn, titulo, editorial, precioBase, materia, f, anio);
                                        fachada.registrarLibro(es, error);
                                    }else
                                        error = ERRORINGRESO;
                                }else{
                                    Texto * tex = new Texto(isbn, titulo, editorial, precioBase, materia, f);
                                    fachada.registrarLibro(tex, error);
                                }
                            } else{
                                error = ERRORINGRESO;
                            }
                        }else
                            error = FECHAINCORRECTA;
                    break;
                    }
                    default:
                        error = ERRORINGRESO;
                    break;
                }
                cout << "==============================================" << endl;
                if(error == ERRORNULO){
                    cout << "Se ha ingresado el libro correctamente" << endl;;
                }else{
                    imprimirError(error);
                }
                system("pause");
            break;
            }
            case 3:{
                // ==================== REQUERIMIENTO 3 ====================
                system("cls");
                cout << "==============================================" << endl;
                cout << "           ASOCIAR AUTOR A NOVELA" << endl;
                cout << "==============================================" << endl;
                long int isbn, cedula;

                cout << "   >Ingrese ISBN: ";
                cin >> isbn;
                cout << "   >Ingrese Cedula del autor: ";
                cin >> cedula;
                fachada.asociarAutorNovela(cedula, isbn, error);
                cout << "==============================================" << endl;
                if (error == ERRORNULO) {
                    cout << "Autor asociado a la novela." << endl;
                } else {
                    imprimirError(error);
                }
                system("pause");
            break;
            }
            case 4:{
                // ==================== REQUERIMIENTO 6 ====================
                system("cls");
                cout << "==============================================" << endl;
                cout << "           Listar Autores" << endl;
                cout << "==============================================" << endl;
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
                cout << "==============================================" << endl;
                system("pause");
            break;
            }
            case 5:{
                bool listarlibrosmenu = true;
                do{
                    int opc;
                    system("cls");
                    cout << "==============================================" << endl;
                    cout << "               Listar Libros" << endl;
                    cout << "==============================================" << endl;
                    cout << "1. Listar libros por frase" << endl;
                    cout << "2. Listar libro por ISBN" << endl;
                    cout << "3. Registrar venta por ISBN" << endl;
                    cout << "4. Recaudacion por editorial" << endl;
                    cout << "5. Unidades vendidas por tipo" << endl;
                    cout << "6. Libro mas vendido por editorial" << endl;
                    cout << "0. Salir" << endl;
                    cout << "==============================================" << endl;
                    cout << "   >Ingrese una opcion: ";
                    cin >> opc;
                    switch(opc){
                        case 1:{
                            // ==================== REQUERIMIENTO 4 ====================
                            system("cls");
                            cout << "==============================================" << endl;
                            cout << "         Listar libros por frase" << endl;
                            cout << "==============================================" << endl;
                            String frase;
                            Iterador librosPorFrase;
                            cout << "   >Ingrese Frase: ";
                            frase.scan();
                            cout << "==============================================" << endl;
                            fachada.listarPorFrase(frase, error, librosPorFrase);
                            if (error != ERRORNULO) {
                                imprimirError(error);
                            } else {
                                while (librosPorFrase.hayMasObjetos()) {
                                    Libro* libro = (Libro*)librosPorFrase.proximoObjeto();
                                    imprimirLibroBasico(libro);
                                }
                            }
                            cout << "==============================================" << endl;
                            system("pause");
                        break;
                        }
                        case 2:{
                            // ==================== REQUERIMIENTO 5 ====================
                            system("cls");
                            cout << "==============================================" << endl;
                            cout << "         Listar libros por ISBN" << endl;
                            cout << "==============================================" << endl;
                            long int isbn;
                            Libro * libro = NULL;
                            cout << "   >Ingrese ISBN: ";
                            cin >> isbn;
                            cout << "==============================================" << endl;
                            fachada.listarLibro(isbn, error, libro);
                            if (error != ERRORNULO) {
                                imprimirError(error);
                            } else {
                                imprimirDetalleLibro(libro);
                            }
                            cout << "==============================================" << endl;
                            system("pause");
                        break;
                        }
                        case 3:{
                            // ==================== REQUERIMIENTO 7 ====================
                            system("cls");
                            cout << "==============================================" << endl;
                            cout << "         Registrar venta por ISBN" << endl;
                            cout << "==============================================" << endl;
                            long int isbn;
                            cout << "   >Ingrese ISBN: ";
                            cin >> isbn;
                            cout << "==============================================" << endl;
                            float importe;
                            fachada.registrarVenta(isbn, error, importe);
                            if (error != ERRORNULO) {
                                imprimirError(error);
                            } else {
                                cout << "Importe de la venta del libro: " << importe << endl;
                            }
                            cout << "==============================================" << endl;
                            system("pause");
                        }
                        break;
                        case 4:{
                            // ==================== REQUERIMIENTO 8 ====================
                            system("cls");
                            cout << "==============================================" << endl;
                            cout << "         Recaudacion por editorial" << endl;
                            cout << "==============================================" << endl;
                            String frase;
                            cout << "   >Ingrese editorial: ";
                            frase.scan();
                            cout << "==============================================" << endl;
                            cout << "Recaudacion: "<< fachada.recaudacionEditorial(frase) << endl;
                            cout << "==============================================" << endl;
                            system("pause");
                        break;
                        }
                        case 5:{
                            // ==================== REQUERIMIENTO 9 ====================
                            system("cls");
                            cout << "==============================================" << endl;
                            cout << "         Unidades vendidas por tipo" << endl;
                            cout << "==============================================" << endl;
                            int novelas = 0;
                            int textos = 0;
                            int escolares = 0;
                            float precioBase;
                            cout << "   >Ingrese precio base:" ;
                            cin >> precioBase;
                            fachada.unidadesVendidasPorTipo(precioBase, novelas, textos, escolares);
                            cout << "==============================================" << endl;
                            cout << "Novelas: " << novelas << endl;
                            cout << "Textos comunes: " << textos << endl;
                            cout << "Textos escolares: " << escolares << endl;
                            cout << "==============================================" << endl;
                            system("pause");
                        break;
                        }
                        case 6:{
                            // ==================== REQUERIMIENTO 10 ====================
                            system("cls");
                            cout << "==============================================" << endl;
                            cout << "         Libro mas vendido por editorial" << endl;
                            cout << "==============================================" << endl;
                            String frase;
                            Libro* masVendido = NULL;
                            cout << "   >Ingrese editorial: ";
                            frase.scan();
                            fachada.listarMasVendidoEditorial(frase, error, masVendido);
                            cout << "==============================================" << endl;
                            if (error != ERRORNULO) {
                                imprimirError(error);
                            } else {
                                imprimirDetalleLibro(masVendido);
                            }
                            cout << "==============================================" << endl;
                            system("pause");
                        break;
                        }
                        case 0:{
                            listarlibrosmenu = false;
                        break;
                        }
                        default:{
                            error = ERRORINGRESO;
                            cout << "==============================================" << endl;
                            imprimirError(error);
                            system("pause");
                        break;
                        }
                    }
                }while(listarlibrosmenu);

            break;
            }
            case 0:{
                ejecutar = false;
            break;
            }
            default:{
                error = ERRORINGRESO;
                cout << "==============================================" << endl;
                imprimirError(error);
                system("pause");
                break;
            }
        }
    }while(ejecutar);

}
