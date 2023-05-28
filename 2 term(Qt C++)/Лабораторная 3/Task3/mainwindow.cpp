#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(721,158);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Vector <double> a;
    Vector <double> b;

    QString input = ui->lineEdit->text();
    input+=' ';

    for(int i=0;i<input.size();i++)
    {
        if(!(input[i].isDigit() || input[i]==' '))
        {
            QMessageBox::warning(this,"eror","");
            return;
        }
    }

    QString text;

    int num = 0;
        for(int i=0;i<input.size();i++)
        {

                QString number="";
                if(input[i]==' ') continue;
                while(input[i]!=' ' && i+1!=input.size())
                {
                    number+=input[i];
                    i++;
                }
                a.push_back(number.toInt());
        }

        text+="vector a : ";
        for (int i = 0; i < a.size(); i++)
            text+= QString::number(a[i]) + ", ";
        text+="\n";

        int amount = a.size() / 3;
        for (int i = 0; i < amount * 3; i += 3)
        {
            a.sort(i,i+3);
            b.push_back(a.at(i + 1));
        }
        if (a.size() - amount * 3 == 2)
        {
            int tmp = a.at(a.size() - 1) + a.at(a.size() - 2);
            b.push_back(tmp/2);
        }
        if (a.size() - amount * 3 == 1)
        {
            int tmp = a.at(a.size() - 1);
            b.push_back(tmp);
        }
        text+="vector b : ";
        for (int i = 0; i < b.size(); i++)
            text+= QString::number(b[i]) + ", ";

        ui->textEdit->setText(text);
}

