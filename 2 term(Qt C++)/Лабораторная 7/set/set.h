#ifndef SET_H
#define SET_H
#include <iostream>
#include <QDebug>
#include "avl.h"

template <typename KeyType>
class set
{
public:
    set(){}
    ~set(){}

    void insert(KeyType key);
    void erase(KeyType key);
    //iterator find(KeyType key);
    size_t count(KeyType key);
    bool contains(KeyType key);

    void clear();
    size_t size();
    bool empty();
    void print(QString& out);

    list_iterator<KeyType> lbegin();
    list_iterator<KeyType>  lend();
    iterator<KeyType,ValueType>  hbegin();
    iterator<KeyType,ValueType>  hend();
    void print_list(){_set.list_print();}

private:
    AVL<KeyType> _set;
    size_t _size = 0;
};

template<typename KeyType>
void set<KeyType>::insert(KeyType key)
{
    if(_set.contains(_set.get_root(),key))
        return;
    else
    {
        _set.insert(_set.get_root(),key);
        _size++;
    }
}

template<typename KeyType>
void set<KeyType>::erase(KeyType key)
{
    if(_set.contains(_set.get_root(),key))
    {
        _set.remove(_set.get_root(),key);
        --_size;
    }
}

template<typename KeyType>
size_t set<KeyType>::count(KeyType key)
{
    if(_set.contains(_set.get_root(),key))
    {
        return 1;
    }
    else return 0;
}

template<typename KeyType>
bool set<KeyType>::contains(KeyType key)
{
    return _set.contains(_set.get_root(),key);
}

template<typename KeyType>
void set<KeyType>::clear()
{
    _set.clear();
    _size = 0;
}

template<typename KeyType>
size_t set<KeyType>::size()
{
    return _size;
}

template<typename KeyType>
bool set<KeyType>::empty()
{
    return _size == 0;
}

template<typename KeyType>
void set<KeyType>::print(QString &out)
{
    _set.preorder_print(_set.get_root(), out);
}

template<typename KeyType>
list_iterator<KeyType> set<KeyType>::lbegin()
{
    return list_iterator<KeyType>(_set.get_head(),_set.get_tail(),_set.get_head());
}

template<typename KeyType>
list_iterator<KeyType> set<KeyType>::lend()
{
    return list_iterator<KeyType>(_set.get_head(),_set.get_tail(),nullptr);
}

template<typename KeyType>
iterator<KeyType>  set<KeyType>::hbegin()
{
    return iterator<KeyType> (_set.get_root(),_set.get_root());
}

template<typename KeyType>
iterator<KeyType>  set<KeyType>::hend()
{
    return iterator<KeyType>(_set.get_root(),nullptr);
}

#endif // SET_H
