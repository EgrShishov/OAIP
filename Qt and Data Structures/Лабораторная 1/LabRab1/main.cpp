#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QFile>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QTextStream>
#include <QDate>
#include <QByteArray>
#include <QTableWidgetItem>

void Write(QString filename)
{
    QFile in(filename);
    if(!in.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Cant open file";
        return ;
    }

    QTextStream out (&in);
    out << "Hello world";
    in.close();
}

void Read(QString filename)
{
    QFile out(filename);
    if(!out.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Cant open file";
        return ;
    }

    QTextStream in(&out);
    QString text = in.readAll();
    qDebug() << text;

    out.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
