#ifndef SQUAREWIDGET_H
#define SQUAREWIDGET_H

#include <QWidget>
#include <QToolButton>

class squareWidget
{
public:
    squareWidget();
    QToolButton* block;

    bool clicked;
    int state; // 0 for filled, 1 for empty

    void set_state(); // set state to filled since all are initializzed as empty

public slots:
    void show();


};

#endif // SQUAREWIDGET_H
