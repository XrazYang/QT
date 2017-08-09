#include "mybutton.h"
#include<QMouseEvent>
#include<QTime>
#include<QTimerEvent>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    this->startTimer(100);
}

void MyButton::mousePressEvent(QMouseEvent *event){
    QTime time = QTime::currentTime();
    this->setText(time.toString());
}

void MyButton::timerEvent(QTimerEvent *e){
    QTime time = QTime::currentTime();
    this->setText(time.toString());

}
