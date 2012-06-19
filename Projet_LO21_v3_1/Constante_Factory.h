/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file Constante_Factory.h
 *  \brief Permet la création de Constante et de Nombre depuis différents médias
 *  \author Hamici Mathilde, Suzanne Aurélie
 */
#ifndef CONSTANTE_FACTORY_H
#define CONSTANTE_FACTORY_H

#include "Constantes.h"
#include "Gestion_constantes.h"
#include "Logger.h"

extern LoggerConsole* logger1;
extern LoggerFile* logger2;

using namespace Calcul;

/*! \class FabriqueNombre
 * \brief Utilisation du design pattern factory pour créer des objets de type Nombre
 */
class FabriqueNombre{
public:
    /*!
     * \brief getNombre
     * \details Genère un Nombre à partir d'un QString.
     * \param QString contenant la Constante a générer
     */
    Nombre* getNombre(QString chaine);

    /*!
     * \brief newNombre
     * \details Genère un Nombre à partir d'un pointeur de Nombre. Permet de dupliquer un Nombre existant.
     * \param Nombre* à dupliquer
     */
    Nombre* newNombre(Nombre* a);

    /*!
     * \brief getType
     * \details Genère un Nombre à partir d'un Nombre, en prenant compte d'un type de sortie (entier, réel, rationnel).
     * \param1 Nombre* à transformer
     * \param2 int contenant le type
     */
    Nombre* getType(Nombre* a, int type);
};

/*! \class FabriqueConstante
 * \brief Utilisation du design pattern factory pour créer des objets de type Constante.
 */
class FabriqueConstante{
public:
    /*!
     * \brief getConstante
     * \details Genère une Constante à partir d'un QString.
     * \param QString contenant la Constante a générer
     */
    Constante* getConstante(QString chaine);

    /*!
     * \brief getComplexe
     * \details Genère un Complexe à partir d'un QString. Elle convertit tous les non Complexe en Complexe
     * \param QString contenant la Constante a générer
     */
    Constante* getComplexe(QString chaine);

    /*!
     * \brief getType
     * \details Genère une Constante à partir d'une Constante, en prenant compte d'un type de sortie
     * (entier, réel, rationnel).
     * \param1 Constante* à transformer
     * \param2 int contenant le type
     */
    Constante* getType(Constante* a, int type);

    /*!
     * \brief newConstante
     * \details Genère une Constante à partir d'un pointeur de Constante. Permet de dupliquer une Constante existante.
     * \param Constante* à dupliquer
     */
    Constante* newConstante(Constante* a);
};

#endif // CONSTANTE_FACTORY_H
