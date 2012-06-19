/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file Gestion_constantes.cpp
 *  \brief Implémentation de fonction pour la gestion des constantes : pile et fonctions de vérification de validité
 *         de chaine de caractères
 *  \author Hamici Mathilde, Suzanne Aurélie
 */
#include "Gestion_constantes.h"
#include "Logger.h"

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
    if(type==0){
        logger1->Write(&LogMessage(ERROR,"nombre non valide"));
        logger2->Write(&LogMessage(ERROR,"nombre non valide"));
    }
    return type;
}


int FormuleValide(QString s)
{
    int trouve=0;
    QString n, m;

    if(s.at(0)=='\'' && s.at(s.length()-1)=='\''){return  5;}

    for(int i = 0; i<s.length(); i++){
        if(s.at(i) != '$') {
            if(trouve==0) n=n+s.at(i);
            else m=m+s.at(i);
        }else trouve=1;
    }

    if(trouve==0)return NombreValide(n);
    else if(NombreValide(n)!=0 && NombreValide(m)!=0) return 4;
    else {
        logger1->Write(&LogMessage(ERROR,"constante non valide"));
        logger2->Write(&LogMessage(ERROR,"constante non valide"));
        return 0;
    }
}


int Stack::push(Constante* nb)
{
    if (this->isFull()){
        logger1->Write(&LogMessage(WARNING,"pile pleine"));
        logger2->Write(&LogMessage(WARNING,"pile pleine"));
        return -1;}
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
   logger1->Write(&LogMessage(WARNING,"pile vide"));
   logger2->Write(&LogMessage(WARNING,"pile vide"));
   return NULL;
}

void Stack::clear(){
    while (!isEmpty()){
        pop();
    }
}

int Stack::Swap(Entier* x, Entier* y){
        int a = x->GetEntier();
        int b = y->GetEntier();

        if(a<nbElements && b<nbElements)
        {
            Constante* tmp = tab[a-1];
            tab[a-1]=tab[b-1];
            tab[b-1]=tmp;

            return 1;
        }
        logger1->Write(&LogMessage(ERROR,"taille pile insuffisante"));
        logger2->Write(&LogMessage(ERROR,"taille pile insuffisante"));
        return 0;
}


void Stack::afficherPile(){
    QString buffer = "";
    for (iterator it = begin(); it != end(); ++it){
        buffer += it.getIt()->ConvertChaine() + " ";
    }
    qDebug() << "PILE : [" << buffer << "]";
}

QString Stack::retournePileS(){
    QString buffer = "";
    for (iterator it = begin(); it != end(); ++it){
        buffer = it.getIt()->ConvertChaine() + "\n" + buffer;
    }
    return buffer;
}

