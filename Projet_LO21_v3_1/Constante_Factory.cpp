#include "Constante_Factory.h"

Nombre* FabriqueNombre::getNombre(QString chaine)
{
    int type = FormuleValide(chaine);

    if(type==1) {return new Entier(chaine);}
    else if(type==2) {return new Reel(chaine);}
    else if(type==3) {return new Rationnel(chaine);}
    else {return NULL;}
}

Nombre* FabriqueNombre::newNombre(Nombre* a){
    if(typeid (*a).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(a);
        return new Entier(e);
    }
    else if (typeid (*a).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(a);
         return new Rationnel(e);
    }
    else if (typeid (*a).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(a);
         return new Reel(e);
    }
}

Constante* FabriqueConstante::getConstante(QString chaine)
{
    int type = FormuleValide(chaine);

    if(type==1 || type==2 || type==3){
        FabriqueNombre fab;
        return fab.getNombre(chaine);
    }
    else if(type==4) {return new Complexe(chaine);}
    else if(type==5) {return new Expression(chaine);}
    else {return NULL;}
}

Constante* FabriqueConstante::getComplexe(QString chaine){
    int type = FormuleValide(chaine);

    if(type==1 || type==2 || type==3){
        Entier* e = new Entier("0");
        FabriqueNombre fab;
        return new Complexe(fab.getNombre(chaine), e);
    }
    else if(type==4) {return new Complexe(chaine);}
    else if(type==5) {return new Expression(chaine);}
    else {return NULL;}
}

Constante* FabriqueConstante::newConstante(Constante* a){
    if(typeid (*a).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(a);
        return new Entier(e);
    }
    else if (typeid (*a).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(a);
         return new Rationnel(e);
    }
    else if (typeid (*a).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(a);
         return new Reel(e);
    }
    else if (typeid (*a).name()==typeid (Complexe).name()){
         Complexe* e = dynamic_cast<Complexe*>(a);
         return new Complexe(e);
    }
}

