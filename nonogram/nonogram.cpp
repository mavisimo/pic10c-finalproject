#include "nonogram.h"
#include "ui_nonogram.h"

nonogram::nonogram(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::nonogram)
{
    ui->setupUi(this);

    // set grid layout
    QGridLayout* layout = new QGridLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    QToolButton* buttons[225];
    for (int i = 0; i < 225; ++i)
    {
        buttons[i] = new QToolButton(this);
        layout->addWidget(buttons[i], i / 15, i % 15);
    }
    centralWidget()->setLayout(layout);
}

nonogram::~nonogram()
{
    delete ui;
}

