/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 9. Jun 20:16:31 2012
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
    QAction *actionDegr;
    QAction *actionRadians;
    QAction *actionAnnuler;
    QAction *actionR_tablir;
    QAction *actionQuitter;
    QWidget *centralWidget;
    QRadioButton *buttonRationnel;
    QRadioButton *buttonReel;
    QRadioButton *buttonEntier;
    QCheckBox *buttonComplexe;
    QPushButton *opSqrPressed;
    QPushButton *opCosPressed;
    QPushButton *opInvPressed;
    QPushButton *onClearPressed;
    QPushButton *num8pressed;
    QPushButton *opModPressed;
    QPushButton *opDropPressed;
    QPushButton *opTanhPressed;
    QPushButton *opLogPressed;
    QPushButton *num3pressed;
    QPushButton *opPowPressed;
    QPushButton *opSwapPressed;
    QPushButton *EspacePressed;
    QPushButton *numParenthesisPressed;
    QPushButton *clickAnnul;
    QPushButton *opMoinsPressed;
    QPushButton *num4pressed;
    QPushButton *num9pressed;
    QPushButton *opCoshPressed;
    QPushButton *opDupPressed;
    QPushButton *pushButton;
    QPushButton *opSumPressed;
    QPushButton *opFactPressed;
    QPushButton *opLnPressed;
    QPushButton *clickRetablir;
    QPushButton *opSqrtPressed;
    QPushButton *opDivPressed;
    QPushButton *num1pressed;
    QPushButton *num2pressed;
    QPushButton *opMeanPressed;
    QPushButton *opSinhPressed;
    QPushButton *opSinPressed;
    QPushButton *numComaPressed;
    QPushButton *opPlusPressed;
    QPushButton *EnterPressed;
    QPushButton *opTanPressed;
    QPushButton *num6pressed;
    QTextEdit *textEdit;
    QPushButton *num5pressed;
    QPushButton *opMultPressed;
    QPushButton *num0pressed;
    QLineEdit *lineEdit;
    QPushButton *opCubePressed;
    QPushButton *num7pressed;
    QPushButton *opSignPressed;
    QPushButton *EvalPressed;
    QPushButton *numCompPressed;
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
        MainWindow->resize(715, 449);
        actionDegr = new QAction(MainWindow);
        actionDegr->setObjectName(QString::fromUtf8("actionDegr"));
        actionDegr->setCheckable(true);
        actionDegr->setChecked(true);
        actionRadians = new QAction(MainWindow);
        actionRadians->setObjectName(QString::fromUtf8("actionRadians"));
        actionRadians->setCheckable(true);
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionR_tablir = new QAction(MainWindow);
        actionR_tablir->setObjectName(QString::fromUtf8("actionR_tablir"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        buttonRationnel = new QRadioButton(centralWidget);
        buttonRationnel->setObjectName(QString::fromUtf8("buttonRationnel"));
        buttonRationnel->setGeometry(QRect(550, 30, 71, 17));
        buttonReel = new QRadioButton(centralWidget);
        buttonReel->setObjectName(QString::fromUtf8("buttonReel"));
        buttonReel->setGeometry(QRect(630, 30, 51, 17));
        buttonEntier = new QRadioButton(centralWidget);
        buttonEntier->setObjectName(QString::fromUtf8("buttonEntier"));
        buttonEntier->setGeometry(QRect(490, 30, 51, 17));
        buttonEntier->setChecked(true);
        buttonComplexe = new QCheckBox(centralWidget);
        buttonComplexe->setObjectName(QString::fromUtf8("buttonComplexe"));
        buttonComplexe->setGeometry(QRect(610, 50, 70, 17));
        opSqrPressed = new QPushButton(centralWidget);
        opSqrPressed->setObjectName(QString::fromUtf8("opSqrPressed"));
        opSqrPressed->setGeometry(QRect(330, 310, 41, 23));
        opCosPressed = new QPushButton(centralWidget);
        opCosPressed->setObjectName(QString::fromUtf8("opCosPressed"));
        opCosPressed->setGeometry(QRect(330, 220, 41, 23));
        opInvPressed = new QPushButton(centralWidget);
        opInvPressed->setObjectName(QString::fromUtf8("opInvPressed"));
        opInvPressed->setGeometry(QRect(380, 280, 41, 23));
        onClearPressed = new QPushButton(centralWidget);
        onClearPressed->setObjectName(QString::fromUtf8("onClearPressed"));
        onClearPressed->setGeometry(QRect(460, 90, 51, 21));
        num8pressed = new QPushButton(centralWidget);
        num8pressed->setObjectName(QString::fromUtf8("num8pressed"));
        num8pressed->setGeometry(QRect(540, 200, 31, 23));
        opModPressed = new QPushButton(centralWidget);
        opModPressed->setObjectName(QString::fromUtf8("opModPressed"));
        opModPressed->setGeometry(QRect(320, 190, 31, 23));
        opDropPressed = new QPushButton(centralWidget);
        opDropPressed->setObjectName(QString::fromUtf8("opDropPressed"));
        opDropPressed->setGeometry(QRect(580, 90, 51, 23));
        opTanhPressed = new QPushButton(centralWidget);
        opTanhPressed->setObjectName(QString::fromUtf8("opTanhPressed"));
        opTanhPressed->setGeometry(QRect(380, 250, 41, 23));
        opLogPressed = new QPushButton(centralWidget);
        opLogPressed->setObjectName(QString::fromUtf8("opLogPressed"));
        opLogPressed->setGeometry(QRect(330, 280, 41, 23));
        num3pressed = new QPushButton(centralWidget);
        num3pressed->setObjectName(QString::fromUtf8("num3pressed"));
        num3pressed->setGeometry(QRect(580, 260, 31, 23));
        opPowPressed = new QPushButton(centralWidget);
        opPowPressed->setObjectName(QString::fromUtf8("opPowPressed"));
        opPowPressed->setGeometry(QRect(280, 190, 31, 23));
        opSwapPressed = new QPushButton(centralWidget);
        opSwapPressed->setObjectName(QString::fromUtf8("opSwapPressed"));
        opSwapPressed->setGeometry(QRect(280, 90, 51, 23));
        EspacePressed = new QPushButton(centralWidget);
        EspacePressed->setObjectName(QString::fromUtf8("EspacePressed"));
        EspacePressed->setGeometry(QRect(630, 280, 51, 31));
        numParenthesisPressed = new QPushButton(centralWidget);
        numParenthesisPressed->setObjectName(QString::fromUtf8("numParenthesisPressed"));
        numParenthesisPressed->setGeometry(QRect(500, 290, 31, 23));
        clickAnnul = new QPushButton(centralWidget);
        clickAnnul->setObjectName(QString::fromUtf8("clickAnnul"));
        clickAnnul->setGeometry(QRect(480, 320, 75, 23));
        opMoinsPressed = new QPushButton(centralWidget);
        opMoinsPressed->setObjectName(QString::fromUtf8("opMoinsPressed"));
        opMoinsPressed->setGeometry(QRect(460, 230, 31, 23));
        num4pressed = new QPushButton(centralWidget);
        num4pressed->setObjectName(QString::fromUtf8("num4pressed"));
        num4pressed->setGeometry(QRect(500, 230, 31, 23));
        num9pressed = new QPushButton(centralWidget);
        num9pressed->setObjectName(QString::fromUtf8("num9pressed"));
        num9pressed->setGeometry(QRect(580, 200, 31, 23));
        opCoshPressed = new QPushButton(centralWidget);
        opCoshPressed->setObjectName(QString::fromUtf8("opCoshPressed"));
        opCoshPressed->setGeometry(QRect(330, 250, 41, 23));
        opDupPressed = new QPushButton(centralWidget);
        opDupPressed->setObjectName(QString::fromUtf8("opDupPressed"));
        opDupPressed->setGeometry(QRect(520, 90, 51, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 150, 75, 23));
        opSumPressed = new QPushButton(centralWidget);
        opSumPressed->setObjectName(QString::fromUtf8("opSumPressed"));
        opSumPressed->setGeometry(QRect(340, 90, 51, 23));
        opFactPressed = new QPushButton(centralWidget);
        opFactPressed->setObjectName(QString::fromUtf8("opFactPressed"));
        opFactPressed->setGeometry(QRect(360, 190, 31, 23));
        opLnPressed = new QPushButton(centralWidget);
        opLnPressed->setObjectName(QString::fromUtf8("opLnPressed"));
        opLnPressed->setGeometry(QRect(280, 280, 41, 23));
        clickRetablir = new QPushButton(centralWidget);
        clickRetablir->setObjectName(QString::fromUtf8("clickRetablir"));
        clickRetablir->setGeometry(QRect(560, 320, 75, 23));
        opSqrtPressed = new QPushButton(centralWidget);
        opSqrtPressed->setObjectName(QString::fromUtf8("opSqrtPressed"));
        opSqrtPressed->setGeometry(QRect(280, 310, 41, 23));
        opDivPressed = new QPushButton(centralWidget);
        opDivPressed->setObjectName(QString::fromUtf8("opDivPressed"));
        opDivPressed->setGeometry(QRect(460, 290, 31, 23));
        num1pressed = new QPushButton(centralWidget);
        num1pressed->setObjectName(QString::fromUtf8("num1pressed"));
        num1pressed->setGeometry(QRect(500, 260, 31, 23));
        num2pressed = new QPushButton(centralWidget);
        num2pressed->setObjectName(QString::fromUtf8("num2pressed"));
        num2pressed->setGeometry(QRect(540, 260, 31, 23));
        opMeanPressed = new QPushButton(centralWidget);
        opMeanPressed->setObjectName(QString::fromUtf8("opMeanPressed"));
        opMeanPressed->setGeometry(QRect(400, 90, 51, 23));
        opSinhPressed = new QPushButton(centralWidget);
        opSinhPressed->setObjectName(QString::fromUtf8("opSinhPressed"));
        opSinhPressed->setGeometry(QRect(280, 250, 41, 23));
        opSinPressed = new QPushButton(centralWidget);
        opSinPressed->setObjectName(QString::fromUtf8("opSinPressed"));
        opSinPressed->setGeometry(QRect(280, 220, 41, 23));
        numComaPressed = new QPushButton(centralWidget);
        numComaPressed->setObjectName(QString::fromUtf8("numComaPressed"));
        numComaPressed->setGeometry(QRect(580, 290, 31, 23));
        opPlusPressed = new QPushButton(centralWidget);
        opPlusPressed->setObjectName(QString::fromUtf8("opPlusPressed"));
        opPlusPressed->setGeometry(QRect(460, 200, 31, 23));
        EnterPressed = new QPushButton(centralWidget);
        EnterPressed->setObjectName(QString::fromUtf8("EnterPressed"));
        EnterPressed->setGeometry(QRect(630, 240, 51, 31));
        opTanPressed = new QPushButton(centralWidget);
        opTanPressed->setObjectName(QString::fromUtf8("opTanPressed"));
        opTanPressed->setGeometry(QRect(380, 220, 41, 23));
        num6pressed = new QPushButton(centralWidget);
        num6pressed->setObjectName(QString::fromUtf8("num6pressed"));
        num6pressed->setGeometry(QRect(580, 230, 31, 23));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(40, 40, 231, 331));
        num5pressed = new QPushButton(centralWidget);
        num5pressed->setObjectName(QString::fromUtf8("num5pressed"));
        num5pressed->setGeometry(QRect(540, 230, 31, 23));
        opMultPressed = new QPushButton(centralWidget);
        opMultPressed->setObjectName(QString::fromUtf8("opMultPressed"));
        opMultPressed->setGeometry(QRect(460, 260, 31, 23));
        num0pressed = new QPushButton(centralWidget);
        num0pressed->setObjectName(QString::fromUtf8("num0pressed"));
        num0pressed->setGeometry(QRect(540, 290, 31, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 380, 651, 20));
        opCubePressed = new QPushButton(centralWidget);
        opCubePressed->setObjectName(QString::fromUtf8("opCubePressed"));
        opCubePressed->setGeometry(QRect(380, 310, 41, 23));
        num7pressed = new QPushButton(centralWidget);
        num7pressed->setObjectName(QString::fromUtf8("num7pressed"));
        num7pressed->setGeometry(QRect(500, 200, 31, 23));
        opSignPressed = new QPushButton(centralWidget);
        opSignPressed->setObjectName(QString::fromUtf8("opSignPressed"));
        opSignPressed->setGeometry(QRect(400, 190, 41, 23));
        EvalPressed = new QPushButton(centralWidget);
        EvalPressed->setObjectName(QString::fromUtf8("EvalPressed"));
        EvalPressed->setGeometry(QRect(530, 150, 75, 23));
        numCompPressed = new QPushButton(centralWidget);
        numCompPressed->setObjectName(QString::fromUtf8("numCompPressed"));
        numCompPressed->setGeometry(QRect(630, 200, 31, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 715, 21));
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
        menuFichier->addAction(actionQuitter);
        menuEdition->addAction(actionAnnuler);
        menuEdition->addAction(actionR_tablir);
        menuParam_tres->addAction(actionDegr);
        menuParam_tres->addAction(actionRadians);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionDegr->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        actionRadians->setText(QApplication::translate("MainWindow", "Radians", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        actionR_tablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        buttonRationnel->setText(QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8));
        buttonReel->setText(QApplication::translate("MainWindow", "R\303\251el", 0, QApplication::UnicodeUTF8));
        buttonEntier->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        buttonComplexe->setText(QApplication::translate("MainWindow", "Complexe", 0, QApplication::UnicodeUTF8));
        opSqrPressed->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        opSqrPressed->setShortcut(QApplication::translate("MainWindow", "S, Q, R", 0, QApplication::UnicodeUTF8));
        opCosPressed->setText(QApplication::translate("MainWindow", "cos", 0, QApplication::UnicodeUTF8));
        opCosPressed->setShortcut(QApplication::translate("MainWindow", "C, O, S", 0, QApplication::UnicodeUTF8));
        opInvPressed->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        opInvPressed->setShortcut(QApplication::translate("MainWindow", "I, N, V", 0, QApplication::UnicodeUTF8));
        onClearPressed->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        onClearPressed->setShortcut(QApplication::translate("MainWindow", "C, L, E, A", 0, QApplication::UnicodeUTF8));
        num8pressed->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num8pressed->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        opModPressed->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        opModPressed->setShortcut(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        opDropPressed->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        opDropPressed->setShortcut(QApplication::translate("MainWindow", "D, R, O, P", 0, QApplication::UnicodeUTF8));
        opTanhPressed->setText(QApplication::translate("MainWindow", "tanh", 0, QApplication::UnicodeUTF8));
        opTanhPressed->setShortcut(QApplication::translate("MainWindow", "T, A, N, H", 0, QApplication::UnicodeUTF8));
        opLogPressed->setText(QApplication::translate("MainWindow", "log", 0, QApplication::UnicodeUTF8));
        opLogPressed->setShortcut(QApplication::translate("MainWindow", "L, O, G", 0, QApplication::UnicodeUTF8));
        num3pressed->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num3pressed->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        opPowPressed->setText(QApplication::translate("MainWindow", "^", 0, QApplication::UnicodeUTF8));
        opPowPressed->setShortcut(QApplication::translate("MainWindow", "P, O, W", 0, QApplication::UnicodeUTF8));
        opSwapPressed->setText(QApplication::translate("MainWindow", "SWAP", 0, QApplication::UnicodeUTF8));
        opSwapPressed->setShortcut(QApplication::translate("MainWindow", "S, W, A, P", 0, QApplication::UnicodeUTF8));
        EspacePressed->setText(QApplication::translate("MainWindow", "Espace", 0, QApplication::UnicodeUTF8));
        EspacePressed->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        numParenthesisPressed->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        numParenthesisPressed->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        clickAnnul->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        clickAnnul->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        opMoinsPressed->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        opMoinsPressed->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        num4pressed->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num4pressed->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num9pressed->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num9pressed->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        opCoshPressed->setText(QApplication::translate("MainWindow", "cosh", 0, QApplication::UnicodeUTF8));
        opCoshPressed->setShortcut(QApplication::translate("MainWindow", "C, O, S, H", 0, QApplication::UnicodeUTF8));
        opDupPressed->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        opDupPressed->setShortcut(QApplication::translate("MainWindow", "D, U, P", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "DEL", 0, QApplication::UnicodeUTF8));
        opSumPressed->setText(QApplication::translate("MainWindow", "SUM", 0, QApplication::UnicodeUTF8));
        opSumPressed->setShortcut(QApplication::translate("MainWindow", "S, U, M", 0, QApplication::UnicodeUTF8));
        opFactPressed->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opFactPressed->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        opLnPressed->setText(QApplication::translate("MainWindow", "ln", 0, QApplication::UnicodeUTF8));
        opLnPressed->setShortcut(QApplication::translate("MainWindow", "L, N", 0, QApplication::UnicodeUTF8));
        clickRetablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        clickRetablir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        opSqrtPressed->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        opSqrtPressed->setShortcut(QApplication::translate("MainWindow", "S, Q, R, T", 0, QApplication::UnicodeUTF8));
        opDivPressed->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        opDivPressed->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        num1pressed->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num1pressed->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num2pressed->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num2pressed->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        opMeanPressed->setText(QApplication::translate("MainWindow", "MEAN", 0, QApplication::UnicodeUTF8));
        opMeanPressed->setShortcut(QApplication::translate("MainWindow", "M, E, A, N", 0, QApplication::UnicodeUTF8));
        opSinhPressed->setText(QApplication::translate("MainWindow", "sinh", 0, QApplication::UnicodeUTF8));
        opSinhPressed->setShortcut(QApplication::translate("MainWindow", "S, I, N, H", 0, QApplication::UnicodeUTF8));
        opSinPressed->setText(QApplication::translate("MainWindow", "sin", 0, QApplication::UnicodeUTF8));
        opSinPressed->setShortcut(QApplication::translate("MainWindow", "S, I, N", 0, QApplication::UnicodeUTF8));
        numComaPressed->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        numComaPressed->setShortcut(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        opPlusPressed->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        opPlusPressed->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        EnterPressed->setText(QApplication::translate("MainWindow", "Enter", 0, QApplication::UnicodeUTF8));
        EnterPressed->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        opTanPressed->setText(QApplication::translate("MainWindow", "tan", 0, QApplication::UnicodeUTF8));
        opTanPressed->setShortcut(QApplication::translate("MainWindow", "T, A, N", 0, QApplication::UnicodeUTF8));
        num6pressed->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num6pressed->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num5pressed->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num5pressed->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        opMultPressed->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        opMultPressed->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        num0pressed->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        num0pressed->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        opCubePressed->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        opCubePressed->setShortcut(QApplication::translate("MainWindow", "C, U, B, E", 0, QApplication::UnicodeUTF8));
        num7pressed->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num7pressed->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        opSignPressed->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        opSignPressed->setShortcut(QApplication::translate("MainWindow", "S, I, G, N", 0, QApplication::UnicodeUTF8));
        EvalPressed->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        numCompPressed->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        numCompPressed->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
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
