/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file Constante_Factory.cpp
 *  \brief Fonctions créant des Constante ou des Nombre
 *  \author Hamici Mathilde, Suzanne Aurélie
 */
#include "Constante_Factory.h"

Nombre* FabriqueNombre::getNombre(QString chaine)
{
    int type = FormuleValide(chaine);

    if(type==1) {return new Entier(chaine);}
    else if(type==2) {return new Reel(chaine);}
    else if(type==3) {return new Rationnel(chaine);}
    else {
        logger1->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        logger2->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        return NULL;
    }
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
    else {
        logger1->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        logger2->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        return NULL;
    }
}

Nombre* FabriqueNombre::getType(Nombre* a, int type){
    if(typeid (*a).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(a);
        if(type==1){Reel* res = new Reel(e->toReel()); return res;}
        else if(type==2){Rationnel* res = new Rationnel(e->toRationnel()); return res;}
        else{return e;}
    }
    else if (typeid (*a).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(a);
         if(type==1){Reel* res = new Reel(e->toReel()); return res;}
         else if(type==2){return e;}
         else{Entier* res = new Entier(e->toEntier()); return res;}
    }
    else if (typeid (*a).name()==typeid (Reel).name()){
         Reel* e = dynamic_cast<Reel*>(a);
         if(type==1){return e;}
         else if(type==2){Rationnel* res = new Rationnel(e->toRationnel()); return res;}
         else{Entier* res = new Entier(e->toEntier()); return res;}
    }
    else {
        logger1->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        logger2->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        return NULL;
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
    else {
        logger1->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        logger2->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        return NULL;
    }
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
    else {
        logger1->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        logger2->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        return NULL;
    }
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
    else if (typeid (*a).name()==typeid (Expression).name()){
         Expression* e = dynamic_cast<Expression*>(a);
         return new Expression(e);
    }
    else {
        logger1->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        logger2->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        return NULL;
    }
}

Constante* FabriqueConstante::getType(Constante* a, int type){
    if(typeid (*a).name()==typeid (Entier).name()){
        Entier* e = dynamic_cast<Entier*>(a);
        if(type==1){Reel* res = new Reel(e->toReel()); return res;}
        else if(type==2){Rationnel* res = new Rationnel(e->toRationnel()); return res;}
        else{return e;}
    }
    else if (typeid (*a).name()==typeid (Rationnel).name()){
         Rationnel* e = dynamic_cast<Rationnel*>(a);
         if(type==1){Reel* res = new Reel(e->toReel()); return res;}
         else if(type==2){return e;}
         else{Entier* res = new Entier(e->toEntier()); return res;}
    }
    else if (typeid (*a).name()==typeid (Reel).name()){
            qDebug()<<"aqui12";
         Reel* e = dynamic_cast<Reel*>(a);
         if(type==1){return e;}
         else if(type==2){Rationnel* res = new Rationnel(e->toRationnel()); return res;}
         else{Entier* res = new Entier(e->toEntier()); return res;}
    }
    else if (typeid (*a).name()==typeid (Complexe).name()){
        FabriqueNombre fab;
        Complexe* e = dynamic_cast<Complexe*>(a);
        e->SetRe(fab.getType(e->GetRe(), type));
        e->SetIm(fab.getType(e->GetIm(), type));
        return e;
    }
    else {
        logger1->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        logger2->Write(&LogMessage(WARNING,"type non conforme, non pris en compte"));
        return NULL;
    }
}
