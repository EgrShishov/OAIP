#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <QString>
#include <QDebug>
#include <initializer_list>
#include <memory>
#include "shared_ptr.h"
//add smart pointers
//****************************************************************//
/*8.Создать двухсвязную очередь из случайных целых, положительных и
отрицательных чисел. Из этой очереди образовать две очереди, первая
из которых должен содержать отрицательные числа, а вторая –
положительные. Элементы очередей не должны перемещаться в памяти.*/
//****************************************************************//

template<class T>
class unique_ptr
{
public:
    unique_ptr() : ptr(nullptr) {}
    unique_ptr(T* ptr) : ptr(ptr){}

    unique_ptr(unique_ptr<T>& other) = delete;
    unique_ptr(unique_ptr<T>&& right) : ptr(std::move(right.ptr)){right.ptr=nullptr;}
    ~unique_ptr()
    {
        if(ptr!=nullptr)
        {
            qDebug()<<"not null"; delete ptr;
        }
        else qDebug()<<"unique destructor";
    }


    T* get() const;
    T* realese();
    void reset(T* newPtr);
    void swap(unique_ptr<T>& other);
    operator bool();
    T* operator->();
    T& operator*();

    bool operator !=(const T* other) const
    {
        get()!= other? true : false;
    }

    unique_ptr<T>& operator =(unique_ptr<T>& other) = delete;
    unique_ptr<T>& operator =(unique_ptr<T>&& other);

    static unique_ptr<T> make_unique(T* ptr)
    {
        return unique_ptr<T>(ptr);
    }

private:
    T* ptr = nullptr;
};


template <class T>
T* unique_ptr<T>::get() const
{
    return ptr;
}


template <class T>
T* unique_ptr<T>::realese()
{
    T* temp = ptr;
    ptr = nullptr;
    return temp;
}


template <class T>
void unique_ptr<T>::reset(T* newPtr)
{
    if(ptr)
       delete ptr;
    ptr = newPtr;
}


template <class T>
void unique_ptr<T>::swap(unique_ptr<T>& other)
{
    T* tmp = std::move(other.ptr);
    other.ptr=std::move(ptr);
    ptr=std::move(tmp);
}


template <class T>
unique_ptr<T>::operator bool()
{
    return ptr;
}


template <class T>
T* unique_ptr<T>::operator->()
{
    return ptr;
}


template <class T>
T& unique_ptr<T>::operator*()
{
    return *ptr;
}

template <class T>
unique_ptr<T>& unique_ptr<T>::operator =(unique_ptr<T>&& other)
{
    if(&other==this)
        return *this;
    delete ptr;

    ptr=other.ptr;
    other.ptr=nullptr;
    return *this;
}

//template <class T>
//class Deque
//{
//public:
//    Deque() : head(nullptr),tail(nullptr), _size(0) {qDebug()<<"deque constructor";}
//    Deque(int size) : head(nullptr),_size(size)
//    {
//        while(size--) push_back(0);
//        qDebug()<<"deque constructor with size";
//    }
//    Deque(std::initializer_list<T> list) : _size(0)
//    {
//        for(auto item : list)
//            push_back(item);
//        qDebug()<<"deque initialiser";
//    }
//    ~Deque()
//    {
//        while(head!=nullptr) pop_front();
//        head=nullptr;
//        tail=nullptr;
//        _size=0;
//        qDebug()<<"deque destructor";
//    }

//    T& front();
//    T& back();

//    bool isEmpty();
//    size_t size();
//    void clear();

//    void push_front(T data);
//    void push_back(T data);
//    void pop_front();
//    void pop_back();

//    T& operator[](int index);
//    T& getAt(int index);

//private:
//    int _size;
//    struct Node
//    {
//        T data;
//        //unique_ptr<Node> next;
//        //unique_ptr<Node> prev;
//        Node* next;
//        Node* prev;
//        Node(T data) : data(data),next(nullptr),prev(nullptr){}
//    };
//    //unique_ptr<Node> head;
//    Node* head;
//    Node* tail;
//};

//template <class T>
//bool Deque<T>::isEmpty()
//{
//    return _size==0;
//}

//template <class T>
//size_t Deque<T>::size()
//{
//    return _size;
//}

//template <class T>
//T& Deque<T>::front()
//{
//    if(!isEmpty())
//    {
//    return head->data;
//    }
//}

//template <class T>
//T& Deque<T>::back()
//{
//    if(!isEmpty())
//    {
//    return tail->data;
//    }
//}

