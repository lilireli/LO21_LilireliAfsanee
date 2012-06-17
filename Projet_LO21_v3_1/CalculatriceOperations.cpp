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

void CalculatriceModele::getAdd(int type){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();

        // gestion des expressions
        if (typeid (*a).name()==typeid (Expression).name() && typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             Expression* f = dynamic_cast<Expression*>(b);
             e->addCalcul(f->Tronque()+" +");
             pile.push(e);
             emit finOp(&pile);
             delete b;
             return;
        }
        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(b->ConvertChaine()+" +");
             pile.push(e);
             emit finOp(&pile);
             delete b;
             return;
        }
        if (typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(b);
             e->calculAdd(a->ConvertChaine()+" +");
             pile.push(e);
             emit finOp(&pile);
             delete a;
             return;
        }

        // gestion des autres types
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
        // else log message "type non reconnu";

        FabriqueConstante fab;
        res = fab.getType(res, type);

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();

        emit finOp(&pile);
        delete a;
        delete b;
    }
    // else log message "taille pile insuffisante"
}

void CalculatriceModele::getSous(int type){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name() && typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             Expression* f = dynamic_cast<Expression*>(b);
             e->addCalcul(f->Tronque()+" -");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(b->ConvertChaine()+" -");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(b);
             e->calculAdd(a->ConvertChaine()+" -");
             pile.push(e);
//             emit finOp(e, 2);
             delete a;
             return;
        }

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

        FabriqueConstante fab;
        res = fab.getType(res, type);

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
//        emit finOp(res, 2);
        finOp(&pile);
        delete a;
        delete b;
    }
}

void CalculatriceModele::getMult(int type){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name() && typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             Expression* f = dynamic_cast<Expression*>(b);
             e->addCalcul(f->Tronque()+" *");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(b->ConvertChaine()+" *");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(b);
             e->calculAdd(a->ConvertChaine()+" *");
             pile.push(e);
//             emit finOp(e, 2);
             delete a;
             return;
        }

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

        FabriqueConstante fab;
        res = fab.getType(res, type);

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
//        emit finOp(res, 2);
        finOp(&pile);
        delete a;
        delete b;
    }
}

void CalculatriceModele::getDiv(int type){
    // type res en fonction type
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name() && typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             Expression* f = dynamic_cast<Expression*>(b);
             e->addCalcul(f->Tronque()+" /");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(b->ConvertChaine()+" /");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(b);
             e->calculAdd(a->ConvertChaine()+" /");
             pile.push(e);
//             emit finOp(e, 2);
             delete a;
             return;
        }

        Constante* res;
        if(type==2)// si le type est rationnel on converti les r�els en entier avant la division
                   // afin de limiter les pertes d'infos de la division
        {
            if (typeid (*a).name()==typeid (Reel).name()){
                Reel* e = dynamic_cast<Reel*>(a);
                Entier *en = new Entier (e->toEntier());
                delete a;
                a = en;
            }
            if (typeid (*b).name()==typeid (Reel).name()){
                Reel* e = dynamic_cast<Reel*>(b);
                Entier *en = new Entier (e->toEntier());
                delete b;
                b = en;
            }
        }

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
//        emit finOp(res, 2);
        finOp(&pile);
        delete a;
        delete b;
    }
}

void CalculatriceModele::getPow(int type){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name() && typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             Expression* f = dynamic_cast<Expression*>(b);
             e->addCalcul(f->Tronque()+" -");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(b->ConvertChaine()+" pow");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(b);
             e->calculAdd(a->ConvertChaine()+" pow");
             pile.push(e);
//             emit finOp(e, 2);
             delete a;
             return;
        }

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

        FabriqueConstante fab;
        res = fab.getType(res, type);

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
//        emit finOp(res, 2);
        finOp(&pile);
        delete a;
        delete b;
    }
}

void CalculatriceModele::getMod(){
    if(pile.size()>=2){
        Constante* b = pile.pop();
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name() && typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             Expression* f = dynamic_cast<Expression*>(b);
             e->addCalcul(f->Tronque()+" -");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(b->ConvertChaine()+" mod");
             pile.push(e);
//             emit finOp(e, 2);
             delete b;
             return;
        }
        if (typeid (*b).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(b);
             e->calculAdd(a->ConvertChaine()+" mod");
             pile.push(e);
//             emit finOp(e, 2);
             delete a;
             return;
        }

        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name() && typeid (*b).name()==typeid (Entier).name()){
            Entier* e1 = dynamic_cast<Entier*>(b);
            Entier* e2 = dynamic_cast<Entier*>(a);
            res = &(e2->mod(*e1));
            pile.push(res);
            qDebug() << "res : " << res->ConvertChaine();
//            emit finOp(res, 2);
            delete a;
            delete b;
        }else{
            pile.push(a);
            pile.push(b);
        }
        finOp(&pile);
    }
}

