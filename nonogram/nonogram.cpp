#include "nonogram.h"
#include "ui_nonogram.h"

nonogram::nonogram(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::nonogram)
{
    ui->setupUi(this);
    this->setWindowTitle("nonogram");

    // set grid layout
    QGridLayout* layout = new QGridLayout;
    layout->setMargin(0);
    layout->setSpacing(0);

    // starter work
    solution = create_solution();
    clues = create_clues(solution);
    for (int i = 0; i < 14; ++i)
    {
        QString text = "";
        for (int j = 0; j < int(clues[i].size()); ++j) text = text + QString::number(clues[i][j]) + " ";
        clue_d[i] = new QToolButton();
        clue_d[i]->setText(text);
        if (i<7) layout->addWidget(clue_d[i],i+1,0);
        else layout->addWidget(clue_d[i],0,i-6);
    }

    QSignalMapper* signalMapper = new QSignalMapper(this) ;
    for (int i = 0; i < 49; ++i)
    {
        buttons[i] = new QToolButton();
        layout->addWidget(buttons[i], 1 + (i/7), 1 + (i%7));
        connect(buttons[i], SIGNAL(released()), signalMapper, SLOT(map()));
        signalMapper->setMapping(buttons[i],i);
        connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(color(int)));
    }

    layout->setSizeConstraint(QGridLayout::SetFixedSize);
    QWidget* new_window = new QWidget();
    new_window->setLayout(layout);
    setCentralWidget(new_window);
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

std::vector<std::vector<int> > nonogram::create_clues(std::vector<int> solution)
{
    std::vector<std::vector<int> > clues(14);
    for (int i = 0; i < 7; i++)
    {
        int count1=0, count2=0;
        for (int j = 0; j < 7; j++)
        {
            if ((solution[7*i+j] == 1 && count1 != 0) || (j == 6))
            {
                if (solution[7*i+j]== 0) count1++;
                if (count1 > 0) clues[i].push_back(count1);
                count1 = 0;
            }
            else if (solution[7*i+j] == 0) count1++;
            if ((solution[7*j+i] == 1 && count2 != 0) || (j == 6))
            {
                if (solution[7*j+i]== 0) count2++;
                if (count2 > 0) clues[7+i].push_back(count2);
                count2 = 0;
            }
            else if (solution[7*j+i] == 0) count2++;
        }
    }
    return clues;
}

void nonogram::color(int i)
{
    if (solution[i] == 0) buttons[i]->setStyleSheet(QString("background-color: blue; "));
    else buttons[i]->setStyleSheet(QString("background-color: gray; "));
}

