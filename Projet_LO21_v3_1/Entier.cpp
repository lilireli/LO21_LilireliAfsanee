/*
  Hamici Mathilde
  Suzanne Aur�lie
  Projet LO21 - Calculatrice � notation polonaise invers�e
*/
/*!
 *  \file Entier.cpp
 *  \brief Fonctions de gestion des Entier
 *  \author Hamici Mathilde, Suzanne Aur�lie
 */
#include "Constantes.h"
#include <qDebug>

namespace Calcul{
Entier Entier::operator + (Entier r1){return n+r1.n;}

Reel Entier::operator + (Reel r1){return this->toReel()+r1;}

Rationnel Entier::operator + (Rationnel r1){return this->toRationnel()+r1;}

Nombre* Entier::operator + (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Entier(*this + *e);
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

Constante* Entier::operator + (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Entier(*this + *e);
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

Entier Entier::operator - (Entier r1){return n-r1.n;}

Entier Entier::operator - (){return -n;}

Reel Entier::operator - (Reel r1){return this->toReel()-r1;}

Rationnel Entier::operator - (Rationnel r1){return this->toRationnel()-r1;}

Nombre* Entier::operator - (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Entier(*this  - *e);
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

Constante* Entier::operator - (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Entier(*this  - *e);
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

Entier Entier::operator * (Entier r1){return n*r1.n;}

Reel Entier::operator * (Reel r1){return this->toReel()*r1;}

Rationnel Entier::operator * (Rationnel r1){return this->toRationnel()*r1;}

Nombre* Entier::operator * (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Entier(*this  * *e);
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

Constante* Entier::operator * (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Entier(*this  * *e);
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

Reel Entier::operator / (Reel r1){return this->GetReel()/r1.GetReel();}

Rationnel Entier::operator / (Entier r1){
    if(r1.n!=0){
        Rationnel res(n, r1.n);
        res.Simplification();
        return res;
    }
    else{
        logger1->Write(&LogMessage(WARNING,"division par 0"));
        logger2->Write(&LogMessage(WARNING,"division par 0"));
        Rationnel res(0, 1);
        return res;
    }
}

Rationnel Entier::operator / (Rationnel r1){
    Rationnel res(n*r1.GetDen(), r1.GetNum());
    res.Simplification();
    return res;
}

Nombre* Entier::operator / (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Rationnel(*this / *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Nombre* res = new Rationnel(*this / *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Nombre* res = new Reel(*this / *e);
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Nombre* res = NULL;
        return res;
    }
}

Constante* Entier::operator / (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Rationnel(*this / *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Rationnel(*this / *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Constante* res = new Reel(*this / *e);
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

Reel Entier::puissance (Reel r1){return pow(this->GetReel(), r1.GetReel());}

Rationnel Entier::puissance (Entier r1){
    Rationnel res;
    int res_i=1;

    for(int i=0; i<r1.n; i++){res_i = res_i * n;}

    if (r1.n < 0) {res.SetDen(res_i);}
    else if(r1.n == 0){res.SetNum(1);}
    else{res.SetNum(res_i);}

    res.Simplification();
    return res;
}

Reel Entier::puissance (Rationnel r1){return pow(this->GetReel(), r1.GetRationnel());}

Constante* Entier::puissance (Constante* r1){
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

Reel Entier::sinus(){return sin(this->GetReel());}
Reel Entier::cosinus(){return cos(this->GetReel());}
Reel Entier::tangente(){return tan(this->GetReel());}
Reel Entier::sinush(){return sinh(this->GetReel());}
Reel Entier::cosinush(){return cosh(this->GetReel());}
Reel Entier::tangenteh(){return tanh(this->GetReel());}


Reel* Entier::ln(){
    if(isPositif()&&!isNull()){Reel* res = new Reel(log(this->GetReel())); return res;}
    else{
        logger1->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        logger2->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        return NULL;
    }
}

Reel* Entier::logdix(){
    if(isPositif()&&!isNull()){Reel* res = new Reel(log10(this->GetReel())); return res;}
    else{
        logger1->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        logger2->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        return NULL;
    }
}

Rationnel* Entier::inv(){Rationnel *res = new Rationnel(1, n); return res;}

Reel* Entier::rsqr(){
    if(isPositif()&&!isNull()){Reel* res = new Reel(log10(sqrt(this->GetReel()))); return res;}
    else{
        logger1->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        logger2->Write(&LogMessage(WARNING,"hors limites de la fonction"));
        return NULL;
    }
}

Entier Entier::sqr(){return n*n;}
Entier Entier::cube(){return n*n*n;}

Entier Entier::mod(Entier e){return n%e.GetEntier();}

Entier Entier::fact(){
    Entier res(1);
    for(int i=2; i<=n; i++){res.n = res.n*i;}
    return res;
}

}
