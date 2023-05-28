#include "shop.h"

shop::shop(){}


shop::~shop(){}


void shop::setNumber(int number)
{
    this->number=number;
}


void shop::setFIO(QString FIO)
{
    this->FIO=FIO;
}


void shop::setAdress(QString adress)
{
    this->adress=adress;
}


void shop::setDate(QDate date)
{
    this->date=date;
}


int shop::getNumber()
{
    return number;
}


QString shop::getFIO()
{
    return FIO;
}


QString shop::getAdress()
{
    return adress;
}


QDate shop::getDate()
{
    return date;
}
