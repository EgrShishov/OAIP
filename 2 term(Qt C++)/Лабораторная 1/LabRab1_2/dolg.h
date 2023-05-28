#ifndef DOLG_H
#define DOLG_H

#include <QString>
#include "myClass.h"
#include "reader.h"

class Dolg{

public:
    void set_user_id(short user_id);
    void set_book_id(short book_id);
    void set_date_of_giving(QString date_of_giving);
    void set_using_period(short using_period);
    void set_date_of_returning(QString date_of_returning);

    short get_user_id();
    short get_book_id();
    QString get_dat_of_giving();
    short get_using_period();
    QString get_dat_returning();

    Dolg* load_from_file(QString filename);
    QString createList(Library* database);
    QString dolgList(Reader* database);

private:
    short user_id;
    short book_id;
    QString date_of_giving;
    short using_period;
    QString date_of_returning;
};

#endif // DOLG_H
