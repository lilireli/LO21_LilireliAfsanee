/*
  Hamici Mathilde
  Suzanne Aur�lie
  Projet LO21 - Calculatrice � notation polonaise invers�e
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
            if(pile.Swap(e1, e2))

            emit finOp(&pile);

//            historique.push(pile.clone());
        }
        else{
            pile.push(b);
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


void CalculatriceModele::getSum(int type){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            int k = e->GetEntier();

            if(pile.size()>=k)
            {
                for(int i=0; i<k; i++){
                    emit getAdd(type);
                }

                Constante* res = pile.pop();
                pile.push(res);
                if(typeid (*res).name()==typeid (Expression).name()){
                    emit getExpression();
                }
                delete a;
            }
            else {pile.push(a);}

            emit finOp(&pile);
//            historique.push(pile.clone());
        }
        // else log message("type non conforme");
    }
    // else log message("taille pile insuffisante");
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

                delete a;
            }
            else{
                pile.push(a);
                // log message("taille pile insuffisante");
            }
            emit finOp(&pile);
//            historique.push(pile.clone());
        }
        // else log message("type non conforme");
    }
    // else log message("taille pile insuffisante");
}

void CalculatriceModele::getClear(){
    pile.clear();
    emit finOp(&pile);
//    pile.afficherPile();
//    historique.push(pile.clone());
}

void CalculatriceModele::getDup(){
    if (pile.size()>=1){
        FabriqueConstante fab;

        Constante* c = pile.pop();
        pile.push(c);
        Constante* clone = fab.newConstante(c);
        pile.push(clone);
        //historique.push(pile.clone());
        //afficherHistorique();
        emit finOp(&pile);
    }
    // else log message("taille pile insuffisante");
}

void CalculatriceModele::getDrop(){
    if(pile.size() >= 1){
        Constante* c = pile.pop();
        delete c;
        emit finOp(&pile);
        //historique.push(pile.clone());
        //afficherHistorique();
    }
    // else log message("taille pile insuffisante");
}
