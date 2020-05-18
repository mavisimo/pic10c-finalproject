#include "nonogram.h"
#include "ui_nonogram.h"

nonogram::nonogram(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::nonogram)
{
    ui->setupUi(this);
}

nonogram::~nonogram()
{
    delete ui;
}

