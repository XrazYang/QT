#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mydialog.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void showSelectDialog();
    void showLabel(int a );
    
private:
    Ui::Widget *ui;
    MyDialog *md;
};

#endif // WIDGET_H
