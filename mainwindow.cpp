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
        QString color = splitter[2].simplified();//Getting color
        QVector<QString> temp;
        temp.append(password);
        temp.append(color);
        database.insert(user, temp);
        temp.clear();
    }
    input.close();
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
    changePage(4);
    initialize();
    game_init();
    ui->gameuser->setText(current_user);
    for(int i=0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
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

    for(int i=0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

void MainWindow::on_changeok_clicked()
{
    if(database.value(current_user).at(0) == ui->changeoldpwin->text())
    {
        if (ui->changenewpwin->text() == ui->changerepwin->text())
        {
            if (ui->changecolorbox->currentText() == database.value(current_user).at(2))
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
                ui->changenewpwin->clear();
                ui->changerepwin->clear();
                ui->changeoldpwin->clear();
            }
            else
            {
                QMessageBox::information(this, "ERROR", "Information does not match!");
                ui->changenewpwin->clear();
                ui->changerepwin->clear();
                ui->changeoldpwin->clear();
            }
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
    progressgame();
}

void MainWindow::on_p2_clicked()
{
    board[0][1] = 1;
    ui->p2->setText("X");
    ui->p2->setDisabled(1);
    progressgame();
}

void MainWindow::on_p3_clicked()
{
    board[0][2] = 1;
    ui->p3->setText("X");
    ui->p3->setDisabled(1);
    progressgame();
}

void MainWindow::on_p4_clicked()
{
    board[1][0] = 1;
    ui->p4->setText("X");
    ui->p4->setDisabled(1);
    progressgame();
}

void MainWindow::on_p5_clicked()
{
    board[1][1] = 1;
    ui->p5->setText("X");
    ui->p5->setDisabled(1);
    progressgame();
}

void MainWindow::on_p6_clicked()
{
    board[1][2] = 1;
    ui->p6->setText("X");
    ui->p6->setDisabled(1);
    progressgame();
}

void MainWindow::on_p7_clicked()
{
    board[2][0] = 1;
    ui->p7->setText("X");
    ui->p7->setDisabled(1);
    progressgame();
}

void MainWindow::on_p8_clicked()
{
    board[2][1] = 1;
    ui->p8->setText("X");
    ui->p8->setDisabled(1);
    progressgame();
}

void MainWindow::on_p9_clicked()
{
    board[2][2] = 1;
    ui->p9->setText("X");
    ui->p9->setDisabled(1);
    progressgame();
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
    update();

    ui->compscore->setReadOnly(true);
    ui->userscore->setReadOnly(true);
    ui->drawscore->setReadOnly(true);

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
    //Default board
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

void MainWindow::endgame()
{
    ui->p1->setDisabled(1);
    ui->p2->setDisabled(1);
    ui->p3->setDisabled(1);
    ui->p4->setDisabled(1);
    ui->p5->setDisabled(1);
    ui->p6->setDisabled(1);
    ui->p7->setDisabled(1);
    ui->p8->setDisabled(1);
    ui->p9->setDisabled(1);
}

int MainWindow::calculate()
{
    int total;
    //check diagonals
    total = (board[0][0] + board[1][1] + board[2][2]);
    if(total > 1) return 4;
    total =(board[0][2] + board[1][1] + board[2][0]);
    if( total > 1) return -4;

    total = 0;
    //check rows
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            total += board[i][j];
        }
        if(total > 1) return i+1;
        total = 0;
    }

    //check columns
    total = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            total += board[j][i];
        }
        if(total > 1) return -(i+1);
        total = 0;
    }
    return 0;   //return 0 if no close wins
}

int MainWindow::checkwinner() //Checks to see if there is a winner

{
    //Checking 1-9 diagonal
    int sum = 0;
    sum = board[0][0]+board[1][1]+board[2][2];
    if (sum == 3)
        return 1;
    else if (sum == -3)
        return -1;
    //Checking 3-6 diagonal
    sum =(board[0][2]+board[1][1]+board[2][0]);
    if (sum==3)
        return 1;
    else if (sum==-3)
        return -1;

    sum = 0;
    //check rows
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            sum += board[i][j];
        }
        if(sum == 3)
            return 1;
        else if(sum == -3)
            return -1;
        sum = 0;
    }

    //check columns
    sum = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            sum += board[j][i];
        }
        if(sum == 3)
            return 1;
        else if(sum == -3)
            return -1;
        sum = 0;
    }
    //check for empty spaces
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (board[j][i] == 0)
                return 0;
        }
    }
    return 2;
}

void MainWindow::progressgame()
{
    int check = checkwinner();
    if (check == 1)
    {
        endgame();
        QMessageBox::information(this, "playerWin", "Congrats dawg. You win!");
        user_score++;
        reset();
    }

    if (check == 2)
    {
        endgame();
        QMessageBox::information(this, "Draw", "It's a draw!");
        draw_score++;
        reset();
    }

    else
    {
        move();

        check = checkwinner();

        if(check == -1)
        {
            endgame();
            QMessageBox::information(this, "Loser", "You lose!");
            comp_score++;
            reset();
        }
    }
}


void MainWindow::move()
{
    int condition = calculate();
    bool foundEmpty = false;

    if (condition == 4)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[i][i] == 0)
            {
                board[i][i] = -1;
                place(i,i);
                break;
            }
        }
    }

    else if (condition == -4)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[i][2-i] == 0)
            {
                board[i][2-i] = -1;
                place(i,2-i);
                break;
            }
        }
    }
    else if(condition > 0 && condition < 4)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[condition-1][i] == 0)
            {
                board[condition-1][i] = -1;
                place(condition-1,i);
                break;
            }
        }
    }
    else if(condition < 0 && condition > -4)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[i][(-condition)-1] == 0)
            {
                board[i][(-condition)-1] = -1;
                place(i,(-condition)-1);
                break;
            }
        }
    }
    else if(condition == 0)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == 0)
                {
                    board[i][j] = -1;
                    place(i,j);
                    foundEmpty = true;
                    break;
                }

            }
            if(foundEmpty) break;
        }
    }
}

void MainWindow::place(int i, int j)
{
    if(i == 0 && j == 0)
    {
        ui->p1->setText("O");
        ui->p1->setDisabled(1);
    }
    if(i == 0 && j == 1)
    {
        ui->p2->setText("O");
        ui->p2->setDisabled(1);
    }
    if(i == 0 && j == 2)
    {
        ui->p3->setText("O");
        ui->p3->setDisabled(1);
    }
    if(i == 1 && j == 0)
    {
        ui->p4->setText("O");
        ui->p4->setDisabled(1);
    }
    if(i == 1 && j == 1)
    {
        ui->p5->setText("O");
        ui->p5->setDisabled(1);
    }
    if(i == 1 && j == 2)
    {
        ui->p6->setText("O");
        ui->p6->setDisabled(1);
    }
    if(i == 2 && j == 0)
    {
        ui->p7->setText("O");
        ui->p7->setDisabled(1);
    }
    if(i == 2 && j == 1)
    {
        ui->p8->setText("O");
        ui->p8->setDisabled(1);
    }
    if(i == 0 && j == 0)
    {
        ui->p9->setText("O");
        ui->p9->setDisabled(1);
    }
}
