#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "edittingwindow.h"
#include "secondwindow.h"
#include "thirdwindow.h"
#include "myClass.h"
#include "reader.h"
#include "dolg.h"
#include <QFileDialog>
#include <QCompleter>
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

private slots:
    void on_action_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_action_2_triggered();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_comboBox_4_activated(int index);

    void on_pushButton_10_clicked();

    void on_comboBox_5_currentIndexChanged(int index);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_comboBox_5_activated(int index);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_6_clicked();

    void on_action_3_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
