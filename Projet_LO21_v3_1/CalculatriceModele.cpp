/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file CalculatriceModele.cpp
 *  \brief Toutes les fonctions de CalculatriceModele qui ne sont pas des opérations
 *  \author Hamici Mathilde, Suzanne Aurélie
 */
#include "CalculatriceModele.h"
#include <typeinfo>
#include "mainwindow.h"
#include "Constantes.h"
#include "Constante_Factory.h"

using namespace Calcul;

CalculatriceModele::CalculatriceModele(QObject *parent) :
    QObject(parent)
{
    logger1 = new LoggerConsole();
    logger1->Write((new LogMessage(INFO, "Debut de log")));
    logger2 = new LoggerFile();
    logger2->Write((new LogMessage(INFO, "Debut de log")));
    historique.push(pile.clone());
}

void CalculatriceModele::affichePileTaille(){
    qDebug() << "PILE : " << pile.size();
}

void CalculatriceModele::getNombre(QString s, bool complexe){
    FabriqueConstante cte;
    Constante* val;

    if(!complexe){
        val = cte.getConstante(s);

        if (typeid (*val).name()==typeid (Complexe).name()){
            logger1->Write(&LogMessage(ERROR,"type complexe non autorise"));
            logger2->Write(&LogMessage(ERROR,"type complexe non autorise"));
            return;
        }
    }else{//si mode complexe activé
        val = cte.getComplexe(s);
        // on décide d'allouer quand même le nombre si il n'est pas complexe,
        // la conversion est possible et l'utilisateur peut oublier de rentrer tout le nombre si il est réel
        // on convertit cependant le nombre en complexe
    }

    if(val!=NULL) {pile.push(val);
        historique.push(pile.clone());
        this->affichePileTaille();
        emit finOp(&pile);
    }else{
        logger1->Write(&LogMessage(ERROR,"type non pris en compte"));
        logger2->Write(&LogMessage(ERROR,"type non pris en compte"));
    }
}

void CalculatriceModele::getExpression(){
    if(pile.size()>=1){
        Constante *a = pile.pop();

        if (typeid (*a).name() == typeid (Expression).name()){
            Expression* e = dynamic_cast<Expression*>(a);
            QString expression = e->ConvertChaine();
            if(expression.at(0)!='\'' || expression.at(expression.length()-1)!='\''){/*/ lever exception*/}

            QString chaine;

            for(int i=1; i<expression.length()-1; i++){
                if(expression.at(i)==' '){
                    emit evalExp(chaine);
                    chaine.clear();
                }else{
                    chaine+=expression.at(i);
                }
            }
            emit evalExp(chaine);
        }else{
            // la constante n'est pas une expression, on la remet dans la pile
            logger1->Write(&LogMessage(WARNING,"la constante n'est pas de type expression"));
            logger2->Write(&LogMessage(WARNING,"la constante n'est pas de type expression"));
            pile.push(a);
        }
    }
}

void CalculatriceModele::effacerPile(){
    if(!pile.isEmpty()){
        logger1->Write(&LogMessage(WARNING,"La pile sera effacée"));
        logger2->Write(&LogMessage(WARNING,"La pile sera effacée"));
    }

    while(!pile.isEmpty()){
        pile.pop();
    }
    emit finOp(&pile);
}

void CalculatriceModele::transformerPile(){
    if(!pile.isEmpty()){
        int taille = pile.size();
        Constante** tmp = new Constante*[taille];
        FabriqueConstante fab;

        for(int i=0; i<taille; i++){tmp[taille-i-1] = pile.pop();}

        for(int i=0; i<taille; i++){
            Constante* toPop = fab.getComplexe(tmp[i]->ConvertChaine());
            pile.push(toPop);
        }
        qDebug()<<"transforme pile";
        delete[] tmp;
        logger1->Write(&LogMessage(WARNING,"La pile sera transformée en complexes"));
        logger2->Write(&LogMessage(WARNING,"La pile sera transformée en complexes"));
        emit finOp(&pile);
    }
}

