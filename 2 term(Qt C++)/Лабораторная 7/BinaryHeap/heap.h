#ifndef HEAP_H
#define HEAP_H
#include <QString>
#include <QTreeWidget>
#include <QDebug>
#include "shared_ptr.h"
#include <memory>

template <typename T>
class heap
{
public:
    heap() : _size(1), _heap(new T[_size]){}
    heap(int size) : _size(size), _heap(new T[_size]) {}
    ~heap(){delete[] _heap;}

    void insert(T value);
    T peek();
    T* get_root();
    void pop();
    void heapify_up(int index);
    void heapify_down(int index);
    void replace(int index, const T& new_value);
    void remove(int index);
    size_t size();
    bool is_empty();
    void clear();
    void print_heap(QTreeWidget* treeWidget, QTreeWidgetItem* parent,int i);
    T operator[](int index);

protected:
    void resize();

private:
    size_t _size;
    size_t elements_amount = 0;
    T* _heap = nullptr;
};

template<typename T>
void heap<T>::insert(T value) //add resize
{
    if(elements_amount == _size) resize();
    _heap[elements_amount] = value;
    heapify_up(elements_amount++);
}

template<typename T>
T heap<T>::peek()
{
    if(!is_empty())
        return _heap[0];
}

template<typename T>
T* heap<T>::get_root()
{
    if(!is_empty())
   return _heap;
}

template<typename T>
void heap<T>::pop() //delete max element
{
    if(!is_empty())
    {
        qDebug()<<"mama"<<QString::number(elements_amount);
        std::swap(_heap[0],_heap[elements_amount-1]);
        elements_amount--;
        heapify_down(0);
    }
}

template<typename T>
void heap<T>::heapify_up(int index)
{
    int i = index;
    int parent = (i-1)/2;

    while(i && _heap[i] > _heap[parent])
    {
        std::swap(_heap[i],_heap[parent]);
        i = parent;
        parent = (i-1)/2;
    }
    return;
}

template<typename T>
void heap<T>::heapify_down(int index)
{
    int parent = index;
    int left_child = parent*2 + 1;
    int right_child = parent*2 + 2;

    if(left_child < elements_amount && _heap[left_child] > _heap[parent])
        parent = left_child;
    if(right_child < elements_amount && _heap[right_child] > _heap[parent])
        parent  = right_child;

    if(parent!=index)
    {
    std::swap(_heap[index],_heap[parent]);
    heapify_down(parent);
    }
}

template<typename T>
void heap<T>::replace(int index, const T& new_value)
{
    if(index < elements_amount)
    {
        _heap[index] = new_value;
        heapify_down(index);
    }
}

template<typename T>
void heap<T>::remove(int index)
{
    if(index < _size)
    {
        std::swap(_heap[index],_heap[elements_amount-1]);
        elements_amount--;
        heapify_down(index);
    }
}

template<typename T>
size_t heap<T>::size()
{
    return elements_amount;
}

template<typename T>
bool heap<T>::is_empty()
{
    return elements_amount == 0;
}

template<typename T>
void heap<T>::clear()
{
    delete[] _heap;
    _size = 1;
    elements_amount = 0;
    _heap = new T[_size];
}

template<typename T>
void heap<T>::print_heap(QTreeWidget *treeWidget, QTreeWidgetItem *parent,int i)
{
    if(i < size())
    {
    QTreeWidgetItem* it = new QTreeWidgetItem;
    it->setText(0,QString::number(_heap[i]));
    if(i==0)
        treeWidget->addTopLevelItem(it);
    else
        parent->addChild(it);

    print_heap(treeWidget,it,2*i+1);
    print_heap(treeWidget,it,2*i+2);
    }
}

template<typename T>
T heap<T>::operator[](int index)
{
    if(index < elements_amount)
    return _heap[index];
}

template<typename T>
void heap<T>::resize()
{
    size_t old_size = _size;
    _size*=2;
    T* new_arr = new T[_size];
    for(int i = 0; i < old_size; i++)
    {
        new_arr[i] = _heap[i];
    }
    delete[] _heap;
    _heap = new_arr;
}

#endif // HEAP_H