//template <class T>
//void Deque<T>::push_front(T data)
//{
//    Node* newNode = new Node(data);

//    if(isEmpty())
//    {
//        head=tail=newNode;
//    }
//    else
//    {
//        newNode->next=head;
//        head->prev=newNode;
//        head=newNode;
//    }
//    _size++;
//}

//template <class T>
//void Deque<T>::push_back(T data)
//{
//    Node* newNode = new Node(data);

//    if(isEmpty())
//    {
//        head=tail=newNode;
//    }
//    else
//    {
//        tail->next=newNode;
//        newNode->prev=tail;
//        tail=newNode;
//    }

//    _size++;
//}

//template <class T>
//void Deque<T>::pop_front()
//{
//    if(head==nullptr) return;

//    Node* ptr = head->next;
//    if(ptr!=nullptr)
//    {
//        ptr->prev = nullptr;
//    }
//    else
//    {
//        tail = ptr;
//    }

//    delete head;
//    _size--;
//    head = ptr;
//}

//template <class T>
//void Deque<T>::pop_back()
//{
//    if(tail==nullptr) return;

//    Node* ptr = tail->prev;
//    if(ptr!=nullptr)
//    {
//        ptr->next = nullptr;
//    }
//    else
//    {
//        head = ptr;
//    }

//    delete tail;
//    _size--;
//    tail = ptr;
//}
#define shared_ptr std::shared_ptr
//template <class T>
//void Deque<T>::clear()
//{
//    while(head!=nullptr) pop_front();
//}

//template <class T>
//T& Deque<T>::getAt(int index)
//{
//    if(index<0 || index>_size)
//        throw std::out_of_range ("index out of range");

//    Node* cur = head;
//    int curIndex = 0;
//    while(curIndex!=index)
//    {
//        cur = cur->next;
//        curIndex++;
//    }
//    return cur->data;
//}

//template <class T>
//T& Deque<T>::operator[](int index)
//{
//    return getAt(index);
//}

//template<class T>
//class Deque
//{
//public:
//    Deque() : head(nullptr), tail(nullptr), _size(0) { qDebug() << "deque constructor"; }
//    Deque(int size) : head(nullptr), _size(size)
//    {
//        while (size--) push_back(0);
//        qDebug() << "deque constructor with size";
//    }
//    Deque(std::initializer_list<T> list) : _size(0)
//    {
//        for (auto item : list)
//            push_back(item);
//        qDebug() << "deque initializer";
//    }
//    ~Deque()
//    {
//        while (head != nullptr) pop_back();
//        head = nullptr;
//        tail = nullptr;
//        _size = 0;
//        qDebug() << "deque destructor";
//    }

//    T& front();
//    T& back();

//    bool isEmpty();
//    size_t size();
//    void clear();

//    void push_front(T data);
//    void push_back(T data);
//    void pop_front();
//    void pop_back();

//    T& operator[](int index);

//private:
//    int _size;
//    struct Node
//    {
//        T data;
//        unique_ptr<Node> next;
//        Node* prev;
//        Node(T data) : data(data), next(nullptr), prev(nullptr) {}
//    };
//    unique_ptr<Node> head;
//    Node* tail;
//};

//template <class T>
//bool Deque<T>::isEmpty()
//{
//    return head.get()==nullptr;
//}

//template <class T>
//size_t Deque<T>::size()
//{
//    return _size;
//}

//template <class T>
//T& Deque<T>::front()
//{
//    if (!isEmpty())
//    {
//        return head->data;
//    }
//}

//template <class T>
//T& Deque<T>::back()
//{
//    if (!isEmpty())
//    {
//        return tail->data;
//    }
//}

//template <class T>
//void Deque<T>::push_front(T data)
//{
//    unique_ptr<Node> newNode = unique_ptr<Node>::make_unique(new Node(data));

//    if (isEmpty())
//    {
//        head = std::move(newNode);
//        tail = head.get();
//    }
//    else
//    {
//        newNode->next = std::move(head);
//        if (head) head->prev = newNode.get();
//        head = std::move(newNode);
//    }

//    _size++;
//}

//template <class T>
//void Deque<T>::push_back(T data)
//{
//    unique_ptr<Node> newNode = unique_ptr<Node>::make_unique(new Node(data));

//    if (isEmpty())
//    {
//        head = std::move(newNode);
//        tail = head.get();
//    }
//    else
//    {
//        tail->next = std::move(newNode);
//        if (tail->next) tail->next->prev = tail;
//        tail = tail->next.get();
//    }

