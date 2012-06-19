/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file MainWindow.cpp
 *  \brief Gestion de l'interface graphique (ce que ne fait pas, ou peu simplement, QTdesigner)
 *  \author Hamici Mathilde, Suzanne Aurélie
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Gestion_constantes.h"
#include "Constante_Factory.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initialisations
    model = new CalculatriceModele;
    buffer = "";
    ui->numCompPressed->setEnabled(false);
    typeNombre = 0;
    degre=true;
    complexe=false;
    taille_pile = 6;

    this->resize(685, 520);
    hide = false;

    // fenêtre pour selectionner la taille de la pile
    FenetrePile.setFixedSize(200, 150);
    QGroupBox *groupPile = new QGroupBox("Taille de la pile d'affichage", &FenetrePile);

    QSpinBox *taille = new QSpinBox(&FenetrePile);
        taille->setMaximum(30);
    QPushButton *valid = new QPushButton("Valider", &FenetrePile);
        valid->setCheckable(true);

    QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(taille);
        vbox->addWidget(valid);

        groupPile->setLayout(vbox);
        groupPile->setFixedSize(160, 110);
        groupPile->move(20,20);

    connect(taille, SIGNAL(valueChanged(int)), this, SLOT(setTaillePile(int)));
    connect(valid, SIGNAL(clicked()), &FenetrePile, SLOT(close()));
    connect(ui->actionTaille_Affich, SIGNAL(triggered()), &FenetrePile, SLOT(exec()));


    // afficher clavier
    connect(ui->actionAfficher_clavier, SIGNAL(triggered()), this, SLOT(affichClavier()));
    connect(this, SIGNAL(cache()), ui->clavier, SLOT(hide()));
    connect(this, SIGNAL(montre()), ui->clavier, SLOT(show()));


    // mise à jour degrés / radians
    connect(ui->actionDegres, SIGNAL(triggered()), this, SLOT(degreActif()));
    connect(ui->actionRadians, SIGNAL(triggered()), this, SLOT(radianActif()));


    // Opérations essentielles
    connect(this, SIGNAL(pressEntrerN(QString, bool)), model, SLOT(getNombre(QString, bool)));
    connect(model, SIGNAL(evalExp(QString)), this, SLOT(EnterAction(QString)));
    connect(model, SIGNAL(finOp(Stack*)), model, SLOT(ajoutHistorique(Stack*)));
    connect(this, SIGNAL(finEntree()), this, SLOT(rafraichissement()));
    connect(model, SIGNAL(finOp(Stack*)), this, SLOT(affichePile(Stack*)));
    connect(model, SIGNAL(finAnRe(Stack*)), this, SLOT(affichePile(Stack*)));
    connect(this, SIGNAL(pressEval()), model, SLOT(getExpression()));


    // opérations
    connect(this, SIGNAL(pressAdd(int)), model, SLOT(getAdd(int)));
    connect(this, SIGNAL(pressSous(int)), model, SLOT(getSous(int)));
    connect(this, SIGNAL(pressMult(int)), model, SLOT(getMult(int)));
    connect(this, SIGNAL(pressDiv(int)), model, SLOT(getDiv(int)));

    connect(this, SIGNAL(pressPow(int)), model, SLOT(getPow(int)));
    connect(this, SIGNAL(pressMod()), model, SLOT(getMod()));
    connect(this, SIGNAL(pressFact()), model, SLOT(getFact()));
    connect(this, SIGNAL(pressSign(int)), model, SLOT(getSign(int)));

    connect(this, SIGNAL(pressSin(bool)), model, SLOT(getSin(bool)));
    connect(this, SIGNAL(pressCos(bool)), model, SLOT(getCos(bool)));
    connect(this, SIGNAL(pressTan(bool)), model, SLOT(getTan(bool)));

    connect(this, SIGNAL(pressSinh(bool)), model, SLOT(getSinh(bool)));
    connect(this, SIGNAL(pressCosh(bool)), model, SLOT(getCosh(bool)));
    connect(this, SIGNAL(pressTanh(bool)), model, SLOT(getTanh(bool)));

    connect(this, SIGNAL(pressLn()), model, SLOT(getLn()));
    connect(this, SIGNAL(pressLog()), model, SLOT(getLog()));
    connect(this, SIGNAL(pressInv(int)), model, SLOT(getInv(int)));

    connect(this, SIGNAL(pressSqrt()), model, SLOT(getSqrt()));
    connect(this, SIGNAL(pressSqr(int)), model, SLOT(getSqr(int)));
    connect(this, SIGNAL(pressCube(int)), model, SLOT(getCube(int)));

    connect(this, SIGNAL(pressSwap()), model, SLOT(getSwap()));
    connect(this, SIGNAL(pressSum(int)), model, SLOT(getSum(int)));
    connect(this, SIGNAL(pressMean(int)), model, SLOT(getMean(int)));
    connect(this, SIGNAL(pressClear()), model, SLOT(getClear()));
    connect(this, SIGNAL(pressDup()), model, SLOT(getDup()));
    connect(this, SIGNAL(pressDrop()), model, SLOT(getDrop()));


    // Annuler / Rétablir
    connect(this, SIGNAL(pressAnnuler()), model, SLOT(annuler()));
    connect(this, SIGNAL(pressRetablir()), model, SLOT(retablir()));
    connect(model, SIGNAL(compVF()), this, SLOT(verifComp()));
    connect(this, SIGNAL(vaVerif(bool)), model, SLOT(actualiserPile(bool)));

    // Gérer les complexe
    connect(this, SIGNAL(complexeVrai()), model, SLOT(transformerPile()));
    connect(this, SIGNAL(complexeFaux()), model, SLOT(effacerPile()));

    // Sauvegarde de contexte
    connect(ui->actionEnregistrer, SIGNAL(triggered()), model, SLOT(ecritureFichier()));
    connect(ui->actionOuvrir, SIGNAL(triggered()), model, SLOT(lireFichier()));

    connect(ui->actionEnregistrer, SIGNAL(triggered()), this, SLOT(enregistrer()));
    connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(lire()));
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}


