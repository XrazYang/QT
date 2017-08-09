#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QKeyEvent>
#include<QEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::keyPressEvent(QKeyEvent *event){
    QString qs = event->text();
    qDebug()<<"Widget keyboard press  "<<qs<<endl ;

}

bool Widget::eventFilter(QObject *watched, QEvent *event){
    if(watched == ui->lineEdit ){
        if(event->type() == QEvent::KeyPress){
            QString qs = (static_cast<QKeyEvent *>(event))->text();
            qDebug()<<"eventFilter keyboard press  "<<qs<<endl ;
        }
    }
    return QWidget::eventFilter(watched,event);
}
