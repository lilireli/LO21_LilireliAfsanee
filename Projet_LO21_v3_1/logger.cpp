/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
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

