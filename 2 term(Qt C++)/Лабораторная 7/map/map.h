#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <QDebug>
#include <QString>
#include "rbtree.h"

template <typename KeyType, typename ValueType>
class map
{
public:
    map(){}
    ~map(){}

    void insert(KeyType key, ValueType value);
    void erase(KeyType key);
    ValueType find(KeyType key);
    bool contains(KeyType key);

    bool empty();
    size_t size();
    void clear();

    list_iterator<KeyType,ValueType> lbegin();
    list_iterator<KeyType,ValueType>  lend();
    iterator<KeyType,ValueType>  hbegin();
    iterator<KeyType,ValueType>  hend();
    void print_list(){_map.list_print();}

    void print(QString& ans)
    {
        _map.preorder_print(_map.get_root(),ans);
    }

    ValueType& operator[](KeyType key);
    ValueType operator[](KeyType key) const;


private:
    size_t _size = 0;
    size_t elements = 0;
    AVL<KeyType,ValueType> _map;
};


template<typename KeyType, typename ValueType>
void map<KeyType, ValueType>::insert(KeyType key, ValueType value)
{
    if(_map.contains(_map.get_root(),key))
    {
        _map.find(_map.get_root(),key)->data.second = value;
        qDebug()<<"value updated";
    }
    else
    {
    _map.insert(_map.get_root(),key,value);
    elements++;
    }
}

template<typename KeyType, typename ValueType>
void map<KeyType, ValueType>::erase(KeyType key)
{
    if(_map.contains(_map.get_root(),key))
    {
        _map.remove(_map.get_root(),key);
        elements--;
    }
}

template<typename KeyType, typename ValueType>
ValueType map<KeyType, ValueType>::find(KeyType key)
{
    if(_map.contains(_map.get_root(),key))
    {
        return _map.find(_map.get_root(),key)->data.second;
    }
    else return ValueType();
}

template<typename KeyType, typename ValueType>
bool map<KeyType, ValueType>::contains(KeyType key)
{
    return _map.contains(_map.get_root(),key);
}

template<typename KeyType, typename ValueType>
bool map<KeyType, ValueType>::empty()
{
    return elements == 0;
}

template<typename KeyType, typename ValueType>
size_t map<KeyType, ValueType>::size()
{
    return elements;
}

template<typename KeyType, typename ValueType>
void map<KeyType, ValueType>::clear()
{
    _map.clear();
    _size = 0;
    elements = 0;
}

template<typename KeyType, typename ValueType>
list_iterator<KeyType,ValueType>  map<KeyType, ValueType>::lbegin()
{
    return list_iterator<KeyType,ValueType>(_map.get_head(),_map.get_tail(),_map.get_head());
}

template<typename KeyType, typename ValueType>
list_iterator<KeyType,ValueType>  map<KeyType, ValueType>::lend()
{
    return list_iterator<KeyType,ValueType>(_map.get_head(),_map.get_tail(), nullptr);
}

template<typename KeyType, typename ValueType>
iterator<KeyType,ValueType>  map<KeyType, ValueType>::hbegin()
{
    return iterator<KeyType,ValueType> (_map.get_root(),_map.get_root());
}

template<typename KeyType, typename ValueType>
iterator<KeyType,ValueType>  map<KeyType, ValueType>::hend()
{
    return iterator<KeyType,ValueType>(_map.get_root(),nullptr);
}

template<typename KeyType, typename ValueType>
ValueType &map<KeyType, ValueType>::operator[](KeyType key)
{
    if(contains(key))
    return _map.find(_map.get_root(),key)->data.second;
    else
    {
        _map.insert(_map.get_root(),key,ValueType());
        elements++;
        return _map.find(_map.get_root(),key)->data.second;
    }
}

template<typename KeyType, typename ValueType>
ValueType map<KeyType, ValueType>::operator[](KeyType key) const
{
    if(_map(key))
        return _map.find(_map.get_root(),key);
    else
        return ValueType();
}

#endif // MAP_H