// boutons de type
void MainWindow::on_buttonEntier_clicked(){
    if (typeNombre != 0){
        typeNombre = 0;
        if (complexe == true){
            ui->opCoshPressed->setEnabled(false);
            ui->opCosPressed->setEnabled(false);
            ui->opFactPressed->setEnabled(false);
            ui->opInvPressed->setEnabled(false);
            ui->opLnPressed->setEnabled(false);
            ui->opLogPressed->setEnabled(false);
            ui->opModPressed->setEnabled(false);
            ui->opPowPressed->setEnabled(false);
            ui->opSinhPressed->setEnabled(false);
            ui->opSinPressed->setEnabled(false);
            ui->opTanhPressed->setEnabled(false);
            ui->opTanPressed->setEnabled(false);
        }
        else {
            ui->opCoshPressed->setEnabled(true);
            ui->opCosPressed->setEnabled(true);
            ui->opFactPressed->setEnabled(true);
            ui->opInvPressed->setEnabled(true);
            ui->opLnPressed->setEnabled(true);
            ui->opLogPressed->setEnabled(true);
            ui->opModPressed->setEnabled(true);
            ui->opPowPressed->setEnabled(true);
            ui->opSinhPressed->setEnabled(true);
            ui->opSinPressed->setEnabled(true);
            ui->opTanhPressed->setEnabled(true);
            ui->opTanPressed->setEnabled(true);
        }
    }
}

