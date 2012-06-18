/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
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
    if(im==NULL){
        logger1->Write(&LogMessage(WARNING,"partie imaginaire nulle"));
        logger2->Write(&LogMessage(WARNING,"partie imaginaire nulle"));
        im = new Entier;
    }
}

Complexe::Complexe(Complexe* comp){
    FabriqueNombre cte;
    re = cte.newNombre(comp->re);
    im = cte.newNombre(comp->im);
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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return res;
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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return res;
    }

    return res;
}

Complexe Complexe::operator + (Entier r1) {return *this+r1.toComplexe();}

Complexe Complexe::operator + (Reel r1) {return *this+r1.toComplexe();}

Complexe Complexe::operator + (Rationnel r1) {return *this+r1.toComplexe();}

Constante* Complexe::operator + (Constante* r1)
{
    Complexe* res;

    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        res = new Complexe(*this + *e);
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         res = new Complexe(*this + *e);
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         res = new Complexe(*this + *e);
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         qDebug() << "tredqte";
         Complexe res_i(&(*this + *e));
         qDebug()<<"sjhfg"<<res_i.ConvertChaine();
         res = new Complexe(&(*this + *e));
         qDebug() << "ertfe"<<res->ConvertChaine();
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res = NULL;
    }

    return res;
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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
    }

    return res;
}

Complexe Complexe::operator - (){Complexe vide; return vide-*this;}

Complexe Complexe::operator - (Entier r1) {return *this-r1.toComplexe();}

Complexe Complexe::operator - (Reel r1) {return *this-r1.toComplexe();}

Complexe Complexe::operator - (Rationnel r1) {return *this-r1.toComplexe();}

Constante* Complexe::operator - (Constante* r1)
{
    Complexe* res;

    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        res = new Complexe(*this - *e);
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         res = new Complexe(*this - *e);
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         res = new Complexe(*this - *e);
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         res = new Complexe(*this - *e);
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res = NULL;
    }
    return res;
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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
    }



    qDebug()<<"Complexe"<<res.ConvertChaine();
    return res;
}

Complexe Complexe::operator * (Entier r1) {return *this*r1.toComplexe();}

Complexe Complexe::operator * (Reel r1) {return *this*r1.toComplexe();}

Complexe Complexe::operator * (Rationnel r1) {return *this*r1.toComplexe();}

Constante* Complexe::operator * (Constante* r1)
{
    Complexe* res;

    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        res = new Complexe(*this * *e);
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         res = new Complexe(*this * *e);
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         res = new Complexe(*this * *e);
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         res = new Complexe(*this * *e);
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res = NULL;
    }
    return res;
}

Complexe Complexe::operator / (Complexe r1)
{
    // z/z' = z * 1/z' = z * conjugue(z')/module(z')²
    Complexe res;

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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
    }

        // carré de b et b²+a²
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
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
    }

        // a² + b²
    if(typeid (*a).name()==typeid (Entier).name()){
         Entier* e = dynamic_cast<Entier*>(a);
         module = *e + b;
    }
    else if (typeid (*a).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(a);
         module = *e + b;
    }
    else if (typeid (*a).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(a);
         module = *e + b;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
    }

    // conjugue de r1 / |r1|
        // division de la partie réelle par le module
    if(typeid (*r1.re).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1.re);
        res.re = *e / module;
    }
    else if (typeid (*r1.re).name()==typeid (Rationnel).name()){
        Rationnel* e = dynamic_cast<Rationnel*>(r1.re);
        res.re = *e / module;
    }
    else if (typeid (*r1.re).name()==typeid (Reel).name()){
        Reel* e = dynamic_cast<Reel*>(r1.re);
        res.re = *e / module;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
    }

        // inverse de la partie imaginaire + division par le module
    if(typeid (*r1.im).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1.im);
        res.im = (-*e) / module;
    }
    else if (typeid (*r1.im).name()==typeid (Rationnel).name()){
        Rationnel* e = dynamic_cast<Rationnel*>(r1.im);
        res.im = (-*e) / module;
    }
    else if (typeid (*r1.im).name()==typeid (Reel).name()){
        Reel* e = dynamic_cast<Reel*>(r1.im);
        res.im = (-*e) / module;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res.re = new Entier(0);    res.im = new Entier(0);
        return &res;
    }

    res = *this * res;

    qDebug()<<"Complexe"<<res.ConvertChaine();
    return res;
}

Complexe Complexe::operator / (Entier r1) {return *this/r1.toComplexe();}

Complexe Complexe::operator / (Reel r1) {return *this/r1.toComplexe();}

Complexe Complexe::operator / (Rationnel r1) {return *this/r1.toComplexe();}

Constante* Complexe::operator / (Constante* r1)
{
    Complexe* res;

    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        res = new Complexe(*this / *e);
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         res = new Complexe(*this / *e);
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         res = new Complexe(*this / *e);
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         res = new Complexe(*this / *e);
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        res = NULL;
    }
    return res;
}

Complexe Complexe::sqr(){return *this* *this;}
Complexe Complexe::cube(){return *this * *this * *this;}


}
