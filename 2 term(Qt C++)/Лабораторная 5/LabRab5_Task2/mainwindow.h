#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deque.h"
#include <QCompleter>
#include <QStringList>
#include <QGraphicsDropShadowEffect>
#include <QRegularExpression>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void print();

private slots:
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
    Deque<int> deq;
    QGraphicsDropShadowEffect* effect;
};
#endif // MAINWINDOW_H
