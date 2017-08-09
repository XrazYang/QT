#include "widget.h"
#include "ui_widget.h"
#include<QRegularExpression>
#include<QRegularExpressionMatch>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->confirm,&QPushButton::clicked,this,&Widget::login);
    connect(ui->cancel,&QPushButton::clicked,this,&Widget::close);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::login(){
    QRegularExpression name("^[A-Za-z0-9]+$",QRegularExpression::CaseInsensitiveOption);
    QRegularExpression pass ("^[A-Z]+$");
    QRegularExpressionMatch mName = name.match(ui->name->text());
    QRegularExpressionMatch mPass = pass.match(ui->password->text());

    if(mName.hasMatch()) ui->label_3->setText("true");
    else  ui->label_3->setText("false");

    if(mPass.hasMatch()) ui->label_4->setText("true");
    else  ui->label_4->setText("false");

}

void Widget::close(){
    this->close();
}
