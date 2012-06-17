/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Gestion_constantes.h"
#include "Constante_Factory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new CalculatriceModele;
    buffer = "";
    ui->numCompPressed->setEnabled(false);
    degre=true;
    complexe=false;
    taille_pile = 6;

    FenetrePile.setFixedSize(200, 150);
    QGroupBox *groupPile = new QGroupBox("Taille de la pile d'affichage", &FenetrePile);

    QSpinBox *taille = new QSpinBox(&FenetrePile);
        taille->setMaximum(20);
    QPushButton *valid = new QPushButton("Valider", &FenetrePile);
        valid->setCheckable(true);

    QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(taille);
        vbox->addWidget(valid);

        groupPile->setLayout(vbox);
        groupPile->setFixedSize(160, 110);
        groupPile->move(10,10);

    connect(taille, SIGNAL(valueChanged(int)), this, SLOT(setTaillePile(int)));
    connect(valid, SIGNAL(clicked()), &FenetrePile, SLOT(close()));
    connect(ui->actionTaille_Affich, SIGNAL(triggered()), &FenetrePile, SLOT(exec()));

    connect(ui->actionDegres, SIGNAL(triggered()), this, SLOT(degreActif()));
    connect(ui->actionRadians, SIGNAL(triggered()), this, SLOT(radianActif()));

    connect(this, SIGNAL(pressEntrerN(QString, bool)), model, SLOT(getNombre(QString, bool)));
    connect(model, SIGNAL(evalExp(QString)), this, SLOT(EnterAction(QString)));
    connect(this, SIGNAL(finEntree()), this, SLOT(rafraichissement()));
    connect(model, SIGNAL(finOp(Stack*)), this, SLOT(affichePile(Stack*)));
    connect(this, SIGNAL(pressEval()), model, SLOT(getExpression()));

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

    connect(this, SIGNAL(pressAnnuler()), model, SLOT(annuler()));
    connect(this, SIGNAL(pressRetablir()), model, SLOT(retablir()));

    connect(this, SIGNAL(complexeVrai()), model, SLOT(transformerPile()));
    connect(this, SIGNAL(complexeFaux()), model, SLOT(effacerPile()));

    connect(this, SIGNAL(destroyed()), model, SLOT(ecritureFichier()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


// boutons de type
void MainWindow::on_buttonEntier_clicked(){
    if (typeNombre != 0){
        typeNombre = 0;
        if (complexe == 1){
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
        if (complexe == 1){
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

        if (complexe == 1){
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
        if(s=="-"){emit pressSous(typeNombre);}
        if(s=="*"){emit pressMult(typeNombre);}
        if(s=="/"){emit pressDiv(typeNombre);}

        if(s=="pow"){emit pressPow(typeNombre);}
        if(s=="mod"){emit pressMod();}
        if(s=="fact"){emit pressFact();}
        if(s=="sign"){emit pressSign(typeNombre);}

        if(s=="sin"){emit pressSin(degre);}
        if(s=="cos"){emit pressCos(degre);}
        if(s=="tan"){emit pressTan(degre);}

        if(s=="sinh"){emit pressSinh(degre);}
        if(s=="cosh"){emit pressCosh(degre);}
        if(s=="tanh"){emit pressTanh(degre);}

        if(s=="ln"){emit pressLn();}
        if(s=="log"){emit pressLog();}
        if(s=="inv"){emit pressInv(typeNombre);}

        if(s=="sqrt"){emit pressSqrt();}
        if(s=="sqr"){emit pressSqr(typeNombre);}
        if(s=="cube"){emit pressCube(typeNombre);}

        if(s=="swap"){emit pressSwap();}
        if(s=="sum"){emit pressSum(typeNombre);}
        if(s=="mean"){emit pressMean(typeNombre);}
        if(s=="clear"){emit pressClear();}
        if(s=="dup"){emit pressDup();}
        if(s=="drop"){emit pressDrop();}
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
