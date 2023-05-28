#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "reader.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

extern QString filename2;
extern Reader* ourLibrary;
extern int K;

thirdwindow::thirdwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdwindow)
{
    ui->setupUi(this);
}

thirdwindow::~thirdwindow()
{
    delete ui;
}

void thirdwindow::on_pushButton_2_clicked() //добавление в файл читателей
{
    QString user_id=ui->lineEdit_6->text();
    QString FIO=ui->lineEdit_8->text();
    QString adress=ui->lineEdit_9->text();
    QString phonenumber=ui->lineEdit_10->text();

    QFile file(filename2);
    file.open(QIODevice::Append);

    bool flag=true;
    for(int i=0;i<user_id.size();i++)
    {
        QChar ch=user_id[i];
        if(!ch.isDigit() || i>4)
        {
            flag=false;
            break;
        }
    }

    for(int i=1;i<phonenumber.size();i++)
    {
        QChar ch=phonenumber[i];
        if(!ch.isDigit() || i>10)
        {
            flag=false;
            break;
        }
    }

    if(!user_id.isEmpty() && !FIO.isEmpty() && !adress.isEmpty() && !phonenumber.isEmpty() && flag)
    {
    K++;
    Reader* newData = new Reader[K];
    for(int i=0;i<K-1;i++)
    {
        newData[i]=ourLibrary[i];
    }
    delete [] ourLibrary;
    ourLibrary=newData;
    ourLibrary[K-1].set_reader_id(user_id.toShort());
    ourLibrary[K-1].set_FIO(FIO);
    ourLibrary[K-1].set_adress(adress);
    ourLibrary[K-1].set_phonenumber(phonenumber);

    QTextStream text(&file);
    text<<user_id<<","<<FIO<<","<<adress<<","<<phonenumber<<"\n";
    file.close();
    hide();
    }
    else if (!flag)
    {
        QMessageBox::warning(this,tr("Error"),tr("В поле 'код читателя' и 'домашний телефон' должны содержаться только цифры,не больше четырех"));
    }
    else
    {
        QMessageBox::warning(this,tr("Error"),("Одно или несколько полей не заполнены!"));
    }
}

