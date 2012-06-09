#ifndef CONSTANTE_FACTORY_H
#define CONSTANTE_FACTORY_H

#include "Constantes.h"
#include "Gestion_constantes.h"

using namespace Calcul;

class FabriqueNombre{
public:
    Nombre* getNombre(QString chaine);
};

class FabriqueConstante{
public:
    Constante* getConstante(QString chaine);
};

#endif // CONSTANTE_FACTORY_H
