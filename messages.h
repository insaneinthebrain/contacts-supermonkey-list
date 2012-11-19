#ifndef MESSAGES_H
#define MESSAGES_H

#include "ui_mainwindow.h"

class Messages
{
public:
    int ask;
    Messages();
    int Msg_saveAsk();
    int Msg_saveWarning();
    void Msg_clearWarning();
    void Msg_searchNotfound(QString);
    void Msg_About();


private:
    QString notfound;

};

#endif // MESSAGES_H
