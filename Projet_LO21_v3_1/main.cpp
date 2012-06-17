/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file main.c
 *  \brief Lance l'application
 *  \author {Hamici Mathilde, Suzanne Aurélie}
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
