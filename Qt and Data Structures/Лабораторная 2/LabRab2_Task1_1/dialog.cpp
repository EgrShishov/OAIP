#include "dialog.h"
#include "ui_dialog.h"

int amount=0;
dialog::dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
}

bool closed = false;
dialog::~dialog()
{
    delete ui;
}

void dialog::on_buttonBox_accepted()
{
//    QString text = ui->lineEdit->text();

//    amount = text.toInt();

//    close();
}


void dialog::on_buttonBox_rejected()
{
    closed = true;
    close();
}

void dialog::accept()
{
    QString text = ui->lineEdit->text();
    bool error = false;
    amount = text.toInt();

    for(int i=0;i<text.size();i++)
    {
        QChar ch = text[i];
        if(!ch.isDigit() || i>7)
        {
            error = true;
            break;
        }
    }
    if(text.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Введите количество");
        return;
    }
    else if(amount<0)
    {
        QMessageBox::warning(this,"Ошибка","Количество не должно быть отрицательным");
        return;
    }
    else if(amount>1000000)
    {
        QMessageBox::warning(this,"Ошибка","Слишком много!");
        return;
    }
    else if(error)
    {
        QMessageBox::warning(this,"Ошибка","В поле должны содержаться только цифры");
        return;
    }
    else
    {
        QDialog::accept();
    }

}
