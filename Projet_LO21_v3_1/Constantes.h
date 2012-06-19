/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file Constantes.h
 *  \brief Création de tous les types de Constante : Entier, Reel, Rationnel, Complexe, Expression
 *  \author Hamici Mathilde, Suzanne Aurélie
 */
#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <QString>
#include <QUrl>
#include <cmath>
#include <typeinfo>
#include <QDebug>
#include "Logger.h"

extern LoggerConsole* logger1;
extern LoggerFile* logger2;

#define PI 3.14159265

namespace Calcul {

/*! \class Constante
 * \brief Classe abstraite qui contiendra tous les types de nombres
 */
class Constante{
public:
    virtual ~Constante(){}
    /*! \brief ConvertChaine
     *  Méthode virtuelle qui convertit une Constante en une chaine de caractères
     *  \returns Retourne un const QString
     */
    virtual const QString ConvertChaine()const = 0;   // fonction pour l'affichage
    virtual bool isNull() = 0;
};

class Complexe;
class Nombre;
class Reel;
class Rationnel;
class Entier;

/*! \class Nombre
 * \brief Classe abstraite qui contiendra les nombres de type entier, rationnel et réel
 */
class Nombre : public Constante{
public:
    virtual ~Nombre(){}
    /*!
     *  \brief toComplexe
     *  \details Méthode virtuelle qui convertit un Nombre en un Complexe
     *  \returns Retourne un complexe
     */
    virtual Complexe toComplexe() = 0;
    virtual const QString ConvertChaine()const = 0;
    virtual bool isNull() = 0;
    virtual bool isPositif() = 0;
};

/*! \class Complexe
 * \brief Classe qui contiendra deux pointeurs vers des objets de type Nombre
 */
class Complexe : public Constante{
    Nombre* re;
    Nombre* im;
public:
    Complexe(QString s="0$0");
    Complexe(Nombre* reel, Nombre* imaginaire=NULL);
    Complexe(Complexe* comp);
    ~Complexe() {/*delete re; delete im;*/}   // ne fait rien sinon erreur
    Nombre* GetRe()const {return re;}
    Nombre* GetIm()const {return im;}
    void SetRe(Nombre* r){re = r;}
    void SetIm(Nombre* i){im = i;}
    bool isNull() { return (re->isNull() && im->isNull());}
    const QString ConvertChaine()const {return re->ConvertChaine()+'$'+im->ConvertChaine();}

    // opérations de base
    Complexe operator + (Complexe r1);
    Complexe operator + (Entier r1);
    Complexe operator + (Reel r1);
    Complexe operator + (Rationnel r1);
    Constante* operator + (Constante* r1);

    Complexe operator - (Complexe r1);
    Complexe operator - ();
    Complexe operator - (Entier r1);
    Complexe operator - (Reel r1);
    Complexe operator - (Rationnel r1);
    Constante* operator - (Constante* r1);

    Complexe operator * (Complexe r1);
    Complexe operator * (Entier r1);
    Complexe operator * (Reel r1);
    Complexe operator * (Rationnel r1);
    Constante* operator * (Constante* r1);

    Complexe operator / (Complexe r1);
    Complexe operator / (Entier r1);
    Complexe operator / (Reel r1);
    Complexe operator / (Rationnel r1);
    Constante* operator / (Constante* r1);

    Complexe sqr();
    Complexe cube();
};

/*! \class Reel
 * \brief Classe qui permet d'implémenter un réel à l'aide d'un double
 */
class Reel : public Nombre{
    double n;
public:
    Reel(QString r="0"): n(r.toDouble()){}
    Reel(double r): n(r){}
    Reel(Reel* r): n(r->n){}
    ~Reel(){}
    double GetReel()const{return n;}
    int GetEntier()const{return static_cast<int>(n);}
    Entier toEntier();
    Rationnel toRationnel();
    Complexe toComplexe(){Complexe c(this); return c;}
    const QString ConvertChaine()const {return QString::number(n);}
    bool isNull() {return(n==0);}
    bool isPositif() {return(n>=0);}

