/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRegisterUser;
    QAction *actionLogOut;
    QAction *actionExit;
    QAction *actionNewGame;
    QAction *actionEndGame;
    QAction *actionChangepw;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *Login;
    QLabel *loginlabelname;
    QLabel *loginlabelpassword;
    QLineEdit *loginuserin;
    QLineEdit *loginpwin;
    QPushButton *loginlogin;
    QPushButton *loginexit;
    QWidget *RegisterUser;
    QLabel *reglabeluser;
    QLabel *reglabelpassword;
    QLabel *reglabelpw2;
    QLabel *reglabelcolor;
    QComboBox *regcombcolor;
    QLineEdit *reglineEdituser;
    QLineEdit *reglineEditpw1;
    QLineEdit *reglineEditpw2;
    QPushButton *regOK;
    QPushButton *regCancel;
    QWidget *Welcome;
    QPushButton *wchangepw;
    QPushButton *wstart;
    QPushButton *wexit;
    QWidget *change_password;
    QLabel *oldpasslabel;
    QLabel *newpasslabel;
    QLabel *newpassreenter;
    QLabel *changecolor;
    QComboBox *changecolorbox;
    QLineEdit *changeoldpwin;
    QLineEdit *changenewpwin;
    QLineEdit *changerepwin;
    QPushButton *changeok;
    QPushButton *changecancel;
    QMenuBar *menuBar;
    QMenu *menuUser;
    QMenu *menuGame;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        actionRegisterUser = new QAction(MainWindow);
        actionRegisterUser->setObjectName(QString::fromUtf8("actionRegisterUser"));
        actionLogOut = new QAction(MainWindow);
        actionLogOut->setObjectName(QString::fromUtf8("actionLogOut"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNewGame = new QAction(MainWindow);
        actionNewGame->setObjectName(QString::fromUtf8("actionNewGame"));
        actionEndGame = new QAction(MainWindow);
        actionEndGame->setObjectName(QString::fromUtf8("actionEndGame"));
        actionChangepw = new QAction(MainWindow);
        actionChangepw->setObjectName(QString::fromUtf8("actionChangepw"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -1, 391, 261));
        Login = new QWidget();
        Login->setObjectName(QString::fromUtf8("Login"));
        loginlabelname = new QLabel(Login);
        loginlabelname->setObjectName(QString::fromUtf8("loginlabelname"));
        loginlabelname->setGeometry(QRect(50, 60, 121, 17));
        loginlabelpassword = new QLabel(Login);
        loginlabelpassword->setObjectName(QString::fromUtf8("loginlabelpassword"));
        loginlabelpassword->setGeometry(QRect(50, 100, 66, 17));
        loginuserin = new QLineEdit(Login);
        loginuserin->setObjectName(QString::fromUtf8("loginuserin"));
        loginuserin->setGeometry(QRect(181, 56, 113, 27));
        loginpwin = new QLineEdit(Login);
        loginpwin->setObjectName(QString::fromUtf8("loginpwin"));
        loginpwin->setGeometry(QRect(181, 98, 113, 27));
        loginpwin->setEchoMode(QLineEdit::Password);
        loginlogin = new QPushButton(Login);
        loginlogin->setObjectName(QString::fromUtf8("loginlogin"));
        loginlogin->setGeometry(QRect(180, 170, 98, 27));
        loginexit = new QPushButton(Login);
        loginexit->setObjectName(QString::fromUtf8("loginexit"));
        loginexit->setGeometry(QRect(280, 170, 98, 27));
        stackedWidget->addWidget(Login);
        RegisterUser = new QWidget();
        RegisterUser->setObjectName(QString::fromUtf8("RegisterUser"));
        reglabeluser = new QLabel(RegisterUser);
        reglabeluser->setObjectName(QString::fromUtf8("reglabeluser"));
        reglabeluser->setGeometry(QRect(20, 45, 91, 17));
        reglabelpassword = new QLabel(RegisterUser);
        reglabelpassword->setObjectName(QString::fromUtf8("reglabelpassword"));
        reglabelpassword->setGeometry(QRect(20, 79, 71, 17));
        reglabelpw2 = new QLabel(RegisterUser);
        reglabelpw2->setObjectName(QString::fromUtf8("reglabelpw2"));
        reglabelpw2->setGeometry(QRect(20, 115, 131, 17));
        reglabelcolor = new QLabel(RegisterUser);
        reglabelcolor->setObjectName(QString::fromUtf8("reglabelcolor"));
        reglabelcolor->setGeometry(QRect(21, 154, 66, 17));
        regcombcolor = new QComboBox(RegisterUser);
        regcombcolor->setObjectName(QString::fromUtf8("regcombcolor"));
        regcombcolor->setGeometry(QRect(210, 147, 78, 27));
        reglineEdituser = new QLineEdit(RegisterUser);
        reglineEdituser->setObjectName(QString::fromUtf8("reglineEdituser"));
        reglineEdituser->setGeometry(QRect(180, 40, 141, 27));
        reglineEditpw1 = new QLineEdit(RegisterUser);
        reglineEditpw1->setObjectName(QString::fromUtf8("reglineEditpw1"));
        reglineEditpw1->setGeometry(QRect(180, 75, 141, 27));
        reglineEditpw1->setEchoMode(QLineEdit::Password);
        reglineEditpw2 = new QLineEdit(RegisterUser);
        reglineEditpw2->setObjectName(QString::fromUtf8("reglineEditpw2"));
        reglineEditpw2->setGeometry(QRect(180, 110, 141, 27));
        reglineEditpw2->setEchoMode(QLineEdit::Password);
        regOK = new QPushButton(RegisterUser);
        regOK->setObjectName(QString::fromUtf8("regOK"));
        regOK->setGeometry(QRect(180, 200, 98, 27));
        regCancel = new QPushButton(RegisterUser);
        regCancel->setObjectName(QString::fromUtf8("regCancel"));
        regCancel->setGeometry(QRect(290, 200, 98, 27));
        stackedWidget->addWidget(RegisterUser);
        Welcome = new QWidget();
        Welcome->setObjectName(QString::fromUtf8("Welcome"));
        wchangepw = new QPushButton(Welcome);
        wchangepw->setObjectName(QString::fromUtf8("wchangepw"));
        wchangepw->setGeometry(QRect(20, 190, 141, 27));
        wstart = new QPushButton(Welcome);
        wstart->setObjectName(QString::fromUtf8("wstart"));
        wstart->setGeometry(QRect(172, 190, 98, 27));
        wexit = new QPushButton(Welcome);
        wexit->setObjectName(QString::fromUtf8("wexit"));
        wexit->setGeometry(QRect(280, 190, 98, 27));
        stackedWidget->addWidget(Welcome);
        change_password = new QWidget();
        change_password->setObjectName(QString::fromUtf8("change_password"));
        oldpasslabel = new QLabel(change_password);
        oldpasslabel->setObjectName(QString::fromUtf8("oldpasslabel"));
        oldpasslabel->setGeometry(QRect(30, 70, 111, 17));
        newpasslabel = new QLabel(change_password);
        newpasslabel->setObjectName(QString::fromUtf8("newpasslabel"));
        newpasslabel->setGeometry(QRect(30, 110, 121, 17));
        newpassreenter = new QLabel(change_password);
        newpassreenter->setObjectName(QString::fromUtf8("newpassreenter"));
        newpassreenter->setGeometry(QRect(30, 150, 141, 17));
        changecolor = new QLabel(change_password);
        changecolor->setObjectName(QString::fromUtf8("changecolor"));
        changecolor->setGeometry(QRect(30, 40, 66, 17));
        changecolorbox = new QComboBox(change_password);
        changecolorbox->setObjectName(QString::fromUtf8("changecolorbox"));
        changecolorbox->setGeometry(QRect(220, 30, 78, 27));
        changeoldpwin = new QLineEdit(change_password);
        changeoldpwin->setObjectName(QString::fromUtf8("changeoldpwin"));
        changeoldpwin->setGeometry(QRect(210, 60, 113, 27));
        changenewpwin = new QLineEdit(change_password);
        changenewpwin->setObjectName(QString::fromUtf8("changenewpwin"));
        changenewpwin->setGeometry(QRect(210, 110, 113, 27));
        changerepwin = new QLineEdit(change_password);
        changerepwin->setObjectName(QString::fromUtf8("changerepwin"));
        changerepwin->setGeometry(QRect(210, 150, 113, 27));
        changeok = new QPushButton(change_password);
        changeok->setObjectName(QString::fromUtf8("changeok"));
        changeok->setGeometry(QRect(170, 200, 98, 27));
        changecancel = new QPushButton(change_password);
        changecancel->setObjectName(QString::fromUtf8("changecancel"));
        changecancel->setGeometry(QRect(280, 200, 98, 27));
        stackedWidget->addWidget(change_password);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuUser = new QMenu(menuBar);
        menuUser->setObjectName(QString::fromUtf8("menuUser"));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuUser->menuAction());
        menuBar->addAction(menuGame->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuUser->addAction(actionRegisterUser);
        menuUser->addAction(actionLogOut);
        menuUser->addAction(actionExit);
        menuGame->addAction(actionNewGame);
        menuGame->addAction(actionEndGame);
        menuEdit->addAction(actionChangepw);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionRegisterUser->setText(QApplication::translate("MainWindow", "Register User", 0, QApplication::UnicodeUTF8));
        actionLogOut->setText(QApplication::translate("MainWindow", "Log Out", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionNewGame->setText(QApplication::translate("MainWindow", "New Game", 0, QApplication::UnicodeUTF8));
        actionEndGame->setText(QApplication::translate("MainWindow", "End Game", 0, QApplication::UnicodeUTF8));
        actionChangepw->setText(QApplication::translate("MainWindow", "Change password", 0, QApplication::UnicodeUTF8));
        loginlabelname->setText(QApplication::translate("MainWindow", "User Name", 0, QApplication::UnicodeUTF8));
        loginlabelpassword->setText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
        loginlogin->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        loginexit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        reglabeluser->setText(QApplication::translate("MainWindow", "User Name", 0, QApplication::UnicodeUTF8));
        reglabelpassword->setText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
        reglabelpw2->setText(QApplication::translate("MainWindow", "Re-Enter Password", 0, QApplication::UnicodeUTF8));
        reglabelcolor->setText(QApplication::translate("MainWindow", "Color", 0, QApplication::UnicodeUTF8));
        regcombcolor->clear();
        regcombcolor->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Black", 0, QApplication::UnicodeUTF8)
        );
        regOK->setText(QApplication::translate("MainWindow", "OK", 0, QApplication::UnicodeUTF8));
        regCancel->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        wchangepw->setText(QApplication::translate("MainWindow", "Change Password", 0, QApplication::UnicodeUTF8));
        wstart->setText(QApplication::translate("MainWindow", "Start Game", 0, QApplication::UnicodeUTF8));
        wexit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        oldpasslabel->setText(QApplication::translate("MainWindow", "Password (Old)", 0, QApplication::UnicodeUTF8));
        newpasslabel->setText(QApplication::translate("MainWindow", "Password (New)", 0, QApplication::UnicodeUTF8));
        newpassreenter->setText(QApplication::translate("MainWindow", "Re-Enter Password", 0, QApplication::UnicodeUTF8));
        changecolor->setText(QApplication::translate("MainWindow", "Color", 0, QApplication::UnicodeUTF8));
        changecolorbox->clear();
        changecolorbox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Black", 0, QApplication::UnicodeUTF8)
        );
        changeok->setText(QApplication::translate("MainWindow", "OK", 0, QApplication::UnicodeUTF8));
        changecancel->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        menuUser->setTitle(QApplication::translate("MainWindow", "User", 0, QApplication::UnicodeUTF8));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
