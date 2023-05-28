#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(size());

    ui->pushButton->setStyleSheet("* {background-color : rgb(255,160,0)}");

    setWindowTitle("Hashmap");
    const QIcon hashIcon("D:/hash.png");
    setWindowIcon(hashIcon);
    ui->widget->yAxis->setRange(0,15000);
    ui->widget->xAxis->setRange(0,64);
    ui->widget_2->yAxis->setRange(0,15000);
    ui->widget_2->xAxis->setRange(0,2048);
    ui->widget->yAxis->setLabel("Время поиска (нс)");
    ui->widget->xAxis->setLabel("Количество элементов");
    ui->widget_2->yAxis->setLabel("Время поиска (нс)");
    ui->widget_2->xAxis->setLabel("Количество элементов");

    effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(QColor(255,160,0));
    effect->setBlurRadius(50);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setEnabled(true);
    ui->widget->setGraphicsEffect(effect);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QCPGraph* graph16 = ui->widget->addGraph();
    QCPGraph* graph64 = ui->widget_2->addGraph();

    ui->widget->clearGraphs();
    ui->widget->clearItems();
    ui->widget->legend->setVisible(true);
    QVector<double> vect1;
    QVector<double> vect2;

    std::vector <int> keys16;
    std::vector <int> keys64;
    std::vector <int> keys128;
    std::vector <int> keys2048;

    hashTable table16(16);
    hashTable table64(64);
    hashTable table128(128);
    hashTable table2048(2048);

    for(int i=0;i<16;i++)
    {
        int key = rand()%1136718;
        keys16.push_back(key);
        QString value = "16";
        table16.insert(key,value);
    }

    for(int i=0;i<64;i++)
    {
        int key = rand()%1136718;
        keys64.push_back(key);
        QString value = "64";
        table64.insert(key,value);
    }

    for(int i=0;i<128;i++)
    {
        int key = rand()%1136718;
        keys128.push_back(key);
        QString value = "128";
        table128.insert(key,value);
    }

    for(int i=0;i<2048;i++)
    {
        int key = rand()%1136718;
        keys2048.push_back(key);
        QString value = "2048";
        table2048.insert(key,value);
    }

    QElapsedTimer timer;
    for(int i=0;i<16;i++)
    {
        timer.start();
        int j=0;
        table16.search(keys16[j++]);
        vect1.push_back(i+1);
        vect2.push_back(timer.nsecsElapsed());
    }
        graph16->setName("Таблица с 16 элементами");
        graph16->setLineStyle(QCPGraph::lsImpulse);
        graph16->setData(vect1,vect2);
        graph16->setPen(QPen(QColor(255,160,0)));
        ui->widget->replot();
//    ui->widget->addGraph();
//    ui->widget->graph(0)->setName("Таблица с 16 элементами");
//    ui->widget->graph(0)->setLineStyle(QCPGraph::lsImpulse);
//    ui->widget->graph(0)->setData(vect1,vect2);
//    ui->widget->graph(0)->setPen(QPen(QColor(255,160,0)));

    vect1.clear();
    vect2.clear();
    for(int i=0;i<64;i++)
    {
        timer.start();
        int j=0;
        table64.search(keys64[j++]);
        vect1.push_back(i+1);
        vect2.push_back(timer.nsecsElapsed());
    }
//    ui->widget->addGraph();
//    ui->widget->graph(1)->setName("Таблица с 64 элементами");
//    ui->widget->graph(1)->setLineStyle(QCPGraph::lsImpulse);
//    ui->widget->graph(1)->setData(vect1,vect2);
//    ui->widget->graph(1)->setPen(QPen(QColor(123,104,238)));

    graph64->setName("Таблица с 64 элементами");
    graph64->setLineStyle(QCPGraph::lsImpulse);
    graph64->setData(vect1,vect2);
    graph64->setPen(QPen(QColor(123,104,238)));
    ui->widget_2->replot();

    vect1.clear();
    vect2.clear();
    for(int i=0;i<128;i++)
    {
        timer.start();
        int j=0;
        table128.search(keys128[j++]);
        vect1.push_back(i+1);
        vect2.push_back(timer.nsecsElapsed());
    }
//    ui->widget_2->addGraph();
//    ui->widget_2->graph(0)->setName("Таблица с 128 элементами");
//    ui->widget_2->graph(0)->setLineStyle(QCPGraph::lsImpulse);
//    ui->widget_2->graph(0)->setData(vect1,vect2);
//    ui->widget_2->graph(0)->setPen(QPen(QColor(60,170,60)));

    vect1.clear();
    vect2.clear();
    for(int i=0;i<2048;i++)
    {
        timer.start();
        int j=0;
        table2048.search(keys2048[j++]);
        vect1.push_back(i+1);
        vect2.push_back(timer.nsecsElapsed());
    }
//    ui->widget_2->addGraph();
//    ui->widget_2->graph(1)->setName("Таблица с 2048 элементами");
//    ui->widget_2->graph(1)->setLineStyle(QCPGraph::lsImpulse);
//    ui->widget_2->graph(1)->setData(vect1,vect2);
//    ui->widget_2->graph(1)->setPen(QPen(QColor(43,207,238)));

    qDebug()<<vect1.size()<<vect2.size();
    for(int i =0;i<vect1.size();i++)
    {
        qDebug()<<vect1[i]<<" "<<vect2[i];
    }

    ui->widget->replot();
}

