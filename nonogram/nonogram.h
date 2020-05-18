#ifndef NONOGRAM_H
#define NONOGRAM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class nonogram; }
QT_END_NAMESPACE

class nonogram : public QMainWindow
{
    Q_OBJECT

public:
    nonogram(QWidget *parent = nullptr);
    ~nonogram();

private:
    Ui::nonogram *ui;
};
#endif // NONOGRAM_H
