#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include "QPushButton"
#include "QLineEdit"
#include "QMap"
#include "QMessageBox"
#include "QComboBox"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>

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
    initialize();
    login_init();
    ui->compscore->setReadOnly(1);
    ui->userscore->setReadOnly(1);
    ui->drawscore->setReadOnly(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    ui->actionRegisterUser->setEnabled(1);
    ui->actionLogOut->setEnabled(1);
    ui->actionExit->setEnabled(1);
    ui->actionNewGame->setEnabled(1);
    ui->actionEndGame->setEnabled(1);
    ui->actionChangepw->setEnabled(1);
}

void MainWindow::login_init()
{
    ui->actionRegisterUser->setEnabled(1);
    ui->actionLogOut->setDisabled(1);
    ui->actionExit->setEnabled(1);
    ui->actionNewGame->setDisabled(1);
    ui->actionEndGame->setDisabled(1);
    ui->actionChangepw->setDisabled(1);
}

void MainWindow::reg_init()
{
    ui->actionRegisterUser->setDisabled(1);
    ui->actionLogOut->setDisabled(1);
    ui->actionExit->setEnabled(1);
    ui->actionNewGame->setDisabled(1);
    ui->actionEndGame->setDisabled(1);
    ui->actionChangepw->setDisabled(1);
}

void MainWindow::welcome_init()
{
    ui->actionRegisterUser->setDisabled(1);
    ui->actionLogOut->setEnabled(1);
    ui->actionExit->setEnabled(1);
    ui->actionNewGame->setEnabled(1);
    ui->actionEndGame->setDisabled(1);
    ui->actionChangepw->setEnabled(1);
}

void MainWindow::change_init()
{
    ui->actionRegisterUser->setDisabled(1);
    ui->actionLogOut->setEnabled(1);
    ui->actionExit->setEnabled(1);
    ui->actionNewGame->setDisabled(1);
    ui->actionEndGame->setDisabled(1);
    ui->actionChangepw->setDisabled(1);
}

void MainWindow::game_init()
{
    ui->actionRegisterUser->setDisabled(1);
    ui->actionLogOut->setEnabled(1);
    ui->actionExit->setEnabled(1);
    ui->actionNewGame->setDisabled(1);
    ui->actionEndGame->setEnabled(1);
    ui->actionChangepw->setDisabled(1);
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
    initialize();
    reg_init();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionLogOut_triggered()
{
    current_user = "";
    changePage(0);
    initialize();
    login_init();
}

void MainWindow::on_actionNewGame_triggered()
{

}

void MainWindow::on_actionEndGame_triggered()
{
    changePage(2);
    initialize();
    welcome_init();
}

void MainWindow::on_actionChangepw_triggered()
{
    changePage(3);//change password page
    initialize();
    change_init();
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
        ui->reglineEdituser->clear();
        ui->reglineEditpw1->clear();
        ui->reglineEditpw2->clear();
        ui->regcombcolor->clear();
    }
    else if (pw1 != pw2)
    {
        QMessageBox::information(this, "ERROR", "Passwords do not match!");
        ui->reglineEdituser->clear();
        ui->reglineEditpw1->clear();
        ui->reglineEditpw2->clear();
        ui->regcombcolor->clear();
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
        initialize();
        login_init();
        ui->reglineEdituser->clear();
        ui->reglineEditpw1->clear();
        ui->reglineEditpw2->clear();
        ui->regcombcolor->clear();
    }
}

void MainWindow::on_regCancel_clicked()
{
    changePage(0);
    initialize();
    login_init();
}

void MainWindow::on_loginlogin_clicked()
{
    QString user = ui->loginuserin->text();
    QString password = ui->loginpwin->text();

    if (database.contains(user))
    {
        if(database.value(user).at(0) == password)
        {   current_user = user;
            ui->changelabel->setText("Changing password for "+current_user);
            ui->welcomelabel->setText("Welcome "+current_user);
            changePage(2);
            initialize();
            welcome_init();
            ui->loginuserin->clear();
            ui->loginpwin->clear();
        }
        else
        {
            ui->loginuserin->clear();
            ui->loginpwin->text();
            QMessageBox::information(this, "ERROR", "Wrong username or password");
        }
    }
    else
    {
        ui->loginuserin->clear();
        ui->loginpwin->clear();
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
    initialize();
    change_init();
}

void MainWindow::on_wexit_clicked()
{
    QApplication::exit();
}

void MainWindow::on_wstart_clicked()
{
    changePage(4);
    initialize();
    game_init();
    ui->gameuser->setText(current_user);
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
            initialize();
            login_init();
        }
        else
        {
            QMessageBox::information(this, "ERROR", "Passwords do not match");
            ui->changenewpwin->clear();
            ui->changerepwin->clear();
            ui->changeoldpwin->clear();

        }
    }
    else
    {
        QMessageBox::information(this, "ERROR", "Incorrect password");
        ui->changenewpwin->clear();
        ui->changerepwin->clear();
        ui->changeoldpwin->clear();

    }
}

void MainWindow::on_changecancel_clicked()
{
    changePage(2);
    initialize();
    welcome_init();
}


void MainWindow::on_gameend_clicked()
{
    changePage(2);
    initialize();
    welcome_init();
}
//Game slots
void MainWindow::on_p1_clicked()
{
    board[0][0] = 1;
    ui->p1->setText("X");
    ui->p1->setDisabled(1);
}

void MainWindow::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    QPen linePen(Qt::red);
    linePen.setWidth(80);

    if (ui->stackedWidget->currentIndex() == 4)
    {
        painter.drawLine(54,80,54,200);
        painter.drawLine(95,80,95,200);
        painter.drawLine(15,115,147,115);
        painter.drawLine(15,155,147,155);
    }
}


void MainWindow::reset()
{
\
    ui->p1->setText("");
    ui->p2->setText("");
    ui->p3->setText("");
    ui->p4->setText("");
    ui->p5->setText("");
    ui->p6->setText("");
    ui->p7->setText("");
    ui->p8->setText("");
    ui->p9->setText("");

    ui->p1->setEnabled(1);
    ui->p2->setEnabled(1);
    ui->p3->setEnabled(1);
    ui->p4->setEnabled(1);
    ui->p5->setEnabled(1);
    ui->p6->setEnabled(1);
    ui->p7->setEnabled(1);
    ui->p8->setEnabled(1);
    ui->p9->setEnabled(1);

    for(int i=0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

void MainWindow::update()
{
ui->userscore->setText(QString::number(user_score));
ui->compscore->setText(QString::number(comp_score));
ui->drawscore->setText(QString::number(draw_score));
}
