#include "Gestion_constantes.h"

int NombreValide(QString chaine)
{
    QString chiffres("0123456789");
    int type=0;
    int trouve=0, moins=0;

    for(int i=0; i<chaine.length(); i++)
    {
        if(chiffres.contains(chaine.at(i)))
        {
            if(type<1) type=1;
        }
        else if(chaine.at(i) == '/') {
            if(chaine.length()==1){return 0;}
            if(trouve==0){ trouve=1; if(type<3) type=3;}
            else return 0;
        }
        else if(chaine.at(i) == '.') {
            if(trouve==0){ trouve=1; if(type<2) type=2;}
            else return 0;
        }
        else if(chaine.at(i) == '-') {
            if(chaine.length()==1){return 0;}
            if(moins==0){ moins=1;}
            else return 0;
        }
        else
            return 0;
    }
    return type;
}


int FormuleValide(QString s)
{
    int trouve=0;
    QString n, m;

    for(int i = 0; i<s.length(); i++){
        if(s.at(i) != '$') {
            if(trouve==0) n=n+s.at(i);
            else m=m+s.at(i);
        }else trouve=1;
    }

    if(trouve==0)return NombreValide(n);
    else if(NombreValide(n)!=0 && NombreValide(m)!=0) return 4;
    else return 0;
}


    int Stack::push(Constante* nb)
    {
        if (this->isFull()){return -1;}
        else
        {
            tab[nbElements] = nb;
            nbElements ++;
            return 1;
        }

    }

    Constante *Stack::pop()
    {
        if(!this->isEmpty())
        {
            nbElements --;
            return tab[nbElements];
        }
        return NULL;
    }


