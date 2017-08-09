#include "widget.h"
#include <QApplication>
#include<QDebug>
#include"student.h"
#include<QList>
#include<QListIterator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
   // w.show();

//    QString str = "hello";
//    qDebug()<<"str size is  "<<str.size()<<"str capacity is" << str.capacity();

//    str[0] = QChar('H');
//    qDebug()<<str;

//    str.append("QT");
//     qDebug()<<str;
//     qDebug()<<"str size is  "<<str.size()<<"str capacity is" << str.capacity();

//    str.replace(1,4,"i");
//     qDebug()<<str;
//    str.insert(2,"my");
//     qDebug()<<str;

//     str = "hi\r\nQT!\n";
//      qDebug()<<str;

//      QString str1 = str.trimmed();
//       qDebug()<<str1;

//       QString str2= str1.simplified();
//        qDebug()<<str;

//      QVariant v(14);
//       qDebug()<<v.canConvert(QVariant::Int);
//       int age = v.toInt();
//       //qDebug()<< v.toInt();

//       QVariant v1("gsrhg");
//        qDebug()<<v1.convert(QVariant::String);
//        str = v1.toString();

//       QString str3 = QString("name %1 , age  %2").arg(str).arg(age);
//       qDebug()<<str3 ;

//       QString::const_iterator it = str3.cbegin();
//       for( ; it != str3.cend() ; ++it){
//            qDebug()<<*it;
//       }

    QList<Student> student ;

    student.push_back(Student(new QString("yang"),23,new QString("IT"),20000));
    student.push_back(Student(new QString("yang1"),24,new QString("IT"),30000));
    student.push_back(Student(new QString("yang2"),25,new QString("IT"),40000));
    student.push_back(Student(new QString("yang3"),26,new QString("IT"),50000));
    student.push_back(Student(new QString("yang4"),27,new QString("IT"),60000));
    student.push_back(Student(new QString("yang5"),28,new QString("IT"),70000));

    foreach (Student stu, student) {
        stu.display();
    }

    int i = student.indexOf(Student(new QString("yang"),23,new QString("IT"),20000));

     qDebug()<<i ;

     student.append(Student(new QString("yang"),23,new QString("IT"),20000));

     QListIterator<Student> it(student);

     while (it.hasNext()) {
        // Student stu = it.next();
         it.next().display();
     }

     QList<Student>::const_iterator itt = student.constBegin();
     for( ; itt != student.constEnd() ; ++itt){
         //(*it).display();
         itt->display();
     }









    return a.exec();
}
