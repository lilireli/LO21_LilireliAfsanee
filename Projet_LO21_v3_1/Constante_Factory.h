/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
#ifndef CONSTANTE_FACTORY_H
#define CONSTANTE_FACTORY_H

#include "Constantes.h"
#include "Gestion_constantes.h"

using namespace Calcul;

class FabriqueNombre{
public:
    Nombre* getNombre(QString chaine);
    Nombre* newNombre(Nombre* a);
    Nombre* getType(Nombre* a, int type);
};

class FabriqueConstante{
public:
    Constante* getConstante(QString chaine);
    Constante* getComplexe(QString chaine);
    Constante* getType(Constante* a, int type);
    Constante* newConstante(Constante* a);
};

#endif // CONSTANTE_FACTORY_H
