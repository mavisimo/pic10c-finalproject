#include "nonogram.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    nonogram w;
    w.show();
    return a.exec();
}
