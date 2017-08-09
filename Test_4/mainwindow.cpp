#include "mainwindow.h"
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QDebug>
#include<QToolBar>
#include<QPushButton>
#include<QStatusBar>
#include<QLabel>
#include<QTextEdit>
#include<QDockWidget>
#include<QDialog>
#include<QMessageBox>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar =  menuBar();
    QMenu *pFile = mBar->addMenu("File");

    QAction *pNew = pFile->addAction("new");

    connect(pNew,&QAction::triggered,
            [=]()mutable{
        QDialog d ;
        d.exec();
        d.resize(50,50);
         qDebug()<<"test test"<<endl ;
    });

    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("open");
    connect(pOpen,&QAction::triggered,
            [=]()mutable{
        QDialog *d = new QDialog(this);
        d->show();
        d->resize(50,50);
        d->setAttribute(Qt::WA_DeleteOnClose);
        qDebug()<<"test test"<<endl ;
    });


    //////////////////////////////////////////////
    //////////////////////////////////////////////
    QToolBar *toolBar = addToolBar("toolBar");
    toolBar->addAction(pNew);

    QPushButton *b = new QPushButton("about",this);
    toolBar->addWidget(b);
    connect(b,&QPushButton::pressed,[=](){

        QMessageBox::about(this,"about","QT");

        qDebug()<<"test test"<<endl ;
    });

    QPushButton *bb = new QPushButton("question",this);
    toolBar->addWidget(bb);
    connect(bb,&QPushButton::pressed,[=](){

        int ret = QMessageBox::question(this,"question","Are you OK ??",
                                        QMessageBox::Ok,
                                        QMessageBox::Cancel);

        switch (ret) {
        case QMessageBox::Yes:
            qDebug()<<"yes yes !!!"<<endl ;
            break;
        case QMessageBox::No:
            qDebug()<<"no no !!!"<<endl ;
            break;

        default:
            qDebug()<<"error error !!!"<<endl ;
            break;
        }
    });

    QPushButton *bbb = new QPushButton("file dialog",this);
    toolBar->addWidget(bbb);
    connect(bbb,&QPushButton::pressed,[=](){
        QString string = QFileDialog::getOpenFileName(this,"open file","/home", "Images (*.png *.xpm *.jpg);;"
                                                                                "Text files (*.txt);;"
                                                                                "XML files (*.xml)");


        qDebug()<<string<<endl ;
    });


    //////////////////////////////////////////////
    //////////////////////////////////////////////
    QStatusBar *status = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("normal text file");
    status->addWidget(label);

    status->addPermanentWidget(new QLabel("test test test",this));

    //////////////////////////////////////////////
    //////////////////////////////////////////////
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);


    //////////////////////////////////////////////
    //////////////////////////////////////////////
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea,dock);

     QTextEdit *editt = new QTextEdit(this);
     dock->setWidget(editt);
}

MainWindow::~MainWindow()
{

}
