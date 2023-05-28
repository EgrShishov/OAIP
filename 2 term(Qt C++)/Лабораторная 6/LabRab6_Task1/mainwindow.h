#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QGraphicsDropShadowEffect>
#include <QStandardItem>
#include <QTreeView>
#include <QTimer>
#include <QCompleter>
#include <QPropertyAnimation>
#include "dialog.h"
#include "search_tree.h"

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

    void on_pushButton_2_clicked();

public slots:
    void recieve_data(std::vector<std::pair<int,QString>>);

    void set_off();

private:
    Ui::MainWindow *ui;
    search_tree<QString> tree;
    Node<QString>* root = nullptr;
    std::vector<std::pair<int,QString>> array;
    QGraphicsDropShadowEffect* effect;
    QGraphicsDropShadowEffect* effect2;
    Dialog* newDlg;
    QTimer* timer;
};
#endif // MAINWINDOW_H
