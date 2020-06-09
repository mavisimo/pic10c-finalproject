#include "nonogram.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
//    srand(time(0));
    QApplication a(argc, argv);
    nonogram w;
    w.show();
    return a.exec();
}
