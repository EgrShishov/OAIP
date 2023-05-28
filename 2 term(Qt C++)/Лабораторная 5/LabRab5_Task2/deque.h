#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <QString>
#include <QDebug>
#include "shared_ptr.h"

#define k 4
template <class T>
class iterator
{
public:
    iterator() : array(nullptr)
    {
        cords.first = -1;
        cords.second = -1;
    }
    iterator(shared_ptr<shared_ptr<int>> array,int i,int j) : array(array)
    {
        cords.first = i;
        cords.second = j;
    }
    iterator(iterator& other) : array(other.array)
    {
        cords.first = other.cords.first;
        cords.second = other.cords.second;
    }

    T& operator*()
    {
        qDebug()<<"adanda";
        return array.get()[cords.first][cords.second];
    }

    iterator operator++(int)
    {
        iterator temp(*this);
        ++array;
        return temp;
    }

    iterator& operator++()
    {
        if(cords.second == k - 1)
        {
            cords.second = 0;
            cords.first++;
        }
        else
        {
            cords.second++;
        }
        ++array;
        return *this;
    }

    iterator& operator--()
    {
        if (cords.second == 0)
        {
            cords.second = k - 1;
            cords.first--;
        }
        else
        {
            cords.second--;
        }
        --array;
        return *this;
    }
    iterator operator+(int n);
    iterator operator-(int n);

    bool operator!=(iterator& other) const
    {
        return cords.first != other.cords.first || cords.second != other.cords.second;
    }
    bool operator==(iterator& other) const
    {
        return cords.first == other.cords.first && cords.second == other.cords.second;
    }
    bool operator <(iterator& other) const
    {
        return cords.first < other.cords.first || cords.second < other.cords.second;
    }

    std::pair<int,int>& get_index()
    {
        return cords;
    }

    void reset(iterator&& other)
    {
        cords = other.cords;
        array = other.array;
    }

    shared_ptr<shared_ptr<int>>& get_array()
    {
        return array;
    }

private:
    std::pair<int,int> cords;
    shared_ptr<shared_ptr<int>> array;
};

template <class T>
class Deque
{
    friend class iterator<T>;
public:
    Deque()
    {
       _capacity = 1000;
       _size = 0;
       pointers_array.reset(new shared_ptr<int>[_capacity]);
       for(int i=0;i<_capacity;i++)
           pointers_array.get()[i].reset(nullptr);

       pointers_array.get()[_capacity / 2].reset(new T[k]);
       _front.first = _back.first = _capacity / 2;
       _front.second = _back.second = 0;

       begin.reset(iterator<T>(pointers_array,_front.first,_front.second));
       end.reset(iterator<T>(pointers_array,_back.first,_back.second));
    }

    Deque(const Deque<T>& other)
    {
        pointers_array = other.pointers_array;
        _front = other._front;
        _back = other._back;
    }

    bool isEmpty();
    size_t size();
    size_t capacity();
    void clear();
    void resize();

    void push_front(const T& data);
    void push_back(const T& data);
    void pop_front();
    void pop_back();

    T& front();
    T& back();

    T& operator[](int index);

private:
    size_t _capacity = 0;
    size_t _size = 0;
    iterator<T> begin;
    iterator<T> end;
    shared_ptr<shared_ptr<T>> pointers_array;
    int block_count = 0;
    std::pair<int,int> _front;
    std::pair<int,int> _back;
};

template <class T>
bool Deque<T>::isEmpty()
{
   return _size!=0;
}

template <class T>
size_t Deque<T>::size()
{
    return _size;
}

template <class T>
size_t Deque<T>::capacity()
{
    return _capacity;
}

template <class T>
void Deque<T>::resize()
{
    _capacity = _capacity * 2;
    shared_ptr<shared_ptr<T>> new_arr(new shared_ptr<T>[_capacity]);
    int index = _capacity/2 - (_back.first - _front.first)/2;
    for(int i = _front.first;i <= _back.first ;i++)
    {
        new_arr.get()[index].reset(pointers_array.get()[i].get());
        index++;
    }

    pointers_array.reset(nullptr);
    _front.first = _capacity/2 - (_back.first - _front.first)/2;
    _back.first = index - 1;
    pointers_array.reset(new_arr.get());
    begin.reset(iterator<T>(pointers_array,_front.first,_front.second));
    end.reset(iterator<T>(pointers_array,_back.first,_back.second));
}

template <class T>
void Deque<T>::push_front(const T& data)
{
    if(!isEmpty()) //pustoy na samom dele
        pointers_array.get()[_front.first].get()[_front.second] = data;
    else if (_front.second == 0)
    {
        if(_front.first==0) resize();
        --_front.first;
        _front.second = k - 1;
        pointers_array.get()[_front.first].reset(new T[k]);
        pointers_array.get()[_front.first].get()[_front.second] = data;
    }
    else
    {
        _front.second--;
        pointers_array.get()[_front.first].get()[_front.second] = data;
    }
    qDebug()<<"cords"<<--begin.get_index().first;
       ++_size;
}


template <class T>
void Deque<T>::push_back(const T& data)
{
    if(!isEmpty())
        pointers_array.get()[_back.first].get()[_back.second] = data;
    if(_back.second == k - 1)
    {
       if(_back.first == _capacity - 1) resize();
       ++_back.first;
       _back.second = 0;
       pointers_array.get()[_back.first].reset(new T[k]);
       pointers_array.get()[_back.first].get()[_back.second] = data;
    }
    else
    {
       _back.second++;
       pointers_array.get()[_back.first].get()[_back.second] = data;
    }
    qDebug()<<pointers_array.get()[_back.first].get()[_back.second];
    ++_size;
}

template <class T>
void Deque<T>::pop_front()
{
    if(_front.second == k - 1)
    {
        pointers_array.get()[_front.first].reset(nullptr);
        _front.second = 0;
        _front.first++;
    }
    else ++_front.second;
    --_size;
}

template <class T>
void Deque<T>::pop_back()
{
    if(_back.second == 0)
    {
        pointers_array.get()[_back.first].reset(nullptr);
        _back.first--;
        _back.second = k - 1;
    }
    else _back.second--;
    --_size;
}

template <class T>
T& Deque<T>::front()
{
    return pointers_array[_front.first][_front.second];
}

template <class T>
T& Deque<T>::back()
{
    return pointers_array[_back.first][_back.second];
}
template <class T>
void Deque<T>::clear()
{
    for(int i=0;i<_size;i++)
         pointers_array.get()[i].reset(nullptr);
    pointers_array.reset(nullptr);

    _size = 0;
    _capacity = 1000;
    pointers_array.reset(new shared_ptr<int>[_capacity]);
    for(int i=0;i<_capacity;i++)
        pointers_array.get()[i].reset(nullptr);

    pointers_array.get()[_capacity/2].reset(new T[k]);
    _front.first = _back.first = _capacity/2;
    _front.second = _back.second = 0;
    begin.reset(iterator<T>(pointers_array,_front.first,_front.second));
    end.reset(iterator<T>(pointers_array,_back.first,_back.second));
}

template <class T>
T& Deque<T>::operator[](int index)
{
    return pointers_array.get()[(index + _front.second) / k + _front.first].get()[(index + _front.second) % k];
}

#endif // DEQUE_H
