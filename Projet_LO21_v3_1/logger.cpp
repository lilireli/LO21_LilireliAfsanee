/*
  Hamici Mathilde
  Suzanne Aur�lie
  Projet LO21 - Calculatrice � notation polonaise invers�e
*/
/*!
 *  \file Logger.cpp
 *  \brief Gestion des LogMessage pour la console et un fichier
 *  \author Hamici Mathilde, Suzanne Aur�lie
 */
#include "Logger.h"
#include "QMessageBox"

void LoggerFile::Write(const LogMessage* message){
    file<<message->getDegre();
    file<<message->getMessage().toStdString();
    file.flush();
}

void LoggerConsole::Write(const LogMessage *message){
    qDebug()<<message->getDegre();
    qDebug()<<message->getMessage()<<"\n";

    if(message->getDegre()==WARNING || message->getDegre()==ERROR){
        QMessageBox::warning(NULL, message->getDegreS(), message->getMessage());
    }
}

