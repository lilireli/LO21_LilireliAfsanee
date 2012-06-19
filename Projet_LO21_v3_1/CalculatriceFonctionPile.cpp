/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file CalculatriceFonctionPile.cpp
 *  \brief Fonctions sur la pile gérées par la calculatrice
 *  \author Hamici Mathilde, Suzanne Aurélie
 */
#include "CalculatriceModele.h"
#include <typeinfo>
#include "mainwindow.h"
#include "Constantes.h"
#include "Constante_Factory.h"

void CalculatriceModele::getSwap()
{
    if(pile.size()>=2){
        Constante* a = pile.pop();
        Constante* b = pile.pop();

        if(typeid (*a).name()==typeid (Entier).name() && typeid (*b).name()==typeid (Entier).name()){
            Entier* e1 = dynamic_cast<Entier*>(a);
            Entier* e2 = dynamic_cast<Entier*>(b);
            if(!pile.Swap(e1, e2)){
                logger1->Write(&LogMessage(ERROR,"type non conforme"));
                logger2->Write(&LogMessage(ERROR,"type non conforme"));
            }

            emit finOp(&pile);

        }
        else{
            pile.push(b);
            pile.push(a);
            logger1->Write(&LogMessage(ERROR,"type non conforme, entier attendu"));
            logger2->Write(&LogMessage(ERROR,"type non conforme, entier attendu"));
        }
    }
    else{
        logger1->Write(&LogMessage(ERROR,"taille pile insuffisante"));
        logger2->Write(&LogMessage(ERROR,"taille pile insuffisante"));
    }
}


void CalculatriceModele::getSum(int type){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            int k = e->GetEntier();

            if(pile.size()>=k)
            {
                for(int i=0; i<k-1; i++){
                    emit getAdd(type);
                }

                Constante* res = pile.pop();
                pile.push(res);
                if(typeid (*res).name()==typeid (Expression).name()){
                    emit getExpression();
                }
            }
            else {
                logger1->Write(&LogMessage(ERROR,"pas assez d'expressions"));
                logger2->Write(&LogMessage(ERROR,"pas assez d'expressions"));
                pile.push(a);}

            emit finOp(&pile);
        }else{
            pile.push(a);
            logger1->Write(&LogMessage(ERROR,"type non conforme"));
            logger2->Write(&LogMessage(ERROR,"type non conforme"));

        }
    }
    else{
    logger1->Write(&LogMessage(ERROR,"taille pile insuffisante"));
    logger2->Write(&LogMessage(ERROR,"taille pile insuffisante"));
    }
}


void CalculatriceModele::getMean(int type){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);

            if(pile.size()>=e->GetEntier())
            {
                Rationnel nb_moyenne = e->inv();

                pile.push(e);
                emit getSum(type);

                a = pile.pop();
                Constante* res = nb_moyenne * a;
                qDebug()<<"res :"<<res->ConvertChaine();
                pile.push(res);
            }
            else{
                pile.push(a);
                logger1->Write(&LogMessage(ERROR,"taille pile insuffisante"));
                logger2->Write(&LogMessage(ERROR,"taille pile insuffisante"));
            }
        }
        emit finOp(&pile);
        logger1->Write(&LogMessage(ERROR,"type non conforme"));
        logger2->Write(&LogMessage(ERROR,"type non conforme"));
    }
    else{
    logger1->Write(&LogMessage(ERROR,"taille pile insuffisante"));
    logger2->Write(&LogMessage(ERROR,"taille pile insuffisante"));
    }
}

void CalculatriceModele::getClear(){
    pile.clear();
    emit finOp(&pile);
}

void CalculatriceModele::getDup(){
    if (pile.size()>=1){
        FabriqueConstante fab;

        Constante* c = pile.pop();
        pile.push(c);
        Constante* clone = fab.newConstante(c);
        pile.push(clone);
        emit finOp(&pile);
    }
    else{
        logger1->Write(&LogMessage(ERROR,"taille pile insuffisante"));
        logger2->Write(&LogMessage(ERROR,"taille pile insuffisante"));
    }
}

void CalculatriceModele::getDrop(){
    if(pile.size() >= 1){
        Constante* c = pile.pop();
        emit finOp(&pile);
    }
    else{
        logger1->Write(&LogMessage(ERROR,"taille pile insuffisante"));
        logger2->Write(&LogMessage(ERROR,"taille pile insuffisante"));
    }
}
