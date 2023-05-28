#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <QDebug>
#include <iostream>

template <typename T>
class Mama
{
public:
    Mama(T data) : data(data){}
    T data;
    Mama* next = nullptr;
};

template <typename T>
class forward_list
{
public:
    forward_list();
    ~forward_list();

    void push_front(T value);
    void pop_front();
    bool empty();
    size_t size();
    void clear();
    Mama<T>* front();

private:
    size_t _size = 0;
    Mama<T>* head = nullptr;
};

template<typename T>
forward_list<T>::forward_list()
{

}

template<typename T>
forward_list<T>::~forward_list()
{
    while(head!=nullptr)
        pop_front();
}

template<typename T>
void forward_list<T>::push_front(T value)
{
    if(head==nullptr)
    {
        head = new Mama<T>(value);
    }
    else
    {
        Mama<T>* newNode = new Mama<T>(value);
        newNode->next = head;
        head = newNode;
    }
    ++_size;
}

template<typename T>
void forward_list<T>::pop_front()
{
    if(head==nullptr) return;

    Mama<T>* ptr = head;
    head = head->next;
    delete ptr;
    --_size;
}

template<typename T>
bool forward_list<T>::empty()
{
    return head==nullptr;
}

template<typename T>
size_t forward_list<T>::size()
{
    return _size;
}

template<typename T>
void forward_list<T>::clear()
{
    while(head!=nullptr)
        pop_front();
}

template<typename T>
Mama<T> *forward_list<T>::front()
{
    return head;
}

#endif // FORWARD_LIST_H
