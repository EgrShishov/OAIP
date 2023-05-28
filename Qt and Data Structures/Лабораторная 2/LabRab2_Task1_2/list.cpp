#include "list.h"

list::list()
{
  _size = 0;
  _capacity=2;
  _initCapacity=2;
  data = new shop[_capacity];
}


list::~list()
{
 delete[] data;
}

void list::pushBack(shop Data)
{
    if(_size==_capacity)
    {
        shop* tmp = new shop[_capacity];
        for(int i=0;i<_size;i++)
            tmp[i]=data[i];

        _capacity*=2;
        delete[] data;
        data = new shop[_capacity];

        for(int i=0;i<_size;i++)
            data[i]=tmp[i];
        delete[] tmp;
    }
    data[_size]=Data;
    _size++;
}


void list::pushFront(shop data)
{
  return;
}

void list::insert(int index, shop Data)
{
    if(index<=_size && index>=0)
    {
        if(_size==_capacity)
        {
            shop* tmp = new shop[_capacity];
            for(int i=0;i<_size;i++)
                tmp[i]=data[i];

            _capacity*=2;
            delete[] data;
            data = new shop[_capacity];

            for(int i=0;i<_size;i++)
                data[i]=tmp[i];
            delete[] tmp;
        }

        for(int i=_size;i>index;i--)
        {
            data[i]=data[i-1];

        }
        data[index]=Data;
        _size++;
    }

}


void list::erase(int index)
{

    if(_size*2<=_capacity)
    {
        shop* tmp = new shop[_size];
        for(int i=0;i<_size;i++)
            tmp[i]=data[i];

        delete[] data;
        _capacity=_capacity/2+_initCapacity;
        data=new shop[_capacity];

        for(int i=0;i<_size;i++)
            data[i]=tmp[i];
        delete[] tmp;

    }

    for(int i = index;i<_size-1;i++)
     data[i]=data[i+1];
    _size--;

}


shop& list::getAt(int index)
{
   if(index<_size && index>=0)
       return data[index];
}


int list::size()
{
   return _size;
}


bool list::isEmpty()
{
    return _size==0;
}


void list::clear()
{
    delete[] data;
    _size=0;
    _capacity=1;
    data=new shop[_capacity];
}
