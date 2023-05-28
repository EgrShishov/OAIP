#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QCompleter>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QGraphicsDropShadowEffect>
#include "unordered_map.h"

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
    Ui::MainWindow *ui;
    QGraphicsDropShadowEffect* effect;
    struct hasher
    {
        std::size_t operator()(const std::string str) const
        {
            qDebug()<<"hash1";
           std::size_t hash = 0;
           for (char c : str) {
             hash = hash * 31 + c;
           }
           return hash;
         }
    };

    struct hasher_2
    {
        std::size_t operator()(const std::string key) const
        {
           unsigned int hash = 5381;
           for(int i=0;i<key.size();i++)
           {
               hash = ((hash<<5) + hash) + (unsigned int)key[i];
           }
           return hash;
        }
    };

    struct hasher_3
    {
        std::size_t operator()(int key) const
        {
            size_t hash = 0;
            const size_t prime = 31;
            hash = hash ^ (key >> 24);
            hash = hash ^ (key >> 16);
            hash = hash ^ (key >> 8);
            hash = hash ^ key;
            hash = hash * prime;
            return hash;
        }
    };

    unordered_map<std::string,int, hasher> map;
};
#endif // MAINWINDOW_H
