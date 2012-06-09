#include "Constantes.h"

namespace Calcul{
Entier Entier::operator + (Entier r1){return n+r1.n;}

Reel Entier::operator + (Reel r1){return this->toReel()+r1;}

Rationnel Entier::operator + (Rationnel r1){return this->toRationnel()+r1;}

Nombre* Entier::operator + (Nombre* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        return &(*this+*e);
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         return &(*this+*e);
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         return &(*this+*e);
    }
}

Constante* Entier::operator + (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        return &(*this+*e);
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         return &(*this+*e);
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         return &(*this+*e);
    }
}

Entier Entier::operator - (Entier r1){return n-r1.n;}

Entier Entier::operator - (){return -n;}

Reel Entier::operator - (Reel r1){return this->toReel()-r1;}

Rationnel Entier::operator - (Rationnel r1){return this->toRationnel()-r1;}

Constante* Entier::operator - (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        return &(*this-*e);
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         return &(*this-*e);
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         return &(*this-*e);
    }
}

Entier Entier::operator * (Entier r1){return n*r1.n;}

Reel Entier::operator * (Reel r1){return this->toReel()*r1;}

Rationnel Entier::operator * (Rationnel r1){return this->toRationnel()*r1;}

Constante* Entier::operator * (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        return &(*this**e);
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         return &(*this**e);
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         return &(*this**e);
    }
}

// /
//Rationnel Entier::exposant();  // si la puissance est négative retournera 1/x^n

Reel Entier::sinus(){return sin(this->GetReel());}
Reel Entier::cosinus(){return cos(this->GetReel());}
Reel Entier::tangente(){return tan(this->GetReel());}
Reel Entier::sinush(){return sinh(this->GetReel());}
Reel Entier::cosinush(){return cosh(this->GetReel());}
Reel Entier::tangenteh(){return tanh(this->GetReel());}


//Reel Entier::ln();
//Reel Entier::logdix();
//Rationnel Entier::inv();  // retourne 1/x
//Reel Entier::sqrt();
//Entier Entier::sqr();
//Entier Entier::cube();

/*Entier Entier::fact()
{
    Entier res;
    for(int i=2; i<=n; i++){res = res*i;}
    return res;
}

}*/

Entier Entier::mod(Entier e){return n%e.GetEntier();}
}
