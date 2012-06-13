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

void CalculatriceModele::getNombre(QString s, int complexe){
    FabriqueConstante cte;
    Constante* val;

    if(complexe!=1){
        val = cte.getConstante(s);

        if (typeid (*val).name()==typeid (Complexe).name()){
            delete val;
            // exception on ne peut créer un complexe (message d'erreur)
            return;
        }
    }else{//si mode complexe activé
        val = cte.getComplexe(s);
    }

    if(val!=NULL) {pile.push(val);
    this->affichePileTaille();
    emit finOp(val, 0);
    }
    // sinon lever exception
}

void CalculatriceModele::getExpression(){
    if(pile.size()>=1){
        Constante *a = pile.pop();

        if (typeid (*a).name() == typeid (Expression).name()){
            Expression* e = dynamic_cast<Expression*>(a);
            emit finOp(NULL, 1);
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
            pile.push(a);
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
        delete a;
        delete b;
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
        delete a;
        delete b;
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
        delete a;
        delete b;
    }
}

void CalculatriceModele::getDiv(int type){
    // type res en fonction type
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

        FabriqueConstante fab;
        res = fab.getType(res, type);

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 2);
        delete a;
        delete b;
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
        delete a;
        delete b;
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
            delete a;
            delete b;
        }else{
            pile.push(a);
            pile.push(b);
        }
    }
}

void CalculatriceModele::getFact(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Entier(e->fact());
            pile.push(res);
            qDebug() << "res : " << res->ConvertChaine();
            emit finOp(res, 1);
            delete a;
        }else{
            pile.push(a);
        }
    }
}

void CalculatriceModele::getSign(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Entier(-*e);
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Rationnel(-*e);
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(-*e);
        }
        else if (typeid (*a).name()==typeid (Complexe).name()){
             Complexe* e = dynamic_cast<Complexe*>(a);
             res = new Complexe(-*e);
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}


void CalculatriceModele::getSin(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
             Entier* e = dynamic_cast<Entier*>(a);
             res = new Reel(e->sinus());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Reel(e->sinus());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->sinus());
        }

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getCos(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Reel(e->cosinus());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Reel(e->cosinus());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->cosinus());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getTan(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Reel(e->tangente());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Reel(e->tangente());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->tangente());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getSinh(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Reel(e->sinush());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Reel(e->sinush());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->sinush());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getCosh(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Reel(e->cosinush());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Reel(e->cosinush());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->cosinush());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getTanh(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Reel(e->tangenteh());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Reel(e->tangenteh());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->tangenteh());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}


void CalculatriceModele::getLn(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Reel(e->ln());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Reel(e->ln());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->ln());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}


void CalculatriceModele::getLog(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Reel(e->logdix());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Reel(e->logdix());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->logdix());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getInv(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Rationnel(e->inv());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Rationnel(e->inv());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->inv());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}


void CalculatriceModele::getSqrt(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Reel(e->rsqr());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Reel(e->rsqr());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->rsqr());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getSqr(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Entier(e->sqr());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Rationnel(e->sqr());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->sqr());
        }
        else if (typeid (*a).name()==typeid (Complexe).name()){
             Complexe* e = dynamic_cast<Complexe*>(a);
             res = new Complexe(e->sqr());
        }
        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getCube(){
    if(pile.size()>=1){
        Constante* a = pile.pop();
        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Entier(e->cube());
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             res = new Rationnel(e->cube());
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             res = new Reel(e->cube());
        }
        else if (typeid (*a).name()==typeid (Complexe).name()){
             Complexe* e = dynamic_cast<Complexe*>(a);
             res = new Complexe(e->cube());
        }

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
        emit finOp(res, 1);
        //delete a;
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