//    _size++;
//}

//template <class T>
//void Deque<T>::pop_front()
//{
//    if (head.get() == nullptr) return;

//    head = std::move(head->next);
//    if (head)
//    {
//        head->prev = nullptr;
//    }
//    else
//    {
//        tail = nullptr;
//    }

//    _size--;
//}

//template <class T>
//void Deque<T>::pop_back()
//{
//    if (tail == nullptr) return;

//    tail = tail->prev;
//    if (tail)
//    {
//        tail->next.reset(nullptr);
//    }
//    else
//    {
//        head.reset(nullptr);
//    }

//    _size--;
//}

//template <class T>
//void Deque<T>::clear()
//{
//    while(head!=nullptr) pop_back();
//}

template<class T>
class Deque
{
public:
    Deque() : head(nullptr), tail(nullptr), _size(0) { qDebug() << "deque constructor"; }
    Deque(int size) : head(nullptr), _size(size)
    {
        while (size--) push_back(0);
        qDebug() << "deque constructor with size";
    }
    Deque(std::initializer_list<T> list) : _size(0)
    {
        for (auto item : list)
            push_back(item);
        qDebug() << "deque initializer";
    }

    T& front();
    T& back();

    bool isEmpty();
    size_t size();
    void clear();

    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();

    T& operator[](int index);

private:
    int _size;
    struct Node
    {
        T data;
        shared_ptr<Node> next;
        shared_ptr<Node> prev;
        Node(T data) : data(data), next(nullptr), prev(nullptr) {}
    };
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
};

template <class T>
bool Deque<T>::isEmpty()
{
    return head.get()==nullptr;
}

template <class T>
size_t Deque<T>::size()
{
    return _size;
}

template <class T>
T& Deque<T>::front()
{
    if (!isEmpty())
    {
        return head->data;
    }
}

template <class T>
T& Deque<T>::back()
{
    if (!isEmpty())
    {
        return tail->data;
    }
}

template <class T>
void Deque<T>::push_front(T data)
{
    shared_ptr<Node> newNode (new Node(data));

    if (isEmpty())
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = (newNode);
    }

    _size++;
}

template <class T>
void Deque<T>::push_back(T data)
{
    shared_ptr<Node> newNode(new Node(data));

    if (isEmpty())
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    _size++;
}

template <class T>
void Deque<T>::pop_front()
{
    if (head.get() == nullptr) return;

    head = (head->next);
    if (head)
    {
        head->prev.reset();
    }
    else
    {
        tail.reset();
    }

    _size--;
}

template <class T>
void Deque<T>::pop_back()
{
    if (tail.get() == nullptr) return;

    tail = tail->prev;
    if (tail)
    {
        tail->next.reset();
    }
    else
    {
        head.reset();
    }

    _size--;
}

template <class T>
void Deque<T>::clear()
{
    while(head.get()!=nullptr) pop_back();
}

template <class T>
T& Deque<T>::operator[](int index)
{
    if(index < 0 || index >= _size)
        throw std::out_of_range ("index out of range1");

    Node* cur = head.get();
    int curIndex = 0;
    while(curIndex < index && cur != nullptr)
    {
        cur = cur->next.get();
        curIndex++;
    }
    if (cur == nullptr)
           throw std::out_of_range ("index out of range2");
    return cur->data;
}

class solution
{
public:

    solution(){}
    solution(int n)
    {
        for(int i=0;i<n;i++)
          _input.push_back(rand()%200-54);
    }
    void input(int n)
    {
        for(int i=0;i<n;i++)
          _input.push_back(rand()%200-54);
    }

    QString solve()
    {
        QString ans="Сгенерированная очередь : ";
        for(int i=0;i<_input.size();i++)
            ans+=QString::number(_input[i])+", ";
        ans+="\nПозитивные числа : ";
        for(int i=0;i<_input.size();i++)
        {
            if(_input[i]>=0)
                first.push_back(_input[i]);
            else
                second.push_back(_input[i]);
        }

        for(int i=0;i<first.size();i++)
            ans+=QString::number(first[i])+", ";

        ans+="\nНегативные числа : ";

        for(int i=0;i<second.size();i++)
            ans+=QString::number(second[i]) + ", ";

        return ans;
    }

private:
    Deque <double> first;
    Deque <double> second;
    Deque <double> _input;

};
#endif // DEQUE_H
