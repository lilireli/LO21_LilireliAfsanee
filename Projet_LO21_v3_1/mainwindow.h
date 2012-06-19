/*
  Hamici Mathilde
  Suzanne Aur�lie
  Projet LO21 - Calculatrice � notation polonaise invers�e
*/
/*!
 *  \file MainWindow.h
 *  \brief Affichage de la calculatrice, communication entre l'ui et CalculatriceModele
 *  \author Hamici Mathilde, Suzanne Aur�lie
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
 * \brief Vue qui g�re l'affichage et communique avec CalculatriceModele pour effectuer les calculs
 * et rentrer les constantes
 *
 * \details  FenetrePile permettra l'apparition d'une nouvelle fen�tre qui nous permettra la
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
     *  \details fonction permet de remettre la calculatrice comme elle �tait avant
     */
    void setAttributs(int type, bool c, bool d, int taille);

private slots:
    //num�ros
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

    //op�rations essentielles
    void on_EnterPressed_clicked();  // on v�rifie que l'expression rentr�e est valide

    /*!
    * \brief EnterAction
    * \details Methode permettant de  qu'une chaine entr�e au clavier est valide. Elle envoie un signal si
    * la chaine est une constante (ce que l'on peut v�rifier avec formuleValide) et si elle correpond au nom
    * d'une op�ration (en ce cas elle envoie le signal a l'op�ration a appeler).
    * \param QString repr�sentant la chaine de caract�res � �valuer
    *
    */
    void EnterAction(QString s);
    void on_EvalPressed_clicked();
    void on_opDelPressed_clicked();
    /*!
     *  \brief rafraichissement
     *  \details Vide le lineEdit et le buffer, afin de pouvoir recommencer � rentrer un calcul
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
     *  \details Re�oit un signal d�s que l'on annule ou r�tablit, il renvoie un signal pour v�rifier si le type rentr� est Complexe ou non
     *  Dans tous les cas, il demande � une fonction de CalculatriceModele d'actualiser la pile en fonction du bool�en complexe
     */
    void verifComp();

    //op�rations
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
     * \details    Interdit de cliquer sur les boutons non utilisable pour un mode d�fini
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
     *  \details Envoie a calculatrice modele une constante (dont on a d�j� v�rifi� la validit� gr�ce � FormuleValide)
     *  en lui indiquant si elle doit cr�er un complexe ou non
     *  \param1 Prend une chaine de caract�res
     *  \param2 Prend un bool�en
     */
    void pressEntrerN(QString s, bool complexe);
    /*!
     *  \brief finEntree
     *  \details Signal qu'un bloc a �t� rentr�, demande � rafraichir l'affichage et le buffer
     */
    void finEntree();
    void pressEval();

    //Annuler et r�tablir
    void pressAnnuler();
    void pressRetablir();
    /*!
     *  \brief vaVerif
     *  \details Dit au programme, va v�rifier que ce qui est dans la pile correspond au mode Complexe que l'on veut
     *  \param2 Prend un bool�en
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

    // Op�rations
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
    int typeNombre;  // =0 si entier, =1 si r�el, =2 si rationnel
    bool complexe;
    bool degre;
    int taille_pile;
    bool hide;

    CalculatriceModele *model;
    QString buffer;
};

#endif // MAINWINDOW_H
