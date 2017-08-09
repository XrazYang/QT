#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include<QWidget>
#include<QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    ~SubWidget();
    void sendSingnal();

signals:
    void mySingnal();
    void mySingnal(int ,QString);

    //qt4
public slots:
    void hideMyself();

private:
    QPushButton *b ;
};

#endif // SUBWIDGET_H
