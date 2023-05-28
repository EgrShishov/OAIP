#ifndef LIST_H
#define LIST_H

#include <QDebug>
#include <iostream>
template<typename T>
class Papa
{
public:
    T data;
    Papa* next = nullptr;
    Papa* prev = nullptr;
    Papa(T data) : data(data){}
};

template <typename T>
class list
{
public:
    list();
    ~list();

    void push_back(T value);
    void push_front(T value);
    void pop_back();
    void pop_front();
//    void swap(Papa<T>*& lrs, Papa<T>*& rhs)
//    {
//        Papa<T>* temp = head;
//        head = other.head;
//        other.head = temp;

//        // swap tail pointers
//        temp = tail;
//        tail = other.tail;
//        other.tail = temp;

//        // swap sizes
//        size_t temp_size = _size;
//        _size = other._size;
//        other._size = temp_size;
//    }
    void insert(T value, int index);
    void erase(int index);
    void clear()
    {
        while(tail!=nullptr)
            pop_back();
    }
    Papa<T>* getAt(int index);
    Papa<T>* front()
    {
        if(head!=nullptr)
            return head;
    }
    Papa<T>* back()
    {
        if(tail!=nullptr)
            return tail;
    }
    bool empty();
    size_t size();

    T& operator[](int index)
    {
        return getAt(index)->data;
    }
private:
    Papa<T>* head = nullptr;
    Papa<T>* tail = nullptr;
    size_t _size = 0;
};

template<typename T>
list<T>::list()
{

}

template<typename T>
list<T>::~list()
{
    while(_size--)
        pop_back();
}

template<typename T>
void list<T>::push_back(T value)
{
    if(tail==nullptr)
    {
        head = tail = new Papa<T>(value);
    }
    else
    {
        Papa<T>* newNode = new Papa<T>(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    _size++;
}

template<typename T>
void list<T>::push_front(T value)
{
    if(head==nullptr) head = tail = new Papa<T>(value);
    else
    {
        Papa<T>* newNode = new Papa<T>(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    _size++;
}

template<typename T>
void list<T>::pop_back()
{
    if(tail!=nullptr)
    {
        if(tail==head)
        {
            delete tail;
            tail = head = nullptr;
        }
        else
        {
        Papa<T>* ptr = tail->prev;
        ptr->next = nullptr;
        delete tail;
        tail = ptr;
        }
        --_size;
    }
}

template<typename T>
void list<T>::pop_front()
{
    if(head!=nullptr)
    {
        if(tail==head)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
        Papa<T>* ptr = head->next;
        ptr->prev=nullptr;
        delete head;
        head = ptr;
        }
        --_size;
    }
}

template<typename T>
void list<T>::insert(T value, int index)
{
    if(index < 0 || index >=_size) return;

    Papa<T>* newNode = new Papa(value);

    if(index==0) push_front(value);
    else if(index==_size-1) push_back(value);
    else
    {
        Papa<T>* cur = getAt(index);
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next->prev = newNode;
        cur->next = newNode;
    }
    ++_size;
}

template<typename T>
void list<T>::erase(int index)
{
    if(index> 0 && index>=_size) return;

    Papa<T>* delNode = getAt(index);

    if(index==0) pop_front();
    else if(index==_size-1) pop_back();
    else
    {
    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;
    delete delNode;
    }
    --_size;
}

template<typename T>
Papa<T>* list<T>::getAt(int index)
{
    if(!empty())
    {
        Papa<T>* temp = head;
        int n = 0;
        while(n!=index)
        {
            if(head == nullptr)
                return temp;
            temp = temp->next;
            n++;
        }
        return temp;
    }
}

template<typename T>
bool list<T>::empty()
{
    return _size==0;
}

template<typename T>
size_t list<T>::size()
{
    return _size;
}

#endif // LIST_H
