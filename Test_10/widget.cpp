#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->md = new MyDialog(this);
    
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Widget::showSelectDialog);

    connect(md,&MyDialog::mySignal,this,[=](int a){
        ui->label->setText(tr("value =  %1").arg(a));
    });
   // connect(md,&MyDialog::mySignal,this,&Widget::showLabel);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    close();
}

void Widget::showSelectDialog(){
    md->exec();
}
void Widget::showLabel(int a){
   ui->label->setText(tr("value =  %1").arg(a));
}
