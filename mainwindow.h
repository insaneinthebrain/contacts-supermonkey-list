#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "messages.h"
#include <fstream>
#include <string>

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

    void on_btnReload_clicked();

    void on_btnSave_clicked();

    void on_btnClear_clicked();

    void on_btnSearch_clicked();

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_txtBoxSearch_returnPressed();

private:
    void Populate_Row();
    void Unpopulate_List();
    Ui::MainWindow *ui;

    Messages msg;
    std::ifstream rdfile;
    std::ofstream myfile;
    QTableWidgetItem *sname;
    QTableWidgetItem *sphone;
    QTableWidgetItem *semail;
    QString tname;
    QString tphone;
    QString temail;
    int fid;
    int countid;
    int storid[200];
    std::string name;
    std::string phone;
    std::string email;
    QString findthis;
    std::string findthisstr;
    bool saveautoclicked;
    bool clearautoclicked;
    bool formcleared;
    bool found;
    int row;
    int askResults;


};

#endif // MAINWINDOW_H
