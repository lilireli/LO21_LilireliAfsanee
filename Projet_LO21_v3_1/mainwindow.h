/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QStack>
#include <QApplication>
#include <QtGui>
#include "Gestion_constantes.h"
#include "CalculatriceModele.h"
#include "Logger.h"

extern LoggerConsole* logger1;
extern LoggerFile* logger2;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QDialog FenetrePile;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //numéros
    void on_num0pressed_clicked();
    void on_num1pressed_clicked();
    void on_num2pressed_clicked();
    void on_num3pressed_clicked();
    void on_num4pressed_clicked();
    void on_num5pressed_clicked();
    void on_num6pressed_clicked();
    void on_num7pressed_clicked();
    void on_num8pressed_clicked();
    void on_num9pressed_clicked();
    void on_numComaPressed_clicked();
    void on_numCompPressed_clicked();
    void on_numParenthesisPressed_clicked();
    void on_EspacePressed_clicked();

    //opérations essentielles
    void on_EnterPressed_clicked();  // on vérifie que l'expression rentrée est valide
    void EnterAction(QString s);
    void on_EvalPressed_clicked();
    void on_opDelPressed_clicked();
    void rafraichissement();
    void affichePile(Stack* pile);
    void setTaillePile(int n);
    void on_clickAnnul_clicked();
    void on_clickRetablir_clicked();

    //opérations
    void on_opPlusPressed_clicked();
    void on_opMoinsPressed_clicked();
    void on_opMultPressed_clicked();
    void on_opDivPressed_clicked();


    void on_opPowPressed_clicked();
    void on_opModPressed_clicked();
    void on_opFactPressed_clicked();
    void on_opSignPressed_clicked();

    void on_opSinPressed_clicked();
    void on_opCosPressed_clicked();
    void on_opTanPressed_clicked();

    void on_opSinhPressed_clicked();
    void on_opCoshPressed_clicked();
    void on_opTanhPressed_clicked();

    void on_opLnPressed_clicked();
    void on_opLogPressed_clicked();
    void on_opInvPressed_clicked();

    void on_opSqrtPressed_clicked();
    void on_opSqrPressed_clicked();
    void on_opCubePressed_clicked();


    //type
    void on_buttonEntier_clicked();
    void on_buttonReel_clicked();
    void on_buttonRationnel_clicked();
    void on_buttonComplexe_clicked();
    void degreActif();
    void radianActif();

    //pile
    void on_opSwapPressed_clicked();
    void on_opSumPressed_clicked();
    void on_opMeanPressed_clicked();
    void on_opClearPressed_clicked();
    void on_opDupPressed_clicked();
    void on_opDropPressed_clicked();


signals:
    void pressEntrerN(QString s, bool complexe);
    void finEntree();
    void pressEval();
    void pressAnnuler();
    void pressRetablir();

    void complexeVrai();
    void complexeFaux();

    void pressAdd(int typeNombre);
    void pressSous(int typeNombre);
    void pressMult(int typeNombre);
    void pressDiv(int typeNombre);

    void pressPow(int typeNombre);
    void pressMod();
    void pressFact();
    void pressSign(int typeNombre);

    void pressSin(bool degre);
    void pressCos(bool degre);
    void pressTan(bool degre);

    void pressSinh(bool degre);
    void pressCosh(bool degre);
    void pressTanh(bool degre);

    void pressLn();
    void pressLog();
    void pressInv(int typeNombre);

    void pressSqrt();
    void pressSqr(int typeNombre);
    void pressCube(int typeNombre);

    void pressSwap();
    void pressSum(int typeNombre);
    void pressMean(int typeNombre);
    void pressClear();
    void pressDup();
    void pressDrop();


private:
    Ui::MainWindow *ui;
    Stack affichage;
    int typeNombre;  // =0 si entier, =1 si réel, =2 si rationnel
    bool complexe;  // =0 si non activé, =1 si activé
    bool degre;
    int taille_pile;

    CalculatriceModele *model;
    QString buffer;
};

#endif // MAINWINDOW_H
