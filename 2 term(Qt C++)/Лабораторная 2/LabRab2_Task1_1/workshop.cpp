#include "workshop.h"

workshop::workshop()
{

}

workshop::~workshop()
{

}

int workshop::getNumber()
{
return workshopNumber;
}

QString workshop::getName()
{
return name;
}

int workshop::getAmount()
{
return amount;
}

void workshop::setNumber(int number)
{
    this->workshopNumber=number;
}

void workshop::setName(QString name)
{
    this->name=name;
}

void workshop::setAmount(int amount)
{
    this->amount=amount;
}

bool workshop::operator !=(workshop Data)
{
    bool notEquale = false;

    if(this->getAmount()!=Data.getAmount())
        notEquale=true;

    if(this->getName()!=Data.getName())
        notEquale=true;

    if(this->getNumber()!=Data.getNumber())
        notEquale=true;

    return notEquale;
}
