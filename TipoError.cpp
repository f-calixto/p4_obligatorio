#include "TipoError.h"

#include <iostream>
using namespace std;

void ImprimirMensaje(TipoError error) {
    switch (error) {
        case ERRORNULO:
            break;
        case AUTORREGISTRADO: {
            cout << "El autor ya esta registrado.";
            break;
        }
        case LIBROREGISTRADO: {
            cout << "El libro ya esta registrado.";
            break;
        }
        case LIBRONOEXISTE: {
            cout << "El libro no existe.";
            break;
        }
        case AUTORNOEXISTE: {
            cout << "El autor no existe.";
            break;
        }
        case NOESNOVELA: {
            cout << "El libro no es una novela.";
            break;
        }
        case LIBROSFRASE: {
            cout << "No hay libros que coincidan con la frase.";
            break;
        }
        case AUTORESVACIO: {
            cout << "No hay autores registrados.";
            break;
        }
        case EDITORIALSINLIBROS: {
            cout << "No hay libros de esa editorial.";
            break;
        }
        case ERRORINGRESO: {
            cout << "Ha ingresado un valor incorrecto";
            break;
        }
        case FECHAINCORRECTA: {
            cout << "Ha ingresado una fecha no valida";
            break;
        }
    }
}
