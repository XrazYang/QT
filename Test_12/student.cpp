#include "student.h"
#include<QString>
#include<QDebug>

Student::Student()
{
    name = new QString("");
    age = 0 ;
    job = new QString("");
    salary = 0 ;
}

Student::Student(QString *name, int age, QString *job, int salary){
    this->name = name ;
    this->age = age ;
    this->job = job ;
    this->salary = salary ;
}

void Student::display()const{
    QString str = QString("name : %1 ,age %2 ,job %3 ,salary %4 ").arg(*name).arg(age).arg(*job).arg(salary);
    qDebug()<<str;
}

bool Student::operator == (const Student& stu){
    if(!this->name->compare(stu.name)) return true ;
    else return false ;
}
bool Student::operator != (const Student& stu){
   return !(this->operator ==(stu));
}
