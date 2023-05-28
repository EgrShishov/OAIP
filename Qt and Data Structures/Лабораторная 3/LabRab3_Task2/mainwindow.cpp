#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QPixmap pixmap("D:/matrix.jpg");
    //ui->label_3->setPixmap(pixmap);
    //ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 4px;"
          //                                      "  border-style: solid; "
            //                                    "border-color: light green;}"));
    //ui->textEdit_2->setStyleSheet(QString("QTextEdit {border-width: 4px;"
      //                                          "  border-style: solid; "
        //                                        "border-color: light green;}"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    m = ui->spinBox->value();
    n = ui->spinBox_2->value();

    Pair.first.clear();
    Pair.second.clear();
    matrix.clear();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            Pair.first.push_back(1);
            Pair.second.push_back(makePair(i+j+1,double((i+j)*4/3)));
        }
       matrix.push_back(Pair);

    }

    QString matrix1 = "" ,matrix2 = "";

    qDebug()<<"first";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
        matrix1+=QString::number(matrix[i].first[j])+", ";
        }
        matrix1+="\n";
    }

    ui->textEdit->setText(matrix1);

    qDebug()<<"second";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            matrix2+=QString::number(matrix[i].second[j].first) + " && "+QString::number(matrix[i].second[j].second)+", ";

        }
        matrix2+="\n";
    }

    ui->textEdit_2->setText(matrix2);
}

