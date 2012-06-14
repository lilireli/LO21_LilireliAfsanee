#ifndef CALCULATRICEMODELE_H
#define CALCULATRICEMODELE_H
#include <QDebug>
#include <QObject>
#include <QStack>
#include "Constantes.h"
#include "Gestion_constantes.h"

//class CalculatriceModele;
//#include "mainwindow.h"

using namespace Calcul;

class CalculatriceModele : public QObject
{
    Q_OBJECT


    //QStack<Constante*> pile;
    Stack pile;
public:
    explicit CalculatriceModele(QObject *parent = 0);
    void affichePileTaille();
  //  Constante* CreerObjet(const Constante *d);

signals:
     void finOp(Constante* cte, int i);
     void evalExp(QString s);

public slots:
     void getNombre(QString s, bool complexe);
     void getExpression();

     void getAdd();
     void getSous();
     void getMult();
     void getDiv(int type);

     void getPow();
     void getMod();
     void getFact();
     void getSign();

     void getSin(bool degre);
     void getCos(bool degre);
     void getTan(bool degre);

     void getSinh(bool degre);
     void getCosh(bool degre);
     void getTanh(bool degre);

     void getLn();
     void getLog();
     void getInv();

     void getSqrt();
     void getSqr();
     void getCube();

     void getSwap();
     void getSum();
     void getMean();
     void getClear();
     void getDup();
     void getDrop();

};

#endif // CALCULATRICEMODELE_H
