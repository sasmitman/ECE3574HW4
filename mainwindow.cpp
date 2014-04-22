#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QAction"
#include "QPushButton"
#include "QLineEdit"
#include "QMap"
#include "QMessageBox"
#include "QComboBox"

/*
0 = login page
1 = register page
2 = Welcome page
3 = change password page
4 = game
  */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changePage(int i)
{
    ui->stackedWidget->setCurrentIndex(i);
}

void MainWindow::on_actionRegisterUser_triggered()
{
    changePage(1);//Changes page to register user page (1)
}

void MainWindow::on_regOK_clicked()
{
    //Converting info from lineEdit boxes to text
    QString user = ui->reglineEdituser->text();
    QString pw1 = ui->reglineEditpw1->text();
    QString pw2 = ui->reglineEditpw2->text();
    QString color = ui->regcombcolor->currentText();

    if(database.contains(user))
    {
        QMessageBox::information(this, "ERROR", "User already exists!");
    }
    else if (pw1 != pw2)
    {
        QMessageBox::information(this, "ERROR", "Passwords do not match!");
    }
    else
    {
        QVector<QString> temp;
        temp.append(pw1);
        temp.append(color);
        database.insert(user, temp);
        temp.clear();
        changePage(0);
    }
}
