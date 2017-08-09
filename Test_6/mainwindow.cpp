#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QTime>
#include<QMouseEvent>
#include<QTime>
#include<QTimerEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QTime time = QTime::currentTime();
        ui->label_2->setText(time.toString());
    });

    this->startTimer(1000);

    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        QTime time = QTime::currentTime();
        ui->label_3->setText(time.toString());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::paintEvent(QPaintEvent *event){

//    qDebug()<<"paintEvent !!"<<endl ;
//}

//void MainWindow::resizeEvent(QResizeEvent *event){

//    qDebug()<<"resizeEvent !!"<<endl ;
//}

void MainWindow::mousePressEvent(QMouseEvent *event){
    QTime time = QTime::currentTime();
    ui->label->setText(time.toString());
}

void MainWindow::timerEvent(QTimerEvent *e){
    QTime time = QTime::currentTime();
    ui->label_4->setText(time.toString());
}
