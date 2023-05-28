#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <iostream>
#include <forward_list>
#include <memory>
#include <QString>
#include <QDebug>

//to-do : smart pointers instead of row pointers
template <typename KeyType, typename ValueType, typename HashFunc>
class unordered_map
{
public:
    unordered_map() : _size(5) {qDebug()<<"empty constructor";}
    unordered_map(size_t size,HashFunc hasher) : _size(size), hasher(hasher), map(new std::forward_list<std::pair<const KeyType,ValueType>>[size]){qDebug()<<"constructor with size";}
    ~unordered_map()
    {
        qDebug()<<"destructor";
        delete[] map;
    }

    void insert(KeyType key, ValueType value);
    void set_hasher(HashFunc hasher);
    void erase(KeyType key, ValueType value);
    void clear();
    bool contains(KeyType x);
    bool find(KeyType key,ValueType value);
    double load_factor();
    size_t size();
    bool empty();

    QString print();

    ValueType& operator[](KeyType key);
    ValueType operator[](KeyType key) const;

protected:
    void rehash();
    unsigned int hash_function(KeyType key);

private:
    size_t _size = 0;
    size_t elements_amount = 0;
    std::forward_list<std::pair<const KeyType,ValueType>>* map = new std::forward_list<std::pair<const KeyType,ValueType>>[5];
    HashFunc hasher = HashFunc();
};


template<typename KeyType, typename ValueType, typename HashFunc>
void unordered_map<KeyType, ValueType, HashFunc>::insert(KeyType key, ValueType value)
{
    if(load_factor()>75 || _size==elements_amount) rehash();
    unsigned int hash = hash_function(key);
    map[hash].push_front(std::make_pair(key,value));
    elements_amount++;
}

template<typename KeyType, typename ValueType, typename HashFunc>
void unordered_map<KeyType, ValueType, HashFunc>::set_hasher(HashFunc hasher)
{
    this->hasher = hasher;
    qDebug() << "hasher setted";
}

template<typename KeyType, typename ValueType, typename HashFunc>
void unordered_map<KeyType, ValueType, HashFunc>::erase(KeyType key, ValueType value)
{
    unsigned int hash = hash_function(key);
    for(auto& it : map[hash])
    {
        if(it.second==value && it.first==key)
        {
            map[hash].remove(it);
            elements_amount--;
            break;
        }
    }
}

template<typename KeyType, typename ValueType, typename HashFunc>
void unordered_map<KeyType, ValueType, HashFunc>::clear()
{
    for(int i=0;i<_size;i++)
        map[i].clear();
    elements_amount = 0;
}

template<typename KeyType, typename ValueType, typename HashFunc>
bool unordered_map<KeyType, ValueType, HashFunc>::contains(KeyType x)
{
    unsigned int hash = hash_function(x);
    if(!map[hash].empty()) return true;
    return false;
}

template<typename KeyType, typename ValueType, typename HashFunc>
bool unordered_map<KeyType, ValueType, HashFunc>::find(KeyType key, ValueType value)
{
    unsigned int hash = hash_function(key);
    if(!map[hash].empty())
    {
        auto tmp = map[hash];
        for(auto& el : map[hash])
        {
            if(el.second==value)
                return true;
        }
    }
    return false;
}

template<typename KeyType, typename ValueType, typename HashFunc>
double unordered_map<KeyType, ValueType, HashFunc>::load_factor()
{
    return (double) elements_amount/_size * 100;
}

template<typename KeyType, typename ValueType, typename HashFunc>
size_t unordered_map<KeyType, ValueType, HashFunc>::size()
{
    return _size;
}
template<typename KeyType, typename ValueType, typename HashFunc>
bool unordered_map<KeyType, ValueType, HashFunc>::empty()
{
    return _size==0;
}

template<typename KeyType, typename ValueType, typename HashFunc>
QString unordered_map<KeyType, ValueType, HashFunc>::print()
{
    QString ans;
    for(int i=0;i<_size;i++)
    {
        auto temp = map[i];
        if(!temp.empty())
        {
            ans += "List # " + QString::number(i) + ": ";
        while(!temp.empty())
        {
            ans += "(" + QString::fromStdString(temp.front().first) + " " + QString::number(temp.front().second) +  ") , ";
            temp.pop_front();
        }
          ans += "\n";
        }
    }
    return ans;
}

template<typename KeyType, typename ValueType, typename HashFunc>
ValueType &unordered_map<KeyType, ValueType, HashFunc>::operator[](KeyType key)
{
    unsigned int hash = hash_function(key);
    for(auto& it : map[hash])
    {
        if(it.first==key)
            return it.second;
    }

    map[hash].push_front(std::make_pair(key,ValueType()));
    elements_amount++;
    return map[hash].front().second;
}

template<typename KeyType, typename ValueType, typename HashFunc>
ValueType unordered_map<KeyType, ValueType, HashFunc>::operator[](KeyType key) const
{
    unsigned int hash = hash_function(key);
    for(auto& it : map[hash])
    {
        if(it.first==key)
            return it.second;
    }
    return ValueType();
}

template<typename KeyType, typename ValueType, typename HashFunc>
void unordered_map<KeyType, ValueType, HashFunc>::rehash()
{
    std::forward_list<std::pair<const KeyType,ValueType>>* newarr = new std::forward_list<std::pair<const KeyType,ValueType>>[_size*2];
    //std::shared_ptr<std::forward_list<std::pair<const KeyType, ValueType>>[]> newarr(new std::shared_ptr<std::forward_list<std::pair<const KeyType, ValueType>>[_size*2]>);
    int old_size = _size;
    _size*=2;
    for(int i=0;i<old_size;i++)
    {
       std::forward_list<std::pair<const KeyType,ValueType>> tmp = map[i];
       for(auto& it : tmp)
       {
           unsigned int hash = hash_function(it.first);
           newarr[hash].push_front(it);
       }
    }

    delete[] map;
    map = newarr;
}

template<typename KeyType, typename ValueType, typename HashFunc>
unsigned int unordered_map<KeyType, ValueType, HashFunc>::hash_function(KeyType key)
{
    unsigned int hash = hasher(key);
    qDebug()<<"---" << hash;
    qDebug()<< "hash : " << hash % _size;
    return hash % _size;
}

#endif // UNORDERED_MAP_H
