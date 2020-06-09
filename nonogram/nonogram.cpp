#include "nonogram.h"
#include "squarewidget.h"
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

    // starter work
    solution = create_solution();

    //squareWidget* buttons[49];
    QSignalMapper* signalMapper = new QSignalMapper(this) ;
    for (int i = 0; i < 49; ++i)
    {
        //buttons[i] = new squareWidget();
        buttons[i] = new QToolButton(this);
        layout->addWidget(buttons[i], i / 7, i % 7);
        connect(buttons[i], SIGNAL(released()), signalMapper, SLOT(map()));
        signalMapper->setMapping(buttons[i],i);
        connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(color(int)));
    }

    layout->setSizeConstraint(QGridLayout::SetFixedSize);
    centralWidget()->setLayout(layout);
}

nonogram::~nonogram()
{
    delete ui;
}

std::vector<int> nonogram::random_block(int n)
{
    std::vector<int> blocks;
    while (n>0)
    {
        int x = 1 + (rand() % n);
        if (x <= n) { blocks.push_back(x); n -= x; }
    }
    return blocks;
}

std::vector<int> nonogram::create_solution()
{
    std::vector<int> nonogram(49);
    for (int i = 0; i < 7; i++)
    {
        std::vector<int> row = random_block(7);
        bool fill = true; if ((rand() % 2) == 1) fill = false;
        for (int j = 0; j < 7; j++)
        {
            while (row[j] > 0)
            {
                if (fill) nonogram[7*i+j] = 0; else nonogram[7*i+j] = 1;
                row[j] -= 1;
            }
            fill = !fill;
        }
    }
    return nonogram;
}

void nonogram::color(int i)
{
    if (solution[i] == 0) buttons[i]->setStyleSheet(QString("background-color: blue; "));
    else buttons[i]->setStyleSheet(QString("background-color: gray; "));
}

