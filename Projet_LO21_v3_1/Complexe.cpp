#include "Constantes.h"
#include "Constante_Factory.h"
#include <QDebug>

namespace Calcul{
Complexe::Complexe(QString s){
    FabriqueNombre nb;
    int trouve=0;
    QString n, m;

    for(int i = 0; i<s.length(); i++){
        if(s.at(i) != '$') {
            if(trouve==0) n=n+s.at(i);
            else m=m+s.at(i);
        }else trouve=1;
    }

    re = nb.getNombre(n);
    im = nb.getNombre(m);
}

Complexe::Complexe(Nombre* reel, Nombre* imaginaire): re(reel), im(imaginaire){
    if(im==NULL) im = new Entier;
}

Complexe Complexe::operator + (Complexe r1)
{
    Complexe res;

    // partie réelle
    if(typeid (*re).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(re);
        res.re = *e + r1.re;
    }
    else if (typeid (*re).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(re);
         res.re = *e + r1.re;
    }
    else if (typeid (*re).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(re);
         res.re = *e + r1.re;
    }

    // partie imaginaire
    if(typeid (*im).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(im);
        res.im = *e + r1.im;
    }
    else if (typeid (*im).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(im);
         res.im = *e + r1.im;
    }
    else if (typeid (*im).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(im);
         res.im = *e + r1.im;
    }
    qDebug()<<"Complexe"<<res.ConvertChaine();
    return res;
}

Complexe Complexe::operator + (Entier r1) {return *this+r1.toComplexe();}

Complexe Complexe::operator + (Reel r1) {return *this+r1.toComplexe();}

Complexe Complexe::operator + (Rationnel r1) {return *this+r1.toComplexe();}

Constante* Complexe::operator + (Constante* r1)
{
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        return &(*this+ *e);
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         return &(*this + *e);
    }
}

//Complexe Complexe::operator - (Complexe r1);
//Complexe Complexe::operator - ();
//Complexe Complexe::operator - (Entier r1);
//Complexe Complexe::operator - (Reel r1);
//Complexe Complexe::operator - (Rationnel r1);
//Constante* Complexe::operator - (Constante* r1);

//Complexe Complexe::operator * (Complexe r1);
//Complexe Complexe::operator * (Entier r1);
//Complexe Complexe::operator * (Reel r1);
//Complexe Complexe::operator * (Rationnel r1);
//Constante* Complexe::operator * (Constante* r1);

}
