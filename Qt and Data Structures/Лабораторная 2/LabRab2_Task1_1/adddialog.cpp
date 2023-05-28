#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
    ui->textEdit->setToolTip("Введите необходимые данные");
    //connect(ui->buttonBox, SIGNAL(clicked()), this, SLOT(accept()));

//    okButton = new QPushButton("OK",this);
//    okButton->setDefault(true);
//    QObject::connect(okButton,SIGNAL(clicked(bool)),this,SLOT(accept()));

}

addDialog::~addDialog()
{
    delete ui;
}

extern bool somethingChanged;
extern bool isSaved;

void addDialog::on_buttonBox_rejected()
{
hide();
}

void addDialog::on_buttonBox_accepted()
{
    //    int amount = ui->textEdit->document()->lineCount();
    //    //qDebug()<<amount;
    //    QString info="";
    //    int commaCount=0;

    //    for(int i=0;i<amount;i++)
    //    {
    //        commaCount=0;
    //        QString tmp="";
    //        tmp=ui->textEdit->document()->findBlockByLineNumber(i).text();

    //        for(int i=0;i<tmp.size();i++)
    //        {
    //            if(tmp[i]==',') commaCount++;
    //        }

    //        if(commaCount!=2)
    //            error1=true;

    //        if(!tmp.isEmpty())
    //        {
    //            info+=tmp+"\n";
    //        }
    //    }

    //    info.resize(info.size()-1);



    //    if(!info.isEmpty() && !error1)
    //    {
    //    emit sendData(info);
    //    somethingChanged=true;
    //    ui->textEdit->clear();
    //    }
    //    else
    //    {
    //        QMessageBox::warning(this,("Ошибка"),("Введите что-то для приличия"));
    //        return;
    //    }
}

void addDialog::accept()
{
        somethingChanged=false;
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
            QString num,amount;
            tmp=ui->textEdit->document()->findBlockByLineNumber(i).text();

            if(tmp.isEmpty()) continue;
            for(int i=0;i<tmp.size();i++)
            {
                if(tmp[i]==',') commaCount++;
            }

            if(commaCount!=2)
                error1=true;

            num=tmp.section(',',0,-3);
            amount=tmp.section(',',2,2);

            if(num.size()>5)
            {
                error3=true;
                break;
            }
            for(int j=0;j<num.size();j++)
            {
                QChar ch = num[j];
                if(!ch.isDigit())
                    error2=true;
            }

            if(amount.size()>5)
            {
                error3=true;
                break;
            }
            for(int j=0;j<amount.size();j++)
            {
                QChar ch = amount[j];
                if(!ch.isDigit())
                    error2=true;
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
        //isSaved=false;
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
        QMessageBox::warning(this,"Ошибка","Целочисленное значение слишком большое или содержит ошибки");
        return;
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Напишите что-нибудь для приличия!");
        return;
    }
}
