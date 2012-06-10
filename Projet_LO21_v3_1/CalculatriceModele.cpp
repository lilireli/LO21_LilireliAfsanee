#include "CalculatriceModele.h"
#include <typeinfo>
#include "mainwindow.h"
#include "Constantes.h"
#include "Constante_Factory.h"

using namespace Calcul;

CalculatriceModele::CalculatriceModele(QObject *parent) :
    QObject(parent)
{
//    model = new MainWindow;
//    connect(this, SIGNAL(finOp(QString s)), ui, SLOT(rafraichissement(QString s)));
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

void CalculatriceModele::getNombre(QString s){
    FabriqueConstante cte;
    Constante* val = cte.getConstante(s);
    if(val!=NULL) {pile.push(val);
    this->affichePileTaille();
    emit finOp(val, 0);
    }

//    qDebug() << typeid (*val).name();
}

void CalculatriceModele::getExpression(){
    if(pile.size()>=1){
        Constante *a = pile.pop();
        if (typeid (*a).name() == typeid (Expression).name()){
            Expression* e = dynamic_cast<Expression*>(a);
            e->EvalExpression();
        }
    }
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

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
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
        else if (typeid (*a).name()==typeid (Complexe).name()){
             Complexe* e = dynamic_cast<Complexe*>(a);
             res = *e - b;
        }

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
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
        else if (typeid (*a).name()==typeid (Complexe).name()){
             Complexe* e = dynamic_cast<Complexe*>(a);
             res = *e * b;
        }

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}

void CalculatriceModele::getDiv(){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = *e / b;
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = *e / b;
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = *e / b;
        }
        else if (typeid (*a).name()==typeid (Complexe).name()){
             Complexe* e = dynamic_cast<Complexe*>(a);
             res = *e / b;
        }

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}

void CalculatriceModele::getPow(){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = e->puissance(b);
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = e->puissance(b);
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = e->puissance(b);
        }

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}

void CalculatriceModele::getMod(){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name() && typeid (*b).name()==typeid (Entier).name()){
            Entier* e1 = dynamic_cast<Entier*>(b);
            Entier* e2 = dynamic_cast<Entier*>(a);
            res = &(e2->mod(*e1));
            pile.push(res);
            qDebug() << "res : " << res->ConvertChaine();
            emit finOp(res, 2);
        }
    }
}
void CalculatriceModele::getFact(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->fact());
            pile.push(res);
            qDebug() << "res : " << res->ConvertChaine();
            emit finOp(res, 2);
        }
    }
}

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
        else if (typeid (*a).name()==typeid (Complexe).name()){
             Complexe* e = dynamic_cast<Complexe*>(a);
             res = &(-*e);
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
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

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
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
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
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
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
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
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
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
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
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
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}


void CalculatriceModele::getLn(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->ln());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->ln());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->ln());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}


void CalculatriceModele::getLog(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->logdix());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->logdix());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->logdix());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}

void CalculatriceModele::getInv(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->inv());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->inv());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->inv());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}


void CalculatriceModele::getSqrt(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->rsqr());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->rsqr());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->rsqr());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}

void CalculatriceModele::getSqr(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->sqr());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->sqr());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->sqr());
        }
        else if (typeid (*a).name()==typeid (Complexe).name()){
             Complexe* e = dynamic_cast<Complexe*>(a);
             res = &(e->sqr());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}

void CalculatriceModele::getCube(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = &(e->cube());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = &(e->cube());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = &(e->cube());
        }
        else if (typeid (*a).name()==typeid (Complexe).name()){
             Complexe* e = dynamic_cast<Complexe*>(a);
             res = &(e->cube());
        }

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
    }
}



void CalculatriceModele::getSwap()
{

}

void CalculatriceModele::getSum(){}
void CalculatriceModele::getMean(){}
void CalculatriceModele::getClear(){}
void CalculatriceModele::getDup(){}
void CalculatriceModele::getDrop(){}

