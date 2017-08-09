#include "mainwidget.h"
#include<QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    sub = new SubWidget();

    setWindowTitle("the first window");
    b1.setParent(this);
    b1.setText("button1");

    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);

    b2 = new QPushButton(this);
    b2->setText("button2");
    b2->move(100,100);

    connect(b2,&QPushButton::clicked,this,&MainWidget::showSecondWindow);

    //qt5 signal connection
//    void (SubWidget::*test1) ()= &SubWidget::mySingnal;
//    void (MainWidget::*hide1)()= &MainWidget::hideSecondWindow;
//    connect(sub,test1,this,hide1);

//    void (SubWidget::*test2) (int ,QString)= &SubWidget::mySingnal;
//    void (MainWidget::*hide2)(int ,QString)= &MainWidget::hideSecondWindow;
//    connect(sub,test2,this,hide2);

    //qt4 signal connection : use define SIGNAL  AND SLOT
    connect(sub,SIGNAL(mySingnal()),this,SLOT(hideSecondWindow()));

    //Lambda express
    b3 = new QPushButton("Lambda",this);
    b3->move(300,300);

    QString qs("asdfghjkl");
    connect(b3,&QPushButton::clicked,
            [=](bool isChecked){
        qDebug()<<isChecked<<endl;
        qDebug()<<"Lambda"<<":"<<qs<<endl;
    });


}

void MainWidget::showSecondWindow(){
    sub->show();
}

void MainWidget::hideSecondWindow(){
    sub->hide();
}

void MainWidget::hideSecondWindow(int a, QString qs){
    qDebug()<<a<<":"<<qs<<endl;
}

MainWidget::~MainWidget()
{
    if(b2 != NULL)delete b2 ;
    if(b3 != NULL)delete b3 ;
    if(sub != NULL)delete sub ;
}
