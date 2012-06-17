/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
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
}

Entier Entier::operator - (Entier r1){return n-r1.n;}

// voir opérateurs unaires
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
}

Reel Entier::operator / (Reel r1){return this->GetReel()/r1.GetReel();}

Rationnel Entier::operator / (Entier r1){
    Rationnel res(n, r1.n);
    res.Simplification();
    return res;
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
}

Reel Entier::sinus(){return sin(this->GetReel());}
Reel Entier::cosinus(){return cos(this->GetReel());}
Reel Entier::tangente(){return tan(this->GetReel());}
Reel Entier::sinush(){return sinh(this->GetReel());}
Reel Entier::cosinush(){return cosh(this->GetReel());}
Reel Entier::tangenteh(){return tanh(this->GetReel());}


Reel Entier::ln(){return log(this->GetReel());}
Reel Entier::logdix(){return log10(this->GetReel());}
Rationnel Entier::inv(){Rationnel res(1, n); return res;}
Reel Entier::rsqr(){return sqrt(this->GetReel());}
Entier Entier::sqr(){return n*n;}
Entier Entier::cube(){return n*n*n;}

Entier Entier::mod(Entier e){return n%e.GetEntier();}

Entier Entier::fact(){
    Entier res(1);
    for(int i=2; i<=n; i++){res.n = res.n*i;}
    return res;
}

}
