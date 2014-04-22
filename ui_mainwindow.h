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
    QAction *actionRegister_User;
    QAction *actionLog_Out;
    QAction *actionExit;
    QAction *actionNew_Game;
    QAction *actionEnd_Game;
    QAction *actionChange_password;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *Login;
    QLabel *label_name;
    QLabel *label_password;
    QLineEdit *user_in;
    QLineEdit *password_in;
    QPushButton *push_login;
    QPushButton *push_exit;
    QWidget *RegisterUser;
    QLabel *label_user;
    QLabel *label_password_2;
    QLabel *label_pw2;
    QLabel *label_color;
    QComboBox *comb_color;
    QLineEdit *lineEdit_user;
    QLineEdit *lineEdit_pw1;
    QLineEdit *lineEdit_pw2;
    QWidget *Welcome;
    QPushButton *pushButton_change;
    QPushButton *pushButton_start;
    QPushButton *pushButton_exit;
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
        actionRegister_User = new QAction(MainWindow);
        actionRegister_User->setObjectName(QString::fromUtf8("actionRegister_User"));
        actionLog_Out = new QAction(MainWindow);
        actionLog_Out->setObjectName(QString::fromUtf8("actionLog_Out"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        actionEnd_Game = new QAction(MainWindow);
        actionEnd_Game->setObjectName(QString::fromUtf8("actionEnd_Game"));
        actionChange_password = new QAction(MainWindow);
        actionChange_password->setObjectName(QString::fromUtf8("actionChange_password"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -1, 391, 261));
        Login = new QWidget();
        Login->setObjectName(QString::fromUtf8("Login"));
        label_name = new QLabel(Login);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(50, 60, 121, 17));
        label_password = new QLabel(Login);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(50, 100, 66, 17));
        user_in = new QLineEdit(Login);
        user_in->setObjectName(QString::fromUtf8("user_in"));
        user_in->setGeometry(QRect(181, 56, 113, 27));
        password_in = new QLineEdit(Login);
        password_in->setObjectName(QString::fromUtf8("password_in"));
        password_in->setGeometry(QRect(181, 98, 113, 27));
        push_login = new QPushButton(Login);
        push_login->setObjectName(QString::fromUtf8("push_login"));
        push_login->setGeometry(QRect(180, 170, 98, 27));
        push_exit = new QPushButton(Login);
        push_exit->setObjectName(QString::fromUtf8("push_exit"));
        push_exit->setGeometry(QRect(280, 170, 98, 27));
        stackedWidget->addWidget(Login);
        RegisterUser = new QWidget();
        RegisterUser->setObjectName(QString::fromUtf8("RegisterUser"));
        label_user = new QLabel(RegisterUser);
        label_user->setObjectName(QString::fromUtf8("label_user"));
        label_user->setGeometry(QRect(20, 45, 91, 17));
        label_password_2 = new QLabel(RegisterUser);
        label_password_2->setObjectName(QString::fromUtf8("label_password_2"));
        label_password_2->setGeometry(QRect(20, 79, 71, 17));
        label_pw2 = new QLabel(RegisterUser);
        label_pw2->setObjectName(QString::fromUtf8("label_pw2"));
        label_pw2->setGeometry(QRect(20, 115, 131, 17));
        label_color = new QLabel(RegisterUser);
        label_color->setObjectName(QString::fromUtf8("label_color"));
        label_color->setGeometry(QRect(21, 154, 66, 17));
        comb_color = new QComboBox(RegisterUser);
        comb_color->setObjectName(QString::fromUtf8("comb_color"));
        comb_color->setGeometry(QRect(210, 147, 78, 27));
        lineEdit_user = new QLineEdit(RegisterUser);
        lineEdit_user->setObjectName(QString::fromUtf8("lineEdit_user"));
        lineEdit_user->setGeometry(QRect(180, 40, 141, 27));
        lineEdit_pw1 = new QLineEdit(RegisterUser);
        lineEdit_pw1->setObjectName(QString::fromUtf8("lineEdit_pw1"));
        lineEdit_pw1->setGeometry(QRect(180, 75, 141, 27));
        lineEdit_pw2 = new QLineEdit(RegisterUser);
        lineEdit_pw2->setObjectName(QString::fromUtf8("lineEdit_pw2"));
        lineEdit_pw2->setGeometry(QRect(180, 110, 141, 27));
        stackedWidget->addWidget(RegisterUser);
        Welcome = new QWidget();
        Welcome->setObjectName(QString::fromUtf8("Welcome"));
        pushButton_change = new QPushButton(Welcome);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        pushButton_change->setGeometry(QRect(20, 190, 141, 27));
        pushButton_start = new QPushButton(Welcome);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(172, 190, 98, 27));
        pushButton_exit = new QPushButton(Welcome);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(280, 190, 98, 27));
        stackedWidget->addWidget(Welcome);
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
        menuUser->addAction(actionRegister_User);
        menuUser->addAction(actionLog_Out);
        menuUser->addAction(actionExit);
        menuGame->addAction(actionNew_Game);
        menuGame->addAction(actionEnd_Game);
        menuEdit->addAction(actionChange_password);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionRegister_User->setText(QApplication::translate("MainWindow", "Register User", 0, QApplication::UnicodeUTF8));
        actionLog_Out->setText(QApplication::translate("MainWindow", "Log Out", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0, QApplication::UnicodeUTF8));
        actionEnd_Game->setText(QApplication::translate("MainWindow", "End Game", 0, QApplication::UnicodeUTF8));
        actionChange_password->setText(QApplication::translate("MainWindow", "Change password", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("MainWindow", "User Name", 0, QApplication::UnicodeUTF8));
        label_password->setText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
        push_login->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        push_exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        label_user->setText(QApplication::translate("MainWindow", "User Name", 0, QApplication::UnicodeUTF8));
        label_password_2->setText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
        label_pw2->setText(QApplication::translate("MainWindow", "Re-Enter Password", 0, QApplication::UnicodeUTF8));
        label_color->setText(QApplication::translate("MainWindow", "Color", 0, QApplication::UnicodeUTF8));
        comb_color->clear();
        comb_color->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Black", 0, QApplication::UnicodeUTF8)
        );
        pushButton_change->setText(QApplication::translate("MainWindow", "Change Password", 0, QApplication::UnicodeUTF8));
        pushButton_start->setText(QApplication::translate("MainWindow", "Start Game", 0, QApplication::UnicodeUTF8));
        pushButton_exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
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
