#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <QDebug>
template <typename T>
class Nod
{
public:
    T data;
    Nod* next = nullptr;
    Nod() : data(), next(nullptr){}
    Nod(T data) : data(data){}
};

template <typename T>
class Stack
{
public:
    Stack() : arr(nullptr){}
    ~Stack(){while(!empty()) pop();}

    void pop();
    T top();
    void push(T data);
    size_t size();
    bool empty();

    Stack& operator=(Stack& other)
    {
        Stack tmp;
        while(!empty())
        {
            tmp.push(top());
            pop();
        }
        while(!other.empty())
        {
            tmp.push(other.top());
            other.pop();
        }

        while(!tmp.empty())
        {
            push(tmp.top());
            tmp.pop();
        }
        return *this;
    }

private:
    size_t _size = 0;
    Nod<T>* arr = nullptr;
};

template<typename T>
void Stack<T>::pop()
{
    if(arr==nullptr) return;
    Nod<T>* ptr = arr;
    arr = arr->next;
    if(ptr!=nullptr)
    delete ptr;
    --_size;
}

template<typename T>
T Stack<T>::top()
{
    if(!empty()) return arr->data;
}

template<typename T>
void Stack<T>::push(T data)
{
    Nod<T>* newNode = new Nod<T>;
    newNode->data = data;
    newNode->next = arr;
    arr = newNode;
    _size++;
}

template<typename T>
size_t Stack<T>::size()
{
    return _size;
}

template<typename T>
bool Stack<T>::empty()
{
    return _size==0;
}


#endif // STACK_H
