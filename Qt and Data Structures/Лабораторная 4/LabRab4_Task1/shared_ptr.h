#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include <QDebug>

template <class T>
class controlBlock
{
public:
    size_t shared_count = 0;
    size_t week_count = 0;
    T* ptr;
};

template <class T>
class shared_ptr
{
    friend class weak_ptr;
public:
    shared_ptr() : controlPtr(nullptr) {}
    shared_ptr(T* ptr) : controlPtr(new controlBlock<T>)
    {
        controlPtr->ptr=ptr;
        ++(controlPtr->shared_count);
    }
    shared_ptr(shared_ptr<T>& other)
    {
        controlPtr=other.controlPtr;
        if(controlPtr) ++(controlPtr->shared_count);
    }
    shared_ptr(shared_ptr<T>&& other)
    {
        controlPtr=other.controlPtr;
        controlPtr->ptr=other.controlPtr->ptr;
        delete other.controlPtr->ptr;
        other.controlPtr=nullptr;
    }
    shared_ptr(week_ptr<T>& other)
    {

    }
    ~shared_ptr()
    {
        if(controlPtr)
        {
        --(controlPtr->shared_count);
        if(controlPtr->shared_count>0) return;
        if(controlPtr->week_count==0) delete controlPtr;
        else if(controlPtr->shared_count==0)
        {
            delete controlPtr->ptr;
            controlPtr->ptr=nullptr;
            qDebug()<<"Деструктор shared_ptr вызван";
        }
        }
    }

    T* get();
    void reset();
    void reset(T* other);
    void swap(shared_ptr<T>& another);
    bool unique();
    int use_count();

    operator bool();
    T& operator*();
    shared_ptr<T>& operator=(shared_ptr<T>& another);
    shared_ptr<T>& operator=(shared_ptr<T>&& another);
    T* operator->();
    T& operator[](int index);

    template <typename... Args>
    static shared_ptr<T> make_shared(Args&&... args)
    {
        return shared_ptr<T>(new T(std::forward<T>(args)...));
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
    if(controlPtr->ptr!=nullptr)
    {
    --(controlPtr->shared_count);
    if(controlPtr->shared_count==0) delete controlPtr->ptr;
    controlPtr->ptr=other;
    if(other)
    controlPtr->shared_count=1;
    else controlPtr->shared_count=0;
    }
    else
    {
        controlPtr->ptr = other;
        controlPtr->shared_count = 1;
    }
}

template<class T>
void shared_ptr<T>::swap(shared_ptr<T>& another)
{
    T* temp = controlPtr->ptr;
    int count_temp = controlPtr->shared_count;
    controlPtr->ptr = another.controlPtr->ptr;
    controlPtr->shared_count = another.controlPtr->shared_count;
    another.controlPtr->ptr = temp;
    another.controlPtr->shared_count = count_temp;
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
    return controlPtr->ptr==nullptr;
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
    {
        --(controlPtr->shared_count);
        if(controlPtr->shared_count == 0) delete controlPtr->ptr;
    }

    controlPtr->ptr = another.controlPtr->ptr;
    (another.controlPtr->shared_count)++;
    controlPtr->shared_count++;
    return *this;
}

template<class T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T>&& another)
{
    if(controlPtr)
        --(controlPtr->shared_count);

    controlPtr=another.controlPtr;
    another.controlPtr = nullptr;

    return *this;
}

template<class T>
T* shared_ptr<T>::operator->()
{
    return controlPtr->ptr;
}

template<class T>
T& shared_ptr<T>::operator [](int index)
{
    return controlPtr->ptr[index];
}


template <typename T>
class week_ptr
{
public:
    week_ptr(const shared_ptr<T>& ptr) : control(ptr.controlPtr) {}
    week_ptr();
    ~week_ptr()
    {
        control->week_count--;
        if(control->week_count==0 && control->shared_count==0)
        {
            delete control; //?
            control = nullptr;
        }
    }

    void reset();
    void swap(week_ptr<T>& other);
    size_t use_count();
    shared_ptr<T> lock();
    bool expired() const;

    static shared_ptr<T> make_shared(const week_ptr<T>& ptr)
    {
        return shared_ptr<T>(ptr);
    }

private:
    controlBlock<T>* control;
};

template <typename T>
void week_ptr<T>::reset()
{
    control? control->week_count-- : control = nullptr;
}

template <typename T>
void week_ptr<T>::swap(week_ptr<T>& other)
{
    std::swap(control,other.control);
}

template <typename T>
size_t week_ptr<T>::use_count()
{
    return control->shared_count;
}

template <typename T>
shared_ptr<T> week_ptr<T>::lock()
{
    if(!expired())
        return shared_ptr<T>(*this);
    else return shared_ptr<T>();
}

template <typename T>
bool week_ptr<T>::expired() const
{
    return control->shared_count>0;
}

//template <class T>
//class shared_ptr<T[]>
//{
//public:
//    shared_ptr() : controlPtr(nullptr) {}
//    shared_ptr(T* ptr) : controlPtr(new controlBlock<T>)
//    {
//        controlPtr->ptr=ptr;
//        ++controlPtr->shared_count;
//    }
//    shared_ptr(shared_ptr<T>& other)
//    {
//        controlPtr=other.controlPtr;
//        if(controlPtr) ++controlPtr->shared_count;
//    }
//    ~shared_ptr()
//    {
//        --(controlPtr->shared_count);
//        if(controlPtr->shared_count>0) return;
//        if(controlPtr->shared_count==0)
//        {
//            delete[] controlPtr->ptr;
//            controlPtr->ptr=nullptr;
//            qDebug()<<"Деструктор share_ptr вызван";
//        }
//    }

//    T* get();
//    void reset();
//    void swap(shared_ptr<T>& another);
//    bool unique();
//    int use_count();

//    operator bool();
//    T& operator*();
//    shared_ptr<T>& operator=(shared_ptr<T>& another);
//    T* operator->();
//    T& operator[](int index);

//private:
//    controlBlock<T>* controlPtr = nullptr;
//};


//template<class T>
//T* shared_ptr<T[]>::get()
//{
//    return controlPtr->ptr? controlPtr->ptr : nullptr;
//}


//template<class T>
//void shared_ptr<T[]>::reset()
//{
//    if(controlPtr)
//        --(controlPtr->shared_count);
//    controlPtr=nullptr;
//}


//template<class T>
//void shared_ptr<T[]>::swap(shared_ptr<T>& another)
//{
//    std::swap(controlPtr,another.controlPtr);
//}


//template<class T>
//bool shared_ptr<T[]>::unique()
//{
//    return !(controlPtr->shared_count-1);
//}


//template<class T>
//int shared_ptr<T[]>::use_count()
//{
//    return controlPtr? controlPtr->shared_count : 0;
//}


//template<class T>
//shared_ptr<T[]>::operator bool()
//{
//    return controlPtr->ptr!=nullptr;
//}


//template<class T>
//T& shared_ptr<T[]>::operator*()
//{
//    return *(controlPtr->ptr);
//}


//template<class T>
//shared_ptr<T>& shared_ptr<T[]>::operator=(shared_ptr<T>& another)
//{
//    if(controlPtr)
//        --(controlPtr->shared_count);

//    controlPtr->ptr=another.controlPtr->ptr;
//    another.controlPtr = nullptr;

//    return *this;
//}


//template<class T>
//T* shared_ptr<T[]>::operator->()
//{
//    return controlPtr->ptr;
//}

//template <class T>
//T& shared_ptr<T[]>::operator[](int index)
//{
//    return controlPtr->ptr[index];
//}

#endif // SHARED_PTR_H
