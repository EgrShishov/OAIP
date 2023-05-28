#include "myClass.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
extern int N;
extern int _id;
extern QString filename1;
extern Library* database;

short Library::get_id(){ return id;}

QString Library::get_bookname(){return bookname;}

QString Library::get_language(){return language;}

QString Library::get_surname(){return surname;}

short Library::get_year(){return year;}

void Library::set_id(short new_id){this->id=new_id;}

void Library::set_bookname(QString new_bookname){this->bookname=new_bookname;}

void Library::set_language(QString new_language){this->language=new_language;}

void Library::set_surname(QString new_surname){this->surname=new_surname;}

void Library::set_year(short new_year){this->year=new_year;}

Library* Library::load_from_file(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    int i=0;
    QTextStream text(&file);
    while(!text.atEnd())
    {
        QString data = text.readLine();
        ++N;
    }

    Library* database=new Library[N];
    text.seek(0);

    short id,year; QString bookname,language,surname;
    while(!text.atEnd())
    {
        QString data = text.readLine();


        id=data.section(',',0,-5).toShort();
        surname=data.section(',',1,1);
        bookname=data.section(',',2,2);
        year=data.section(',',3,3).toShort();
        language=data.section(',',4,4);

        database[i].set_id(id);
        database[i].set_surname(surname);
        database[i].set_bookname(bookname);
        database[i].set_year(year);
        database[i].set_language(language);
        i++;

    }

    return database;

}

void Library::sort_info(Library* database,int key)
{
    Library temp;

    if(key==2)
    {
        Library temp;
          int i = 0;
          for(int j = 1;j<N;j++)
          {
            temp = database[j];
            i = j-1;
            while(i>=0 && database[i].get_year()>temp.get_year())
            {
              database[i+1] = database[i];
              i = i-1;
              database[i+1]=temp;
            }
          }
    }
    else if (key==1)
    {

        Library temp;
          int i = 0;
          for(int j = 1;j<N;j++)
          {
            temp = database[j];
            i = j-1;
            while(i>=0 && database[i].get_bookname()>temp.get_bookname())
            {
              database[i+1] = database[i];
              i = i-1;
              database[i+1]=temp;
            }
          }

    }
    else if(key==0)
    {

        Library temp;
          int i = 0;
          for(int j = 1;j<N;j++)
          {
            temp = database[j];
            i = j-1;
            while(i>=0 && database[i].get_surname()>temp.get_surname())
            {
              database[i+1] = database[i];
              i = i-1;
              database[i+1]=temp;
            }
          }

    }

}

void Library::correct_info(int key,QString newData)
{

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
        this->id=newData.toShort();
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
        for(int i=0;i<newData.size();i++)
        {
            QChar ch=newData[i];
            if(ch==',')
            {
                errorCatch=true;
                break;
            }


        }

        if(!errorCatch)
        this->surname=newData;
        break;
    }
    case 2: //bookName
    {
        for(int i=0;i<newData.size();i++)
        {
            QChar ch=newData[i];
            if(ch!=',')
            {
                errorCatch=true;
                break;
            }

        }

        if(!errorCatch)
        this->bookname=newData;
        break;
    }
    case 3: //year
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
        this->year=newData.toShort();
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
    case 4: //language
    {
        for(int i=0;i<newData.size();i++)
        {
            QChar ch=newData[i];
            if(ch!=',')
            {
                errorCatch=true;
                break;
            }

        }
        //if(!errorCatch)
        this->language=newData;
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


        if(errorCatch)
        {
            QMessageBox* msg = new QMessageBox();
            msg->setParent(0);
            msg->setIcon(QMessageBox::Warning);
            msg->setWindowTitle("Error");
            msg->setText("Поля должны содержать только цифры");
            msg->show();
        }
    }


    QFile file(filename1);
    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QTextStream correct(&file);
    int i=0,pos=0;

    for(int i=0;i<N;i++)
    {
        QString tmp = QString::number(database[i].get_id())+","+database[i].get_surname()+","+database[i].get_bookname()+","+QString::number(database[i].get_year())+","+database[i].get_language() + "\n";
        correct<<tmp;
    }

//    while(!correct.atEnd())
//    {
//        pos=correct.pos();
//        QString data = correct.readLine();
//        ++i;
//        if(i==_id) break;
//    }

//    correct.seek(pos);
//    QString data=correct.readLine();
//    QString tmp=correct.readAll();
//    correct.seek(pos);
//    while(!correct.atEnd())
//    {
//        correct<<" ";
//    }

//    correct.seek(pos);
//    Data=QString::number(this->get_id())+","+this->get_surname()+","+this->get_bookname()+","+QString::number(this->get_year())+","+this->get_language();
//    correct<<Data<<"\n";
//    correct<<tmp;

    file.close();
}

void Library::delete_info(int key)
{
    QFile file(filename1);
    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QTextStream text(&file);

    //std::swap(database[key-1],database[N-1]);

    Library* newData = new Library[N-1];

    for(int i=key;i<N-1;i++)
    {
        database[i]=database[i+1];
    }
    N--;

    for(int i=0;i<N;i++)
    {
        newData[i]=database[i];
    }

    delete[] database;
    database=newData;

    for(int i=0;i<N;i++)
    {
        QString newText = QString::number(database[i].get_id())+","+database[i].get_surname()+","+database[i].get_bookname()+","+QString::number(database[i].get_year())+","+database[i].get_language()+"\n";
        text<<newText;
    }

    file.close();
}
