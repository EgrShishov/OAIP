#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pair.h"
#include "vector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    int n,m;
    pair <Vector<int>,Vector<pair<int,double>>> Pair;
    Vector < pair<Vector<int>,Vector<pair<int,double>>> > matrix;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
