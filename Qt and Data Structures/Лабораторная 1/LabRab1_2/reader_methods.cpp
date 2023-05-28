#include "reader.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

extern int K;
extern int _id;
extern QString filename2;
extern Reader* ourLibrary;

QString Reader::get_adress(){return adress;}

QString Reader::get_FIO(){return FIO;}

QString Reader::get_phonenumber(){return phone_number;}

short Reader::get_reader_id(){return reader_id;}

void Reader::set_adress(QString adress){this->adress=adress;}

void Reader::set_FIO(QString FIO){this->FIO=FIO;}

void Reader::set_phonenumber(QString phonenumber){this->phone_number=phonenumber;}

void Reader::set_reader_id(short reader_id){this->reader_id=reader_id;}

Reader* Reader::load_from_file(QString filename2)
{
    QFile file(filename2);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    int i=0;
    QTextStream text(&file);
    while(!text.atEnd())
    {
        QString data = text.readLine();
        K++;
    }

    Reader* database=new Reader[K];
    text.seek(0);

    short reader_id; QString FIO,adress,phonenumber;
    while(!text.atEnd())
    {
        QString data = text.readLine();

        reader_id=data.section(',',0,-4).toShort();
        FIO=data.section(',',1,1);
        adress=data.section(',',2,2);
        phonenumber=data.section(',',3,3);

        database[i].set_adress(adress);
        database[i].set_FIO(FIO);
        database[i].set_phonenumber(phonenumber);
        database[i].set_reader_id(reader_id);

        i++;

    }

    return database;

}

void Reader::delete_from_file(int key)
{
    QFile file(filename2);
    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QTextStream text(&file);
//    QString tmp,info; int pos=0,i=0;

//    while(!text.atEnd())
//    {
//        pos=text.pos();
//        tmp=text.readLine();
//        ++i;
//        if(key!=i) continue;
//        else
//        {
//            info=text.readAll();
//            break;
//        }

//    }
//    text.seek(pos);
//    text<<info;
//    file.close();


    Reader* newData = new Reader[K-1];

    for(int i=key;i<K-1;i++)
    {
        ourLibrary[i]=ourLibrary[i+1];
    }
    K--;

    for(int i=0;i<K;i++)
    {
        newData[i]=ourLibrary[i];
    }

    delete[] ourLibrary;
    ourLibrary=newData;

    for(int i=0;i<K;i++)
    {
        QString newText = QString::number(ourLibrary[i].get_reader_id())+","+ourLibrary[i].get_FIO()+","+ourLibrary[i].get_adress()+","+ourLibrary[i].get_phonenumber()+"\n";
        text<<newText;
    }

    file.close();
}

void Reader::correct_file(int key,QString newData)
{

//    QFile file(filename2);
//    file.open(QIODevice::WriteOnly|QIODevice::ReadOnly|QIODevice::Text);

//    QTextStream correct(&file);
//    int i=0,pos=0;
//    while(!correct.atEnd())
//    {
//        QString data = correct.readLine();
//        ++i;
//        if(i==_id-1) pos=correct.pos();
//    }
//    correct.seek(pos);

    QString Data;

    bool errorCatch=false;

    switch(key)
    {

    case 0: //id
    {

        for(int i=0;i<newData.size();i++)
        {
            QChar ch=newData[i];
            if(!ch.isDigit() || i>4)
            {
                errorCatch=true;
                break;
            }

        }
        if(!errorCatch)
        this->reader_id=newData.toShort();
        else
        {
            QMessageBox* msg = new QMessageBox();
            msg->setParent(0);
            msg->setIcon(QMessageBox::Warning);
            msg->setWindowTitle("Error");
            msg->setText("Поля должны содержать только цифры и не быть более 5-ти символов в длину");
            msg->show();
        }
        break;
    }
    case 1: //FIO
    {
        this->FIO=newData;
        break;
    }
    case 2: //adress
    {
        this->adress=newData;
        break;
    }
    case 3: //phone
    {
        for(int i=1;i<newData.size();i++)
        {
            QChar ch=newData[i];
            if(!ch.isDigit())
            {
                errorCatch=true;
                break;
            }

        }
        if(!errorCatch)
        this->phone_number=newData;
        else
        {
            QMessageBox* msg = new QMessageBox();
            msg->setParent(0);
            msg->setIcon(QMessageBox::Warning);
            msg->setWindowTitle("Error");
            msg->setText("Поля должны содержать только цифры");
            msg->show();
        }
        break;
        this->phone_number=newData;
        break;
    }
    default:
    {
        QMessageBox* msg = new QMessageBox;
        msg->setParent(0);
        msg->setIcon(QMessageBox::Warning);
        msg->setWindowTitle("Error");
        msg->setText("Ошибка");
        msg->show();
        break;
    }

    }

    QFile file(filename2);
    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QTextStream correct(&file);

    for(int i=0;i<K;i++)
    {
        QString tmp = QString::number(ourLibrary[i].get_reader_id())+","+ourLibrary[i].get_FIO()+","+ourLibrary[i].get_adress()+","+ourLibrary[i].get_phonenumber() + "\n";
        correct<<tmp;
    }

//    Data=QString::number(this->get_reader_id())+","+this->get_FIO()+","+this->get_adress()+","+this->get_phonenumber();
//    correct<<Data;

    file.close();
}
