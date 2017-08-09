#include "widget.h"
#include "ui_widget.h"
#include<QMouseEvent>
#include<QWheelEvent>
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QCursor cursor;
    //set cursor shape
    cursor.setShape(Qt::OpenHandCursor);

    //use cursor
    setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event){

    if(event->button() == Qt::LeftButton) {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();
    }else if (event->button() == Qt::RightButton){
        qDebug()<<"mouse press reght button "<<endl ;
    }
}



void Widget::mouseMoveEvent(QMouseEvent *event){

    //please attention
    if(event->buttons() & Qt::LeftButton){
        move(event->globalPos()-offset);
    }
}


void Widget::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();

}

void Widget::mouseDoubleClickEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton) {

        if(windowState() != Qt::WindowFullScreen){
            setWindowState(Qt::WindowFullScreen);
        }
        else setWindowState(Qt::WindowNoState);
    }

}

void Widget::wheelEvent(QWheelEvent *event){
    if(event->delta() > 0 ){
        ui->textEdit->zoomIn();
    }else {
        ui->textEdit->zoomOut();
    }

}
