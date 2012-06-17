/*
  Hamici Mathilde
  Suzanne Aur�lie
  Projet LO21 - Calculatrice � notation polonaise invers�e
*/
/*!
 *  \file main.c
 *  \brief Lance l'application
 *  \author {Hamici Mathilde, Suzanne Aur�lie}
 */
#include "Logger.h"

LoggerConsole* logger1;
LoggerFile* logger2;

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    
    return a.exec();
}
