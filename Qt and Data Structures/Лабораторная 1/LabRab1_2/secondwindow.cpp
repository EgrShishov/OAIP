#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "myClass.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

extern QString filename1;
extern int N;
extern Library* database;

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_pushButton_clicked()
{
    QString id=ui->lineEdit->text();
    QString author=ui->lineEdit_2->text();
    QString bookname=ui->lineEdit_3->text();
    QString year=ui->lineEdit_4->text();
    QString language=ui->lineEdit_5->text();

    bool errorFlag=false;
    bool flag=true;
    bool flag2=true;
    for(int i=0;i<id.size();i++)
    {
        if(id[i]==',')
        {
            errorFlag=true;
            break;
        }
    }


    for(int i=0;i<author.size();i++)
    {
        if(author[i]==',')
        {
            errorFlag=true;
            break;
        }
    }

    for(int i=0;i<bookname.size();i++)
    {
        if(bookname[i]==',')
        {
            errorFlag=true;
            break;
        }
    }

    for(int i=0;i<year.size();i++)
    {
        if(year[i]==',' || !year[i].isDigit())
        {
            errorFlag=true;
            break;
        }
    }

    for(int i=0;i<language.size();i++)
    {
        if(language[i]==',')
        {
            errorFlag=true;
            break;
        }
    }


    for(int i=0;i<id.size();i++)
    {
        QChar ch=id[i];
        if(!ch.isDigit() || id.size()>4)
        {
            flag=false;
            break;
        }
    }

    for(int i=0;i<year.size();i++)
    {
        QChar ch=year[i];
        if(!ch.isDigit() || year.size()>4)
        {
            flag2=false;
            break;
        }
    }

    if(!id.isEmpty() && !author.isEmpty() && !bookname.isEmpty() && !year.isEmpty() && !language.isEmpty() && !errorFlag && flag && flag2)
    {

    QFile file(filename1);
    file.open(QIODevice::Append);

    N++;
    Library* newData = new Library[N];
    for(int i=0;i<N-1;i++)
    {
        newData[i]=database[i];
    }
    delete [] database;
    database=newData;
    database[N-1].set_id(id.toShort());
    database[N-1].set_bookname(bookname);
    database[N-1].set_language(language);
    database[N-1].set_surname(author);
    database[N-1].set_year(year.toShort());

    QTextStream text(&file);
    text<<id<<","<<author<<","<<bookname<<","<<year<<","<<language<<"\n";
    file.close();
    hide();
    }
    else if (!flag || !flag2)
    {
        QMessageBox::warning(this,tr("Error"),tr("В поле 'Код книги' и 'Год издания' должны содержаться только цифры и не больше четырех"));
    } else if(errorFlag)
    {
        QMessageBox::warning(this,tr("Error"),tr("В полях не должно быть запятых!"));
    }
    else
    {
        QMessageBox::warning(this,tr("Error"),tr("Одно или несколько из полей не заполнено"));
    }

}

