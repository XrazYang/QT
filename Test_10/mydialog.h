#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include<QSpinBox>

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MyDialog(QWidget *parent = nullptr);

signals:
    void mySignal(int);

public slots:
    void sendMySignal();
    
private:
   QSpinBox *box;
   QPushButton *button ;

    
};

#endif // MYDIALOG_H
