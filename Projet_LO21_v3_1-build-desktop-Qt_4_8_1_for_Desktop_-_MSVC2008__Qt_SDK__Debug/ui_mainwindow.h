/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 19. Jun 16:08:35 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDegres;
    QAction *actionRadians;
    QAction *actionAnnuler;
    QAction *actionR_tablir;
    QAction *actionQuitter;
    QAction *actionTaille_Affich;
    QAction *actionAfficher_clavier;
    QAction *actionCacher_clavier;
    QAction *actionEnregistrer;
    QAction *actionOuvrir;
    QWidget *centralWidget;
    QGroupBox *clavier;
    QGroupBox *groupBox_6;
    QPushButton *opPlusPressed;
    QPushButton *opModPressed;
    QPushButton *opDivPressed;
    QPushButton *opMultPressed;
    QPushButton *opMoinsPressed;
    QGroupBox *groupBox_7;
    QPushButton *EnterPressed;
    QPushButton *opDelPressed;
    QPushButton *clickAnnul;
    QPushButton *clickRetablir;
    QGroupBox *groupBox_8;
    QPushButton *EspacePressed;
    QPushButton *num5pressed;
    QPushButton *num7pressed;
    QPushButton *num6pressed;
    QPushButton *numComaPressed;
    QPushButton *num9pressed;
    QPushButton *numParenthesisPressed;
    QPushButton *num0pressed;
    QPushButton *num1pressed;
    QPushButton *num4pressed;
    QPushButton *numCompPressed;
    QPushButton *num3pressed;
    QPushButton *num8pressed;
    QPushButton *num2pressed;
    QGroupBox *groupBox_5;
    QTextEdit *textEdit;
    QGroupBox *groupBox_2;
    QPushButton *opSinhPressed;
    QPushButton *opCoshPressed;
    QPushButton *opSinPressed;
    QPushButton *opTanhPressed;
    QPushButton *opCosPressed;
    QPushButton *opTanPressed;
    QLineEdit *lineEdit;
    QPushButton *EvalPressed;
    QGroupBox *groupBox;
    QPushButton *opDropPressed;
    QPushButton *opSwapPressed;
    QPushButton *opDupPressed;
    QPushButton *opMeanPressed;
    QPushButton *opSumPressed;
    QPushButton *opClearPressed;
    QGroupBox *groupBox_3;
    QPushButton *opLogPressed;
    QPushButton *opPowPressed;
    QPushButton *opFactPressed;
    QPushButton *opLnPressed;
    QPushButton *opCubePressed;
    QPushButton *opSignPressed;
    QPushButton *opSqrPressed;
    QPushButton *opInvPressed;
    QPushButton *opSqrtPressed;
    QGroupBox *groupBox_4;
    QCheckBox *buttonComplexe;
    QRadioButton *buttonEntier;
    QRadioButton *buttonRationnel;
    QRadioButton *buttonReel;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuParam_tres;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(676, 518);
        actionDegres = new QAction(MainWindow);
        actionDegres->setObjectName(QString::fromUtf8("actionDegres"));
        actionDegres->setCheckable(true);
        actionDegres->setChecked(true);
        actionRadians = new QAction(MainWindow);
        actionRadians->setObjectName(QString::fromUtf8("actionRadians"));
        actionRadians->setCheckable(true);
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionR_tablir = new QAction(MainWindow);
        actionR_tablir->setObjectName(QString::fromUtf8("actionR_tablir"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionTaille_Affich = new QAction(MainWindow);
        actionTaille_Affich->setObjectName(QString::fromUtf8("actionTaille_Affich"));
        actionAfficher_clavier = new QAction(MainWindow);
        actionAfficher_clavier->setObjectName(QString::fromUtf8("actionAfficher_clavier"));
        actionAfficher_clavier->setCheckable(true);
        actionAfficher_clavier->setChecked(true);
        actionAfficher_clavier->setEnabled(true);
        actionCacher_clavier = new QAction(MainWindow);
        actionCacher_clavier->setObjectName(QString::fromUtf8("actionCacher_clavier"));
        actionCacher_clavier->setCheckable(true);
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QString::fromUtf8("actionOuvrir"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        clavier = new QGroupBox(centralWidget);
        clavier->setObjectName(QString::fromUtf8("clavier"));
        clavier->setGeometry(QRect(510, 0, 149, 459));
        groupBox_6 = new QGroupBox(clavier);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 160, 131, 81));
        opPlusPressed = new QPushButton(groupBox_6);
        opPlusPressed->setObjectName(QString::fromUtf8("opPlusPressed"));
        opPlusPressed->setGeometry(QRect(10, 20, 31, 23));
        opModPressed = new QPushButton(groupBox_6);
        opModPressed->setObjectName(QString::fromUtf8("opModPressed"));
        opModPressed->setGeometry(QRect(70, 50, 31, 23));
        opDivPressed = new QPushButton(groupBox_6);
        opDivPressed->setObjectName(QString::fromUtf8("opDivPressed"));
        opDivPressed->setGeometry(QRect(30, 50, 31, 23));
        opMultPressed = new QPushButton(groupBox_6);
        opMultPressed->setObjectName(QString::fromUtf8("opMultPressed"));
        opMultPressed->setGeometry(QRect(90, 20, 31, 23));
        opMoinsPressed = new QPushButton(groupBox_6);
        opMoinsPressed->setObjectName(QString::fromUtf8("opMoinsPressed"));
        opMoinsPressed->setGeometry(QRect(50, 20, 31, 23));
        groupBox_7 = new QGroupBox(clavier);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 30, 131, 91));
        EnterPressed = new QPushButton(groupBox_7);
        EnterPressed->setObjectName(QString::fromUtf8("EnterPressed"));
        EnterPressed->setGeometry(QRect(70, 10, 51, 31));
        opDelPressed = new QPushButton(groupBox_7);
        opDelPressed->setObjectName(QString::fromUtf8("opDelPressed"));
        opDelPressed->setGeometry(QRect(10, 10, 51, 31));
        clickAnnul = new QPushButton(groupBox_7);
        clickAnnul->setObjectName(QString::fromUtf8("clickAnnul"));
        clickAnnul->setGeometry(QRect(10, 50, 51, 31));
        clickRetablir = new QPushButton(groupBox_7);
        clickRetablir->setObjectName(QString::fromUtf8("clickRetablir"));
        clickRetablir->setGeometry(QRect(70, 50, 51, 31));
        groupBox_8 = new QGroupBox(clavier);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 270, 131, 171));
        EspacePressed = new QPushButton(groupBox_8);
        EspacePressed->setObjectName(QString::fromUtf8("EspacePressed"));
        EspacePressed->setGeometry(QRect(60, 140, 61, 23));
        num5pressed = new QPushButton(groupBox_8);
        num5pressed->setObjectName(QString::fromUtf8("num5pressed"));
        num5pressed->setGeometry(QRect(50, 50, 31, 23));
        num7pressed = new QPushButton(groupBox_8);
        num7pressed->setObjectName(QString::fromUtf8("num7pressed"));
        num7pressed->setGeometry(QRect(10, 20, 31, 23));
        num6pressed = new QPushButton(groupBox_8);
        num6pressed->setObjectName(QString::fromUtf8("num6pressed"));
        num6pressed->setGeometry(QRect(90, 50, 31, 23));
        numComaPressed = new QPushButton(groupBox_8);
        numComaPressed->setObjectName(QString::fromUtf8("numComaPressed"));
        numComaPressed->setGeometry(QRect(90, 110, 31, 23));
        num9pressed = new QPushButton(groupBox_8);
        num9pressed->setObjectName(QString::fromUtf8("num9pressed"));
        num9pressed->setGeometry(QRect(90, 20, 31, 23));
        numParenthesisPressed = new QPushButton(groupBox_8);
        numParenthesisPressed->setObjectName(QString::fromUtf8("numParenthesisPressed"));
        numParenthesisPressed->setGeometry(QRect(10, 110, 31, 23));
        num0pressed = new QPushButton(groupBox_8);
        num0pressed->setObjectName(QString::fromUtf8("num0pressed"));
        num0pressed->setGeometry(QRect(50, 110, 31, 23));
        num1pressed = new QPushButton(groupBox_8);
        num1pressed->setObjectName(QString::fromUtf8("num1pressed"));
        num1pressed->setGeometry(QRect(10, 80, 31, 23));
        num4pressed = new QPushButton(groupBox_8);
        num4pressed->setObjectName(QString::fromUtf8("num4pressed"));
        num4pressed->setGeometry(QRect(10, 50, 31, 23));
        numCompPressed = new QPushButton(groupBox_8);
        numCompPressed->setObjectName(QString::fromUtf8("numCompPressed"));
        numCompPressed->setGeometry(QRect(10, 140, 41, 23));
        num3pressed = new QPushButton(groupBox_8);
        num3pressed->setObjectName(QString::fromUtf8("num3pressed"));
        num3pressed->setGeometry(QRect(90, 80, 31, 23));
        num8pressed = new QPushButton(groupBox_8);
        num8pressed->setObjectName(QString::fromUtf8("num8pressed"));
        num8pressed->setGeometry(QRect(50, 20, 31, 23));
        num2pressed = new QPushButton(groupBox_8);
        num2pressed->setObjectName(QString::fromUtf8("num2pressed"));
        num2pressed->setGeometry(QRect(50, 80, 31, 23));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 0, 489, 459));
        textEdit = new QTextEdit(groupBox_5);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(10, 50, 231, 361));
        groupBox_2 = new QGroupBox(groupBox_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(260, 260, 161, 81));
        opSinhPressed = new QPushButton(groupBox_2);
        opSinhPressed->setObjectName(QString::fromUtf8("opSinhPressed"));
        opSinhPressed->setGeometry(QRect(10, 50, 41, 23));
        opCoshPressed = new QPushButton(groupBox_2);
        opCoshPressed->setObjectName(QString::fromUtf8("opCoshPressed"));
        opCoshPressed->setGeometry(QRect(60, 50, 41, 23));
        opSinPressed = new QPushButton(groupBox_2);
        opSinPressed->setObjectName(QString::fromUtf8("opSinPressed"));
        opSinPressed->setGeometry(QRect(10, 20, 41, 23));
        opTanhPressed = new QPushButton(groupBox_2);
        opTanhPressed->setObjectName(QString::fromUtf8("opTanhPressed"));
        opTanhPressed->setGeometry(QRect(110, 50, 41, 23));
        opCosPressed = new QPushButton(groupBox_2);
        opCosPressed->setObjectName(QString::fromUtf8("opCosPressed"));
        opCosPressed->setGeometry(QRect(60, 20, 41, 23));
        opTanPressed = new QPushButton(groupBox_2);
        opTanPressed->setObjectName(QString::fromUtf8("opTanPressed"));
        opTanPressed->setGeometry(QRect(110, 20, 41, 23));
        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(10, 20, 461, 20));
        EvalPressed = new QPushButton(groupBox_5);
        EvalPressed->setObjectName(QString::fromUtf8("EvalPressed"));
        EvalPressed->setGeometry(QRect(190, 420, 51, 31));
        groupBox = new QGroupBox(groupBox_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(260, 360, 191, 81));
        opDropPressed = new QPushButton(groupBox);
        opDropPressed->setObjectName(QString::fromUtf8("opDropPressed"));
        opDropPressed->setGeometry(QRect(130, 50, 51, 23));
        opSwapPressed = new QPushButton(groupBox);
        opSwapPressed->setObjectName(QString::fromUtf8("opSwapPressed"));
        opSwapPressed->setGeometry(QRect(10, 20, 51, 23));
        opDupPressed = new QPushButton(groupBox);
        opDupPressed->setObjectName(QString::fromUtf8("opDupPressed"));
        opDupPressed->setGeometry(QRect(70, 50, 51, 23));
        opMeanPressed = new QPushButton(groupBox);
        opMeanPressed->setObjectName(QString::fromUtf8("opMeanPressed"));
        opMeanPressed->setGeometry(QRect(130, 20, 51, 23));
        opSumPressed = new QPushButton(groupBox);
        opSumPressed->setObjectName(QString::fromUtf8("opSumPressed"));
        opSumPressed->setGeometry(QRect(70, 20, 51, 23));
        opClearPressed = new QPushButton(groupBox);
        opClearPressed->setObjectName(QString::fromUtf8("opClearPressed"));
        opClearPressed->setGeometry(QRect(10, 50, 51, 21));
        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(260, 130, 161, 121));
        opLogPressed = new QPushButton(groupBox_3);
        opLogPressed->setObjectName(QString::fromUtf8("opLogPressed"));
        opLogPressed->setGeometry(QRect(10, 80, 41, 23));
        opPowPressed = new QPushButton(groupBox_3);
        opPowPressed->setObjectName(QString::fromUtf8("opPowPressed"));
        opPowPressed->setGeometry(QRect(110, 80, 41, 23));
        opFactPressed = new QPushButton(groupBox_3);
        opFactPressed->setObjectName(QString::fromUtf8("opFactPressed"));
        opFactPressed->setGeometry(QRect(110, 50, 41, 23));
        opLnPressed = new QPushButton(groupBox_3);
        opLnPressed->setObjectName(QString::fromUtf8("opLnPressed"));
        opLnPressed->setGeometry(QRect(60, 80, 41, 23));
        opCubePressed = new QPushButton(groupBox_3);
        opCubePressed->setObjectName(QString::fromUtf8("opCubePressed"));
        opCubePressed->setGeometry(QRect(110, 20, 41, 23));
        opSignPressed = new QPushButton(groupBox_3);
        opSignPressed->setObjectName(QString::fromUtf8("opSignPressed"));
        opSignPressed->setGeometry(QRect(10, 50, 41, 23));
        opSqrPressed = new QPushButton(groupBox_3);
        opSqrPressed->setObjectName(QString::fromUtf8("opSqrPressed"));
        opSqrPressed->setGeometry(QRect(60, 20, 41, 23));
        opInvPressed = new QPushButton(groupBox_3);
        opInvPressed->setObjectName(QString::fromUtf8("opInvPressed"));
        opInvPressed->setGeometry(QRect(60, 50, 41, 23));
        opSqrtPressed = new QPushButton(groupBox_3);
        opSqrtPressed->setObjectName(QString::fromUtf8("opSqrtPressed"));
        opSqrtPressed->setGeometry(QRect(10, 20, 41, 23));
        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(260, 60, 211, 61));
        buttonComplexe = new QCheckBox(groupBox_4);
        buttonComplexe->setObjectName(QString::fromUtf8("buttonComplexe"));
        buttonComplexe->setGeometry(QRect(130, 40, 70, 17));
        buttonEntier = new QRadioButton(groupBox_4);
        buttonEntier->setObjectName(QString::fromUtf8("buttonEntier"));
        buttonEntier->setGeometry(QRect(10, 20, 51, 17));
        buttonEntier->setChecked(true);
        buttonRationnel = new QRadioButton(groupBox_4);
        buttonRationnel->setObjectName(QString::fromUtf8("buttonRationnel"));
        buttonRationnel->setGeometry(QRect(70, 20, 71, 17));
        buttonReel = new QRadioButton(groupBox_4);
        buttonReel->setObjectName(QString::fromUtf8("buttonReel"));
        buttonReel->setGeometry(QRect(150, 20, 51, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 676, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuParam_tres = new QMenu(menuBar);
        menuParam_tres->setObjectName(QString::fromUtf8("menuParam_tres"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuParam_tres->menuAction());
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuEdition->addAction(actionAfficher_clavier);
        menuParam_tres->addAction(actionDegres);
        menuParam_tres->addAction(actionRadians);
        menuParam_tres->addSeparator();
        menuParam_tres->addAction(actionTaille_Affich);

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionDegres->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        actionRadians->setText(QApplication::translate("MainWindow", "Radians", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionR_tablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        actionR_tablir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionTaille_Affich->setText(QApplication::translate("MainWindow", "Taille pile d'affichage", 0, QApplication::UnicodeUTF8));
        actionAfficher_clavier->setText(QApplication::translate("MainWindow", "Afficher clavier", 0, QApplication::UnicodeUTF8));
        actionCacher_clavier->setText(QApplication::translate("MainWindow", "Cacher clavier", 0, QApplication::UnicodeUTF8));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0, QApplication::UnicodeUTF8));
        actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir", 0, QApplication::UnicodeUTF8));
        clavier->setTitle(QApplication::translate("MainWindow", "Clavier", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Op\303\251rations basiques", 0, QApplication::UnicodeUTF8));
        opPlusPressed->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        opPlusPressed->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        opModPressed->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        opModPressed->setShortcut(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        opDivPressed->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        opDivPressed->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        opMultPressed->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        opMultPressed->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        opMoinsPressed->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        opMoinsPressed->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QString());
        EnterPressed->setText(QApplication::translate("MainWindow", "Enter", 0, QApplication::UnicodeUTF8));
        EnterPressed->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        opDelPressed->setText(QApplication::translate("MainWindow", "DEL", 0, QApplication::UnicodeUTF8));
        opDelPressed->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        clickAnnul->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        clickAnnul->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        clickRetablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        clickRetablir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Rentrer expression", 0, QApplication::UnicodeUTF8));
        EspacePressed->setText(QApplication::translate("MainWindow", "Espace", 0, QApplication::UnicodeUTF8));
        EspacePressed->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        num5pressed->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num5pressed->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num7pressed->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num7pressed->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num6pressed->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num6pressed->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        numComaPressed->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        numComaPressed->setShortcut(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        num9pressed->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num9pressed->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        numParenthesisPressed->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        numParenthesisPressed->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        num0pressed->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        num0pressed->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        num1pressed->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num1pressed->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num4pressed->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num4pressed->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        numCompPressed->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        numCompPressed->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        num3pressed->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num3pressed->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num8pressed->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num8pressed->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num2pressed->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num2pressed->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Calculatrice", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Fonctions trigonom\303\251triques", 0, QApplication::UnicodeUTF8));
        opSinhPressed->setText(QApplication::translate("MainWindow", "sinh", 0, QApplication::UnicodeUTF8));
        opSinhPressed->setShortcut(QApplication::translate("MainWindow", "H, S, I, N", 0, QApplication::UnicodeUTF8));
        opCoshPressed->setText(QApplication::translate("MainWindow", "cosh", 0, QApplication::UnicodeUTF8));
        opCoshPressed->setShortcut(QApplication::translate("MainWindow", "H, C, O, S", 0, QApplication::UnicodeUTF8));
        opSinPressed->setText(QApplication::translate("MainWindow", "sin", 0, QApplication::UnicodeUTF8));
        opSinPressed->setShortcut(QApplication::translate("MainWindow", "S, I, N", 0, QApplication::UnicodeUTF8));
        opTanhPressed->setText(QApplication::translate("MainWindow", "tanh", 0, QApplication::UnicodeUTF8));
        opTanhPressed->setShortcut(QApplication::translate("MainWindow", "H, T, A, N", 0, QApplication::UnicodeUTF8));
        opCosPressed->setText(QApplication::translate("MainWindow", "cos", 0, QApplication::UnicodeUTF8));
        opCosPressed->setShortcut(QApplication::translate("MainWindow", "C, O, S", 0, QApplication::UnicodeUTF8));
        opTanPressed->setText(QApplication::translate("MainWindow", "tan", 0, QApplication::UnicodeUTF8));
        opTanPressed->setShortcut(QApplication::translate("MainWindow", "T, A, N", 0, QApplication::UnicodeUTF8));
        EvalPressed->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Op\303\251rations sur la pile", 0, QApplication::UnicodeUTF8));
        opDropPressed->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        opDropPressed->setShortcut(QApplication::translate("MainWindow", "D, R, O, P", 0, QApplication::UnicodeUTF8));
        opSwapPressed->setText(QApplication::translate("MainWindow", "SWAP", 0, QApplication::UnicodeUTF8));
        opSwapPressed->setShortcut(QApplication::translate("MainWindow", "S, W, A, P", 0, QApplication::UnicodeUTF8));
        opDupPressed->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        opDupPressed->setShortcut(QApplication::translate("MainWindow", "D, U, P", 0, QApplication::UnicodeUTF8));
        opMeanPressed->setText(QApplication::translate("MainWindow", "MEAN", 0, QApplication::UnicodeUTF8));
        opMeanPressed->setShortcut(QApplication::translate("MainWindow", "M, E, A, N", 0, QApplication::UnicodeUTF8));
        opSumPressed->setText(QApplication::translate("MainWindow", "SUM", 0, QApplication::UnicodeUTF8));
        opSumPressed->setShortcut(QApplication::translate("MainWindow", "S, U, M", 0, QApplication::UnicodeUTF8));
        opClearPressed->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        opClearPressed->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Op\303\251rations diverses", 0, QApplication::UnicodeUTF8));
        opLogPressed->setText(QApplication::translate("MainWindow", "log", 0, QApplication::UnicodeUTF8));
        opLogPressed->setShortcut(QApplication::translate("MainWindow", "L, O, G", 0, QApplication::UnicodeUTF8));
        opPowPressed->setText(QApplication::translate("MainWindow", "^", 0, QApplication::UnicodeUTF8));
        opPowPressed->setShortcut(QApplication::translate("MainWindow", "P, O, W", 0, QApplication::UnicodeUTF8));
        opFactPressed->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opFactPressed->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opLnPressed->setText(QApplication::translate("MainWindow", "ln", 0, QApplication::UnicodeUTF8));
        opLnPressed->setShortcut(QApplication::translate("MainWindow", "L, N", 0, QApplication::UnicodeUTF8));
        opCubePressed->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        opCubePressed->setShortcut(QApplication::translate("MainWindow", "C, U, B, E", 0, QApplication::UnicodeUTF8));
        opSignPressed->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        opSignPressed->setShortcut(QApplication::translate("MainWindow", "S, I, G, N", 0, QApplication::UnicodeUTF8));
        opSqrPressed->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        opSqrPressed->setShortcut(QApplication::translate("MainWindow", "S, Q, R", 0, QApplication::UnicodeUTF8));
        opInvPressed->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        opInvPressed->setShortcut(QApplication::translate("MainWindow", "I, N, V", 0, QApplication::UnicodeUTF8));
        opSqrtPressed->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        opSqrtPressed->setShortcut(QApplication::translate("MainWindow", "S, Q, R, T", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Choix du type", 0, QApplication::UnicodeUTF8));
        buttonComplexe->setText(QApplication::translate("MainWindow", "Complexe", 0, QApplication::UnicodeUTF8));
        buttonEntier->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        buttonRationnel->setText(QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8));
        buttonReel->setText(QApplication::translate("MainWindow", "R\303\251el", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
        menuParam_tres->setTitle(QApplication::translate("MainWindow", "Param\303\250tres", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
