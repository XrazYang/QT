#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QFileInfo>
#include<QFileDialog>
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_readFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"open","./","TXT(*.txt)");

    if(!path.isEmpty()){

        QFile file(path);

        bool open = file.open(QIODevice::ReadOnly);
//        if(open){
//            QByteArray array = file.readAll();
//            ui->textEdit->setText(QString(array));
//        }

         QByteArray array ;

         while(!file.atEnd()){
             array += file.readLine();
         }
         ui->textEdit->setText(QString(array));
        file.close();


        QFileInfo info(path);
        qDebug()<<"name =   "<<info.fileName();
        qDebug()<<"size =   "<<info.size();
        qDebug()<<"suffix=   "<<info.suffix();

    }
}

void Widget::on_writeFile_clicked()
{

     QString name = QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt)");

     if(!name.isEmpty()){
         QFile file ;
         file.setFileName(name);
         if(file.open(QIODevice::WriteOnly)){
             QString str = ui->textEdit->toPlainText();
             QByteArray array = str.toUtf8();

             file.write(array);

         }



     }

}
