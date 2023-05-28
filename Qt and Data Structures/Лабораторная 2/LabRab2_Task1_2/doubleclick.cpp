#include "doubleclick.h"
#include "ui_doubleclick.h"

doubleClick::doubleClick(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::doubleClick)
{
    ui->setupUi(this);
    ui->pushButton->setToolTip("Заказ будет снят со списка и исполнен");
    ui->pushButton->setStyleSheet("* { background-color: rgb(255,255,115) }");
}

int index2=0;
int indexOfComboBox=0;
extern list List;
extern bool somethingChanged;

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
}


void doubleClick::on_pushButton_clicked() //снять с производства(удалить)
{
    List.erase(index2);
    somethingChanged=true;
    emit update("aboba");
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
            break;
            return true;
        }
        if(count>5)
        {
            return true;
        }
    }
}

void doubleClick::accept()
{
    QString newData=ui->lineEdit->text();
    bool error = false;

    if(indexOfComboBox==0)
    {
        if(checkInt(newData))
            error = true;
    }
    if(!newData.isEmpty() && !error)
    {

        switch(indexOfComboBox)
        {
        case 0:
        {
            if(!error)
            {
            List.getAt(index2).setNumber(newData.toInt());
            somethingChanged=true;
            emit update("aboba");
            } else return;
            break;
        }
        case 1:
            List.getAt(index2).setFIO(newData);
            somethingChanged=true;
            emit update("aboba");
            break;
        case 2:
            List.getAt(index2).setAdress(newData);
            somethingChanged=true;
            emit update("aboba");
            break;
        case 3:
            QDate date;
            date = QDate::fromString(newData,"dd.MM.yyyy");
            if(date.isValid())
            {
            List.getAt(index2).setDate(date);
            } else
            {
                QMessageBox::warning(this,"Ошибка","Введите корректную дату");
                return;
            }
            somethingChanged=true;
            emit update("aboba");
            break;
        }
        ui->lineEdit->clear();
        QDialog::accept();
    }
    else if(newData.size()>5 && indexOfComboBox==0)
    {
        QMessageBox::warning(this,"Ошибка","Целочисленное значение слишком большое");
    }
    else if(error)
    {
        QMessageBox::warning(this,"Ошибка","Численные поля должны содержать только цифры");
    }
    else
    {
        QMessageBox::warning(this,("Ошибка"),("Поля не должны быть пустыми!"));
        return;
    }
}
