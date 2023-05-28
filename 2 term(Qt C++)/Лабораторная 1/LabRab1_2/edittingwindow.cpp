#include "edittingwindow.h"
#include "ui_edittingwindow.h"
#include "myClass.h"
#include "reader.h"
#include <QChar>

extern Library* database;
extern Reader* ourLibrary;
extern QString filename1,filename2;
extern int N;
extern int M;
extern int K;
extern int _id;
extern int choice2;
int choice_radio=0;

bool isBook=false;
bool isReader=false;
QString newData;
int index1=0;

edittingWindow::edittingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edittingWindow)
{
    ui->setupUi(this);

    if(choice2==0)
    {
        ui->comboBox->clear();
        isBook=true;
        QStringList list_choice;
        list_choice<<"Идентификатор"<<"ФИО автора"<<"Название книги"<<"Год издания"<<"Язык";

        ui->comboBox->addItems(list_choice);
    }
    else if(choice2==1)
    {
        ui->comboBox->clear();
        isReader=true;
        QStringList list_choice;
        list_choice<<"Идентификатор"<<"ФИО читателя"<<"Домашний адрес"<<"Контактный телефон";

        ui->comboBox->addItems(list_choice);
    }

}

edittingWindow::~edittingWindow()
{
    delete ui;
}

void edittingWindow::on_comboBox_currentIndexChanged(int index)
{
   index1=index;
}


void edittingWindow::on_buttonBox_accepted()
{

    newData=ui->lineEdit->text();

    if(!newData.isEmpty())
    {
    int index=0,index2;

    for(int i=0;i<N;i++)
    {
        if(database[i].get_id()==_id)
        {
            index=i;
        }
    }

    for(int j=0;j<K;j++)
    {
        if(ourLibrary[j].get_reader_id()==_id)
        {
            index2=j;
        }
    }

    if(isBook)
    {
      database[index].correct_info(index1,newData);
    }
    else if(isReader)
    {
      ourLibrary[index2].correct_file(index1,newData);
    }

    close();
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Поле не должно быть пустым!");
    }
}


void edittingWindow::on_buttonBox_rejected()
{
    close();
}


//void edittingWindow::on_radioButton_clicked() //books
//{
//    ui->comboBox->clear();
//    isBook=true;
//    QStringList list_choice;
//    list_choice<<"Идентификатор"<<"ФИО автора"<<"Название книги"<<"Год издания"<<"Язык";

//    ui->comboBox->addItems(list_choice);
//}


//void edittingWindow::on_radioButton_2_clicked() //readers
//{
//    ui->comboBox->clear();
//    isReader=true;
//    QStringList list_choice;
//    list_choice<<"Идентификатор"<<"ФИО читателя"<<"Домашний адрес"<<"Контактный телефон";

//    ui->comboBox->addItems(list_choice);
//}


void edittingWindow::on_radioButton_clicked()
{
    choice_radio=0;
}


void edittingWindow::on_radioButton_2_clicked()
{
    choice_radio=1;
}


void edittingWindow::on_pushButton_clicked()
{
    if(isBook)
    {
        for(int i=0;i<N;i++)
        {
            if(database[i].get_id()==_id)
            {
                qDebug()<<i;
                database[i].delete_info(i); //не работает
                ui->lineEdit->setText("Запись удалена");
            }
        }
    }
    else if(isReader)
    {
    //ourLibrary[_id-1].delete_from_file(_id);
        for(int i=0;i<K;i++)
        {
            if(ourLibrary[i].get_reader_id()==_id)
            {
                qDebug()<<i;
                ourLibrary[i].delete_from_file(i); //не работает
                ui->lineEdit->setText("Запись удалена");
            }
        }
    }
    close();
}

