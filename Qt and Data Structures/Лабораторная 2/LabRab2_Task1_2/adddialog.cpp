#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
}

addDialog::~addDialog()
{
    delete ui;
}

extern bool somethingChanged;

void addDialog::on_buttonBox_rejected()
{
hide();
}

void addDialog::on_buttonBox_accepted()
{
}

void addDialog::accept()
{
        bool error1 = false;
        bool error2 = false;
        bool error3 = false;

        int amount = ui->textEdit->document()->lineCount();

        QString info="";
        int commaCount=0;

        for(int i=0;i<amount;i++)
        {
            commaCount=0;
            QString tmp="";
            QString num,stringDate;
            tmp=ui->textEdit->document()->findBlockByLineNumber(i).text();

            if(tmp.isEmpty()) continue;
            for(int i=0;i<tmp.size();i++)
            {
                if(tmp[i]==',') commaCount++;
            }

            if(commaCount!=3)
                error1=true;

            num=tmp.section(',',0,-4);
            stringDate=tmp.section(',',3,3);
            if(num.size()>5)
            {
                error3=true;
                break;
            }

            QDate date;
            date = QDate::fromString(stringDate,"dd.MM.yyyy");

            for(int j=0;j<num.size();j++)
            {
                QChar ch = num[j];
                if(!ch.isDigit())
                    error2=true;
            }

            if(!date.isValid())
            {
                QMessageBox::warning(this,"Ошибка","Введите корректную дату");
                error2=true;
                return;
            }

            if(!tmp.isEmpty())
            {
                info+=tmp+"\n";
            }
        }

        info.resize(info.size()-1);
        qDebug()<<error1;



    if(!info.isEmpty() && !error1 && !error2)
    {
        emit sendData(info);
        somethingChanged=true;
        ui->textEdit->clear();
        QDialog::accept();
    }
    else if(error1)
    {
        QMessageBox::warning(this,"Ошибка","Все строки не должны содержать лишней информации");
        return;
    }
    else if(error2)
    {
        QMessageBox::warning(this,"Ошибка","Цифры должны оставаться цифрами, символы не допускаются");
        return;
    }
    else if(error3)
    {
        QMessageBox::warning(this,"Ошибка","Целочисленное значение слишком большое");
        return;
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Напишите что-нибудь для приличия!");
        return;
    }
}
