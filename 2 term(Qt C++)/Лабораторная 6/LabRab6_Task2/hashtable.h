#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QDebug>
#include <QString>

class hashTable
{
public:
    hashTable(size_t size);
    ~hashTable();

    void insert(int key,QString value);
    QString search(int key);
    void remove(int key);
    double percent_of_load();
    void rehash();
    int hash_function(int key);
    int liner_function(int key,int i);
    QString print();
    bool empty();

private:
    class Node
    {
    public:
        Node(){}
        Node(int key, QString value) : key(key), value(value) {}
        ~Node(){}
        int key;
        QString value;
        bool filed = false;
    };
    Node* hash_table;
    size_t hash_table_size = 0;
    size_t elements_amount = 0;
};

#endif // HASHTABLE_H
