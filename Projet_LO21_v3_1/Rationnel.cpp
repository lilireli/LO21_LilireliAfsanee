#include "Constantes.h"

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

Constante* Rationnel::operator + (Constante* r1){
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

Constante* Rationnel::operator - (Constante* r1){
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

Constante* Rationnel::operator * (Constante* r1){
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


/*Rationnel operator /(Rationnel r1, Rationnel r2)
{
    if(r2.GetNum()!=0){
        Rationnel div(r1.GetNum()*r2.GetDen(), r1.GetDen()*r2.GetNum());
        div.Simplification();
        return div;
    }
    Rationnel div(0,1);
    return div;
}*/


//Rationnel Rationnel::exposant();

Reel Rationnel::sinus(){return sin(this->GetRationnel());}
Reel Rationnel::cosinus(){return cos(this->GetRationnel());}
Reel Rationnel::tangente(){return tan(this->GetRationnel());}
Reel Rationnel::sinush(){return sinh(this->GetRationnel());}
Reel Rationnel::cosinush(){return cosh(this->GetRationnel());}
Reel Rationnel::tangenteh(){return tanh(this->GetRationnel());}

//Reel Rationnel::ln();
//Reel Rationnel::logdix();
//Rationnel Rationnel::inv();
//Reel Rationnel::sqrt();
//Rationnel Rationnel::sqr();
//Rationnel Rationnel::cube();
}
