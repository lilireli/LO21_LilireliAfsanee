/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
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
    //historique.push(pile.clone());
}

void CalculatriceModele::affichePileTaille(){
    qDebug() << "PILE : " << pile.size();
    //for(int i = 0;i<pile.size();i++)
        //qDebug() << pile.at(i);
    /*
    for ( it = pile.begin(); it!=pile.end(); ++it) {
        qDebug() << *it;
    }
    */
}

void CalculatriceModele::getNombre(QString s, bool complexe){
    FabriqueConstante cte;
    Constante* val;

    if(!complexe){
        val = cte.getConstante(s);

        if (typeid (*val).name()==typeid (Complexe).name()){
            delete val;
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
            delete a;
        }else{
            // la constante n'est pas une expression, on la remet dans la pile
            logger1->Write(&LogMessage(WARNING,"la constante n'est pas de type expression"));
            logger2->Write(&LogMessage(WARNING,"la constante n'est pas de type expression"));
            pile.push(a);
        }
    }
}

void CalculatriceModele::effacerPile(){
    while(!pile.isEmpty()){
        pile.pop();
    }
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
        delete[] tmp;
    }
}



//void CalculatriceModele::afficherHistorique(){
//    QStack<Stack*>::iterator i;
//    for (i = historique.begin(); i !=historique.end(); ++i){
//        (*i)->afficherPile();
//    }
//}

void CalculatriceModele::afficherSuppressionHistorique(){
    QStack<Stack*>::iterator i;
    for (i = suppressionHistorique.begin(); i !=suppressionHistorique.end(); ++i){
        (*i)->afficherPile();
    }
}

void CalculatriceModele::annuler(){
    if (historique.size() >= 2){
        qDebug() << "Affichage de l'historique : ";
//        afficherHistorique();
        Stack* p1 = historique.pop();
        qDebug() << "Affichage de l'historique : ";
//        afficherHistorique();
        suppressionHistorique.push(p1);
        afficherSuppressionHistorique();
        qDebug()<<historique.size();
        Stack* p2 =  historique.last();
        qDebug()<<"p2 : ";
        p2->afficherPile();
        pile = *p2;
        qDebug()<<"pile : ";
        pile.afficherPile();

        emit raffraichirUi(pile.retournePileS());
        //afficherHistorique();
        //affichePileTaille();

    }
}

void CalculatriceModele::retablir(){
    if(!suppressionHistorique.empty()){
        qDebug()<<"suppression historique : ";
        afficherSuppressionHistorique();
        Stack* p = suppressionHistorique.pop();
        qDebug()<<"suppression historique : ";
        afficherSuppressionHistorique();
        historique.push(p);
        qDebug()<<"historique : ";
//        afficherHistorique();
        Stack* p2 =  historique.last();
        qDebug()<<"p2 : ";
        p2->afficherPile();
        pile = *p2;
        qDebug()<<"pile : ";
        pile.afficherPile();
        emit raffraichirUi(pile.retournePileS());
    }
}

void CalculatriceModele::ecritureFichier(){
    std::ofstream file;
    file.open("sauvegardeContexte", std::ios::app); //app : ajout en fin de fichier
    file.seekp(std::ios::beg);//changer la position du pointeur au début du flux

    if(!file.good()/*pret à lire ou écrire*/) return;
    QStack<Stack*>::iterator i;
    for (i = historique.begin(); i !=historique.end(); ++i){
        Stack::iterator it;
        QString buffer = "";
        for (it = (*i)->begin(); it != (*i)->end(); ++it){
            buffer += it.getIt()->ConvertChaine() + " ";
        }
        file<<buffer.toStdString()<<"\n";
        file.flush();
    }
    file.flush();//synchronisation

    file.close();
}



