#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <QString>
#include <QUrl>
#include <cmath>
#include <typeinfo>

namespace Calcul {

class Constante{
public:
    virtual QString ConvertChaine() = 0;   // fonction pour l'affichage
};

class Complexe;
class Nombre;
class Reel;
class Rationnel;
class Entier;

class Nombre : public Constante{
public:
    virtual Complexe toComplexe() = 0;
    virtual Nombre* operator +(Nombre* r1)=0;
    virtual QString ConvertChaine() = 0;
};


class Complexe : public Constante{
    Nombre* re;
    Nombre* im;
public:
    Complexe(QString s="0$0");
    Complexe(Nombre* reel, Nombre* imaginaire=NULL);
    Nombre* GetRe(){return re;}
    Nombre* GetIm(){return im;}
    QString ConvertChaine() {return re->ConvertChaine()+'$'+im->ConvertChaine();}

    // op�rations de base
    Complexe operator + (Complexe r1);
    Complexe operator + (Entier r1);
    Complexe operator + (Reel r1);
    Complexe operator + (Rationnel r1);
    Constante* operator + (Constante* r1);

//    Complexe operator - (Complexe r1);
//    Complexe operator - ();
//    Complexe operator - (Entier r1);
//    Complexe operator - (Reel r1);
//    Complexe operator - (Rationnel r1);
//    Constante* operator - (Constante* r1);

//    Complexe operator * (Complexe r1);
//    Complexe operator * (Entier r1);
//    Complexe operator * (Reel r1);
//    Complexe operator * (Rationnel r1);
//    Constante* operator * (Constante* r1);
};

class Reel : public Nombre{
    double n;
public:
    Reel(QString r="0"): n(r.toDouble()){}
    Reel(double r): n(r){}
    int GetReel(){return n;}
    Complexe toComplexe(){Complexe c(this); return c;}
    QString ConvertChaine() {return QString::number(n);}

    // op�rations de base
    Reel operator = (Reel r1);

    Reel operator + (Reel r1);
    Reel operator + (Entier r1);
    Reel operator + (Rationnel r1);
    Nombre* operator +(Nombre* r1);
    Constante* operator + (Constante* r1);

    Reel operator - (Reel r1);
    Reel operator - ();
    Reel operator - (Entier r1);
    Reel operator - (Rationnel r1);
    Constante* operator - (Constante* r1);

    Reel operator * (Reel r1);
    Reel operator * (Entier r1);
    Reel operator * (Rationnel r1);
    Constante* operator * (Constante* r1);

    Reel operator / (Reel r1);
    Reel operator / (Entier r1);
    Reel operator / (Rationnel r1);
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
        den = m.toInt(); if(den==0) den=1;
    }
    Rationnel(int n, int m=1): num(n), den(m){if(den == 0) den=1;}
    void SetNum(int n){num=n;}
    void SetDen(int n){den=n;}
    int GetNum(){return num;}
    int GetDen(){return den;}
    double GetRationnel(){return double(num)/den;}
    void Simplification();
    Reel toReel(){Reel r(double(num)/den); return r;}
    Complexe toComplexe(){Complexe c(this); return c;}
    QString ConvertChaine() {return QString::number(num)+'/'+QString::number(den);}

    // op�rations de base
    Rationnel operator = (Rationnel r1);

    Rationnel operator + (Rationnel r1);
    Rationnel operator + (Entier r1);
    Reel operator + (Reel r1);
    Nombre* operator + (Nombre* r1);
    Constante* operator + (Constante* r1);

    Rationnel operator - (Rationnel r1);
    Rationnel operator - ();
    Rationnel operator - (Entier r1);
    Reel operator - (Reel r1);
    Constante* operator - (Constante* r1);

    Rationnel operator * (Rationnel r1);
    Rationnel operator * (Entier r1);
    Reel operator * (Reel r1);
    Constante* operator * (Constante* r1);

    Rationnel operator / (Rationnel r1);
    Rationnel operator / (Entier r1);
    Reel operator / (Reel r1);
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
    int GetEntier(){return n;}
    double GetReel() {return n;}
    Reel toReel(){Reel r(n); return r;}
    Rationnel toRationnel(){Rationnel r(n); return r;}
    Complexe toComplexe(){Complexe c(this); return c;}
    QString ConvertChaine() {return QString::number(n);}

    // op�rations de base
    Entier operator = (Entier r1);

    Entier operator + (Entier r1);
    Reel operator + (Reel r1);
    Rationnel operator +(Rationnel r1);
    Nombre* operator + (Nombre* r1);
    Constante* operator + (Constante* r1);

    Entier operator - (Entier r1);
    Entier operator - ();
    Reel operator - (Reel r1);
    Rationnel operator -(Rationnel r1);
    Constante* operator - (Constante* r1);

    Entier operator * (Entier r1);
    Reel operator * (Reel r1);
    Rationnel operator *(Rationnel r1);
    Constante* operator * (Constante* r1);

    Reel operator / (Reel r1);
    Rationnel operator / (Entier r1);
    Rationnel operator / (Rationnel r1);
    Constante* operator / (Constante* r1);

    Reel puissance (Reel r1);
    Rationnel puissance (Entier r1);
    Reel puissance (Rationnel r1);
    Constante* puissance (Constante* r1);

    // retournent des r�els
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
    QString ConvertChaine(){return exp;}
    Constante* EvalExpression();
};

}

#endif // CONSTANTES_H
