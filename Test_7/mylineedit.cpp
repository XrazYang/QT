#include "mylineedit.h"
#include<QDebug>
#include<QKeyEvent>
#include<QEvent>

MyLineEdit::MyLineEdit(QWidget *parent):QLineEdit(parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *ev){

    QString qs = ev->text();
    qDebug()<<"MyLineEDit keyboard press  "<<qs<<endl ;

   // QLineEdit::keyPressEvent(ev);

    //ev->ignore();

}

bool MyLineEdit::event(QEvent *ev){

    if(ev->type() == QEvent::KeyPress ){
        QString qs = (static_cast<QKeyEvent *>(ev))->text();
        qDebug()<<"event keyboard press  "<<qs<<endl ;
    }

    return QLineEdit::event(ev);

}
