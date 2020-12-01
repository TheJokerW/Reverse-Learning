#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    msgLable=new QLabel(this);

    showMessage("Hello World!");
}

Dialog::~Dialog()
{

}

void Dialog::showMessage(QString msg)
{
    if(msgLable!=nullptr)
    {
        msgLable->setText(msg);
        msgLable->show();
    }
}
