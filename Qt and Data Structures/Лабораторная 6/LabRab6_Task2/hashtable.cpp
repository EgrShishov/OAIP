#include "hashtable.h"

hashTable::hashTable(size_t size) : hash_table_size(size), elements_amount(0)
{
    hash_table = new Node[size];
    for(int i=0;i<hash_table_size;i++)
    {
        hash_table[i].filed=false;
        hash_table[i].key=0;
        hash_table[i].value="";
    }
}

hashTable::~hashTable()
{
    delete[] hash_table;
}

void hashTable::insert(int key, QString value)
{
    int hash = hash_function(key);
    bool key_exist = false;
    size_t i = 0;

    while(hash_table[hash].filed==true && hash_table[hash].key==key)
    {
        hash = liner_function(key,i++);
    }

    if(hash_table[hash].key==key)
    {
        hash_table[hash].value=value;
        hash_table[hash].filed = true;
    }
    else
    {
        hash_table[hash].key = key;
        hash_table[hash].value = value;
        hash_table[hash].filed = true;
        elements_amount++;
    }
}

QString hashTable::search(int key)
{
    int hash = hash_function(key);
    size_t  i  = 0;

    while(hash_table[hash].filed==true)
    {
        if(hash_table[hash].key==key)
        {
            return hash_table[hash].value;
        }
        hash = liner_function(hash,i++);
    }
    return "not_found";
}

void hashTable::remove(int key)
{
    int hash = hash_function(key);
    bool is_exist = false;
    size_t i = 0;

    while(hash_table[hash].filed==true)
    {
        if(hash_table[hash].key==key)
        {
            hash_table[hash].filed = false;
            break;
        }
        hash = liner_function(hash,i++);
    }

}

double hashTable::percent_of_load()
{
    return ((double)elements_amount/hash_table_size * 100);
}

void hashTable::rehash()
{

}

int hashTable::hash_function(int key)
{
    return key % hash_table_size;
}

int hashTable::liner_function(int key,int i)
{
    return (hash_function(key) + i) % hash_table_size;
}

QString hashTable::print()
{
    QString ans  = "Hash table :\n-------------------------------------\n";
    for(int i=0;i<hash_table_size;i++)
    {
       if(hash_table[i].filed==true)
       ans+="(" + QString::number(hash_table[i].key) + ", " + hash_table[i].value + ")" + '\n';
    }
    return ans;
}

bool hashTable::empty()
{
    return elements_amount==0;
}
