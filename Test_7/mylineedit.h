#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include<QLineEdit>


class MyLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit MyLineEdit(QWidget *parent = 0);

public:
    void keyPressEvent(QKeyEvent *ev);
    bool event(QEvent *ev);

};

#endif // MYLINEEDIT_H
