#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
   // for(int i=0;i<6;i++)
   // ui->tableWidget->setColumnWidth(i, 80);
    //ui->tableWidget->setColumnHidden(id_colum, true/false);
}

AddDialog::~AddDialog()
{
    delete ui;
}

extern bool divisionByZero;
bool checkExpr(QString expr)
{
    if(expr.isEmpty())
    {

    }
   bool error = false;
   for(int i=0;i<expr.size();i++)
   {
       QChar ch = expr[i];

       if (ch=='/' || ch=='+' || ch=='*' || ch=='-' || ch=='(' || ch==')')
       {
           qDebug()<<"case2";

       }
       else if(ch.isLetter())
       {
       if(ch.isUpper())
       {
           qDebug()<<"upper";
           error=true;
           break;
       }
       if(ch>'e' || ch<'a')
       {
           error=true;
           qDebug()<<"not a-e";
           break;
       }
           }
       else {
           error=true;
           break;
       }
   }

   return error;
}


void AddDialog::accept()
{
    QString expr = ui->lineEdit->text();
    ReversePolishNotation ab(expr);
    double a,b,c,d,e;
    bool error = false;
    qDebug()<<expr;
    if(ab.checkEnt(expr) && !divisionByZero)
    {
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Ошибка");
        msg->setText("Введенное выражение неккоректно,попробуйте еще раз");
        msg->setIcon(QMessageBox::Warning);
        msg->show();
        error=true;
        return;
    }
    if(divisionByZero)
    {
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Ошибка");
        msg->setText("Деление на ноль!");
        msg->setIcon(QMessageBox::Warning);
        msg->show();
        error=true;
        return;
    }


    if(!error)
    {
        a=ui->doubleSpinBox->value();
        b=ui->doubleSpinBox_2->value();
        c=ui->doubleSpinBox_3->value();
        d=ui->doubleSpinBox_4->value();
        e=ui->doubleSpinBox_5->value();
        emit sendData(expr,a,b,c,d,e);
        close();

    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Не все поля заполнены");
        return;
    }
}