    // opérations de base
    Reel operator = (Reel r1){return r1;}

    Reel operator + (Reel r1);
    Reel operator + (Entier r1);
    Reel operator + (Rationnel r1);
    Nombre* operator +(Nombre* r1);
    Constante* operator + (Constante* r1);

    Reel operator - (Reel r1);
    Reel operator - ();
    Reel operator - (Entier r1);
    Reel operator - (Rationnel r1);
    Nombre* operator -(Nombre* r1);
    Constante* operator - (Constante* r1);

    Reel operator * (Reel r1);
    Reel operator * (Entier r1);
    Reel operator * (Rationnel r1);
    Nombre* operator *(Nombre* r1);
    Constante* operator * (Constante* r1);

    Reel operator / (Reel r1);
    Reel operator / (Entier r1);
    Reel operator / (Rationnel r1);
    Nombre* operator / (Nombre* r1);
    Constante* operator / (Constante* r1);

    Reel puissance (Reel r1);
    Reel puissance (Entier r1);
    Reel puissance (Rationnel r1);
    Constante* puissance (Constante* r1);

    Reel sinus();
    Reel cosinus();
    Reel tangente();
    Reel sinush();
    Reel cosinush();
    Reel tangenteh();

    Reel *ln();
    Reel *logdix();
    Reel *inv();
    Reel *rsqr();
    Reel sqr();
    Reel cube();

};

/*! \class Rationnel
 * \brief Classe qui permet d'implémenter un rationnel à l'aide de deux int
 */
class Rationnel : public Nombre{
    int num;
    int den;
public:
    Rationnel(QString s = "0/1"){
        int trouve=0;
        QString n, m;

        for(int i = 0; i<s.length(); i++){
            if(s.at(i) != '/') {
                if(trouve==0) n=n+s.at(i);
                else m=m+s.at(i);
            }else trouve=1;
        }
        num = n.toInt();
        den = m.toInt();
        if(den == 0){
            logger1->Write(&LogMessage(WARNING,"division par zéro, remplacé par 0"));
            logger2->Write(&LogMessage(WARNING,"division par zéro, remplacé par 0"));
            den=1;
            num=0;
        }
    }
    Rationnel(int n, int m=1): num(n), den(m){
        if(den == 0){
            logger1->Write(&LogMessage(WARNING,"division par zéro, remplacé par 0"));
            logger2->Write(&LogMessage(WARNING,"division par zéro, remplacé par 0"));
            den=1;
            num=0;
        }
    }
    Rationnel(Rationnel* r):num(r->num), den(r->den){}
    ~Rationnel(){}
    void SetNum(int n){num=n;}
    void SetDen(int n){den=n;}
    int GetNum()const{return num;}
    int GetDen()const{return den;}
    double GetRationnel()const{return double(num)/den;}
    void Simplification();
    Entier toEntier();
    Reel toReel(){Reel r(double(num)/den); return r;}
    Complexe toComplexe(){Complexe c(this); return c;}
    const QString ConvertChaine()const {return QString::number(num)+'/'+QString::number(den);}
    bool isNull() { return(num==0) ;}
    bool isPositif(){return((num > 0 && den > 0) || (num < 0 && den < 0) || (num == 0 && den == 0));}

    // opérations de base
    Rationnel operator + (Rationnel r1);
    Rationnel operator + (Entier r1);
    Reel operator + (Reel r1);
    Nombre* operator + (Nombre* r1);
    Constante* operator + (Constante* r1);

    Rationnel operator - (Rationnel r1);
    Rationnel operator - ();
    Rationnel operator - (Entier r1);
    Reel operator - (Reel r1);
    Nombre* operator - (Nombre* r1);
    Constante* operator - (Constante* r1);

    Rationnel operator * (Rationnel r1);
    Rationnel operator * (Entier r1);
    Reel operator * (Reel r1);
    Nombre* operator * (Nombre* r1);
    Constante* operator * (Constante* r1);

