#include "Constante_Factory.h"

Nombre* FabriqueNombre::getNombre(QString chaine)
{
    int type = FormuleValide(chaine);

    if(type==1) {return new Entier(chaine);}
    else if(type==2) {return new Reel(chaine);}
    else if(type==3) {return new Rationnel(chaine);}
    else {return NULL;}
}

Constante* FabriqueConstante::getConstante(QString chaine)
{
    int type = FormuleValide(chaine);

    if(type==1) {return new Entier(chaine);}
    else if(type==2) {return new Reel(chaine);}
    else if(type==3) {return new Rationnel(chaine);}
    else if(type==4) {return new Complexe(chaine);}
    else if(type==5) {return NULL;}
    else {return NULL;}

    // faire expression
}

