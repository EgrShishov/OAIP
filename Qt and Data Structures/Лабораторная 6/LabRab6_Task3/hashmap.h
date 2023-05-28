#ifndef HASHMAP_H
#define HASHMAP_H

#include <QDebug>
#include <QString>
#include <iostream>
#include <stack>
#include "stack.h"
#define Stack std::stack
template <typename T>
struct Node{
    int key;
    T value;
    Node(int key,T value) : key(key), value(value){}
    Node() {}
};

template <typename T>
class HashMap
{
public:
    HashMap() : _size(1), elements_amount(0), hash_map(new Stack<Node<T>>[1]){}
    HashMap(int size) : _size(size) , elements_amount(0), hash_map(new Stack<Node<T>>[size]){}
    ~HashMap() { delete[] hash_map;}

    void insert(int key,T value);
    bool find(int key, T value);
    bool exist(int key);
    T get(int key);
    void remove(int key);
    double percent_of_load();
    void rehash();
    void resize();
    QString print_map();
    size_t size();

    Node<T>& operator[](int index);

protected:
    int hash_function(int key);

private:
    size_t _size;
    size_t elements_amount;
    Stack<Node<T>>* hash_map;
};

template <typename T>
void HashMap<T>::insert(int key, T value)
{
    if(percent_of_load()>=75) rehash();
    int hash = hash_function(key);
    bool value_exist = false;
    Stack<Node<T>> tmp = hash_map[hash];
    while(!tmp.empty())
    {
        if(tmp.top().value==value)
        {
            value_exist = true;
            break;
        }
        tmp.pop();
    }
    if(!value_exist)
    {
    Node<T> node(key,value);
    hash_map[hash].push(node);
    elements_amount++;
    } else qDebug()<<"value exist, not replaces";
    qDebug()<<elements_amount;
}

template <typename T>
bool HashMap<T>::find(int key,T value)
{
    int hash = hash_function(key);
    bool is_exist = false;

    Stack<Node<T>> tmp = hash_map[hash];
    qDebug()<<QString::number(tmp.size());

    while(!tmp.empty())
    {
        if(tmp.top().value == value && tmp.top().key == key)
        {
            is_exist = true;
            break;
        }
        tmp.pop();
    }

    if(!is_exist)
    {
        hash_map[hash].push(Node<T>(key,value));
    }

    return is_exist;
}

template<typename T>
bool HashMap<T>::exist(int key)
{
    int hash = hash_function(key);
    bool is_exist = false;

    Stack<Node<T>> tmp = hash_map[hash];

    while(!tmp.empty())
    {
        if(tmp.top().key == key )
        {
            is_exist = true;
            break;
        }
        tmp.pop();
    }

    return is_exist;
}

template<typename T>
T HashMap<T>::get(int key)
{
    int hash = hash_function(key);
    Stack<Node<T>> tmp = hash_map[hash];
    while(!tmp.empty())
    {
        if(tmp.top().key == key)
        {
            return tmp.top().value;
        }
        tmp.pop();
    }
    return T();
}

template <typename T>
void HashMap<T>::remove(int key)
{
    int hash = hash_function(key);
    Stack<Node<T>> tmp;
    bool key_exist = false;

    while(!hash_map[hash].empty())
    {
        if(hash_map[hash].top().key==key)
        {
            key_exist = true;
            hash_map[hash].pop();
            elements_amount--;
            qDebug()<<"value deleted";
            break;
        }
        tmp.push(hash_map[hash].top());
        hash_map[hash].pop();
    }

    while(!tmp.empty())
    {
        hash_map[hash].push(tmp.top());
        tmp.pop();
    }
}

template <typename T>
int HashMap<T>::hash_function(int key)
{
    return key % _size;
}

template <typename T>
double HashMap<T>::percent_of_load()
{
    return (double) elements_amount / size() * 100;
}

template <typename T>
void HashMap<T>::rehash() //seems to be correct
{
    size_t old_size = _size;
    size_t new_size = _size * 2;
    _size = new_size;
    Stack<Node<T>>* newArr = new Stack<Node<T>>[_size];
    for(int i=0;i<old_size;i++)
    {
        Stack<Node<T>> tmp;
        tmp = hash_map[i];
        while(!tmp.empty())
        {
            int hash = hash_function(tmp.top().key);
            qDebug()<<"hash"<<hash;
            newArr[hash].push(tmp.top());
            tmp.pop();
        }
    }

    delete [] hash_map;
    hash_map = newArr;
    qDebug()<<"table has rehashed";
}

template <typename T>
void HashMap<T>::resize()
{
    size_t old_size = _size;
    size_t new_size = _size * 2;
    _size = new_size;
    Stack<Node<T>>* newArr = new Stack<Node<T>>[new_size];
    for(int i = 0;i < old_size;i++)
    {
        newArr[i] = hash_map[i];
    }

    //delete[] hash_map;
    hash_map = newArr;
    qDebug()<<"table has been resized";
}

//specialisation to QString type
template<>
QString HashMap<QString>::print_map();

template <typename T>
QString HashMap<T>::print_map()
{
    qDebug()<<"hashtable size" << _size;

    QString ans;
    for(int i = 0;i<_size;i++)
    {
        if(!hash_map[i].empty())
        {
            Stack<Node<T>> tmp = hash_map[i];
            ans += "Стек # " + QString::number(i + 1) + " : ";
            while(!tmp.empty())
            {
                ans += "(" + QString::number(tmp.top().key) + " " + QString::number(tmp.top().value) + ")" + ", ";
                tmp.pop();
            }
            ans += '\n';
        }
    }
    return ans;
}

template <typename T>
size_t HashMap<T>::size()
{
    return _size;
}

template<typename T>
Node<T>& HashMap<T>::operator[](int index)
{
    if(index<_size && index>=0)
        return hash_map[index].top();
    else
        throw std::out_of_range("index out of range in operator[]");
}


//#7 Cоздать хеш-таблицу из случайных целых чисел и найти в ней номер
//стека, содержащего минимальное значение ключа

class solution : HashMap<int>
{
public:
    solution(){}

    short solve() //redo
    {
        for(int i = 0; i < ::abs(rand()%400+1); i++)
        {
            map.insert(rand()%1000,rand());
        }

        int min_key = INT_MAX;
        int stack_index = -1;

        for(int i = 0; i < 1000; i++)
        {
            if(map.exist(i) && i < min_key)
                min_key = i;
        }
        return min_key;
    }

    QString print()
    {
        return map.print_map();
    }

    HashMap<int> map;
};

#endif // HASHMAP_H
