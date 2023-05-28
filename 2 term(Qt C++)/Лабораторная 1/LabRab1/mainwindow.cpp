#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDataStream>
#include <QDateTime>
#include <QTableWidget>
#include <QTableWidgetItem>

QString filename="";
QString currDate=QDate::currentDate().toString();
int search_id=0;

bool checkingFile(QString filename)
{
    bool error = true;

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox* msg = new QMessageBox();
        msg->setParent(0);
        msg->setWindowTitle("Ошибка");
        msg->setIcon(QMessageBox::Warning);
        msg->setText("Файл невозможно открыть");
        msg->show();
        error=false;
        file.close();
        return error;
    }
    else{
        QTextStream text(&file);
        while(!text.atEnd())
        {
            QString tmp = text.readLine();
            int _day=(tmp.section('.',0,-3).toInt());
            int _month=(tmp.section('.',1,1).toInt());
            int _year=(tmp.section('.',2,2).toInt());
            QDate temp(_year,_month,_day);

            if(!temp.isValid())
            {
                QMessageBox* msg = new QMessageBox();
                msg->setParent(0);
                msg->setWindowTitle("Ошибка");
                msg->setIcon(QMessageBox::Warning);
                msg->setText("Файл содержит ошибки или не соответствует ожиданиям");
                msg->show();
                error=false;
                file.close();
                return error;
            }

        }
    }
    file.close();

    return error;

}

QString checking(QString b,int k)
{
    QString ans,a;
    QString K=QString::number(k);
    if (k>=0) {
            if (k==1 || k%100==1) {
                a=(" день");
            }
            else if(k>=2 && k<=4) {
                a=(" дня");
          } else if (k>=5 && k<=20 || k==0 || k%100==11) {
                a=(" дней");
          } else if (k%10==1) {
                a=(" день");
          } else if (k%10==2 || k%10==3 || k%10==4) {
                a=(" дня");
          } else if (k%10==5 || k%10==6 || k%10==7 || k%10==8 || k%10==9 || k%10==0) {
               a=(" дней");
          }
        }

    ans+=b;
    ans+=K;
    ans+=a;
    return ans;
}

bool checkInput(QString a)
{
    QString day,month,year; bool flag=true;

    day=a.section('.',0,-3);
    month=a.section('.',1,1);
    year=a.section('.',2,2);

    QDate data(year.toInt(),month.toInt(),day.toInt());

    if(data.isValid())
    {
        flag=true;
    } else
    {
        flag=false;
    }

    return flag;
}

class Date
{
public:

    Date NextDay()
    {
        Date newDay;

        int day=this->get_day();
        int month=this->get_month();
        int year=this->get_year();

        QDate day1(year,month,day);
        day1=day1.addDays(1);
        newDay.set_day(day1.day());
        newDay.set_month(day1.month());
        newDay.set_year(day1.year());

        return newDay;
    }
    Date PreviousDay()
    {
        Date newDay;

        int day=this->get_day();
        int month=this->get_month();
        int year=this->get_year();

        QDate day1(year,month,day);
        day1=day1.addDays(-1);
        newDay.set_day(day1.day());
        newDay.set_month(day1.month());
        newDay.set_year(day1.year());

        return newDay;

    }
    static bool IsLeap(int year)
    {
       //int year=this->get_year();
        return QDate::isLeapYear(year);
    }
    short WeekNumber()
    {
        int day=this->get_day();
        int month=this->get_month();
        int year=this->get_year();
        QDate ourDate(year,month,day);
        return ourDate.weekNumber();
    }
    static int DaysTillYourBirthday(Date bithdaydate)
    {
        //int currDay=(currDate.section('.',0,-3).toInt());
        //int currMonth=(currDate.section('.',1,1).toInt());
        //int currYear=(currDate.section('.',2,2).toInt());
        //QDate curr=(currYear,currDay,currMonth);

        QDate curr(QDate::currentDate());

        int currDayBith=(bithdaydate.get_day());
        int currMonthBith=(bithdaydate.get_month());
        QDate currBith(2023,currMonthBith,currDayBith);

        int daysBetween=0;
        daysBetween=curr.daysTo(currBith);

        return daysBetween;
    }
    static int Duration(Date date)
    {
        int day=date.get_day();
        int month=date.get_month();
        int year=date.get_year();

        QDate currdate=QDate::currentDate();

        int duration=0;

        QDate datee(year,month,day);

        duration=currdate.daysTo(datee);
        return duration;
    }
    void set_day(int day1){this->day=day1;}
    void set_month(int month1){this->month=month1;}
    void set_year(int year1){this->year=year1;}
    int get_day() {return day;}
    int get_month() {return month;}
    int get_year() {return year;}
private:
    int day;
    int month;
    int year;
};