void MainWindow::on_buttonReel_clicked(){
    if (typeNombre != 1) {
        typeNombre = 1;
        if (complexe == true){
            ui->opCoshPressed->setEnabled(false);
            ui->opCosPressed->setEnabled(false);
            ui->opFactPressed->setEnabled(false);
            ui->opInvPressed->setEnabled(false);
            ui->opLnPressed->setEnabled(false);
            ui->opLogPressed->setEnabled(false);
            ui->opModPressed->setEnabled(false);
            ui->opPowPressed->setEnabled(false);
            ui->opSinhPressed->setEnabled(false);
            ui->opSinPressed->setEnabled(false);
            ui->opTanhPressed->setEnabled(false);
            ui->opTanPressed->setEnabled(false);
        }
        else {
            ui->opCoshPressed->setEnabled(true);
            ui->opCosPressed->setEnabled(true);
            ui->opFactPressed->setEnabled(false);
            ui->opInvPressed->setEnabled(true);
            ui->opLnPressed->setEnabled(true);
            ui->opLogPressed->setEnabled(true);
            ui->opModPressed->setEnabled(false);
            ui->opPowPressed->setEnabled(true);
            ui->opSinhPressed->setEnabled(true);
            ui->opSinPressed->setEnabled(true);
            ui->opTanhPressed->setEnabled(true);
            ui->opTanPressed->setEnabled(true);
        }
    }
}

void MainWindow::on_buttonRationnel_clicked(){
    if (typeNombre != 2) {
        typeNombre = 2;

        if (complexe == true){
            ui->opCoshPressed->setEnabled(false);
            ui->opCosPressed->setEnabled(false);
            ui->opFactPressed->setEnabled(false);
            ui->opInvPressed->setEnabled(false);
            ui->opLnPressed->setEnabled(false);
            ui->opLogPressed->setEnabled(false);
            ui->opModPressed->setEnabled(false);
            ui->opPowPressed->setEnabled(false);
            ui->opSinhPressed->setEnabled(false);
            ui->opSinPressed->setEnabled(false);
            ui->opTanhPressed->setEnabled(false);
            ui->opTanPressed->setEnabled(false);
        }
        else{
            ui->opCoshPressed->setEnabled(true);
            ui->opCosPressed->setEnabled(true);
            ui->opFactPressed->setEnabled(false);
            ui->opInvPressed->setEnabled(true);
            ui->opLnPressed->setEnabled(true);
            ui->opLogPressed->setEnabled(true);
            ui->opModPressed->setEnabled(false);
            ui->opPowPressed->setEnabled(true);
            ui->opSinhPressed->setEnabled(true);
            ui->opSinPressed->setEnabled(true);
            ui->opTanhPressed->setEnabled(true);
            ui->opTanPressed->setEnabled(true);
        }
    }
}

void MainWindow::on_buttonComplexe_clicked(){
    if (!complexe){
        complexe = true;
        ui->numCompPressed->setEnabled(true);
        ui->opCoshPressed->setEnabled(false);
        ui->opCosPressed->setEnabled(false);
        ui->opFactPressed->setEnabled(false);
        ui->opInvPressed->setEnabled(false);
        ui->opLnPressed->setEnabled(false);
        ui->opLogPressed->setEnabled(false);
        ui->opModPressed->setEnabled(false);
        ui->opPowPressed->setEnabled(false);
        ui->opSinhPressed->setEnabled(false);
        ui->opSinPressed->setEnabled(false);
        ui->opTanhPressed->setEnabled(false);
        ui->opTanPressed->setEnabled(false);
        ui->opSqrtPressed->setEnabled(false);
        emit complexeVrai();
    }
    else {
        complexe = false;
        ui->numCompPressed->setEnabled(false);
        ui->opCoshPressed->setEnabled(true);
        ui->opCosPressed->setEnabled(true);
        ui->opInvPressed->setEnabled(true);
        ui->opLnPressed->setEnabled(true);
        ui->opLogPressed->setEnabled(true);
        ui->opPowPressed->setEnabled(true);
        ui->opSinhPressed->setEnabled(true);
        ui->opSinPressed->setEnabled(true);
        ui->opTanhPressed->setEnabled(true);
        ui->opTanPressed->setEnabled(true);
        ui->opSqrtPressed->setEnabled(true);

        if (typeNombre == 0){
            ui->opFactPressed->setEnabled(true);
            ui->opModPressed->setEnabled(true);
        }
        else {
            ui->opFactPressed->setEnabled(false);
            ui->opModPressed->setEnabled(false);
        }
        emit complexeFaux();
    }
}

