#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

signals:

public slots:
    void showSecondWindow();
    void hideSecondWindow();
    void hideSecondWindow(int,QString);

private:
    QPushButton b1 ;
    QPushButton *b2 ;
    QPushButton *b3 ;

    SubWidget *sub ;
};

#endif // MAINWIDGET_H
