/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>
#include <QString>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

enum Priority {
               DEBUG,
               CONFIG,
               INFO,
               WARNING,
               ERROR

};

class LogMessage
{
    QString message;
    Priority degre;

public:
    LogMessage(Priority p, QString m) : message(m), degre(p) {}
    QString getMessage()const {return message;}
    Priority getDegre() const {return degre;}
    void setMessage(QString s){message = s;}
    void setDegre(Priority p){degre = p;}
};

class  Logger
{
public :
    Logger() {}
    virtual ~Logger(){}
    //LogMessage* getLMessage(){return message;}
    //void setMessage(LogMessage* m){message = m;}
    virtual void Write(const LogMessage* m) = 0;
};

class LoggerConsole : public Logger
{
public:
    LoggerConsole() {}
    virtual void Write(const LogMessage* message);
};

class LoggerFile : public Logger
{
    std::ofstream file;
public:
    LoggerFile()
    {
        file.open("output.log", std::ios::app); //app : ajout en fin de fichier
        file.seekp(std::ios::beg);//changer la position du pointeur au début du flux

        if(!file.good()/*pret à lire ou écrire*/) return;
        file<<"\nLog : Nouvelle instance de pile\n";
        file.flush();//synchronisation
    }

    virtual ~LoggerFile(){
        if (!file.good()) return;
        file<<"\n Log : fin d'une instance de pile";
        file.flush();
        file.close();
    }
    virtual void Write(const LogMessage *message);
};


#endif // LOGGER_H
