#ifndef MYCLASS_H
#define MYCLASS_H

#include <QString>
#include <QListWidgetItem>

class Library
{
public:
    short get_id();
    QString get_surname();
    QString get_bookname();
    short get_year();
    QString get_language();

    void set_id(short new_id);
    void set_surname(QString new_surname);
    void set_bookname(QString new_bookname);
    void set_year(short new_year);
    void set_language(QString new_language);

    Library* load_from_file(QString filename);
    void add_info();
    void correct_info(int key,QString newData);
    void delete_info(int key);
    void sort_info(Library* database,int key);

private:
   short id;
   QString surname;
   QString bookname;
   short year;
   QString language;
};

#endif // MYCLASS_H

