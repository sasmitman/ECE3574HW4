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
    void writeTo(QString username);     //Write everything from QMap into file

private slots:
    //User menu slots
    void on_actionRegisterUser_triggered();//Register user menu
    void on_actionExit_triggered();        //Exit
    //Login page
    void on_loginlogin_clicked();//Login button
    void on_loginexit_clicked();//Exit button
    //Register user slots
    void on_regOK_clicked();//OK button
    void on_regCancel_clicked();//cancel button
    //Welcome page slots
    void on_wchangepw_clicked();//Change password button
private:
    Ui::MainWindow *ui;
    QMap<QString, QVector<QString> > database;
};

#endif // MAINWINDOW_H
