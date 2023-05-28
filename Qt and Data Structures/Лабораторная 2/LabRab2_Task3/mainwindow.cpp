#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("* { background-color: rgb(255,125,100) }");

    setFixedSize(1104,592);
    add = new AddDialog();
    add->setModal(true);
    add->setFixedSize(503,193);
    connect(ui->pushButton,SIGNAL(clicked()),add,SLOT(show()));
    connect(add,SIGNAL(sendData(QString,double,double,double,double,double)),this,SLOT(recieveData(QString,double ,double ,double ,double ,double )));
//    connect(add, SIGNAL(sendData(QString)),this, SLOT(recieveData(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString filename = "D:\\rpn.txt";
    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    QTextStream text(&file);
    ReversePolishNotation rpn;
    int rowCount = 0;
    QString expression;
    double a=0,b=0,c=0,d=0,e=0;

    while(!text.atEnd())
    {
        text>>expression;
        text>>a>>b>>c>>d>>e;
        ui->tableWidget->setRowCount(rowCount+1);
        qDebug()<<a<<b<<c<<d<<e;
        ui->tableWidget->setItem(rowCount,0,new QTableWidgetItem(expression));
        //QString rpn_ = rpn.convertionToRPN(expression);
        rpn = ReversePolishNotation(expression + '\n');
        QString ans=rpn.convertionToRPN();
        double _ans=rpn.calculation(ans,a,b,c,d,e);
        //qDebug()<<ans;
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(ans));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(QString::number(a)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(QString::number(b)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,new QTableWidgetItem(QString::number(c)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,new QTableWidgetItem(QString::number(d)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,new QTableWidgetItem(QString::number(e)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,new QTableWidgetItem(QString::number(_ans)));
        rowCount++;
    }
    file.close();
}

void MainWindow::recieveData(QString expr, double a,double b,double c,double d,double e)
{
    ReversePolishNotation rpn;
    rpn = ReversePolishNotation(expr + '\n');
    QString ans=rpn.convertionToRPN();
    double _ans=rpn.calculation(ans,a,b,c,d,e);
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(expr));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(ans));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(QString::number(a)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(QString::number(b)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,new QTableWidgetItem(QString::number(c)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,new QTableWidgetItem(QString::number(d)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,new QTableWidgetItem(QString::number(e)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,new QTableWidgetItem(QString::number(_ans)));
}
