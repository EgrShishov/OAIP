#include "doubleclick.h"
#include "ui_doubleclick.h"

doubleClick::doubleClick(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::doubleClick)
{
    ui->setupUi(this);
    ui->pushButton->setToolTip("Товар будет снят с производства и удален из списка");
    ui->pushButton->setStyleSheet("* { background-color: rgb(133,196,120) }");

    ui->lineEdit->clear();
}

int index2=0;
int indexOfComboBox=0;
extern list List;
extern bool somethingChanged;
extern bool isSaved;
extern QStringList _list;

doubleClick::~doubleClick()
{
    delete ui;
}


void doubleClick::on_buttonBox_rejected()
{
    hide();
}


void doubleClick::on_buttonBox_accepted()
{
//    bool error = false;
//    QString newData=ui->lineEdit->text();

//    if(!newData.isEmpty())
//    {
//    switch(indexOfComboBox)
//    {
//    case 0:
//        List[index2]->data.setNumber(newData.toInt());
//        somethingChanged=true;
//        break;
//    case 1:
//        List[index2]->data.setName(newData);
//        somethingChanged=true;
//        break;
//    case 2:
//        List[index2]->data.setAmount(newData.toInt());
//        somethingChanged=true;
//        break;
//    }

//    error=false;
//    }

//    else
//    {
//        QMessageBox::warning(this,("Ошибка"),("Поля не должны быть пустыми!"));
//        error=true;
//    }
}


void doubleClick::on_pushButton_clicked() //снять с производства(удалить)
{
    List.erase(index2);
    qDebug()<<"deleting";
        qDebug()<<_list[3*index2];
    _list.removeAt(3*index2);
        qDebug()<<_list[3*index2];
    _list.removeAt(3*index2);
        qDebug()<<_list[3*index2];
    _list.removeAt(3*index2);

    somethingChanged=true;
    emit sendData("aboba");
    //isSaved=false;
    close();
}


void doubleClick::recieveIndex(int index)
{
    index2=index;
}

void doubleClick::on_comboBox_currentIndexChanged(int index)
{
    indexOfComboBox=index;
}

bool checkInt(QString Int)
{
    int count=0;
    for(int i=0;i<Int.size();i++)
    {
        QChar ch = Int[i];
        count++;
        if(!ch.isDigit())
        {
            return true;
        }

        if(Int.size()>5)
        {
            return true;
        }
    }
}


void doubleClick::accept()
{
    somethingChanged=false;
    QString newData=ui->lineEdit->text();
    bool error = false;

    if(indexOfComboBox==0)
    {
        if(checkInt(newData))
            error = true;
    } else if(indexOfComboBox==2)
    {
        if(checkInt(newData))
            error=true;
    }
    if(!newData.isEmpty() && !error)
    {

        switch(indexOfComboBox)
        {
        case 0:
            if(!checkInt(newData))
            {
            List[index2]->data.setNumber(newData.toInt());
            qDebug()<<_list[index2*3];
            _list.insert(index2*3,newData);
            _list.insert(index2*3+1,List[index2]->data.getName());
            _list.insert(index2*3+2,QString::number(List[index2]->data.getAmount()));
            somethingChanged=true;
            emit sendData("aboba");
            } else return;
            break;
        case 1:
            List[index2]->data.setName(newData);
            _list.insert(index2*3+1,newData);
            somethingChanged=true;
            emit sendData("aboba");
            break;
        case 2:
            if(!error)
            {
            List[index2]->data.setAmount(newData.toInt());
            _list.insert(index2*3+2,newData);
            somethingChanged=true;
            emit sendData("aboba");
            } else return;
            break;
        }
        ui->lineEdit->clear();
        QDialog::accept();
    }
    else if(newData.size()>5 && indexOfComboBox==0)
    {
     QMessageBox::warning(this,"Ошибка","Целочисленное значение слишком большое или содержит ошибки");
     return;
    }
    else if(newData.size()>5 && indexOfComboBox==2)
    {

     QMessageBox::warning(this,"Ошибка","Целочисленное значение слишком большое или содержит ошибки");
     return;
    }
    else if(error)
    {
        QMessageBox::warning(this,"Ошибка","Целочисленные поля должны содержать только цифры");
    }
    else
    {
        QMessageBox::warning(this,("Ошибка"),("Поля не должны быть пустыми!"));
        return;
    }
}
