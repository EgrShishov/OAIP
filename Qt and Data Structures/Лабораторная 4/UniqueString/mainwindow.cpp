#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    unique_ptr mama(new char[5]);
    unique_ptr papa(new char[5]);
    mama.get()[0]='\0';
    papa.get()[0]='\0';
    std::strcpy(mama.get(),"mama");
    std::strcpy(papa.get(),"papa");
    String::strcpy(mama,papa);
    qDebug()<<mama.get();
}

MainWindow::~MainWindow()
{
    delete ui;
}

