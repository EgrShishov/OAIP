#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Rectangle.h"
#include <QWidget>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1000,700);
    this->setWindowTitle("Самосвал");
    this->setWindowIcon(QIcon("D:\\Лабораторные работы по ОАиП\\2-ой семестр\\Лабораторная 0\\full_BOt33YYd"));

    scene=new QGraphicsScene;
    //timerMove=new QTimer(this);
    scene->setSceneRect(0, 0, 600, 600);
    rectangle=new class Rectangle();
    truck = new class Truck();

    ui->graphicsView->setScene(scene);

    scene->addItem(truck);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete truck;
    delete rectangle;
    delete scene;
}


void MainWindow::on_pushButton_clicked()
{
    if(truck->x() >= 280)
       {

           //truck->kuzov_off();

           truck->setPos(-280, truck->y());
       }
    truck->moveRight();
    scene->update();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(truck->x() <= -280)
       {

           //truck->kuzov_off();

           truck->setPos(280, truck->y());
       }
    truck->moveLeft();
    scene->update();
}


void MainWindow::on_pushButton_4_clicked()
{
    if(truck->y() >= 280)
       {

           //truck->kuzov_off();

           truck->setPos(truck->x(), -280);
       }
    truck->moveDown();
    scene->update();
}


void MainWindow::on_pushButton_3_clicked()
{
    if(truck->y() <= -280)
       {

           //truck->kuzov_off();

           truck->setPos(truck->x(), 280);
       }
    truck->moveUp();
    scene->update();
}


void MainWindow::on_pushButton_5_clicked() //опустить
{
  truck->kuzov_off();
  scene->update();
}


void MainWindow::on_pushButton_6_clicked() //поднять
{
    truck->kuzov_on();
    scene->update();
}

