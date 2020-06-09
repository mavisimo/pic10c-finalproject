#include "squarewidget.h"

squareWidget::squareWidget()
{
     block = new QToolButton();
     clicked = false;
     state = 1;
}

void squareWidget::set_state()
{
    state = 0;
}


