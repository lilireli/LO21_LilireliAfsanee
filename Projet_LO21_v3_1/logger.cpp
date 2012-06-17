/*
  Hamici Mathilde
  Suzanne Aur�lie
  Projet LO21 - Calculatrice � notation polonaise invers�e
*/
#include "Logger.h"

void LoggerFile::Write(const LogMessage* message){
    file<<message->getDegre();
    file<<message->getMessage().toStdString();
    file.flush();
}

void LoggerConsole::Write(const LogMessage *message){
    qDebug()<<message->getDegre()<<"\n";
    qDebug()<<message->getMessage()<<"\n";
}

