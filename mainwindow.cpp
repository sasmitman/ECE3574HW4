#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QAction"
#include "QPushButton"
#include "QLineEdit"
#include "QMap"
#include "QMessageBox"
#include "QComboBox"
#include <QTextStream>
#include <QFile>
#include <QDebug>

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
    readFile();
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile()
{
    QString path = "passwords.dat";
    QFile input(path);
    input.open(QIODevice::ReadOnly);
    QTextStream stream(&input);
    //Reading from the file and importing into a QList
    while(!stream.atEnd())
    {
        QString line = stream.readLine();//Reading from line
        QStringList splitter = line.split("::");//Splitting to name and date
        QString user = splitter[0];//Getting username
        QString password = splitter[1];//Getting password
        QString color = splitter[2];//Getting color
        QVector<QString> temp;
        temp.append(password);
        temp.append(color);
        database.insert(user, temp);
        temp.clear();
    }
}

void MainWindow::writeTo(QString username)
{
    QFile input("passwords.dat");
    if(!input.open(QFile::Append | QFile::Text))
    {
        qDebug() << "could not open file";
        return;
    }
    QTextStream fout(&input);
    QMapIterator<QString, QVector<QString> > i(database);
    //while (i.hasNext())
    // {
    //    i.next();
    fout<<username<<"::"<<database.value(username).at(0)<<"::"<<database.value(username).at(1)<<endl;
    // }
    input.close();
}

void MainWindow::changePage(int i)
{
    ui->stackedWidget->setCurrentIndex(i);
}

void MainWindow::on_actionRegisterUser_triggered()
{
    changePage(1);//Changes page to register user page (1)
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
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
        writeTo(user);
        changePage(0);
    }
}

void MainWindow::on_regCancel_clicked()
{
    changePage(0);
}

void MainWindow::on_loginlogin_clicked()
{
    QString user = ui->loginuserin->text();
    QString password = ui->loginpwin->text();

    if (database.contains(user))
    {
        if(database.value(user).at(0) == password)
            changePage(2);
        else
            QMessageBox::information(this, "ERROR", "Wrong username or password");
    }
    else
    {
        QMessageBox::information(this, "ERROR", "Wrong username or password");
    }
}

void MainWindow::on_loginexit_clicked()
{
    QApplication::exit();
}

void MainWindow::on_wchangepw_clicked()
{
    changePage(3);
}