int N=0;
Date* ourdata = NULL;

Date bithdaydate;
QString bithdaydate1;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //qDebug()<<MainWindow::size();
    setFixedSize(1258,514);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //дата рождения
{
   QString day,year,month;
   if(checkInput(bithdaydate1=ui->lineEdit_3->text()))
   {

       if((bithdaydate1=ui->lineEdit_3->text()).isEmpty())
       {
           QMessageBox::warning(this,tr("Ошибка"),"Введеные поля не должны быть пустыми");
           return;
       }

   day=bithdaydate1.section('.',0,-3);
   month=bithdaydate1.section('.',1,1);
   year=bithdaydate1.section('.',2,2);
   QDate data(year.toInt(),month.toInt(),day.toInt());

   bithdaydate.set_day(day.toInt());
   bithdaydate.set_month(month.toInt());
   bithdaydate.set_year(year.toInt());

   int ANS = Date::DaysTillYourBirthday(bithdaydate);
   if(ANS<0)
   {
       ANS=data.daysInYear()-abs(ANS);
   }
   QString ans = QString::number(ANS);
   QString a("До вашего дня рождения осталось ");
   QString b=checking(a,ANS);

   QMessageBox::information(this, tr("День рождения"), b);
   } else
   {
   QMessageBox::warning(this,tr("Ошибка"),tr("Введенной даты не существует!"));
   return;
   }
}


void MainWindow::on_pushButton_2_clicked() //изменение даты в файле
{
    if(filename=="")
    {
    QMessageBox::warning(this,tr("Ошибка"),tr("Пожалуйста,откройте сначала файл"));
    return;
    } else
    {
    QFile file(filename);
    //ui->lineEdit_6->setText("Введите старую дату");
    QString number1 = (ui->lineEdit_7->text());
    int number=0;
    if(number1.size()>10)
    {
        QMessageBox::warning(this,tr("Ошибка"),tr("Не верное число"));
        return;
    }
    else if(number1.toInt()>N)
    {
        QMessageBox::warning(this,tr("Ошибка"),tr("Не найдено"));
        return;
    }
    else
    {
        number=number1.toInt();
    }
    //ui->lineEdit_6->setText("Введите новую дату");
    QString newinfo = ui->lineEdit_6->text();
    if(newinfo.isEmpty())
    {
        QMessageBox::warning(this,tr("Ошибка"),tr("Поля не должны быть пустыми"));
    }
    file.open(QIODevice::WriteOnly|QIODevice::ReadOnly);

    QString day,month,year;
    day=newinfo.section('.',0,-3);
    month=newinfo.section('.',1,1);
    year=newinfo.section('.',2,2);

    QDate data(year.toInt(),month.toInt(),day.toInt());

    if(data.isValid())
    {

    QString add=data.toString("dd.MM.yyyy");

    QTextStream text(&file);
    int pos=0,pos1=0; QString aboba;
    int count=0;

    ourdata[number-1].set_day(newinfo.section('.',0,-3).toInt());
    ourdata[number-1].set_month(newinfo.section('.',1,1).toInt());
    ourdata[number-1].set_year(newinfo.section('.',2,2).toInt());

    while(!text.atEnd())
    {
          pos=text.pos();
//        aboba=text.readLine();
//        if(aboba==search)
//        {
//            pos1=pos;
//        }

        aboba=text.readLine();
        count++;
        if(count==number)
        {
            pos1=pos;
        }
    }

    text.seek(pos1);
    text<<add;
    file.close();
    ui->statusbar->showMessage("Информация успешно изменена!");
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(add);
    ui->tableWidget->setItem(number-1,0,item);
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Такой даты не существует");
        return;
    }
    }
}


