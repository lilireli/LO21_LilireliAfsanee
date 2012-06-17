/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
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

class Constante{
public:
    virtual ~Constante(){}
    virtual const QString ConvertChaine() const = 0;   // fonction pour l'affichage
};

class Complexe;
class Nombre;
class Reel;
class Rationnel;
class Entier;

class Nombre : public Constante{
public:
    virtual ~Nombre(){}
    virtual Complexe toComplexe() = 0;
    virtual const QString ConvertChaine() const = 0;
};


class Complexe : public Constante{
    Nombre* re;
    Nombre* im;
public:
    Complexe(QString s="0$0");
    Complexe(Nombre* reel, Nombre* imaginaire=NULL);
    Complexe(Complexe* comp);
    ~Complexe() {delete re; delete im;}
    Nombre* GetRe()const {return re;}
    Nombre* GetIm()const{return im;}
    void SetRe(Nombre* r){re = r;}
    void SetIm(Nombre* i){im = i;}
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

    Reel ln();
    Reel logdix();
    Reel inv();
    Reel rsqr();
    Reel sqr();
    Reel cube();

};

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

    Reel ln();
    Reel logdix();
    Rationnel inv();
    Reel rsqr();
    Rationnel sqr();
    Rationnel cube();
};

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

    Reel ln();
    Reel logdix();
    Rationnel inv();  // retourne 1/x donc ne peut pas retourner un entier, retourne un rationnel car moins de pertes
    Reel rsqr();
    Entier sqr();
    Entier cube();

    Entier mod(Entier e);
    Entier fact();
};


class Expression : public Constante{
    QString exp;
public:
    Expression(QString s): exp(s){}
    Expression(Expression* e): exp(e->exp){}
    ~Expression(){}
    const QString ConvertChaine()const {return exp;}
    const QString Tronque(){exp.remove(0, 1); exp.remove(exp.length()-1, 1); return exp;}
    void addCalcul(QString s){exp.remove(exp.length()-1, 1); exp+=" "+s+"'";}
    void calculAdd(QString s){exp.remove(0, 1); exp="'"+s+" "+exp;} // ajoute avant expression une constante
};

}

#endif // CONSTANTES_H
