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
    Constante* CreerObjet(const Constante *d);

signals:
     void finOp(QString s);

public slots:
     void getNombre(QString s, int type);  // mettre la constante dans pile
     void getExpression();

     void getAdd();
     void getSous();
     void getMult();
     void getDiv();

     void getPow();
     void getMod();
     void getFact();
     void getSign();

     void getSin();
     void getCos();
     void getTan();

     void getSinh();
     void getCosh();
     void getTanh();

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