void MainWindow::on_pushButton_3_clicked() //добавление в файл
{
    QFile file(filename);

    if(!file.open(QIODevice::Append))
    {
        QMessageBox::warning(this,tr("Открытие файла"),tr("Пожалуйста,откройте сначала файл"));
        return;
    }

    if(checkingFile(filename))
    {
    QTextStream writeStream(&file);
    QString newrecord = ui->lineEdit->text();
    if(newrecord.isEmpty())
    {
        QMessageBox::warning(this,tr("Ошибка"),"Введеные поля не должны быть пустыми");
        return;
    }
    QString day,month,year;

    QString format("dd,mm,yyyy");

    day=newrecord.section('.',0,-3);
    month=newrecord.section('.',1,1);
    year=newrecord.section('.',2,2);

    QDate aboba(year.toInt(),month.toInt(),day.toInt());
    QString add=aboba.toString("dd.MM.yyyy");

    if(aboba.isValid()==false)
    {
        QMessageBox::warning(this,tr("Ошибка"),tr("Введите корректную дату!"));
    } else if(newrecord.isEmpty())
    {
        QMessageBox::warning(this,tr("Ошибка"),tr("Нужно ввести дату!"));
    } else
    {
    writeStream<<add<<"\n";
    ui->statusbar->showMessage("Дата успешно добавлена!");
    QTableWidgetItem* item = new QTableWidgetItem();
    item->setText(add);
    item->setFlags(Qt::ItemIsEditable);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(N,0,item);
    ui->statusbar->showMessage("Информация успешно добавлена!");
    N++;
    Date* newData = new Date[N];
    for(int i=0;i<N-1;i++)
    {
        newData[i]=ourdata[i];
    }
    delete [] ourdata;
    ourdata=newData;
    ourdata[N-1].set_day(day.toInt());
    ourdata[N-1].set_month(month.toInt());
    ourdata[N-1].set_year(year.toInt());
    }
    file.close();
    } else
    {
        ui->tableWidget->clear();
        QStringList labels;
        labels << "Даты" << "Следуюший день" << "Предыдущий день " << "Разница" << "Номер недели" << "Високосный?";
        ui->tableWidget->setHorizontalHeaderLabels(labels);
        ui->tableWidget->setRowCount(0);
        filename="";
    }

    qDebug()<<filename;
}


void MainWindow::on_pushButton_4_clicked() //високосность года
{
    if(filename=="")
    {
        QMessageBox::warning(this,tr("Ошибка"),tr("Для начала откройте файл с датами"));
        return;
    } else
    {
    for(int i=0;i<N;i++)
    {
        int year=ourdata[i].get_year();

   QTableWidgetItem* item = new QTableWidgetItem();
   //ui->lineEdit_2->setText(year1);
   if(Date::IsLeap(year))
   {
       item->setText("Високосный");
      //ui->lineEdit_2->setText("Високосный");
   } else
   {
       item->setText("Не високосный");
       //ui->lineEdit_2->setText("Не вискосный");

   }
   ui->tableWidget->setItem(i,5,item);
   item->setFlags(Qt::ItemIsEditable);
    }
    }
}


void MainWindow::on_action_3_triggered()
{

}


void MainWindow::on_action_2_triggered() //выход из приложения
{
    QApplication::quit();
}


