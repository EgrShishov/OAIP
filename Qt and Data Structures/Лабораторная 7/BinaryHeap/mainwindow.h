#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QStringList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QGraphicsDropShadowEffect>
#include <QCompleter>
#include "forward_list.h"
#include "list_heap.h"
#include "heap.h"

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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsDropShadowEffect* effect;
    list_heap<int> myHeap;
    heap<int> intHeap;
};
#endif // MAINWINDOW_H
