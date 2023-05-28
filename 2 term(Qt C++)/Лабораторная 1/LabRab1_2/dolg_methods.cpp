#include "dolg.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDate>

extern int D;
extern int N;
extern int M;

void Dolg::set_user_id(short user_id)
{
    this->user_id=user_id;
}

void Dolg::set_book_id(short book_id)
{
    this->book_id=book_id;
}

void Dolg::set_date_of_giving(QString date_of_giving)
{
    this->date_of_giving=date_of_giving;
}

void Dolg::set_using_period(short using_period)
{
    this->using_period=using_period;
}

void Dolg::set_date_of_returning(QString date_of_returning)
{
    this->date_of_giving=date_of_returning;
}

short Dolg::get_user_id()
{
    return user_id;
}

short Dolg::get_book_id()
{
    return book_id;
}

QString Dolg::get_dat_of_giving()
{
    return date_of_giving;
}

short Dolg::get_using_period()
{
    return using_period;
}

QString Dolg::get_dat_returning()
{
    return date_of_returning;
}

Dolg* Dolg::load_from_file(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    int i=0;
    QTextStream text(&file);
    while(!text.atEnd())
    {
        QString data = text.readLine();
        ++D;
    }

    Dolg* ourData=new Dolg[D];
    text.seek(0);

    short reader_id,book_id,using_period; QString date_of_giving, date_of_returning;
    while(!text.atEnd())
    {
        QString data = text.readLine();

        reader_id=data.section(',',0,-5).toShort();
        book_id=data.section(',',1,1).toShort();
        date_of_giving=data.section(',',2,2);
        date_of_returning=data.section(',',3,3);
        using_period=data.section(',',4,4).toShort();

        ourData[i].set_user_id(reader_id);
        ourData[i].set_book_id(book_id);
        ourData[i].set_date_of_giving(date_of_giving);
        ourData[i].set_date_of_returning(date_of_returning);
        ourData[i].set_using_period(using_period);
        i++;

    }

    return ourData;
}

QString Dolg::createList(Library* database)
{

    QString ans="";
        for(int j=0;j<N;j++)
        {
            if(database[j].get_id()==this->get_book_id())
            {
                ans+=database[j].get_bookname();
            }
        }
    return ans;
}


QString Dolg::dolgList(Reader *database)
{
    QString ans="";
        for(int j=0;j<M;j++)
        {

            QString data=this->get_dat_of_giving();
            QString day,month,year;
            day=data.section('.',0,-3);
            month=data.section('.',1,1);
            year=data.section('.',2,2);
            QDate data1(year.toInt(),month.toInt(),day.toInt());

            QString info=this->get_dat_returning();
            day=info.section('.',0,-3);
            month=info.section('.',1,1);
            year=info.section('.',2,2);
            QDate data2(year.toInt(),month.toInt(),day.toInt());
            int duration=data1.daysTo(data2);

            if(duration > 10+this->get_using_period())
            {
                ans+=database[j].get_FIO();
                ans+='\n';
            }
        }
    return ans;
}
