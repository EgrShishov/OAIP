#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCompleter>
#include <QResizeEvent>
#include <QShortcut>
#include <QMessageBox>
#include <QCloseEvent>
#include "dialog.h"
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
    void on_pushButton_clicked();

    void print();

    void Print();

    void PrintInt();

    void on_pushButton_2_clicked();

    void slotShortcutCtrlI();

    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    Vector <double> myVect;
    Vector <std::string> stringVect;
    Vector <int> intVect;
    bool checkInput(QString input);
    QString varType;
    Dialog* dlg;
    QShortcut       *keyCtrlI;    // объект горячей клавиши F11
};
#endif // MAINWINDOW_H
