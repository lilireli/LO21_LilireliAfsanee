#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QStack>
#include "Gestion_constantes.h"
#include "CalculatriceModele.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

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

    //opérations essentielles
    void on_EnterPressed_clicked();  // on vérifie que l'expression rentrée est valide

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

    //pile
    void on_opSwapPressed_clicked();
    void on_opSumPressed_clicked();
    void on_opMeanPressed_clicked();
    void on_opClearPressed_clicked();
    void on_opDupPressed_clicked();
    void on_opDropPressed_clicked();


signals:
    void pressEntrerN(QString s, int type);
    void pressAdd();
    void pressSous();
    void pressMult();
    void pressDiv();

    void pressPow();
    void pressMod();
    void pressFact();
    void pressSign();

    void pressSin();
    void pressCos();
    void pressTan();

    void pressSinh();
    void pressCosh();
    void pressTanh();

    void pressLn();
    void pressLog();
    void pressInv();

    void pressSqrt();
    void pressSqr();
    void pressCube();

    void pressSwap();
    void pressSum();
    void pressMean();
    void pressClear();
    void pressDup();
    void pressDrop();


private:
    Ui::MainWindow *ui;
    QStack<QString> pile;
    // unuseful
    QStack<QString> affichage;
    int typeNombre;
    int complexe;
    CalculatriceModele *model;
    QString buffer;
    QString aff;
};

#endif // MAINWINDOW_H
