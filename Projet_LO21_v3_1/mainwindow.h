/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
/*!
 *  \file MainWindow.h
 *  \brief Affichage de la calculatrice, communication entre l'ui et CalculatriceModele
 *  \author Hamici Mathilde, Suzanne Aurélie
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

/*! \class MainWindow
 * \brief Vue qui gère l'affichage et communique avec CalculatriceModele pour effectuer les calculs
 * et rentrer les constantes
 *
 * \details  FenetrePile permettra l'apparition d'une nouvelle fenêtre qui nous permettra la
 * selection de la taille de la pile
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    QDialog FenetrePile;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /*!
     *  \brief SetAttributs
     *  \details fonction permet de remettre la calculatrice comme elle était avant
     */
    void setAttributs(int type, bool c, bool d, int taille);

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

    /*!
    * \brief EnterAction
    * \details Methode permettant de  qu'une chaine entrée au clavier est valide. Elle envoie un signal si
    * la chaine est une constante (ce que l'on peut vérifier avec formuleValide) et si elle correpond au nom
    * d'une opération (en ce cas elle envoie le signal a l'opération a appeler).
    * \param QString représentant la chaine de caractères à évaluer
    *
    */
    void EnterAction(QString s);
    void on_EvalPressed_clicked();
    void on_opDelPressed_clicked();
    /*!
     *  \brief rafraichissement
     *  \details Vide le lineEdit et le buffer, afin de pouvoir recommencer à rentrer un calcul
     */
    void rafraichissement();
    /*!
     *  \brief affichePile
     *  \details Actualise la pile avec la pile de calculatriceModele actuelle
     */
    void affichePile(Stack* pile);
    /*!
     *  \brief setTaillePile
     *  \details Ajuste la taille de la pile qui sera comprise entre 0 et 30
     */
    void setTaillePile(int n);
    void on_clickAnnul_clicked();
    void on_clickRetablir_clicked();
    /*!
     *  \brief verifComp
     *  \details Reçoit un signal dès que l'on annule ou rétablit, il renvoie un signal pour vérifier si le type rentré est Complexe ou non
     *  Dans tous les cas, il demande à une fonction de CalculatriceModele d'actualiser la pile en fonction du booléen complexe
     */
    void verifComp();

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
    /**
     * \brief      Permet de montrer/cacher les boutons utilisables pour chaque type de nombre
     * \details    Interdit de cliquer sur les boutons non utilisable pour un mode défini
     */
    void on_buttonEntier_clicked();
    void on_buttonReel_clicked();
    void on_buttonRationnel_clicked();
    void on_buttonComplexe_clicked();
    void degreActif();
    void radianActif();
    void affichClavier();

    //pile
    void on_opSwapPressed_clicked();
    void on_opSumPressed_clicked();
    void on_opMeanPressed_clicked();
    void on_opClearPressed_clicked();
    void on_opDupPressed_clicked();
    void on_opDropPressed_clicked();

    //gestion enregistrement
    void lire();
    void enregistrer();


signals:
    // rentrer une expression
    /*!
     *  \brief PressEntrerN
     *  \details Envoie a calculatrice modele une constante (dont on a déjà vérifié la validité grâce à FormuleValide)
     *  en lui indiquant si elle doit créer un complexe ou non
     *  \param1 Prend une chaine de caractères
     *  \param2 Prend un booléen
     */
    void pressEntrerN(QString s, bool complexe);
    /*!
     *  \brief finEntree
     *  \details Signal qu'un bloc a été rentré, demande à rafraichir l'affichage et le buffer
     */
    void finEntree();
    void pressEval();

    //Annuler et rétablir
    void pressAnnuler();
    void pressRetablir();
    /*!
     *  \brief vaVerif
     *  \details Dit au programme, va vérifier que ce qui est dans la pile correspond au mode Complexe que l'on veut
     *  \param2 Prend un booléen
     */
    void vaVerif(bool complexe);

    // gestion complexe
    void complexeVrai();
    void complexeFaux();

    // Affichage clavier
    void cache();
    void montre();

    // Sauvegarde contexte
    void pressFermer();

    // Opérations
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
    bool complexe;
    bool degre;
    int taille_pile;
    bool hide;

    CalculatriceModele *model;
    QString buffer;
};

#endif // MAINWINDOW_H
