#ifndef NONOGRAM_H
#define NONOGRAM_H

#include <QMainWindow>
#include <QWidget>
#include <QToolButton>
#include <QGridLayout>
#include <QSignalMapper>
#include <cmath>
#include <ctime>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class nonogram; }
QT_END_NAMESPACE

class nonogram : public QMainWindow
{
    Q_OBJECT

public:
    nonogram(QWidget *parent = nullptr);
    QToolButton* buttons[49]; // making this fixed 7x7
    std::vector<int> solution;
    ~nonogram();

private:
    Ui::nonogram *ui;
    std::vector<int> random_block(int n);
    std::vector<int> create_solution();
//    std::vector<std::vector<int> > create_clues(std::vector<std::vector<int> > solution);
//    int find_vert_max(int n, std::vector<std::vector<int> > clues);

private slots:
    void color(int i); // color block when clicked

};
#endif // NONOGRAM_H
