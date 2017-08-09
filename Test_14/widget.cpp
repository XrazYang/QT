#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->clear,&QPushButton::clicked,this,&Widget::clear);

    this->receiver = new QUdpSocket(this);
    //QHostAddress address("172.0.0.1");
    this->receiver->bind(QHostAddress::LocalHost,6664);
    connect(this->receiver,&QUdpSocket::readyRead,this,&Widget::readData);


    this->send = new QUdpSocket(this);
    connect(ui->send,&QPushButton::clicked,this,[=](){
        QString value = ui->textEdit->toPlainText();
        QByteArray data = value.toUtf8();
        //QHostAddress address("192.168.42.107");

       long len =  send->writeDatagram(data.data(),data.size(),QHostAddress::LocalHost,6665);
       if(len != -1){
           qDebug()<<"success !!  ";
       }
    });



}

Widget::~Widget()
{
    delete ui;
}

void Widget::clear(){
    ui->textEdit->clear();
}

void Widget::readData(){
    QByteArray data ;
    //QString value ;
    while (this->receiver->hasPendingDatagrams()) {
        data.resize(this->receiver->pendingDatagramSize());
        this->receiver->readDatagram(data.data(),data.size());
    }

    if(!data.isEmpty()){
      QString value(data) ;
      //qDebug()<<value;
      this->ui->textEdit->clear();
      ui->textEdit->setText(value);
    }

    qDebug()<<" receiver success !!  ";
}
