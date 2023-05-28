#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include <QDebug>
#include <iostream>
template <class T>
class controlBlock
{
public:
    size_t shared_count = 0;
    size_t week_count = 0;
    T* ptr;
    controlBlock() : ptr(nullptr), shared_count(0) {}
};


template <class T>
class shared_ptr
{
public:
    shared_ptr() : controlPtr(nullptr) {}
    shared_ptr(T* ptr) : controlPtr(new controlBlock<T>)
    {
        controlPtr->ptr=ptr;
        ++controlPtr->shared_count;
    }
    shared_ptr(const shared_ptr<T>& other)
    {
        controlPtr=other.controlPtr;
        if(controlPtr) ++controlPtr->shared_count;
    }
    ~shared_ptr()
    {
        if(controlPtr!=nullptr)
        {
        --(controlPtr->shared_count);
        if(controlPtr->shared_count>0) return;
        if(controlPtr->shared_count==0)
        {
            delete controlPtr->ptr;
            controlPtr->ptr=nullptr;
            qDebug()<<"Деструктор share_ptr вызван";
        }
        }
    }

    T* get();
    void reset();
    void reset(T* other);
    void release();
    void swap(shared_ptr<T>& another);
    bool unique();
    int use_count();

    operator bool();
    T& operator*();
    shared_ptr<T>& operator=(shared_ptr<T>& another);
    T* operator->();
    T& operator[](int index);

    shared_ptr& operator++() {
        ++controlPtr->ptr;
        return *this;
    }
    shared_ptr& operator--() {
        --controlPtr->ptr;
        return *this;
    }

private:
    controlBlock<T>* controlPtr = nullptr;
};


template<class T>
T* shared_ptr<T>::get()
{
    return controlPtr->ptr? controlPtr->ptr : nullptr;
}


template<class T>
void shared_ptr<T>::reset()
{
    if(controlPtr)
        --(controlPtr->shared_count);
    controlPtr=nullptr;
}

template<class T>
void shared_ptr<T>::reset(T* other)
{
    if(controlPtr!=nullptr)
    {
        if(--controlPtr->shared_count==0)
        {
            controlPtr->ptr=nullptr;
            controlPtr=nullptr;
        }
    }

    controlPtr = new controlBlock<T>;

    if(other != nullptr){
        controlPtr->ptr = other;
        controlPtr->shared_count = 1;
    }
}

template<class T>
void shared_ptr<T>::swap(shared_ptr<T>& another)
{
    std::swap(controlPtr,another.controlPtr);
}


template<class T>
bool shared_ptr<T>::unique()
{
    return !(controlPtr->shared_count-1);
}


template<class T>
int shared_ptr<T>::use_count()
{
    return controlPtr? controlPtr->shared_count : 0;
}


template<class T>
shared_ptr<T>::operator bool()
{
    return controlPtr->ptr!=nullptr;
}


template<class T>
T& shared_ptr<T>::operator*()
{
    return *(controlPtr->ptr);
}


template<class T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T>& another)
{
    if(controlPtr)
        --(controlPtr->shared_count);

    controlPtr->ptr=another.controlPtr->ptr;
    if(controlPtr)
        ++controlPtr->shared_count;

    return *this;
}


template<class T>
T* shared_ptr<T>::operator->()
{
    return controlPtr->ptr;
}

template <class T>
T& shared_ptr<T>::operator[](int index)
{
    return controlPtr->ptr[index];
}

#endif // SHARED_PTR_H
