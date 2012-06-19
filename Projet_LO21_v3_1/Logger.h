/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file Logger.h
 *  \brief Gestion des LogMessage pour la console et un fichier
 *  \author Hamici Mathilde, Suzanne Aurélie
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>
#include <QString>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/*! \enum Priority
 * \brief Gère la priorité de chaque LogMessage
 */
enum Priority {
               DEBUG,
               CONFIG,
               INFO,
               WARNING,
               ERROR

};

/*! \class LogMessage
 * \brief Création d'un logMessage contenant une priorité et du texte
 */
class LogMessage
{
    QString message;
    Priority degre;

public:
    LogMessage(Priority p, QString m) : message(m), degre(p) {}
    const QString getMessage()const {return message;}
    Priority getDegre() const {return degre;}
    /*!
     *  \brief getDegreS
     *  \details retourne le degre du LogMessage, sous forme de texte
     * \returns Retourne un const Qstring
     */
    const QString getDegreS() const{
        if(degre==DEBUG){return "Debug";}
        else if(degre==CONFIG){return "Config";}
        else if(degre==INFO){return "Info";}
        else if(degre==WARNING){return "Warning";}
        else if(degre==ERROR){return "Erreur";}
    }
    void setMessage(QString s){message = s;}
    void setDegre(Priority p){degre = p;}
};

/*! \class Logger
 * \brief Classe abstraite permettant de créer des objets qui gèrerons des LogMessage
 */
class  Logger
{
public :
    Logger() {}
    virtual ~Logger(){}
    /*!
     *  \brief Write
     *  \details fonction abstraite qui permet d'écrire un LogMessage
     */
    virtual void Write(const LogMessage* m) = 0;
};

/*! \class LoggerConsole
 * \brief Classe qui écrit des LogMessage dans la console, selon la catégorie du message elle emet un QMessageBox
 * pour informer l'utilisateur
 */
class LoggerConsole : public Logger
{
public:
    LoggerConsole() {}
    virtual void Write(const LogMessage* message);
};

/*! \class LoggerFile
 * \brief Classe qui écrit des LogMessage dans un fichier
 */
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
