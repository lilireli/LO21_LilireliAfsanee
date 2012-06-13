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
    taille_pile = 6;
    //connect(ActionAfficherClavie, SIGNAL(ac));

    connect(this, SIGNAL(pressEntrerN(QString, int)), model, SLOT(getNombre(QString, int)));
    connect(model, SIGNAL(evalExp(QString)), this, SLOT(EnterAction(QString)));
    connect(this, SIGNAL(finEntree()), this, SLOT(rafraichissement()));
    connect(model, SIGNAL(finOp(Constante*, int)), this, SLOT(affichePile(Constante*, int)));
    connect(this, SIGNAL(pressEval()), model, SLOT(getExpression()));

    connect(this, SIGNAL(pressAdd()), model, SLOT(getAdd()));
    connect(this, SIGNAL(pressSous()), model, SLOT(getSous()));
    connect(this, SIGNAL(pressMult()), model, SLOT(getMult()));
    connect(this, SIGNAL(pressDiv(int)), model, SLOT(getDiv(int)));

    connect(this, SIGNAL(pressPow()), model, SLOT(getPow()));
    connect(this, SIGNAL(pressMod()), model, SLOT(getMod()));
    connect(this, SIGNAL(pressFact()), model, SLOT(getFact()));
    connect(this, SIGNAL(pressSign()), model, SLOT(getSign()));

    connect(this, SIGNAL(pressSin()), model, SLOT(getSin()));
    connect(this, SIGNAL(pressCos()), model, SLOT(getCos()));
    connect(this, SIGNAL(pressTan()), model, SLOT(getTan()));

    connect(this, SIGNAL(pressSinh()), model, SLOT(getSinh()));
    connect(this, SIGNAL(pressCosh()), model, SLOT(getCosh()));
    connect(this, SIGNAL(pressTanh()), model, SLOT(getTanh()));

    connect(this, SIGNAL(pressLn()), model, SLOT(getLn()));
    connect(this, SIGNAL(pressLog()), model, SLOT(getLog()));
    connect(this, SIGNAL(pressInv()), model, SLOT(getInv()));

    connect(this, SIGNAL(pressSqrt()), model, SLOT(getSqrt()));
    connect(this, SIGNAL(pressSqr()), model, SLOT(getSqr()));
    connect(this, SIGNAL(pressCube()), model, SLOT(getCube()));

    connect(this, SIGNAL(pressSwap()), model, SLOT(getSwap()));
    connect(this, SIGNAL(pressSum()), model, SLOT(getSum()));
    connect(this, SIGNAL(pressMean()), model, SLOT(getMean()));
    connect(this, SIGNAL(pressClear()), model, SLOT(getClear()));
    connect(this, SIGNAL(pressDup()), model, SLOT(getDup()));
    connect(this, SIGNAL(pressDrop()), model, SLOT(getDrop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//numéros
void MainWindow::on_num0pressed_clicked()
{
    buffer += "0";
    ui->lineEdit->insert("0");
}

void MainWindow::on_num1pressed_clicked()
{
    buffer += "1";
    ui->lineEdit->insert("1");
}

void MainWindow::on_num2pressed_clicked()
{
    buffer += "2";
    ui->lineEdit->insert("2");
}

void MainWindow::on_num3pressed_clicked()
{
    buffer += "3";
    ui->lineEdit->insert("3");
}

void MainWindow::on_num4pressed_clicked()
{
    buffer += "4";
    ui->lineEdit->insert("4");
}

void MainWindow::on_num5pressed_clicked()
{
    buffer += "5";
    ui->lineEdit->insert("5");
}

void MainWindow::on_num6pressed_clicked()
{
    buffer += "6";
    ui->lineEdit->insert("6");
}

void MainWindow::on_num7pressed_clicked()
{
    buffer += "7";
    ui->lineEdit->insert("7");
}

void MainWindow::on_num8pressed_clicked()
{
    buffer += "8";
    ui->lineEdit->insert("8");
}

void MainWindow::on_num9pressed_clicked()
{
    buffer += "9";
    ui->lineEdit->insert("9");
}

void MainWindow::on_numComaPressed_clicked()
{
    buffer += ".";
    ui->lineEdit->insert(".");
}

void MainWindow::on_numCompPressed_clicked()
{
    buffer += "$";
    ui->lineEdit->insert("$");
}

void MainWindow::on_numParenthesisPressed_clicked()
{
    buffer += "\'";
    ui->lineEdit->insert("\'");
}

void MainWindow::on_EspacePressed_clicked()
{
    buffer += " ";
    ui->lineEdit->insert(" ");
}

// boutons de type
void MainWindow::on_buttonEntier_clicked(){
    if (typeNombre != 0){
        typeNombre = 0;
        if (complexe == 1){
            ui->opCoshPressed->setVisible(false);
            ui->opCosPressed->setVisible(false);
            ui->opFactPressed->setVisible(false);
            ui->opInvPressed->setVisible(false);
            ui->opLnPressed->setVisible(false);
            ui->opLogPressed->setVisible(false);
            ui->opModPressed->setVisible(false);
            ui->opPowPressed->setVisible(false);
            ui->opSinhPressed->setVisible(false);
            ui->opSinPressed->setVisible(false);
            ui->opTanhPressed->setVisible(false);
            ui->opTanPressed->setVisible(false);
        }
        else {
            ui->opCoshPressed->setVisible(true);
            ui->opCosPressed->setVisible(true);
            ui->opFactPressed->setVisible(true);
            ui->opInvPressed->setVisible(true);
            ui->opLnPressed->setVisible(true);
            ui->opLogPressed->setVisible(true);
            ui->opModPressed->setVisible(true);
            ui->opPowPressed->setVisible(true);
            ui->opSinhPressed->setVisible(true);
            ui->opSinPressed->setVisible(true);
            ui->opTanhPressed->setVisible(true);
            ui->opTanPressed->setVisible(true);
        }
    }
}

void MainWindow::on_buttonReel_clicked(){
    if (typeNombre != 1) {
        typeNombre = 1;
        if (complexe == 1){
            ui->opCoshPressed->setVisible(false);
            ui->opCosPressed->setVisible(false);
            ui->opFactPressed->setVisible(false);
            ui->opInvPressed->setVisible(false);
            ui->opLnPressed->setVisible(false);
            ui->opLogPressed->setVisible(false);
            ui->opModPressed->setVisible(false);
            ui->opPowPressed->setVisible(false);
            ui->opSinhPressed->setVisible(false);
            ui->opSinPressed->setVisible(false);
            ui->opTanhPressed->setVisible(false);
            ui->opTanPressed->setVisible(false);
        }
        else {
            ui->opCoshPressed->setVisible(true);
            ui->opCosPressed->setVisible(true);
            ui->opFactPressed->setVisible(false);
            ui->opInvPressed->setVisible(true);
            ui->opLnPressed->setVisible(true);
            ui->opLogPressed->setVisible(true);
            ui->opModPressed->setVisible(false);
            ui->opPowPressed->setVisible(true);
            ui->opSinhPressed->setVisible(true);
            ui->opSinPressed->setVisible(true);
            ui->opTanhPressed->setVisible(true);
            ui->opTanPressed->setVisible(true);
        }
    }
}

void MainWindow::on_buttonRationnel_clicked(){
    if (typeNombre != 2) {
        typeNombre = 2;

        if (complexe == 1){
            ui->opCoshPressed->setVisible(false);
            ui->opCosPressed->setVisible(false);
            ui->opFactPressed->setVisible(false);
            ui->opInvPressed->setVisible(false);
            ui->opLnPressed->setVisible(false);
            ui->opLogPressed->setVisible(false);
            ui->opModPressed->setVisible(false);
            ui->opPowPressed->setVisible(false);
            ui->opSinhPressed->setVisible(false);
            ui->opSinPressed->setVisible(false);
            ui->opTanhPressed->setVisible(false);
            ui->opTanPressed->setVisible(false);
        }
        else{
            ui->opCoshPressed->setVisible(true);
            ui->opCosPressed->setVisible(true);
            ui->opFactPressed->setVisible(false);
            ui->opInvPressed->setVisible(true);
            ui->opLnPressed->setVisible(true);
            ui->opLogPressed->setVisible(true);
            ui->opModPressed->setVisible(false);
            ui->opPowPressed->setVisible(true);
            ui->opSinhPressed->setVisible(true);
            ui->opSinPressed->setVisible(true);
            ui->opTanhPressed->setVisible(true);
            ui->opTanPressed->setVisible(true);
        }
    }
}

void MainWindow::on_buttonComplexe_clicked(){
    if (complexe != 1){
        complexe = 1;
        ui->opCoshPressed->setVisible(false);
        ui->opCosPressed->setVisible(false);
        ui->opFactPressed->setVisible(false);
        ui->opInvPressed->setVisible(false);
        ui->opLnPressed->setVisible(false);
        ui->opLogPressed->setVisible(false);
        ui->opModPressed->setVisible(false);
        ui->opPowPressed->setVisible(false);
        ui->opSinhPressed->setVisible(false);
        ui->opSinPressed->setVisible(false);
        ui->opTanhPressed->setVisible(false);
        ui->opTanPressed->setVisible(false);
    }
    else {
        complexe = 0;
        if (typeNombre == 0){
            ui->opCoshPressed->setVisible(true);
            ui->opCosPressed->setVisible(true);
            ui->opFactPressed->setVisible(true);
            ui->opInvPressed->setVisible(true);
            ui->opLnPressed->setVisible(true);
            ui->opLogPressed->setVisible(true);
            ui->opModPressed->setVisible(true);
            ui->opPowPressed->setVisible(true);
            ui->opSinhPressed->setVisible(true);
            ui->opSinPressed->setVisible(true);
            ui->opTanhPressed->setVisible(true);
            ui->opTanPressed->setVisible(true);
        }
        else {
            ui->opCoshPressed->setVisible(true);
            ui->opCosPressed->setVisible(true);
            ui->opFactPressed->setVisible(false);
            ui->opInvPressed->setVisible(true);
            ui->opLnPressed->setVisible(true);
            ui->opLogPressed->setVisible(true);
            ui->opModPressed->setVisible(false);
            ui->opPowPressed->setVisible(true);
            ui->opSinhPressed->setVisible(true);
            ui->opSinPressed->setVisible(true);
            ui->opTanhPressed->setVisible(true);
            ui->opTanPressed->setVisible(true);
        }
    }
}


//opérations essentielles
void MainWindow::on_EnterPressed_clicked()
{
    ui->lineEdit->insert(" ");

    EnterAction(buffer);
    emit finEntree();
}

void MainWindow::EnterAction(QString s)
{
    if(FormuleValide(s)){
        emit pressEntrerN(s, complexe);
    }
    else{
        if(s=="+"){emit pressAdd();}
        if(s=="-"){emit pressSous();}
        if(s=="*"){emit pressMult();}
        if(s=="/"){emit pressDiv(typeNombre);}

        if(s=="pow"){emit pressPow();}
        if(s=="mod"){emit pressMod();}
        if(s=="fact"){emit pressFact();}
        if(s=="sign"){emit pressSign();}

        if(s=="sin"){emit pressSin();}
        if(s=="cos"){emit pressCos();}
        if(s=="tan"){emit pressTan();}

        if(s=="sinh"){emit pressSinh();}
        if(s=="cosh"){emit pressCosh();}
        if(s=="tanh"){emit pressTanh();}

        if(s=="ln"){emit pressLn();}
        if(s=="log"){emit pressLog();}
        if(s=="inv"){emit pressInv();}

        if(s=="sqrt"){emit pressSqrt();}
        if(s=="sqr"){emit pressSqr();}
        if(s=="cube"){emit pressCube();}

        if(s=="swap"){emit pressSwap();}
        if(s=="sum"){emit pressSum();}
        if(s=="mean"){emit pressMean();}
        if(s=="clear"){emit pressClear();}
        if(s=="dup"){emit pressDup();}
        if(s=="drop"){emit pressDrop();}
    }
}

void MainWindow::on_EvalPressed_clicked(){
    emit pressEval();
}

void MainWindow::on_opDelPressed_clicked(){
    buffer.remove(buffer.length()-1, 1);
    ui->lineEdit->clear();
    ui->lineEdit->insert(buffer);
}

void MainWindow::rafraichissement()
{
    buffer.clear();
    ui->lineEdit->clear();
}

void MainWindow::affichePile(Constante *cte, int j)
{
    FabriqueConstante fab;// afficher selon mode (convertEnt, convertReel ...)
    ui->textEdit->clear();

    for(int k=0; k<j; k++){
        Constante* del = affichage.pop();
        delete del;
    }

    if(cte!= NULL){ui->textEdit->insertPlainText(cte->ConvertChaineType(typeNombre)+"\n");}

    int t=0;
    if(affichage.size()>=taille_pile){ t=taille_pile;}
    else {t=affichage.size();}

    if(t!=0){
        Constante** tmp = new Constante*[t];

        for(int i=0; i<=t-1; i++){
            tmp[t-i-1] = affichage.pop();
            ui->textEdit->insertPlainText(tmp[t-i-1]->ConvertChaineType(typeNombre)+"\n");
        }

        while(!affichage.isEmpty()) {affichage.pop();}

        for(int i=0; i<=t-1; i++){affichage.push(tmp[i]);}
        delete[] tmp;
    }

    if(cte != NULL){
        FabriqueConstante fab;
        Constante* to_push = fab.newConstante(cte);
        affichage.push(to_push);
    }
}

//opérations
void MainWindow::on_opPlusPressed_clicked()
{
    buffer += "+";
    ui->lineEdit->insert("+");
}

void MainWindow::on_opMoinsPressed_clicked()
{
    buffer += "-";
    ui->lineEdit->insert("-");
}

void MainWindow::on_opMultPressed_clicked()
{
    buffer += "*";
    ui->lineEdit->insert("*");
}

void MainWindow::on_opDivPressed_clicked()
{
    buffer += "/";
    ui->lineEdit->insert("/");
}


void MainWindow::on_opPowPressed_clicked()
{
    buffer += "exp";
    ui->lineEdit->insert("exp");
}

void MainWindow::on_opModPressed_clicked()
{
    buffer += "mod";
    ui->lineEdit->insert("mod");
}

void MainWindow::on_opFactPressed_clicked()
{
    buffer += "fact";
    ui->lineEdit->insert("fact");
}

void MainWindow::on_opSignPressed_clicked()
{
    buffer += "sign";
    ui->lineEdit->insert("sign");
}


void MainWindow::on_opSinPressed_clicked()
{
    buffer += "sin";
    ui->lineEdit->insert("sin");
}

void MainWindow::on_opCosPressed_clicked()
{
    buffer += "cos";
    ui->lineEdit->insert("cos");
}

void MainWindow::on_opTanPressed_clicked()
{
    buffer += "tan";
    ui->lineEdit->insert("tan");
}

void MainWindow::on_opSinhPressed_clicked()
{
    buffer += "sinh";
    ui->lineEdit->insert("sinh");
}

void MainWindow::on_opCoshPressed_clicked()
{
    buffer += "cosh";
    ui->lineEdit->insert("cosh");
}

void MainWindow::on_opTanhPressed_clicked()
{
    buffer += "tanh";
    ui->lineEdit->insert("tanh");
}


void MainWindow::on_opLnPressed_clicked()
{
    buffer += "ln";
    ui->lineEdit->insert("ln");
}

void MainWindow::on_opLogPressed_clicked()
{
    buffer += "log";
    ui->lineEdit->insert("log");
}

void MainWindow::on_opInvPressed_clicked()
{
    buffer += "inv";
    ui->lineEdit->insert("inv");
}

void MainWindow::on_opSqrtPressed_clicked()
{
    buffer += "sqrt";
    ui->lineEdit->insert("sqrt");
}

void MainWindow::on_opSqrPressed_clicked()
{
    buffer += "sqr";
    ui->lineEdit->insert("sqr");
}

void MainWindow::on_opCubePressed_clicked()
{
    buffer += "cube";
    ui->lineEdit->insert("cube");
}

// opérations sur la pile
void MainWindow::on_opSwapPressed_clicked()
{
    buffer += "swap";
    ui->lineEdit->insert("swap");
}

void MainWindow::on_opSumPressed_clicked()
{
    buffer += "sum";
    ui->lineEdit->insert("sum");
}

void MainWindow::on_opMeanPressed_clicked()
{
    buffer += "mean";
    ui->lineEdit->insert("mean");
}

void MainWindow::on_opClearPressed_clicked()
{
    buffer += "clear";
    ui->lineEdit->insert("clear");
}

void MainWindow::on_opDupPressed_clicked()
{
    buffer += "dup";
    ui->lineEdit->insert("dup");
}

void MainWindow::on_opDropPressed_clicked()
{
    buffer += "drop";
    ui->lineEdit->insert("drop");
}
