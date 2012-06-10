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
        Complexe* res = new Complexe(*this + *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Complexe* res = new Complexe(*this + *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Complexe* res = new Complexe(*this + *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         Complexe* res = new Complexe(*this + *e);
         return res;
    }
}

Complexe Complexe::operator - (Complexe r1)
{
    Complexe res;

    // partie réelle
    if(typeid (*re).name()==typeid (Entier).name()){
         Entier* e = dynamic_cast<Entier*>(re);
         res.re = *e - r1.re;
    }
    else if (typeid (*re).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(re);
         res.re = *e - r1.re;
    }
    else if (typeid (*re).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(re);
         res.re = *e - r1.re;
    }

    // partie imaginaire
    if(typeid (*im).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(im);
        res.im = *e - r1.im;
    }
    else if (typeid (*im).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(im);
         res.im = *e - r1.im;
    }
    else if (typeid (*im).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(im);
         res.im = *e - r1.im;
    }
    qDebug()<<"Complexe"<<res.ConvertChaine();
    return res;
}

Complexe Complexe::operator - (){Complexe vide; return vide-*this;}

Complexe Complexe::operator - (Entier r1) {return *this-r1.toComplexe();}

Complexe Complexe::operator - (Reel r1) {return *this-r1.toComplexe();}

Complexe Complexe::operator - (Rationnel r1) {return *this-r1.toComplexe();}

Constante* Complexe::operator - (Constante* r1)
{
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Complexe* res = new Complexe(*this - *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Complexe* res = new Complexe(*this - *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Complexe* res = new Complexe(*this - *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         Complexe* res = new Complexe(*this - *e);
         return res;
    }
}

Complexe Complexe::operator * (Complexe r1)
{
    Complexe res;
    // zz' = (xx' - yy') + i(xy' + yx')
    // on notera *this * r1 = (re_1 - re_2) + i(im_1 + im_2);
    Nombre *re_1, *re_2, *im_1, *im_2;

    // partie réelle de this
    if(typeid (*re).name()==typeid (Entier).name()){
         Entier* e = dynamic_cast<Entier*>(re);
         re_1 = *e * r1.re;
         im_1 = *e * r1.im;
    }
    else if (typeid (*re).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(re);
         re_1 = *e * r1.re;
         im_1 = *e * r1.im;
    }
    else if (typeid (*re).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(re);
         re_1 = *e * r1.re;
         im_1 = *e * r1.im;
    }

    // partie imaginaire de this
    if(typeid (*im).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(im);
        re_2 = *e * r1.im;
        im_2 = *e * r1.re;
    }
    else if (typeid (*im).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(im);
         re_2 = *e * r1.im;
         im_2 = *e * r1.re;
    }
    else if (typeid (*im).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(im);
         re_2 = *e * r1.im;
         im_2 = *e * r1.re;
    }

    // partie réelle
    if(typeid (*re_1).name()==typeid (Entier).name()){
         Entier* e = dynamic_cast<Entier*>(re_1);
         res.re = *e - re_2;
    }
    else if (typeid (*re_1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(re_1);
         res.re = *e - re_2;
    }
    else if (typeid (*re_1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(re_1);
         res.re = *e - re_2;
    }

    // partie imaginaire
    if(typeid (*im_1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(im_1);
        res.im = *e + im_2;
    }
    else if (typeid (*im_1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(im_1);
         res.im = *e + im_2;
    }
    else if (typeid (*im_1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(im_1);
         res.im = *e + im_2;
    }



    qDebug()<<"Complexe"<<res.ConvertChaine();
    return res;
}

Complexe Complexe::operator * (Entier r1) {return *this*r1.toComplexe();}

Complexe Complexe::operator * (Reel r1) {return *this*r1.toComplexe();}

Complexe Complexe::operator * (Rationnel r1) {return *this*r1.toComplexe();}

Constante* Complexe::operator * (Constante* r1)
{
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Complexe* res = new Complexe(*this * *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Complexe* res = new Complexe(*this * *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Complexe* res = new Complexe(*this * *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         Complexe* res = new Complexe(*this * *e);
         return res;
    }
}

Complexe Complexe::operator / (Complexe r1)
{
 /*   // z/z' = z * 1/z' = z * conjugue(z')/module(z')²
    Complexe res;

    // conjugue de r1
    Complexe conjugue = r1;

        // inverse de la partie imaginaire
    if(typeid (*conjugue.im).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(conjugue.im);
        b = new Entier(-*e);
    }
    else if (typeid (*conjugue.im).name()==typeid (Rationnel).name()){
        Rationnel* e = dynamic_cast<Rationnel*>(conjugue.im);
        b = new Rationnel(-*e);
    }
    else if (typeid (*conjugue.im).name()==typeid (Reel).name()){
        Reel* e = dynamic_cast<Reel*>(conjugue.im);
        b = new Reel(-*e);
    }


    // module de r1    |z| = racine(a² + b²)
    Nombre *module, *a, *b;

        // carré de a
    if(typeid (*r1.re).name()==typeid (Entier).name()){
         Entier* e = dynamic_cast<Entier*>(r1.re);
         a = new Entier(e->sqr());
    }
    else if (typeid (*r1.re).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1.re);
         a = new Rationnel(e->sqr());
    }
    else if (typeid (*r1.re).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1.re);
         a = new Reel(e->sqr());
    }

        // carré de b
    if(typeid (*r1.im).name()==typeid (Entier).name()){
         Entier* e = dynamic_cast<Entier*>(r1.im);
         b = new Entier(e->sqr());
    }
    else if (typeid (*r1.im).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1.im);
         b = new Rationnel(e->sqr());
    }
    else if (typeid (*r1.im).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1.im);
         b = new Reel(e->sqr());
    }

        // a² + b²
    if(typeid (*a).name()==typeid (Entier).name()){
         Entier* e = dynamic_cast<Entier*>(a);
         module = *e + b;
         conjuge.re = conjuge.re / &module
    }
    else if (typeid (*a).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(a);
         module = *e + b;
    }
    else if (typeid (*a).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(a);
         module = *e + b;
    }

    Complexe inverse = conjugue/module;


    qDebug()<<"Complexe"<<res.ConvertChaine();
    return res;*/
    return r1;
}

Complexe Complexe::operator / (Entier r1) {return *this/r1.toComplexe();}

Complexe Complexe::operator / (Reel r1) {return *this/r1.toComplexe();}

Complexe Complexe::operator / (Rationnel r1) {return *this/r1.toComplexe();}

Constante* Complexe::operator / (Constante* r1)
{
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Complexe* res = new Complexe(*this / *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Complexe* res = new Complexe(*this / *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Complexe* res = new Complexe(*this / *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         Complexe* res = new Complexe(*this / *e);
         return res;
    }
}


}
