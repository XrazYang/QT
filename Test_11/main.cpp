#include <QCoreApplication>
#include<iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout<<"hello word !!"<<std::endl ;


    return a.exec();
}