void CalculatriceModele::actualiserPile(bool Comp)
{
    if(!pile.isEmpty()){
        int taille = pile.size();
        Constante** tmp = new Constante*[taille];
        FabriqueConstante fab;

        for(int i=0; i<taille; i++){tmp[taille-i-1] = pile.pop();}


        for(int i=0; i<taille; i++){
            if(Comp){
                Constante* toPop = fab.getComplexe(tmp[i]->ConvertChaine());
                pile.push(toPop);
            }else{
                Constante* val = fab.getConstante(tmp[i]->ConvertChaine());

                if (typeid (*val).name()!=typeid (Complexe).name()){
                    pile.push(val);
                }
            }
        }

        delete[] tmp;
    }
}

void CalculatriceModele::ajoutHistorique(Stack* pile){
    historique.push(pile->clone());
    afficherHistorique();
}

void CalculatriceModele::afficherHistorique(){
    QStack<Stack*>::iterator i;
    for (i = historique.begin(); i !=historique.end(); ++i){
        (*i)->afficherPile();
    }
}

void CalculatriceModele::afficherSuppressionHistorique(){
    QStack<Stack*>::iterator i;
    for (i = suppressionHistorique.begin(); i !=suppressionHistorique.end(); ++i){
        (*i)->afficherPile();
    }
}

void CalculatriceModele::annuler(){
    if (historique.size() >= 2){
        qDebug() << "Affichage de l'historique : (annuler)";
        Stack* p1 = historique.pop();
        qDebug() << "Affichage de l'historique : ";
        suppressionHistorique.push(p1);

        Stack* p2 =  historique.last();
        pile = *p2;

        emit compVF();
        emit finAnRe(&pile);
        qDebug()<<historique.size();
        afficherHistorique();
    }
    else{
        logger1->Write(&LogMessage(WARNING,"Il n'y a rien a annuler"));
        logger2->Write(&LogMessage(WARNING,"Il n'y a rien a annuler"));
    }
}

void CalculatriceModele::retablir(){
    if(!suppressionHistorique.empty()){
        Stack* p = suppressionHistorique.pop();

        historique.push(p);

        Stack* p2 =  historique.last();
        pile = *p2;

        qDebug()<<"historique en sorti de retablir";
        afficherHistorique();
        emit compVF();
        emit finAnRe(&pile);
        qDebug() << "historique apres le signal";
        afficherHistorique();
    }
    else{
        logger1->Write(&LogMessage(WARNING,"Il n'y a rien a rétablir"));
        logger2->Write(&LogMessage(WARNING,"Il n'y a rien a rétablir"));
    }
}

void CalculatriceModele::ecritureFichier(){
    QFile file("sauvegardeContexte.txt");
    if (file.open(QFile::WriteOnly)){
        QTextStream stream(&file);
        Stack::iterator it;
        //QString buffer = "";
        QString text = "";
        for (it = pile.begin(); it != pile.end(); ++it){
            text = it.getIt()->ConvertChaine() + '\n' + text;
        }
        stream << text;
        file.close();
    }

}

void CalculatriceModele::lireFichier(){
    QFile file("sauvegardeContexte.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream flux(&file);
    while(!flux.atEnd()) {
        QString var = flux.readLine();
        FabriqueConstante cte;
        Constante* val;
        val = cte.getConstante(var);
        pile.push(val);
    }
    emit finOp(&pile);
    afficherHistorique();
    file.close();
}

void CalculatriceModele::getFermer(){
    ////////////////////////////////////////////////// A DEBUGGER /////////////////////////////////////////
    while(!historique.empty()) {
        qDebug() << "a";
        Stack* pile = historique.pop();

        qDebug() << "b : " << historique.size();
        if(pile!=0) {
        while(!pile->isEmpty()) {
            qDebug() << "c";
            Constante* c;

            c = pile->pop();
            if (c != NULL){
                  qDebug() <<c->ConvertChaine();
                  delete c;
                  c = NULL;
            }
            qDebug()<<"truc";
        }
        qDebug() << "d";

        delete pile;
        pile = 0;
    }
        else qDebug()<<"else";
    }
    //qDebug() <<"2";
}




