#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <QtGui>
#include <QApplication>
#include "messages.h"

Messages::Messages()
{
}

int Messages::Msg_saveAsk()
{
        QMessageBox msgBox;

        msgBox.setText("Save Contacts List");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setInformativeText("Save Changes?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        ask = msgBox.exec();
        return (ask);

}

int Messages::Msg_saveWarning()
{
        QMessageBox msgBox;

        msgBox.setText("OVERWRITE LIST!!!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setInformativeText("Are you really sure?\n This will overwrite your old list!\n Whatever you see on screen now\n will become your new list.");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        ask = msgBox.exec();
        return (ask);
}

void Messages::Msg_clearWarning()
{
        QMessageBox::warning(0,"Warning", "Pressing save after clearing the list\n WILL OVERWRITE YOUR LIST!\n If this is not your intention, press the Reload list button\n after closing this message.");
}

void Messages::Msg_searchNotfound(QString srch)
{
        notfound = ("Sorry, no records matching - " + srch);
        QMessageBox::information(0,"Not found", notfound);
}

void Messages::Msg_About()
{
        QMessageBox::information(0,"Contacts About", "Contacts version: 1.whatever.whatever\nAuthor: Me(or whoever pushed the compile button).\nLicence: We don't need no steenking licence!");
}
