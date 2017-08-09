#include "widget.h"
#include "ui_widget.h"
#include<QKeyEvent>
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    keyUp = false ;
    keyDown = false ;
    keyLeft = false ;
    keyRight = false ;

    x = 100 ;
    y = 100 ;
    ui->pushButton->move(x,y);

    setFocus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event){

    switch (event->key()) {
    case Qt::Key_Up:
        if(event->isAutoRepeat()) return ;
        keyUp = true ;
        break;
    case Qt::Key_Down:
        if(event->isAutoRepeat()) return ;
        keyDown = true ;
        break;
    case Qt::Key_Left:
        if(event->isAutoRepeat()) return ;
        keyLeft = true ;
        break;
    case Qt::Key_Right:
        if(event->isAutoRepeat()) return ;
        keyRight = true ;
        break;
    default:
        break;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event){

    switch (event->key()) {

    case Qt::Key_Up:
        if(y <= 10 ) y = 0 ;
        else y -= 10 ;

        if( keyLeft ){
            if(x <= 10 )x = 0 ;
            else x-=10 ;

            keyLeft = false ;
        }else if (keyRight){
            if(x >= 190 )x =200;
            else x+=10 ;
            keyRight = false ;
        }

        keyUp = false ;
        ui->pushButton->move(x,y);
        break;
    case Qt::Key_Down:
        if(y>= 190 )y = 200 ;
        else y+=10 ;

        if( keyLeft ){
            if(x <= 10 )x = 0 ;
            else x-=10 ;
            keyLeft = false ;
        }else if (keyRight){
            if(x >= 190 )x =200;
            else x+=10 ;
             keyRight = false ;
        }
        keyDown = false ;
        ui->pushButton->move(x,y);
        break;

    case Qt::Key_Left:
        if(x <= 10 )x = 0 ;
        else x-=10 ;

        if(keyUp){
            if(y <= 10 ) y = 0 ;
            else y -= 10 ;
            keyUp = false ;
        }else if ( keyDown){
            if(y>= 190 )y = 200 ;
            else y+=10 ;
            keyDown = false ;
        }

        keyLeft = false ;
        ui->pushButton->move(x,y);
        break;
    case Qt::Key_Right:
        if(x >= 190 )x =200;
        else x+=10 ;

        if(keyUp){
            if(y <= 10 ) y = 0 ;
            else y -= 10 ;
            keyUp = false ;
        }else if ( keyDown){
            if(y>= 190 )y = 200 ;
            else y+=10 ;
            keyDown = false ;
        }

        keyRight = false ;
        ui->pushButton->move(x,y);
        break;

    default:
        break;
    }


}
