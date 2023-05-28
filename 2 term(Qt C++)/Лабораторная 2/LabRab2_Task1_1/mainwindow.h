#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStringList>
#include <QCompleter>
#include <QFileSystemWatcher>
#include <QListWidgetItem>
#include <QCloseEvent>
#include <QModelIndex>
#include <QMessageBox>
#include "list.h"
#include "workshop.h"
#include "adddialog.h"
#include "doubleclick.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

void recieveData(QString str);

void showWarning(QString str);

void update(QString str);

private slots:
    void on_action_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_search_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_action_2_triggered();

    void on_save_triggered();

    void on_action_3_triggered();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void sort(list& List,int left,int right);

    //void fileChanged(const QString& name);

    void on_comboBox_activated(int index);

signals:
    void sendIndex(int index);

private:
    Ui::MainWindow *ui;
    QString filename="";
    addDialog* add;
    doubleClick* double_click;
    void closeEvent(QCloseEvent *event);
    void saveFile(QString filename);
    void updateTable();
    QFileSystemWatcher* watcher;
    QCompleter* completer;
};
#endif // MAINWINDOW_H
