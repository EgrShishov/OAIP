#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QGraphicsDropShadowEffect>
#include <QCompleter>

#include "set.h"
#include <set>

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

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    set<QString> mySet;
    std::set<QString> stdSet;
    QCompleter* completer = nullptr;
};
#endif // MAINWINDOW_H
