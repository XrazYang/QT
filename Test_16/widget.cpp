#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QDataStream>
#include<QDebug>

#define cout qDebug()<<"[ "<<__FILE__<<" : "<<__LINE__<<" ] "

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_write_clicked()
{
    QFile file("./test.dat");
    if(file.open(QIODevice::WriteOnly)){
        QDataStream out(&file);

        out<<QString("gdfshg")<<1234;

    }
    file.close();

}

void Widget::on_read_clicked()
{
    QFile file("./test.dat");
   if(file.open(QIODevice::ReadOnly)){
       QDataStream in(&file);
       //QByteArray data ;
       QString str ;
       int a ;
       in>>str>>a;

       cout<<str;
       ui->textEdit->setText(str);
   }
   file.close();
}
