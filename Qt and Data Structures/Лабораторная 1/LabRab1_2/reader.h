#ifndef READER_H
#define READER_H

#include <QString>

class Reader
{
public:
    short get_reader_id();
    QString get_FIO();
    QString get_adress();
    QString get_phonenumber();

    void set_reader_id(short reader_id);
    void set_FIO(QString FIO);
    void set_adress(QString adress);
    void set_phonenumber(QString phonenumber);

    Reader* load_from_file(QString filename2);

    void delete_from_file(int key);
    void correct_file(int key,QString newData);

private:
    short reader_id;
    QString FIO;
    QString adress;
    QString phone_number;
};


#endif // READER_H
