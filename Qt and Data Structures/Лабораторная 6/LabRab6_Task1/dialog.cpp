#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setFixedSize(size());
    ui->buttonBox->setStyleSheet("* {background-color : rgb(255,160,0)}");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    std::vector<std::pair<int,QString>> vect;
    int rows = ui->tableWidget->rowCount();
    for(int i = 0; i < rows;i++)
    {
        if(!ui->tableWidget->item(i,0)->text().isEmpty() && !ui->tableWidget->item(0,1)->text().isEmpty())
        vect.push_back(std::make_pair(ui->tableWidget->item(i,0)->text().toInt(),ui->tableWidget->item(i,1)->text()));
    }
    if(vect.empty()) {
        QMessageBox::warning(this,"Ошибка","Вы не заполнили поле");
        QDialog::reject();

    }
    emit send_data(vect);
    qDebug()<<"data sended";
    ui->tableWidget->clear();
}


void Dialog::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(arg1);
}
