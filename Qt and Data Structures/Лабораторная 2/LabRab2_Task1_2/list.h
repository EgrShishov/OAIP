#ifndef LIST_H
#define LIST_H

#include "shop.h"

//struct Element
//{
//    shop data;
//    int indexPrev;
//    int indexNext;
//    Element(shop data, int prev, int next) : data(data), indexNext(next), indexPrev(prev){}
//    Element(){}
//};

class list
{
public:
    list();
    //list(const list& List);
    ~list();

    void pushFront(shop data);

    void pushBack(shop data);

    shop& getAt(int index);

    //shop& operator[] (int index);

    void insert(int index, shop data);

    void erase(int index);

    int size();

    //void setData(int index,shop Data);

    bool isEmpty();

    void clear();

private:
    shop* data;
    int _size = 0;
    int _capacity=0;
    int _initCapacity=0;
};

#endif // LIST_H
