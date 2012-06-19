/*
  Hamici Mathilde
  Suzanne Aur�lie
  Projet LO21 - Calculatrice � notation polonaise invers�e
*/
/*!
 *  \file main.cpp
 *  \brief Lance l'application
 *  \author Hamici Mathilde, Suzanne Aur�lie
 */

/*!
 *  \mainpage Introduction
 *  \par Projet de calculatrice � notation polonaise invers�e.
 *  \par Effectu� dans le cadre de l'UV LO21.
 *  \par La calculatrice prend en charge les types Entier, Reel, Rationnel, Complexe, Expression.
 *  \par
 *   En revanche lors du changement de complexe � non complexe il y a perte de tous les Complexes
 *  Anciennement contenus dans la pile, �tant donn� qu'il n'existe pas de conversion convenable.
 *  \par
 *  Les autres types ne sont prix en consid�ration qu'� l'�valuation d'une op�ration, ceci selon
 *  les op�rations.
 */
#include "Logger.h"

LoggerConsole* logger1;
LoggerFile* logger2;

#include <QtGui/QApplication>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<"que faites-vous";
    MainWindow w;
    w.show();
    
    return a.exec();
}
