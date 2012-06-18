/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/

/*!
 *  \file CalculatriceModele.h
 *  \brief Gère la calculatrice
 *  \author Hamici Mathilde, Suzanne Aurélie
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
    void affichePileTaille();
    //void afficherHistorique();
    void afficherSuppressionHistorique();

signals:
    /*!
     * \brief      finOp
     * \details    renvoie un pointeur sur la pile à MainWindow afin d'actualiser la pile dans l'affichage
     */
     void finOp(Stack* pile);
     void evalExp(QString s);
     void raffraichirUi(QString s);

public slots:
     /*!
      * \brief getNombre
      * \details Genère une Constante à partir d'un QString, en tenant compte du type complexe.
      * Si la constante générée est un complexe alors que le type n'est pas complexe, sa saisie est annulée.
      * Au contraire, si le type est complexe et la constante non complexe on la convertit en complexe.
      * \param1 QString contenant la Constante a générer
      * \param2 bool qui nous indique si la saisie doit s'effectuer en mode complexe ou non
      */
     void getNombre(QString s, bool complexe);
     void getExpression();
     void annuler();
     void retablir();
     void ecritureFichier();
     void effacerPile();
     void transformerPile();

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