void MainWindow::degreActif(){
    ui->actionRadians->setChecked(false);
    degre=true;
}

void MainWindow::radianActif(){
    ui->actionDegres->setChecked(false);
    degre=false;
}

void MainWindow::affichClavier(){
    qDebug()<<"la";
    if(hide==true){
        hide=false;

        this->resize(680, 520);
        emit montre();
    }else{
        hide=true;
        this->resize(510, 520);
        emit cache();
    }
}

//opérations essentielles
void MainWindow::on_EnterPressed_clicked()
{
    if(buffer.isEmpty()){
        emit pressDup();
    }
    else{
        EnterAction(buffer);
        emit finEntree();
    }
}

void MainWindow::EnterAction(QString s)
{
    if(FormuleValide(s)){
        emit pressEntrerN(s, complexe);
    }
    else{
        if(s=="+"){emit pressAdd(typeNombre);}
        else if(s=="-"){emit pressSous(typeNombre);}
        else if(s=="*"){emit pressMult(typeNombre);}
        else if(s=="/"){emit pressDiv(typeNombre);}

        else if(s=="pow"){emit pressPow(typeNombre);}
        else if(s=="mod"){emit pressMod();}
        else if(s=="fact"){emit pressFact();}
        else if(s=="sign"){emit pressSign(typeNombre);}

        else if(s=="sin"){emit pressSin(degre);}
        else if(s=="cos"){emit pressCos(degre);}
        else if(s=="tan"){emit pressTan(degre);}

        else if(s=="sinh"){emit pressSinh(degre);}
        else if(s=="cosh"){emit pressCosh(degre);}
        else if(s=="tanh"){emit pressTanh(degre);}

        else if(s=="ln"){emit pressLn();}
        else if(s=="log"){emit pressLog();}
        else if(s=="inv"){emit pressInv(typeNombre);}

        else if(s=="sqrt"){emit pressSqrt();}
        else if(s=="sqr"){emit pressSqr(typeNombre);}
        else if(s=="cube"){emit pressCube(typeNombre);}

        else if(s=="swap"){emit pressSwap();}
        else if(s=="sum"){emit pressSum(typeNombre);}
        else if(s=="mean"){emit pressMean(typeNombre);}
        else if(s=="clear"){emit pressClear();}
        else if(s=="dup"){emit pressDup();}
        else if(s=="drop"){emit pressDrop();}

        else{
            logger1->Write(&LogMessage(ERROR,"formule non valide"));
            logger2->Write(&LogMessage(ERROR,"formule non valide"));
        }
    }
}

void MainWindow::on_EvalPressed_clicked(){
    emit pressEval();
}

void MainWindow::on_opDelPressed_clicked(){
    if(buffer!=""){
        buffer.remove(buffer.length()-1, 1);
        ui->lineEdit->clear();
        ui->lineEdit->insert(buffer);
    }
    else { emit pressDrop(); }
}

void MainWindow::rafraichissement()
{
    buffer.clear();
    ui->lineEdit->clear();
}

void MainWindow::affichePile(Stack *pile)
{
    ui->textEdit->clear();
    affichage = *(pile->clone());

    int t=0;
    if(affichage.size()>=taille_pile){ t=taille_pile;}
    else {t=affichage.size();}

    if(t!=0){
        Constante** tmp = new Constante*[t];

        for(int i=0; i<=t-1; i++){
            tmp[t-i-1] = affichage.pop();
            ui->textEdit->insertPlainText(tmp[t-i-1]->ConvertChaine()+"\n");
        }

        for(int i=0; i<=t-1; i++){ affichage.push(tmp[i]); }
        delete[] tmp;
    }
}


