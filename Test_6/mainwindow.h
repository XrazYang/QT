#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
//    void paintEvent(QPaintEvent * event);
//    void resizeEvent(QResizeEvent *event);
//    void closeEvent(QCloseEvent *event);
      void mousePressEvent(QMouseEvent *event);
      void timerEvent(QTimerEvent *e);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
