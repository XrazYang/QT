#include "mydialog.h"
#include<QPushButton>


MyDialog::MyDialog(QWidget *parent) : QDialog(parent)
{
    box = new QSpinBox(this);
    box->move(100,50);
    button = new QPushButton(this);
    button->setText("Confim");
    button->move(100,100);

    connect(button,&QPushButton::clicked,this,&MyDialog::sendMySignal);
}

void MyDialog::sendMySignal(){
    int a = this->box->value();
    emit mySignal(a);
    this->close();
}
