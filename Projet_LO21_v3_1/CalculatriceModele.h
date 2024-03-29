/*
  Hamici Mathilde
  Suzanne Aur�lie
  Projet LO21 - Calculatrice � notation polonaise invers�e
*/

/*!
 *  \file CalculatriceModele.h
 *  \brief G�re la calculatrice
 *  \author Hamici Mathilde, Suzanne Aur�lie
 */

#ifndef CALCULATRICEMODELE_H
#define CALCULATRICEMODELE_H
#include <QDebug>
#include <QObject>
#include <QStack>
#include "Constantes.h"
#include "Gestion_constantes.h"
#include "Logger.h"

extern LoggerConsole* logger1;
extern LoggerFile* logger2;


using namespace Calcul;

/*! \class CalculatriceModele
 * \brief Modele qui assure le fonctionnement de la calculatrice
 */
class CalculatriceModele : public QObject
{
    Q_OBJECT

    Stack pile;

    QStack<Stack*> historique;
    QStack<Stack*> suppressionHistorique;

public:
    explicit CalculatriceModele(QObject *parent = 0);
    ~CalculatriceModele();
    void affichePileTaille();
    void afficherHistorique();
    void afficherSuppressionHistorique();

signals:
    /*!
     * \brief      finOp
     * \details    renvoie un pointeur sur la pile � MainWindow afin d'actualiser la pile dans l'affichage
     */
     void finOp(Stack* pile);
     void finAnRe(Stack* pile);
     void compVF();
     void evalExp(QString s);
     void raffraichirUi(QString s);

public slots:
     /*!
      * \brief getNombre
      * \details Gen�re une Constante � partir d'un QString, en tenant compte du type complexe.
      * Si la constante g�n�r�e est un complexe alors que le type n'est pas complexe, sa saisie est annul�e.
      * Au contraire, si le type est complexe et la constante non complexe on la convertit en complexe.
      * \param1 QString contenant la Constante a g�n�rer
      * \param2 bool qui nous indique si la saisie doit s'effectuer en mode complexe ou non
      */
     void getNombre(QString s, bool complexe);

     void getExpression();

     // annuler r�tablir
     /*! \brief ajoutHistorique
      *  Elle est appel�e d�s que l'on fait un changement sur la pile et est ainsi activ�e par finOp(). Elle va cloner une
      * instance de pile pour la rajouter dans la pile historique.
      */
     void ajoutHistorique(Stack* pile);
     /*!
      *  \brief annuler
      *  \details Cette fonction va utiliser la pile historique. Elle pop la premi�re instance de pile qui est dans
      * l'historique et l'ins�re dans la pile suppressionHistorique. Pile prendra alors la valeur de l'avant derni�re pile
      * dans l'historique.
      */
     void annuler();
     /*!
      *  \brief retablir
      *  \details Cette fonction va utiliser la pile suppressionHistorique. Elle pop la premi�re instance de pile qui est dans
      * suppressionHistorique et l'ins�re dans la pile historique. Pile prendra alors la valeur de la derni�re pile
      * dans suppressionHistorique.
      */
     void retablir();

     // lire �crire
     void ecritureFichier();
     void lireFichier();

     /*!
      * \brief      effacerPile
      * \details    Supprime la pile car le mode complexe est d�sactiv�, on ne peut convertir de Complexe � Nombre
      */
     void effacerPile();
     /*!
      * \brief      transformerPile
      * \details    transforme tous les Nombre de la pile en Complexe
      */
     void transformerPile();
     /*!
      * \brief      actualiserPile
      * \details    V�rifie (et corrige si ce n'est pas le cas) que la pile ne contient que des constants de type ad�quat
      * apr�s avoir effectu� annuler ou r�tablir
      */
     void actualiserPile(bool Comp);

     // Op�rations
     void getAdd(int type);
     void getSous(int type);
     void getMult(int type);
     void getDiv(int type);

     void getPow(int type);
     void getMod();
     void getFact();
     void getSign(int type);

     void getSin(bool degre);
     void getCos(bool degre);
     void getTan(bool degre);

     void getSinh(bool degre);
     void getCosh(bool degre);
     void getTanh(bool degre);

     void getLn();
     void getLog();
     void getInv(int type);

     void getSqrt();
     void getSqr(int type);
     void getCube(int type);

     void getSwap();
     void getSum(int type);
     void getMean(int type);
     void getClear();
     void getDup();
     void getDrop();

};

#endif // CALCULATRICEMODELE_H
