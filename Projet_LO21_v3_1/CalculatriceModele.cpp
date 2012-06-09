#include "CalculatriceModele.h"
#include <typeinfo>
#include "mainwindow.h"
#include "Constantes.h"
#include "Constante_Factory.h"

using namespace Calcul;

CalculatriceModele::CalculatriceModele(QObject *parent) :
    QObject(parent)
{
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

void CalculatriceModele::getNombre(QString s, int type){
    FabriqueConstante cte;
    Constante* val = cte.getConstante(s);
    if(val!=NULL) pile.push(val);
    this->affichePileTaille();
}

void CalculatriceModele::getAdd(){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = *e + b;
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = *e + b;
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = *e + b;
        }
        else if (typeid (*a).name()==typeid (Complexe).name()){
            Complexe* e = dynamic_cast<Complexe*>(a);
            res = *e + b;
        }

        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}

void CalculatriceModele::getSous(){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = *e - b;
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = *e - b;
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = *e - b;
        }
        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}

void CalculatriceModele::getMult(){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = *e * b;
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = *e * b;
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = *e * b;
        }
        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}

void CalculatriceModele::getDiv(){}

void CalculatriceModele::getPow(){}

void CalculatriceModele::getMod(){
    if(pile.size()>=1){
        Constante* b = pile.pop();
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name() && typeid (*b).name()==typeid (Entier).name()){
            Entier* e1 = dynamic_cast<Entier*>(b);
            Entier* e2 = dynamic_cast<Entier*>(a);
            res = &(e2->mod(*e1));
        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
        }
    }
}
void CalculatriceModele::getFact(){}

void CalculatriceModele::getSign(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(-*e);
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(-*e);
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(-*e);
        }
        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}

void CalculatriceModele::getSin(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->sinus());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->sinus());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->sinus());
        }

        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}

void CalculatriceModele::getCos(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->cosinus());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->cosinus());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->cosinus());
        }
        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}

void CalculatriceModele::getTan(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->tangente());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->tangente());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->tangente());
        }
        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}

void CalculatriceModele::getSinh(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->sinush());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->sinush());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->sinush());
        }
        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}

void CalculatriceModele::getCosh(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->cosinush());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->cosinush());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->cosinush());
        }
        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}

void CalculatriceModele::getTanh(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->tangenteh());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->tangenteh());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->tangenteh());
        }
        qDebug() << "res : " << res->ConvertChaine();
        pile.push(res);
    }
}


void CalculatriceModele::getLn(){}
void CalculatriceModele::getLog(){}
void CalculatriceModele::getInv(){

}

void CalculatriceModele::getSqrt(){}
void CalculatriceModele::getSqr(){}
void CalculatriceModele::getCube(){}



void CalculatriceModele::getSwap()
{

}

void CalculatriceModele::getSum(){}
void CalculatriceModele::getMean(){}
void CalculatriceModele::getClear(){}
void CalculatriceModele::getDup(){}
void CalculatriceModele::getDrop(){}