void MainWindow::setTaillePile(int n)
{
    taille_pile = n;
}

void MainWindow::on_clickAnnul_clicked(){
    emit pressAnnuler();
}

void MainWindow::on_clickRetablir_clicked(){
    emit pressRetablir();
}

void MainWindow::verifComp(){
    emit vaVerif(complexe);
}


void MainWindow::enregistrer(){
    QFile file("sauvegardeParametre.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        QTextStream stream(&file);
        //QString buffer = "";
        QString text = QString::number(typeNombre) + ";" + QString::number(complexe) + ";" + QString::number(taille_pile) + ";" + QString::number(degre) +";";
        stream << text;
        file.close();
    }
    else{
        logger1->Write(&LogMessage(ERROR,"L'ouverture du fichier a échoué"));
        logger2->Write(&LogMessage(ERROR,"L'ouverture du fichier a échoué"));
    }
}

void MainWindow::lire(){
    QFile file("sauvegardeParametre.txt");
    if(file.open(QIODevice::ReadOnly)){
        QTextStream flux(&file);
        QString var;
        while(!flux.atEnd()) {
            var += flux.readLine();
        }
        QStringList liste = var.split(";");
        typeNombre = liste.at(0).toInt();
        complexe = liste.at(1).toInt();
        taille_pile = liste.at(2).toInt();
        degre = liste.at(3).toInt();
        file.close();

        if (typeNombre == 0) {
            ui->buttonEntier->setChecked(true);
            if (complexe == true){
                ui->opCoshPressed->setEnabled(false);
                ui->opCosPressed->setEnabled(false);
                ui->opFactPressed->setEnabled(false);
                ui->opInvPressed->setEnabled(false);
                ui->opLnPressed->setEnabled(false);
                ui->opLogPressed->setEnabled(false);
                ui->opModPressed->setEnabled(false);
                ui->opPowPressed->setEnabled(false);
                ui->opSinhPressed->setEnabled(false);
                ui->opSinPressed->setEnabled(false);
                ui->opTanhPressed->setEnabled(false);
                ui->opTanPressed->setEnabled(false);
            }
            else {
                ui->opCoshPressed->setEnabled(true);
                ui->opCosPressed->setEnabled(true);
                ui->opFactPressed->setEnabled(true);
                ui->opInvPressed->setEnabled(true);
                ui->opLnPressed->setEnabled(true);
                ui->opLogPressed->setEnabled(true);
                ui->opModPressed->setEnabled(true);
                ui->opPowPressed->setEnabled(true);
                ui->opSinhPressed->setEnabled(true);
                ui->opSinPressed->setEnabled(true);
                ui->opTanhPressed->setEnabled(true);
                ui->opTanPressed->setEnabled(true);
            }
        }
        else if (typeNombre == 1){
            ui->buttonReel->setChecked(true);
            if (complexe == true){
                ui->opCoshPressed->setEnabled(false);
                ui->opCosPressed->setEnabled(false);
                ui->opFactPressed->setEnabled(false);
                ui->opInvPressed->setEnabled(false);
                ui->opLnPressed->setEnabled(false);
                ui->opLogPressed->setEnabled(false);
                ui->opModPressed->setEnabled(false);
                ui->opPowPressed->setEnabled(false);
                ui->opSinhPressed->setEnabled(false);
                ui->opSinPressed->setEnabled(false);
                ui->opTanhPressed->setEnabled(false);
                ui->opTanPressed->setEnabled(false);
            }
            else {
                ui->opCoshPressed->setEnabled(true);
                ui->opCosPressed->setEnabled(true);
                ui->opFactPressed->setEnabled(false);
                ui->opInvPressed->setEnabled(true);
                ui->opLnPressed->setEnabled(true);
                ui->opLogPressed->setEnabled(true);
                ui->opModPressed->setEnabled(false);
                ui->opPowPressed->setEnabled(true);
                ui->opSinhPressed->setEnabled(true);
                ui->opSinPressed->setEnabled(true);
                ui->opTanhPressed->setEnabled(true);
                ui->opTanPressed->setEnabled(true);
            }
        }
        else if (typeNombre == 2){
            ui->buttonRationnel->setChecked(true);

            if (complexe == true){
                ui->opCoshPressed->setEnabled(false);
                ui->opCosPressed->setEnabled(false);
                ui->opFactPressed->setEnabled(false);
                ui->opInvPressed->setEnabled(false);
                ui->opLnPressed->setEnabled(false);
                ui->opLogPressed->setEnabled(false);
                ui->opModPressed->setEnabled(false);
                ui->opPowPressed->setEnabled(false);
                ui->opSinhPressed->setEnabled(false);
                ui->opSinPressed->setEnabled(false);
                ui->opTanhPressed->setEnabled(false);
                ui->opTanPressed->setEnabled(false);
            }
            else{
                ui->opCoshPressed->setEnabled(true);
                ui->opCosPressed->setEnabled(true);
                ui->opFactPressed->setEnabled(false);
                ui->opInvPressed->setEnabled(true);
                ui->opLnPressed->setEnabled(true);
                ui->opLogPressed->setEnabled(true);
                ui->opModPressed->setEnabled(false);
                ui->opPowPressed->setEnabled(true);
                ui->opSinhPressed->setEnabled(true);
                ui->opSinPressed->setEnabled(true);
                ui->opTanhPressed->setEnabled(true);
                ui->opTanPressed->setEnabled(true);
            }
        }
        if (complexe){
            ui->buttonComplexe->setChecked(true);
            ui->buttonComplexe->setChecked(true);
            ui->numCompPressed->setEnabled(true);
            ui->opCoshPressed->setEnabled(false);
            ui->opCosPressed->setEnabled(false);
            ui->opFactPressed->setEnabled(false);
            ui->opInvPressed->setEnabled(false);
            ui->opLnPressed->setEnabled(false);
            ui->opLogPressed->setEnabled(false);
            ui->opModPressed->setEnabled(false);
            ui->opPowPressed->setEnabled(false);
            ui->opSinhPressed->setEnabled(false);
            ui->opSinPressed->setEnabled(false);
            ui->opTanhPressed->setEnabled(false);
            ui->opTanPressed->setEnabled(false);
            ui->opSqrtPressed->setEnabled(false);
        }
        else {
                ui->buttonComplexe->setChecked(false);
                ui->numCompPressed->setEnabled(false);
                ui->opCoshPressed->setEnabled(true);
                ui->opCosPressed->setEnabled(true);
                ui->opInvPressed->setEnabled(true);
                ui->opLnPressed->setEnabled(true);
                ui->opLogPressed->setEnabled(true);
                ui->opPowPressed->setEnabled(true);
                ui->opSinhPressed->setEnabled(true);
                ui->opSinPressed->setEnabled(true);
                ui->opTanhPressed->setEnabled(true);
                ui->opTanPressed->setEnabled(true);
                ui->opSqrtPressed->setEnabled(true);

                if (typeNombre == 0){
                    ui->opFactPressed->setEnabled(true);
                    ui->opModPressed->setEnabled(true);
                }
                else {
                    ui->opFactPressed->setEnabled(false);
                    ui->opModPressed->setEnabled(false);
                }
            }

        ui->actionTaille_Affich->setData(taille_pile);
        if (degre) {
            ui->actionDegres->setChecked(true);
            ui->actionRadians->setChecked(false);
        }
        else {
            ui->actionRadians->setChecked(true);
            ui->actionDegres->setChecked(false);
        }
    }

}



