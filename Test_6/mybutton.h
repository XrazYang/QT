#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *e);

signals:

public slots:

};

#endif // MYBUTTON_H
