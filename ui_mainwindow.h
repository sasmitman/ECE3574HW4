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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
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
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 170, 98, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 170, 98, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(91, 56, 81, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 97, 66, 17));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 50, 113, 27));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 90, 113, 27));
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
        pushButton->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "User name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
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