void MainWindow::on_action_triggered() //окно открытия файла
{
    ui->tableWidget->setRowCount(0);
    filename = QFileDialog::getOpenFileName(this,tr("Откройте файл"),"D://","Text File (*.txt)");

    QFile file(filename);

    if(checkingFile(filename))
    {
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("Ошибка открытия!"),tr("Не получилось открыть файл"));
    } else ui->statusbar->showMessage("Файл успешно открыт!");

    bool ok;
    QString day2="",month2="",year2="";
    int day1,month1,year1;
    int i=0;

    QTextStream text(&file);
    while(!text.atEnd())
    {
        QString data = text.readLine();
        ++N;
    }

    file.close();

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    ourdata=new Date[N];
    while(!text.atEnd())
    {
        QString data = text.readLine();

        day2=data.section('.',0,-3);
        month2=data.section('.',1,1);
        year2=data.section('.',2,2);

        day1=day2.toInt(&ok,10);
        month1=month2.toInt(&ok,10);
        year1=year2.toInt(&ok,10);

        ourdata[i].set_day(day1);
        ourdata[i].set_month(month1);
        ourdata[i].set_year(year1);

        ui->textBrowser->setText(data);
        QTableWidgetItem *text = new QTableWidgetItem();
        text->setText(data);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i,0,text);
        text->setFlags(Qt::ItemIsEditable);
        i++;

    }

    //QTextStream in(&file);

    //while(!in.atEnd())
    //{
    //    QString text;
    //    text=in.readAll();
    //    ui->textBrowser->setText(text);
    //}
    file.close();
    }

    for(int i=0;i<N;i++)
    {
        int day,month,year;
        day=ourdata[i].get_day();
        month=ourdata[i].get_month();
        year=ourdata[i].get_year();

        QString a (" дня/дней");

        QDate data1(year,month,day);
        for(int j=i+1;j<=i+1;j++)
        {
            day=ourdata[j].get_day();
            month=ourdata[j].get_month();
            year=ourdata[j].get_year();
            QDate data2(year,month,day);
            int dif=data1.daysTo(data2);

            QString text=QString::number(std::abs(dif));
            text+=a;

            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(text);
            item->setFlags(Qt::ItemIsEditable);
            ui->tableWidget->setItem(i,3,item);
        }

    }
}


void MainWindow::on_pushButton_5_clicked() //следующий день
{
    if(filename=="")
    {
        QMessageBox::warning(this,tr("Ошибка"),tr("Для начала откройте файл с датами"));
        return;
    } else
    {
    for (int i=0;i<N;i++)
    {
        Date info=ourdata[i].NextDay();

        QString day1=QString::number(info.get_day());
        QString month1=QString::number(info.get_month());
        QString year1=QString::number(info.get_year());

        QString format("dd.MM.yyyy");
        QDate tmp(year1.toInt(),month1.toInt(),day1.toInt());


        //QString text=day1+'.'+month1+'.'+year1;
        QString text=tmp.toString(format);
        ui->textBrowser->setText(text);
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(text);
        item->setFlags(Qt::ItemIsEditable);
        ui->tableWidget->setItem(i,1,item);
    }
    }
}


void MainWindow::on_pushButton_6_clicked() //предыдущий день
{
    if(filename=="")
    {
        QMessageBox::warning(this,tr("Ошибка"),tr("Для начала откройте файл с датами"));
        return;
    } else
    {
    for (int i=0;i<N;i++)
    {
        Date info=ourdata[i].PreviousDay();

        QString day1=QString::number(info.get_day());
        QString month1=QString::number(info.get_month());
        QString year1=QString::number(info.get_year());

        QString format("dd.MM.yyyy");
        QDate tmp(year1.toInt(),month1.toInt(),day1.toInt());


        //QString text=day1+'.'+month1+'.'+year1;
        QString text=tmp.toString(format);
        ui->textBrowser->setText(text);
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(text);
        item->setFlags(Qt::ItemIsEditable);
        ui->tableWidget->setItem(i,2,item);
    }
    }
}


void MainWindow::on_pushButton_7_clicked() //разница между днями
{

    QString data,day,year,month;
    data=ui->lineEdit_4->text();

    if(data.isEmpty())
    {
        QMessageBox::warning(this,tr("Ошибка"),"Введеные поля не должны быть пустыми");
        return;
    }

    Date date;
    day=data.section('.',0,-3);
    month=data.section('.',1,1);
    year=data.section('.',2,2);

    date.set_day(day.toInt());
    date.set_month(month.toInt());
    date.set_year(year.toInt());

    QDate tmp(year.toInt(),month.toInt(),day.toInt());

    if(tmp.isValid())
    {
    int ANS = std::abs(Date::Duration(date));
    QString ans = QString::number(ANS);
    QString a("Разница между двумя датами составляет ");
    QString b=checking(a,ANS);

    a+=ans;
    a+=b;

    QMessageBox::information(this,tr("Info"),b);
    } else
    {
        QMessageBox::warning(this,tr("Ошибка"),"Введенной даты не существует");
    }

}


