#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QMessageBox>
#include <QRegularExpression>
#include <QGraphicsDropShadowEffect>
#include <QCompleter>
#include "deque.h"

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

    void on_pushButton_clicked();

    void print();

private:
    Ui::MainWindow *ui;
    Deque<int> intDeq;
    Deque<QString> stringDeq;
    QGraphicsDropShadowEffect* effect;
};
#endif // MAINWINDOW_H
