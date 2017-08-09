#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QBuffer>

#define cout qDebug()<<"[ "<<__FILE__<<": "<<__LINE__<<" ]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QBuffer memm ;
    memm.open(QIODevice::WriteOnly);
    memm.write("fgdsssggggfgs\n");
    memm.write("fgdsssggggfgs\n");
    memm.write("fgdsssggggfgs\n");
    memm.close();

    //cout<<mem.buffer();

    QFile file ;
    file.setFileName("./buffer.txt");
    if(file.open(QIODevice::WriteOnly)){
        QBuffer mem(&file);
        mem.open(QIODevice::WriteOnly);
        mem.write("fgdsssggggfgs\n");
        mem.write("fgdsssggggfgs\n");
        mem.write("fgdsssggggfgs\n");


        file.write(mem.buffer());
        mem.close();
     }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_read_clicked()
{
    QFile file ;
    file.setFileName("./demo.txt");

    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream (&file);

        stream<<QString("dfgsdhgs \n")<<23423;
        file.close();
    }
}

void Widget::on_write_clicked()
{
    QFile file ;
    file.setFileName("./demo.txt");

    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream (&file);

       // stream<<QString("dfgsdhgs")<<23423;

        QString str ;
        int a ;
        //stream>>str>>a ;

        str = stream.readLine();
        a = stream.readLine().toInt();

        cout<<str<<a;

        file.close();
    }

}
