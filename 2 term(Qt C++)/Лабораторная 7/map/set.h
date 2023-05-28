#ifndef SET_H
#define SET_H
#include "map.h"

template <typename KeyType>
class set : map<KeyType,char>
{
public:
    set(){}
    ~set(){}

    void insert(KeyType key)
    {
        if(_set.contains(key))
            return;
        else
        {
            _set[key]='\0';
        }
    }
    size_t count(KeyType key)
    {
        if(_set.contains(key))
        {
            return 1;
        }
        else return 0;
    }
    bool contains(KeyType key)
    {
        return _set.contains(key);
    }
//    void erase(KeyType key)
//    {
//        _set.erase(key);
//    }
    void print(QString& out);

private:
    map<KeyType,char> _set;
};

#endif // SET_H
