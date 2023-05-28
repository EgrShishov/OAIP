#include "dialog.h"
#include "ui_dialog.h"

int amount=0;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

bool closed = false;
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{

}


void Dialog::on_buttonBox_rejected()
{
    closed = true;
    close();
}

void Dialog::accept()
{
    int choice = -1;
    QString text = ui->lineEdit->text();
    if(ui->radioButton->isChecked())
        choice = 0;
    if(ui->radioButton_2->isChecked())
        choice = 1;

    switch (choice)
    {
    case 0:
        ui->lineEdit->setText("Введите дату постановки на учет");
        break;
    case 1:
        ui->lineEdit->setText("Введите фамилию покупателя");
        break;
    default:
        break;
    }
}
