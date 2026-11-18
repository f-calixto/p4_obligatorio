#ifndef OBJETO_H
#define OBJETO_H
#include "TipoObjeto.h"

class Objeto{
    public:
    virtual TipoObjeto obtenerTipoObjeto() = 0;
};

#endif // OBJETO_H
