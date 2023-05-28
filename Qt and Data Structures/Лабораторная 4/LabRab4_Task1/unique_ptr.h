#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include <iostream>
#include <QDebug>
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
    unique_ptr<T>& operator =(unique_ptr<T>& other) = delete;
    unique_ptr<T>& operator =(unique_ptr<T>&& other);

    bool operator !=(const T* other) const
    {
        get()!= other? true : false;
    }

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
    delete ptr;
    ptr=newPtr;
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

template <typename T>
class unique_ptr<T[]>
{
public:
    unique_ptr() : ptr(nullptr) {}
    unique_ptr(T* ptr) : ptr(ptr){}

    unique_ptr(unique_ptr<T[]>& other) = delete;
    unique_ptr(unique_ptr<T[]>&& right) : ptr(std::move(right)){}
    ~unique_ptr() { delete[] ptr; }


    T* get();
    T* realese();
    void reset(T* newPtr);
    void swap(unique_ptr<T[]>& other);
    operator bool();
    T* operator->();
    T& operator*();
    unique_ptr<T[]>& operator =(unique_ptr<T[]>& other) = delete;
    unique_ptr<T[]>& operator =(unique_ptr<T[]>&& other);

private:
    T* ptr = nullptr;
};


template <class T>
T* unique_ptr<T[]>::get()
{
    return ptr;
}


template <class T>
T* unique_ptr<T[]>::realese()
{
    T* temp = ptr;
    ptr = nullptr;
    return temp;
}


template <class T>
void unique_ptr<T[]>::reset(T* newPtr)
{
    delete[] ptr;
    ptr = newPtr;
}


template <class T>
void unique_ptr<T[]>::swap(unique_ptr<T[]>& other)
{
    T* tmp = std::move(other.ptr);
    other.ptr=std::move(ptr);
    ptr=std::move(tmp);
    //std::swap(ptr,other.ptr);
}


template <class T>
unique_ptr<T[]>::operator bool()
{
    return ptr;
}


template <class T>
T* unique_ptr<T[]>::operator->()
{
    return ptr;
}


template <class T>
T& unique_ptr<T[]>::operator*()
{
    return *ptr;
}


//template <class T>
//unique_ptr<T[]>& unique_ptr<T[]>::operator =(unique_ptr<T[]>& other)
//{
//    delete[] ptr;
//    ptr = other.ptr;
//    other.ptr=nullptr;
//    return *this;
//}

template <class T>
unique_ptr<T[]>& unique_ptr<T[]>::operator =(unique_ptr<T[]>&& other)
{
    if(&other==this)
        return *this;
    delete[] ptr;

    ptr=other.ptr;
    other.ptr=nullptr;
    return *this;
}
#endif // UNIQUE_PTR_H
