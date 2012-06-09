#include "Constantes.h"
#include "Constante_Factory.h"
#include <QDebug>

namespace Calcul{
Complexe::Complexe(QString s){
    FabriqueNombre nb;
    int trouve=0;
    QString n, m;

    for(int i = 0; i<s.length(); i++){
        if(s.at(i) != '/') {
            if(trouve==0) n=n+s.at(i);
            else m=m+s.at(i);
        }else trouve=1;
    }
    re = nb.getNombre(n);
    im = nb.getNombre(n);
}

Complexe::Complexe(Nombre* reel, Nombre* imaginaire): re(reel), im(imaginaire){
    if(im==NULL) im = new Entier;
}

Complexe Complexe::operator + (Complexe r1)
{
    Entier e(1);
    Entier e2(2);

    Nombre* reel = e2+&e;
    Nombre* img = e+&e2;
    Complexe res(reel, img);
    return res;
//    return new Complexe(*re+r1.GetRe(), *im+r1.GetIm());
//    Complexe res;

//    // partie réelle
//    if(typeid (this->re).name()==typeid (Nombre*).name()){
//        //Entier* e = dynamic_cast<Entier*>(this->re);
//        qDebug() << "hjdcwx";
//            Entier i2(4);
//            Entier i1(4);
//        res.re = i1 + &i2;
//        //res.re = *e + r1.re;
//    }
//    else if (typeid (*(this->re)).name()==typeid (Rationnel).name()){
//         Rationnel* e = dynamic_cast<Rationnel*>(this->re);
//         res.re = *e + r1.re;
//    }
//    else if (typeid (*(this->re)).name()==typeid (Reel).name()){
//         Reel* e = dynamic_cast<Reel*>(this->re);
//         res.re = *e + r1.re;
//    }


    // partie imaginaire
//    if(typeid (*this).name()==typeid (Entier).name()){
//        Entier* e = dynamic_cast<Entier*>(this);
//        res.im = *e + r1.im;
//    }
//    else if (typeid (*this).name()==typeid (Rationnel).name()){
//         Rationnel* e = dynamic_cast<Rationnel*>(this);
//         res.im = *e + r1.im;
//    }
//    else if (typeid (*this).name()==typeid (Reel).name()){
//         Reel* e = dynamic_cast<Reel*>(this);
//         res.im = *e + r1.im;
//    }
//    Entier i(3);
//    res.im=&i;

//    return res;
}

Complexe Complexe::operator + (Nombre* r1) {return *this+r1->toComplexe();}

Constante* Complexe::operator + (Constante* r1)
{
    if(typeid (*r1).name()==typeid (Nombre).name()){
        Nombre* e = dynamic_cast<Nombre*>(r1);
        return &(*this+e);
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         return &(*this+*e);
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
