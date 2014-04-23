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
    void changePage(int i);//Changes the pages of the stacked widget
    void readFile();    //Read from file and put into QMap
    void writeTo();     //Write everything from QMap into file

private slots:
    //User menu slots
    void on_actionRegisterUser_triggered();//Register user menu
    void on_actionExit_triggered();        //Exit
    void on_actionLogOut_triggered();       //Logout
    //Game menu slots
    void on_actionNewGame_triggered();      //new game
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
private:
    Ui::MainWindow *ui;
    QMap<QString, QVector<QString> > database;
};

#endif // MAINWINDOW_H
