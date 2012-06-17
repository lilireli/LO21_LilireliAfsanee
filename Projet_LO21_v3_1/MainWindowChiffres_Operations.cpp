/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
