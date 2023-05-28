#include "editwindow.h"
#include "ui_editwindow.h"
#include "myClass.h"
#include "reader.h"

extern Library* database;
extern int id;

editWindow::editWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editWindow)
{
    ui->setupUi(this);
}

editWindow::~editWindow()
{
    delete ui;
}

void editWindow::on_comboBox_currentIndexChanged(int index)
{
   QString newData="aboba";
   database[id].correct_info(index,newData);
}

