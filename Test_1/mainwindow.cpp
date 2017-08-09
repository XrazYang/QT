#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->button->setText("123");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_clicked()
{

}
