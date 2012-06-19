/*
  Hamici Mathilde
  Suzanne Aur�lie
  Projet LO21 - Calculatrice � notation polonaise invers�e
*/
/*!
 *  \file Constante_Factory.h
 *  \brief Permet la cr�ation de Constante et de Nombre depuis diff�rents m�dias
 *  \author Hamici Mathilde, Suzanne Aur�lie
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
 * \brief Utilisation du design pattern factory pour cr�er des objets de type Nombre
 */
class FabriqueNombre{
public:
    /*!
     * \brief getNombre
     * \details Gen�re un Nombre � partir d'un QString.
     * \param QString contenant la Constante a g�n�rer
     */
    Nombre* getNombre(QString chaine);

    /*!
     * \brief newNombre
     * \details Gen�re un Nombre � partir d'un pointeur de Nombre. Permet de dupliquer un Nombre existant.
     * \param Nombre* � dupliquer
     */
    Nombre* newNombre(Nombre* a);

    /*!
     * \brief getType
     * \details Gen�re un Nombre � partir d'un Nombre, en prenant compte d'un type de sortie (entier, r�el, rationnel).
     * \param1 Nombre* � transformer
     * \param2 int contenant le type
     */
    Nombre* getType(Nombre* a, int type);
};

/*! \class FabriqueConstante
 * \brief Utilisation du design pattern factory pour cr�er des objets de type Constante.
 */
class FabriqueConstante{
public:
    /*!
     * \brief getConstante
     * \details Gen�re une Constante � partir d'un QString.
     * \param QString contenant la Constante a g�n�rer
     */
    Constante* getConstante(QString chaine);

    /*!
     * \brief getComplexe
     * \details Gen�re un Complexe � partir d'un QString. Elle convertit tous les non Complexe en Complexe
     * \param QString contenant la Constante a g�n�rer
     */
    Constante* getComplexe(QString chaine);

    /*!
     * \brief getType
     * \details Gen�re une Constante � partir d'une Constante, en prenant compte d'un type de sortie
     * (entier, r�el, rationnel).
     * \param1 Constante* � transformer
     * \param2 int contenant le type
     */
    Constante* getType(Constante* a, int type);

    /*!
     * \brief newConstante
     * \details Gen�re une Constante � partir d'un pointeur de Constante. Permet de dupliquer une Constante existante.
     * \param Constante* � dupliquer
     */
    Constante* newConstante(Constante* a);
};

#endif // CONSTANTE_FACTORY_H
