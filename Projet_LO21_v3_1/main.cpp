/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file main.cpp
 *  \brief Lance l'application
 *  \author Hamici Mathilde, Suzanne Aurélie
 */

/*!
 *  \mainpage Introduction
 *  \par Projet de calculatrice à notation polonaise inversée.
 *  \par Effectué dans le cadre de l'UV LO21.
 *  \par La calculatrice prend en charge les types Entier, Reel, Rationnel, Complexe, Expression.
 *  \par
 *   En revanche lors du changement de complexe à non complexe il y a perte de tous les Complexes
 *  Anciennement contenus dans la pile, étant donné qu'il n'existe pas de conversion convenable.
 *  \par
 *  Les autres types ne sont prix en considération qu'à l'évaluation d'une opération, ceci selon
 *  les opérations.
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
