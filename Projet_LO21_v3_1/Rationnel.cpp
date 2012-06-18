/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
#include "Constantes.h"
#include <QDebug>

namespace Calcul{
void Rationnel::Simplification()
{
    int min;
    if(num < den) min=num; else min=den;

    for(int i=min; i>0; i--)
    {
        if(num%i == 0)
        {
            if(den%i == 0)
            {
                num = num/i;
                den = den/i;
            }
        }
    }

    if(num<0 && den<0) { num=-num; den=-den; }
}

Entier Rationnel::toEntier(){Entier e(this->toReel().GetEntier()); return e;}

Rationnel Rationnel::operator + (Rationnel r1){
    Rationnel somme(num*r1.den + den*r1.num, den*r1.den);
    somme.Simplification();
    return somme;
}

Rationnel Rationnel::operator + (Entier r1){return *this + r1.toRationnel();}

Reel Rationnel::operator + (Reel r1)
{
    return this->toReel()+r1;
}

Nombre* Rationnel::operator + (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Rationnel(*this + *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Nombre* res = new Rationnel(*this + *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Nombre* res = new Reel(*this + *e);
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Nombre* res = NULL;
        return res;
    }
}

Constante* Rationnel::operator + (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Rationnel(*this + *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Rationnel(*this + *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Constante* res = new Reel(*this + *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         Constante* res = new Complexe(*e + *this);
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Constante* res = NULL;
        return res;
    }
}

Rationnel Rationnel::operator - (Rationnel r1){
    Rationnel somme(num*r1.den - den*r1.num, den*r1.den);
    somme.Simplification();
    return somme;
}

Rationnel Rationnel::operator - ()
{
    num=-num;
    this->Simplification();
    return *this;
}

Rationnel Rationnel::operator - (Entier r1){return *this - r1.toRationnel();}

Reel Rationnel::operator - (Reel r1)
{
    return this->toReel()-r1;
}

Nombre* Rationnel::operator - (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Rationnel(*this  - *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Nombre* res = new Rationnel(*this  - *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Nombre* res = new Reel(*this  - *e);
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Nombre* res = NULL;
        return res;
    }
}

Constante* Rationnel::operator - (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Rationnel(*this  - *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Rationnel(*this  - *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Constante* res = new Reel(*this  - *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         Constante* res = new Complexe(-(*e - *this));
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Constante* res = NULL;
        return res;
    }
}


Rationnel Rationnel::operator * (Rationnel r1){
    Rationnel somme(num*r1.num, den*r1.den);
    somme.Simplification();
    return somme;
}

Rationnel Rationnel::operator * (Entier r1){return *this * r1.toRationnel();}

Reel Rationnel::operator * (Reel r1)
{
    return this->toReel()*r1;
}

Nombre* Rationnel::operator * (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Rationnel(*this  * *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Nombre* res = new Rationnel(*this  * *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Nombre* res = new Reel(*this  * *e);
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Nombre* res = NULL;
        return res;
    }
}

Constante* Rationnel::operator * (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Rationnel(*this  * *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Rationnel(*this  * *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Constante* res = new Reel(*this  * *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         Constante* res = new Complexe(*e * *this);
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Constante* res = NULL;
        return res;
    }
}



Rationnel Rationnel::operator / (Rationnel r1){
    if(r1.GetNum()!=0){
        Rationnel div(num*r1.GetDen(), den*r1.GetNum());
        div.Simplification();
        return div;
    }
    logger1->Write(&LogMessage(WARNING,"division par 0"));
    logger2->Write(&LogMessage(WARNING,"division par 0"));
    Rationnel div(0,1);
    return div;
}

Rationnel Rationnel::operator / (Entier r1){
    if(r1.GetEntier()!=0){
        Rationnel div(num, den*r1.GetEntier());
        div.Simplification();
        return div;
    }
    logger1->Write(&LogMessage(WARNING,"division par 0"));
    logger2->Write(&LogMessage(WARNING,"division par 0"));
    Rationnel div(0,1);
    return div;
}

Reel Rationnel::operator / (Reel r1){
    Reel div(this->GetRationnel()/r1.GetReel());
    return div;
}

Nombre* Rationnel::operator / (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Rationnel(*this  / *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Nombre* res = new Rationnel(*this  / *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Nombre* res = new Reel(*this  / *e);
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Nombre* res = NULL;
        return res;
    }
}

Constante* Rationnel::operator / (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Rationnel(*this  / *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Rationnel(*this  / *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Constante* res = new Reel(*this  / *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         Constante* res = new Complexe(*e / *this);
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Constante* res = NULL;
        return res;
    }
}


Reel Rationnel::puissance (Reel r1){return pow(this->GetRationnel(), r1.GetReel());}

Rationnel Rationnel::puissance (Entier r1){
    Rationnel res;
    int res_i_num=1;
    int res_i_den=1;

    for(int i=0; i<r1.GetEntier(); i++){
        res_i_num = res_i_num * num;
        res_i_den = res_i_den * den;
    }

    if (r1.GetEntier() < 0) {res.num = res_i_den;  res.den = res_i_num;}
    else if(r1.GetEntier() == 0){res.num = 1; res.den = 0;}
    else{res.num = res_i_num;  res.den = res_i_den;}

    res.Simplification();
    return res;
}

Reel Rationnel::puissance (Rationnel r1){return pow(this->GetRationnel(), r1.GetRationnel());}

Constante* Rationnel::puissance (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Rationnel(this->puissance(*e));
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Reel(this->puissance(*e));
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Constante* res = new Reel(this->puissance(*e));
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Constante* res = NULL;
        return res;
    }
}


Reel Rationnel::sinus(){return sin(this->GetRationnel());}
Reel Rationnel::cosinus(){return cos(this->GetRationnel());}
Reel Rationnel::tangente(){return tan(this->GetRationnel());}
Reel Rationnel::sinush(){return sinh(this->GetRationnel());}
Reel Rationnel::cosinush(){return cosh(this->GetRationnel());}
Reel Rationnel::tangenteh(){return tanh(this->GetRationnel());}

Reel* Rationnel::ln(){
    if(isPositif()&& !isNull()){Reel *res = new Reel(log(this->GetRationnel())); return res;}
    else{
        logger1->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        logger2->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        return NULL;
    }
}

Reel* Rationnel::logdix(){
    if(isPositif()&& !isNull()){Reel *res = new Reel(log10(this->GetRationnel())); return res;}
    else{
        logger1->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        logger2->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        return NULL;
    }
}

Rationnel* Rationnel::inv(){Rationnel* res = new Rationnel(den, num); return res;}

Reel* Rationnel::rsqr(){
    if(isPositif()&&!isNull()){Reel *res = new Reel(sqrt(this->GetRationnel())); return res;}
    else{
        logger1->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        logger2->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        return NULL;
    }
}

Rationnel Rationnel::sqr(){
    Rationnel res(num*num, den*den);
    res.Simplification();
    return res;}

Rationnel Rationnel::cube(){
    Rationnel res(num*num*num, den*den*den);
    res.Simplification();
    return res;
}

}
