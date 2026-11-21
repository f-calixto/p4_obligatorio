#include "TipoError.h"
#include "String.h"

void ImprimirMensaje(TipoError error) {
    switch (error) {
        case ERRORNULO:
            break;
        case AUTORREGISTRADO: {
            String mensaje("El autor ya esta registrado.");
            mensaje.print();
            break;
        }
        case LIBROREGISTRADO: {
            String mensaje("El libro ya esta registrado.");
            mensaje.print();
            break;
        }
        case LIBRONOEXISTE: {
            String mensaje("El libro no existe.");
            mensaje.print();
            break;
        }
        case AUTORNOEXISTE: {
            String mensaje("El autor no existe.");
            mensaje.print();
            break;
        }
        case NOESNOVELA: {
            String mensaje("El libro no es una novela.");
            mensaje.print();
            break;
        }
        case LIBROSFRASE: {
            String mensaje("No hay libros que coincidan con la frase.");
            mensaje.print();
            break;
        }
        case AUTORESVACIO: {
            String mensaje("No hay autores registrados.");
            mensaje.print();
            break;
        }
        case EDITORIALSINLIBROS: {
            String mensaje("No hay libros de esa editorial.");
            mensaje.print();
            break;
        }
    }
}