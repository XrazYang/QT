#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;
    bool keyUp ;
    bool keyDown ;
    bool keyLeft ;
    bool keyRight;

    int x ;
    int y ;
};

#endif // WIDGET_H
