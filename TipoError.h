#ifndef TIPOERROR_H
#define TIPOERROR_H

typedef enum TipoError{ // el numero entre parentesis representa en que requerimiento se encuentra ese error
    AUTORREGISTRADO, // el autor que se desea registrar ya existe (1)
    LIBROREGISTRADO, // el libro que se desea registrar ya existe (2)
    LIBRONOEXISTE,   // el libro no existe (3,5,7)
    AUTORNOEXISTE,   // el autor no existe (3)
    NOESNOVELA,      // el libro no es una novela (3)
    LIBROSFRASE,     // no existen libros con la frase ingresada (4)
    AUTORESVACIO    // no hay autores en el diccionario de autores (6)
};

#endif // TIPOERROR_H
