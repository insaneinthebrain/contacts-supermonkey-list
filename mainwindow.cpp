#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <QtGui>
#include <QApplication>
#include "messages.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myfile.open("Contacts.txt", std::ios::app);
    myfile.close();
    found=false;
    saveautoclicked=false;
    clearautoclicked=false;
    formcleared=false;
    on_btnReload_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Populate_List()
{

    if(name=="()")name="";
    if(phone=="()")phone="";
    if(email=="()")email="";

    cname = (char*)name.c_str();
    cphone = (char*)phone.c_str();
    cemail = (char*)email.c_str();

         ui->tableWidget->setItem(row, 0, new QTableWidgetItem (tr(cname).arg(row, 0)));
         ui->tableWidget->setItem(row, 1, new QTableWidgetItem (tr(cphone).arg(row, 1)));
         ui->tableWidget->setItem(row, 2, new QTableWidgetItem (tr(cemail).arg(row, 2)));
}


void MainWindow::Unpopulate_List()
{
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem (tr("").arg(row, 0)));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem (tr("").arg(row, 1)));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem (tr("").arg(row, 2)));
}


void MainWindow::on_btnReload_clicked()
{
    clearautoclicked=true;
    on_btnClear_clicked();
    clearautoclicked=false;
    found=false;
    formcleared=false;
    rdfile.open("Contacts.txt");

     row=0;
     fid=1;

    while(rdfile >> fid, getline(rdfile, name, '|'),getline(rdfile, phone, '|'),getline(rdfile, email)){

            Populate_List();
            row++;
      }
            rdfile.close();

}

void MainWindow::on_btnSave_clicked()
{
    if (saveautoclicked==false){
        if(formcleared==true){
            askResults = msg.Msg_saveWarning();
        }else{
            askResults = msg.Msg_saveAsk();
        }
    }

 if(saveautoclicked==true || askResults == QMessageBox::Ok)
 {       if (found==true){
            myfile.open("Contacts.txt", std::ios::app);
         }else{
            myfile.open("Contacts.txt");
         }

            row = 0;
            if(found==true){fid++;}else{fid = 1;}

        do{
                name="";
                phone="";
                email="";

            sname = ui->tableWidget->item(row,0);
            if(sname!=0){
            tname = sname->text();
            name = tname.toUtf8().constData();
                }
            sphone = ui->tableWidget->item(row,1);
            if(sphone!=0){
            tphone = sphone->text();
            phone = tphone.toUtf8().constData();
                }
            semail = ui->tableWidget->item(row,2);
            if(semail!=0){
            temail = semail->text();
            email = temail.toUtf8().constData();
                }

            if(name=="" && phone=="" && email==""){
                }else{
                    if(name=="")name = "()";
                    if(phone=="")phone = "()";
                    if(email=="")email = "()";

                    myfile<<fid<<name<<"|"<<phone<<"|"<<email<<std::endl;
                }
            row++;
            fid++;


        }while(row<201);
            myfile.close();

        if(found==true){
            clearautoclicked=true;
            on_btnClear_clicked();
            clearautoclicked=false;
            formcleared=false;
            rdfile.open("Contacts.txt");

             row=0;
             fid=1;
             countid=0;

            while(rdfile >> fid, getline(rdfile, name, '|'),getline(rdfile, phone, '|'),getline(rdfile, email)){

                Populate_List();

                if(storid[countid] == fid){

                    Unpopulate_List();
                    countid++;
                }
                    row++;

             }
                    rdfile.close();
                    found=false;
                    saveautoclicked=true;
                    on_btnSave_clicked();
                    on_btnReload_clicked();
                    on_btnSave_clicked();
                    saveautoclicked=false;

           }
    }else{}
}

void MainWindow::on_btnClear_clicked()
{
    if(clearautoclicked==false){
        msg.Msg_clearWarning();
    }
    found=false;
    formcleared=true;
    for(row=0; row<201; row++){

        Unpopulate_List();

    }
}

void MainWindow::on_btnSearch_clicked()
{
    findthis = ui->txtBoxSearch->text();
    findthisstr = findthis.toUtf8().constData();

    if(findthis != ""){

        clearautoclicked=true;
        on_btnClear_clicked();
        clearautoclicked=false;
        formcleared=false;
        rdfile.open("Contacts.txt");


         for(row=0; row<200; row++){
             storid[row]=NULL;
         }
         row=0;
         fid=1;
        found=false;
        while(rdfile >> fid, getline(rdfile, name, '|'),getline(rdfile, phone, '|'),getline(rdfile, email)){

           if(findthisstr.find(name)!=name.find(findthisstr) || findthisstr.find(phone)!=phone.find(findthisstr) || findthisstr.find(email)!=email.find(findthisstr)){

                    Populate_List();
                    storid[row]=fid;
                    row++;
                    found=true;

              }
            }

                rdfile.close();
                if(found==false){
                    msg.Msg_searchNotfound(findthis);
                    on_btnReload_clicked();
                }
    }

}


void MainWindow::on_txtBoxSearch_returnPressed()
{
    on_btnSearch_clicked();
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_triggered()
{
    msg.Msg_About();
}

