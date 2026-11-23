#include "DiccionarioLibros.h"

//CONSTRUCTOR NODO
DiccionarioLibros::Nodo::Nodo(Libro* libro){
    info = libro;
    sig = NULL;
}

//CONSTRUCTOR DICCIONARIO
DiccionarioLibros::DiccionarioLibros(){
    for(int i = 0; i < B; i++){
        tabla[i] = NULL;
    }
}

//FUNCION DE DISPERSION
int DiccionarioLibros::H(long int isbn){
    return isbn % B;
}

//PRIMITIVAS
void DiccionarioLibros::Insert(Libro* libro){
    int pos = H(libro->getIsbn());
    Nodo* nuevo = new Nodo(libro);
    nuevo->sig = tabla[pos];
    tabla[pos] = nuevo;
}

bool DiccionarioLibros::Member(long int isbn){
    Nodo* aux = tabla[H(isbn)];
    while(aux != NULL && aux->info->getIsbn() != isbn){
        aux = aux->sig;
    }
    return aux != NULL;
}

Libro* DiccionarioLibros::Find(long int isbn){
    Nodo* aux = tabla[H(isbn)];
    while(aux != NULL && aux->info->getIsbn() != isbn){
        aux = aux->sig;
    }
    return aux->info;
}

bool DiccionarioLibros::estaVacio(){
    int i=0;
    while(i < B && tabla[i] == NULL){
        i++;
    }
    return i == B;
}

//METODOS
void DiccionarioLibros::buscarPorFrase(String frase, Iterador &iter){
    frase.aMinuscula();

    for(int i = 0; i < B; i++){
        Nodo* actual = tabla[i];

        while(actual != NULL){
            String titulo = actual->info->getTitulo();
            titulo.aMinuscula();

            if(titulo.comienzaCon(frase)){
                iter.insertar(actual->info);
            }
            actual = actual->sig;
        }
    }
}

float DiccionarioLibros::calcularRecaudacion(String editorial){
    float total = 0;
    for(int i = 0; i < B; i++){
        Nodo* aux = tabla[i];
        while(aux != NULL){
            if(aux->info->getEditorial() == editorial){
                total += (aux->info->calcularPrecioVenta()) * (aux->info->getUnidadesVendidas());
            }
            aux = aux->sig;
        }
    }
    return total;
}

void DiccionarioLibros::calcularUnidadesVendidas(float precio, int &novelas, int &textos, int &escolares){
    novelas = 0;
    textos = 0;
    escolares = 0;
    for(int i = 0; i < B; i++){
        Nodo* aux = tabla[i];
        while(aux != NULL){
            Libro* libro = aux->info;
            if(libro->getPrecioBase() > precio){
                switch(libro->obtenerTipo()){
                    case NOVELA:
                        novelas += libro->getUnidadesVendidas();
                        break;

                    case TEXTO:
                        textos += libro->getUnidadesVendidas();
                        break;

                    case ESCOLAR:
                        escolares += libro->getUnidadesVendidas();
                        break;
                }
            }
            aux = aux->sig;
        }
    }
}

Libro* DiccionarioLibros::libroMasVendidoEditorial(String editorial){
    Libro* masVendido = NULL;
    for(int i = 0; i < B; i++){
        Nodo* aux = tabla[i];
        while(aux != NULL){
            if(aux->info->getEditorial() == editorial){
                if(masVendido == NULL || aux->info->getUnidadesVendidas() > masVendido->getUnidadesVendidas()){
                   masVendido = aux->info;
                }
            }
            aux = aux->sig;
        }
    }
    return masVendido;
}


//DESTRUCTOR
DiccionarioLibros::~DiccionarioLibros(){
    for(int i = 0; i < B; i++){
        Nodo* aux = tabla[i];
        while(aux != NULL){
            Nodo* siguiente = aux->sig;
            delete aux->info; //BORRA ADEMAS EL LIBRO
            delete aux;
            aux = siguiente;
        }
    }
}
