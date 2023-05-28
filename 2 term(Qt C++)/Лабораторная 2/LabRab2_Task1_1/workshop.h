#ifndef WORKSHOP_H
#define WORKSHOP_H
#include <QString>
class workshop
{
public:
    workshop();
    ~workshop();

    void setNumber(int number);
    void setName(QString name);
    void setAmount(int amount);

    int getNumber();
    QString getName();
    int getAmount();

    bool operator !=(workshop Data);

private:
    QString name;
    int amount;
    int workshopNumber;
};

#endif // WORKSHOP_H
