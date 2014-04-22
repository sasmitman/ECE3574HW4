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

private slots:
    //Menu slots
    void on_actionRegisterUser_triggered();//Register user menu
    //Register user slots
    void on_regOK_clicked();//OK button
    
private:
    Ui::MainWindow *ui;
    QMap<QString, QVector<QString> > database;
};

#endif // MAINWINDOW_H
