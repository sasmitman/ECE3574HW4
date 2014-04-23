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

QString current_user = "";//Keep track of current user

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

void MainWindow::writeTo()
{
    QFile input("passwords.dat");
    if(!input.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "could not open file";
        return;
    }
    QTextStream fout(&input);
    QMapIterator<QString, QVector<QString> > i(database);
    while (i.hasNext())
    {
        i.next();
        fout<<i.key()<<"::"<<database.value(i.key()).at(0)<<"::"<<database.value(i.key()).at(1)<<endl;
    }
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

void MainWindow::on_actionLogOut_triggered()
{
    if (current_user == "")
        QMessageBox::information(this, "ERROR", "User is not signed in");
    else
    {
        current_user = "";
        changePage(0);
    }
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
        writeTo();
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
        {   current_user =user;
            ui->changelabel->setText("Changing password for "+current_user);
            changePage(2);
        }
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

void MainWindow::on_wexit_clicked()
{
    QApplication::exit();
}

void MainWindow::on_wstart_clicked()
{
    changePage(4);
}

void MainWindow::on_changeok_clicked()
{
    if(database.value(current_user).at(0) == ui->changeoldpwin->text())
    {
        if (ui->changenewpwin->text() == ui->changerepwin->text())
        {
            database.remove(current_user);//Deletes from QMap
            QVector<QString> temp;
            temp.append(ui->changenewpwin->text());
            temp.append(ui->changecolorbox->currentText());
            database.insert(current_user, temp);
            temp.clear();
            writeTo();
            changePage(0);
        }
        else
            QMessageBox::information(this, "ERROR", "Passwords do not match");
    }
    else
        QMessageBox::information(this, "ERROR", "Incorrect password");
}

void MainWindow::on_changecancel_clicked()
{
    QApplication::exit();
}
