#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:
    void clear();
    void readData();


private:
    Ui::Widget *ui;
    QUdpSocket *send ;
    QUdpSocket *receiver ;
};

#endif // WIDGET_H
