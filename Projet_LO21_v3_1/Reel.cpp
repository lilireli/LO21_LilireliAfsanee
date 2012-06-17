/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
#include "Constantes.h"

namespace Calcul{
Entier Reel::toEntier(){Entier e(this->GetEntier()); return e;}

Rationnel Reel::toRationnel(){Rationnel r(this->GetEntier()); return r;}

Reel Reel::operator + (Reel r1){return n+r1.n;}

Reel Reel::operator + (Entier r1){return *this+r1.toReel();}

Reel Reel::operator + (Rationnel r1){return *this+r1.toReel();}

Nombre* Reel::operator + (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Reel(*this + *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Nombre* res = new Reel(*this + *e);
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

Constante* Reel::operator + (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Reel(*this + *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Reel(*this + *e);
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

Reel Reel::operator - (Reel r1){return n-r1.n;}

Reel Reel::operator - (){return -n;}

Reel Reel::operator - (Entier r1){return *this-r1.toReel();}

Reel Reel::operator - (Rationnel r1){return *this-r1.toReel();}

Nombre* Reel::operator - (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Reel(*this  - *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Nombre* res = new Reel(*this  - *e);
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

Constante* Reel::operator - (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Reel(-(*this  - *e));
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Reel(*this  - *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Constante* res = new Reel(*this  - *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(r1);
         Constante* res = new Complexe(*e - *this);
         return res;
    }
    else {
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
        Constante* res = NULL;
        return res;
    }
}

Reel Reel::operator * (Reel r1){return n*r1.n;}

Reel Reel::operator * (Entier r1){return *this*r1.toReel();}

Reel Reel::operator * (Rationnel r1){return *this*r1.toReel();}

Nombre* Reel::operator * (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Reel(*this  * *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Nombre* res = new Reel(*this  * *e);
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

Constante* Reel::operator * (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Reel(*this  * *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Reel(*this  * *e);
         return res;
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         Constante* res = new Reel(*e * *this);
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

Reel Reel::operator / (Reel r1){
    if(r1.n != 0){return n/r1.n;}
    else{
        logger1->Write(&LogMessage(WARNING,"division par 0"));
        logger2->Write(&LogMessage(WARNING,"division par 0"));
        Reel res("0");
        return res;
    }
}

Reel Reel::operator / (Entier r1){return n/r1.GetReel();}
Reel Reel::operator / (Rationnel r1){return n/r1.GetRationnel();}
Nombre* Reel::operator / (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Nombre* res = new Reel(*this  / *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Nombre* res = new Reel(*this  / *e);
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

Constante* Reel::operator / (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Reel(*this  / *e);
        return res;
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         Constante* res = new Reel(*this  / *e);
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

Reel Reel::puissance (Reel r1){return pow(n, r1.n);}
Reel Reel::puissance (Entier r1){return pow(n, r1.GetReel());}
Reel Reel::puissance (Rationnel r1){return pow(n, r1.GetRationnel());}

Constante* Reel::puissance (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        Constante* res = new Reel(this->puissance(*e));
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

Reel Reel::sinus(){return sin(n);}
Reel Reel::cosinus(){return cos(n);}
Reel Reel::tangente(){return tan(n);}
Reel Reel::sinush(){return sinh(n);}
Reel Reel::cosinush(){return cosh(n);}
Reel Reel::tangenteh(){return tanh(n);}

Reel Reel::ln(){return log(n);}
Reel Reel::logdix(){return log10(n);}
Reel Reel::inv(){return 1/n;}
Reel Reel::rsqr(){return sqrt(n);}
Reel Reel::sqr(){return n*n;}
Reel Reel::cube(){return n*n*n;}
}
