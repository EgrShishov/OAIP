#ifndef SHOP_H
#define SHOP_H

#include <QString>
#include <QDate>
class shop
{
public:
    shop();
    ~shop();

    void setNumber(int number);
    void setFIO(QString FIO);
    void setAdress(QString adress);
    void setDate(QDate date);

    int getNumber();
    QString getFIO();
    QString getAdress();
    QDate getDate();

private:
    int number = 0;
    QString FIO;
    QString adress;
    QDate date;
};

#endif // SHOP_H
