#include "widget.h"
#include <QApplication>
//#include<QRegExp> qt 4
#include<QRegularExpression>
#include<QRegularExpressionMatch>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

//    QString email = "^[\w-]+(\.[\w-]+)*@[\w-]+(\.[\w-]+)+$";
//    QString password = "^[A-Za-z0-9]+$";
//    QRegularExpression re(password ,QRegularExpression::CaseInsensitiveOption);
////    qDebug()<<re.pattern();
////    QRegularExpression::PatternOptions options = re.patternOptions();
////    qDebug()<<options;

//    QRegularExpressionMatch match = re.match("1161051479dg");
//    if(match.hasMatch()){
//        qDebug()<<true;
//        QString str = match.captured(0);
//        qDebug()<<str;

//    }


    return a.exec();
}
