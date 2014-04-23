#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMap"
#include "QVector"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //User menu slots
    void on_actionRegisterUser_triggered();//Register user menu
    void on_actionExit_triggered();        //Exit
    void on_actionLogOut_triggered();       //Logout
    //Game menu slots
    void on_actionNewGame_triggered();      //new game
    void on_actionEndGame_triggered();      //end game
    //Edit slots
    void on_actionChangepw_triggered();     //change pw
    //Login page
    void on_loginlogin_clicked();//Login button
    void on_loginexit_clicked();//Exit button
    //Register user slots
    void on_regOK_clicked();//OK button
    void on_regCancel_clicked();//cancel button
    //Welcome page slots
    void on_wchangepw_clicked();//Change password button
    void on_wexit_clicked();    //Exit button
    void on_wstart_clicked();   //Start button
    //Change password slots
    void on_changeok_clicked();//OK button
    void on_changecancel_clicked();//Cancel button
    //Game slots
    void on_gameend_clicked();
    //Each grid of the tic tac toe board's slots
    void on_p1_clicked();
    void on_p2_clicked();
    void on_p3_clicked();
    void on_p4_clicked();
    void on_p5_clicked();
    void on_p6_clicked();
    void on_p7_clicked();
    void on_p8_clicked();
    void on_p9_clicked();
private:
    Ui::MainWindow *ui;
    QMap<QString, QVector<QString> > database;
    int board [3][3];   //Tic tac toe board
    int user_score, comp_score, draw_score; //To keep track of the score
    //Menu functions
    void changePage(int i);//Changes the pages of the stacked widget
    void readFile();    //Read from file and put into QMap
    void writeTo();     //Write everything from QMap into file
    void initialize();  //Initializes all menu
    void login_init();  //Initializes login menus
    void reg_init();    //Initializes register user menu
    void welcome_init();//Initializes welcome user menu
    void change_init(); //Initialize change password menu
    void game_init();   //Initialize game menu

    void paintEvent(QPaintEvent * e);    //Draw tic-tac-toe grid
    //Game related funcions
    void reset();              //Reset game
    void update();              //Updates score
    void endgame();             //Ends game

    int calculate();           //Decides AI
    void place(int i, int j);               //AI places piece

    int checkwinner();            //Checks win conditions
    void progressgame();        //Progresses the game
    void move();                //Computer moves
};

#endif // MAINWINDOW_H
