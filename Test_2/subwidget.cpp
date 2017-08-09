#include "subwidget.h"
#include"mainwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("the second windows");
    b = new QPushButton(this);
    b->setText("button");
    b->move(100,100);

    connect(b, &QPushButton::clicked,this,&SubWidget::sendSingnal);
     connect(b, &QPushButton::pressed,this,&SubWidget::hideMyself);
}


SubWidget::~SubWidget(){
    if(b != NULL )delete b;
}

void SubWidget::sendSingnal(){
    emit mySingnal();
    emit mySingnal(100,"test ");
}

void SubWidget::hideMyself(){
    b->setText("slot function");
}