void MainWindow::on_pushButton_8_clicked() //номер недели
{
    if(filename=="")
    {
        QMessageBox::warning(this,tr("Ошибка"),tr("Для начала откройте файл с датами"));
        return;
    } else
    {

    for(int i=0;i<N;i++)
    {
    QString text = QString::number(ourdata[i].WeekNumber());
    //ui->lineEdit_5->setText(text);

    QTableWidgetItem* item = new QTableWidgetItem();
    item->setText(text);
    item->setFlags(Qt::ItemIsEditable);
    ui->tableWidget->setItem(i,4,item);
    }
    }
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    QString da=item->text();
    int day=da.section('.',0,-3).toInt();
    int month=da.section('.',1,1).toInt();
    int year=da.section('.',2,2).toInt();

    Date info;
    info.set_day(day);
    info.set_month(month);
    info.set_year(year);

    int i=0;
    for(i;i<N;i++)
    {
        if(ourdata[i].get_day()==info.get_day() && ourdata[i].get_month()==info.get_month() && ourdata[i].get_year()==info.get_year())
        {
            ui->statusbar->showMessage(QString::number(++i));
            ui->statusbar->showMessage(da);
        }
    }

}


void MainWindow::on_pushButton_9_clicked()
{

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    QStringList labels;
    labels << "Даты" << "Следуюший день" << "Предыдущий день " << "Разница" << "Номер недели" << "Високосный?";
    ui->tableWidget->setHorizontalHeaderLabels(labels);

    QFile file(filename);
    if(filename.isEmpty())
    {
        QMessageBox::warning(this,("Ошибка"),"Для начала откройте файл");
        return;
    }

    if(checkingFile(filename))
    {
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("Ошибка открытия!"),tr("Не получилось открыть файл"));
        return;
    } else ui->statusbar->showMessage("Файл успешно открыт!");

    bool ok;
    QString day2="",month2="",year2="";
    int day1,month1,year1;
    int i=0;

    QTextStream text(&file);
    while(!text.atEnd())
    {
        QString data = text.readLine();
        ++N;
    }

    file.close();

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    ourdata=new Date[N];
    while(!text.atEnd())
    {
        QString data = text.readLine();

        day2=data.section('.',0,-3);
        month2=data.section('.',1,1);
        year2=data.section('.',2,2);

        day1=day2.toInt(&ok,10);
        month1=month2.toInt(&ok,10);
        year1=year2.toInt(&ok,10);

        ourdata[i].set_day(day1);
        ourdata[i].set_month(month1);
        ourdata[i].set_year(year1);

        ui->textBrowser->setText(data);
        QTableWidgetItem *text = new QTableWidgetItem();
        text->setText(data);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i,0,text);
        text->setFlags(Qt::ItemIsEditable);
        i++;

    }

    //QTextStream in(&file);

    //while(!in.atEnd())
    //{
    //    QString text;
    //    text=in.readAll();
    //    ui->textBrowser->setText(text);
    //}
    file.close();
    } else
    {
        filename="";
    }

    for(int i=0;i<N;i++)
    {
        int day,month,year;
        day=ourdata[i].get_day();
        month=ourdata[i].get_month();
        year=ourdata[i].get_year();

        QString a (" дня/дней");

        QDate data1(year,month,day);
        for(int j=i+1;j<=i+1;j++)
        {
            day=ourdata[j].get_day();
            month=ourdata[j].get_month();
            year=ourdata[j].get_year();
            QDate data2(year,month,day);
            int dif=data1.daysTo(data2);

            QString text=QString::number(dif);
            text+=a;

            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(text);
            item->setFlags(Qt::ItemIsEditable);
            ui->tableWidget->setItem(i,3,item);
        }

    }
}