void CalculatriceModele::getFact(){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" fact");
             pile.push(e);
//             emit finOp(e, 1);
             finOp(&pile);
             return;
        }

        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
            Entier* e = dynamic_cast<Entier*>(a);
            res = new Entier(e->fact());
            pile.push(res);
            qDebug() << "res : " << res->ConvertChaine();
//            emit finOp(res, 1);
            delete a;
        }else{
            pile.push(a);
        }
        finOp(&pile);
    }
}

void CalculatriceModele::getSign(int type){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" sign");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

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

        FabriqueConstante fab;
        res = fab.getType(res, type);

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
//        emit finOp(res, 1);
        delete a;
    }
}


void CalculatriceModele::getSin(bool degre){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" sin");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

        Constante* res;

        if(degre){Reel rad(PI/180); a = rad*a;}

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
//        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getCos(bool degre){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" cos");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

        Constante* res;

        if(degre){Reel rad(PI/180); a = rad*a;}

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
//        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getTan(bool degre){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" tan");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

        Constante* res;

        if(degre){Reel rad(PI/180); a = rad*a;}

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
//        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getSinh(bool degre){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" sinh");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

        Constante* res;

        if(degre){Reel rad(PI/180); a = rad*a;}

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
//        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getCosh(bool degre){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" cosh");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

        Constante* res;

        if(degre){Reel rad(PI/180); a = rad*a;}

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
//        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getTanh(bool degre){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" tanh");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

        Constante* res;

        if(degre){Reel rad(PI/180); a = rad*a;}

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
//        emit finOp(res, 1);
        delete a;
    }
}


void CalculatriceModele::getLn(){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" ln");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

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
//        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getLog(){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" log");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

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
//        emit finOp(res, 1);
        delete a;
    }
}

void CalculatriceModele::getInv(int type){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" inv");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

        Constante* res;

        if(typeid (*a).name()==typeid (Entier).name()){
             Entier* e = dynamic_cast<Entier*>(a);
             if (type==1){res = new Reel(e->toReel().inv());}
             else{res = new Rationnel(e->inv());}
        }
        else if (typeid (*a).name()==typeid (Rationnel).name()){
             Rationnel* e = dynamic_cast<Rationnel*>(a);
             if (type==1){res = new Reel(e->toReel().inv());}
             else{res = new Rationnel(e->inv());}
        }
        else if (typeid (*a).name()==typeid (Reel).name()){
             Reel* e = dynamic_cast<Reel*>(a);
             if(type==1){res = new Reel(e->inv());}
             else{res = new Rationnel(e->toRationnel().inv());}
        }


        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
//        emit finOp(res, 1);
        finOp(&pile);
        delete a;
    }
}


void CalculatriceModele::getSqrt(){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" sqrt");
             pile.push(e);
//             emit finOp(e, 1);
             finOp(&pile);
             return;
        }

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
//        emit finOp(res, 1);
        finOp(&pile);
        delete a;
    }
}

void CalculatriceModele::getSqr(int type){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" sqr");
             pile.push(e);
//             emit finOp(e, 1);
             return;
        }

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

        FabriqueConstante fab;
        res = fab.getType(res, type);

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();
//        emit finOp(res, 1);
        finOp(&pile);
        delete a;
    }
}

void CalculatriceModele::getCube(int type){
    if(pile.size()>=1){
        Constante* a = pile.pop();

        if (typeid (*a).name()==typeid (Expression).name()){
             Expression* e = dynamic_cast<Expression*>(a);
             e->addCalcul(" cube");
             pile.push(e);
//             emit finOp(e, 1);
             finOp(&pile);
             return;
        }

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

        FabriqueConstante fab;
        res = fab.getType(res, type);

        pile.push(res);
        qDebug() << "res : " << res->ConvertChaine();

        //historique.push(pile.clone());
//        emit finOp(res, 1);
        finOp(&pile);
        //delete a;
    }
}