    Rationnel operator / (Rationnel r1);
    Rationnel operator / (Entier r1);
    Reel operator / (Reel r1);
    Nombre* operator / (Nombre* r1);
    Constante* operator / (Constante* r1);

    Reel puissance (Reel r1);
    Rationnel puissance (Entier r1);
    Reel puissance (Rationnel r1);
    Constante* puissance (Constante* r1);

    Reel sinus();
    Reel cosinus();
    Reel tangente();
    Reel sinush();
    Reel cosinush();
    Reel tangenteh();

    Reel *ln();
    Reel *logdix();
    Rationnel *inv();
    Reel *rsqr();
    Rationnel sqr();
    Rationnel cube();
};

/*! \class Entier
 * \brief Classe qui permet d'implémenter un entier à l'aide d'un int
 */
class Entier : public Nombre{
    int n;
public:
    Entier(QString e="0"): n(e.toInt()){}
    Entier(int e): n(e){}
    Entier(Entier* e): n(e->n){}
    ~Entier(){}
    int GetEntier()const{return n;}
    double GetReel()const {return n;}
    Reel toReel(){Reel r(n); return r;}
    Rationnel toRationnel(){Rationnel r(n); return r;}
    Complexe toComplexe(){Complexe c(this); return c;}
    const QString ConvertChaine()const {return QString::number(n);}
    bool isNull() {return(n==0);}
    bool isPositif(){return(n>=0);}

    // opérations de base
    Entier operator + (Entier r1);
    Reel operator + (Reel r1);
    Rationnel operator +(Rationnel r1);
    Nombre* operator + (Nombre* r1);
    Constante* operator + (Constante* r1);

    Entier operator - (Entier r1);
    Entier operator - ();
    Reel operator - (Reel r1);
    Rationnel operator -(Rationnel r1);
    Nombre* operator - (Nombre* r1);
    Constante* operator - (Constante* r1);

    Entier operator * (Entier r1);
    Reel operator * (Reel r1);
    Rationnel operator *(Rationnel r1);
    Nombre* operator * (Nombre* r1);
    Constante* operator * (Constante* r1);

    Reel operator / (Reel r1);
    Rationnel operator / (Entier r1);
    Rationnel operator / (Rationnel r1);
    Nombre* operator / (Nombre* r1);
    Constante* operator / (Constante* r1);

    Reel puissance (Reel r1);
    Rationnel puissance (Entier r1);
    Reel puissance (Rationnel r1);
    Constante* puissance (Constante* r1);

    // retournent des réels
    Reel sinus();
    Reel cosinus();
    Reel tangente();
    Reel sinush();
    Reel cosinush();
    Reel tangenteh();

    Reel *ln();
    Reel *logdix();
    Rationnel *inv();  // retourne 1/x donc ne peut pas retourner un entier, retourne un rationnel car moins de pertes
    Reel *rsqr();
    Entier sqr();
    Entier cube();

    Entier mod(Entier e);
    Entier fact();
};

/*! \class Expression
 * \brief Classe qui permet d'implémenter une expression à l'aide d'un QString
 */
class Expression : public Constante{
    QString exp;
public:
    Expression(QString s): exp(s){}
    Expression(Expression* e): exp(e->exp){}
    ~Expression(){}
    const QString ConvertChaine()const {return exp;}
    bool isNull(){return false;}
    /*!
     *  \brief Tronque
     *  retourne une Expression, sans ses quotes
     */
    const QString Tronque(){exp.remove(0, 1); exp.remove(exp.length()-1, 1); return exp;}
    /*!
     *  \brief addCalcul
     *  \details Ajoute un QString a une expression, QString ajouté à la fin
     *  \param Prend un QString
     */
    void addCalcul(QString s){exp.remove(exp.length()-1, 1); exp+=" "+s+"'";}
    /*!
     *  \brief calculAdd
     *  \details Ajoute un QString a une expression, QString ajouté au début
     *  \param Prend un QString
     */
    void calculAdd(QString s){exp.remove(0, 1); exp="'"+s+" "+exp;} // ajoute avant expression une constante
};

}

#endif // CONSTANTES_H
