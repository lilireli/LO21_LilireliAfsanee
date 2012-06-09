#include "Constantes.h"

namespace Calcul{
Reel Reel::operator = (Reel r1){Reel ret(r1.n); return ret;}
// fin reprise
Reel Reel::operator + (Reel r1){return n+r1.n;}

Reel Reel::operator + (Entier r1){return *this+r1.toReel();}

Reel Reel::operator + (Rationnel r1){return *this+r1.toReel();}

Nombre* Reel::operator + (Nombre* r1){
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

Constante* Reel::operator + (Constante* r1){
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

Reel Reel::operator - (Reel r1){return n-r1.n;}

Reel Reel::operator - (){return -n;}

Reel Reel::operator - (Entier r1){return *this-r1.toReel();}

Reel Reel::operator - (Rationnel r1){return *this-r1.toReel();}

Constante* Reel::operator - (Constante* r1){
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

Reel Reel::operator * (Reel r1){return n*r1.n;}

Reel Reel::operator * (Entier r1){return *this*r1.toReel();}

Reel Reel::operator * (Rationnel r1){return *this*r1.toReel();}

Constante* Reel::operator * (Constante* r1){
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

Reel Reel::operator / (Reel r1){return n/r1.n;}
Reel Reel::operator / (Entier r1){return n/r1.GetReel();}
Reel Reel::operator / (Rationnel r1){return n/r1.GetRationnel();}
Constante* Reel::operator / (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        return &(*this/ *e);
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         return &(*this/ *e);
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         return &(*this/ *e);
    }
}

Reel Reel::puissance (Reel r1){return pow(n, r1.n);}
Reel Reel::puissance (Entier r1){return pow(n, r1.GetReel());}
Reel Reel::puissance (Rationnel r1){return pow(n, r1.GetRationnel());}

Constante* Reel::puissance (Constante* r1){
    if(typeid (*r1).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(r1);
        return &(this->puissance(*e));
    }
    else if (typeid (*r1).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(r1);
         return &(this->puissance(*e));
    }
    else if (typeid (*r1).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(r1);
         return &(this->puissance(*e));
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
