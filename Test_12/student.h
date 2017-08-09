#ifndef STUDENT_H
#define STUDENT_H
#include<QString>


class Student
{
public:
    Student();
    Student( QString *name, int age ,QString *job ,int salary);
    bool operator ==(const Student& stu);
    bool operator !=(const Student& stu);

    void display()const;

    QString *name ;
    int age ;
    QString *job ;
    int salary ;
};

#endif // STUDENT_H
