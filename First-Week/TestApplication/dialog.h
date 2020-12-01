#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QLabel* msgLable;
    void showMessage(QString msg);

};
#endif // DIALOG_H
