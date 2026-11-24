#ifndef OBJETO_H
#define OBJETO_H
#include "TipoObjeto.h"

class Objeto{
    public:
    virtual TipoObjeto obtenerTipoObjeto() = 0;
    virtual ~Objeto(){}
};

#endif // OBJETO_H
