#ifndef LIST_HEAP_H
#define LIST_HEAP_H
#include <iostream>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>
#include <vector>
#include <list.h>

template <typename T>
class list_heap
{
public:
    list_heap() {}
    list_heap(size_t size) {}

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

private:
    size_t elements = 0;
    list<T> heap;
};

template<typename T>
void list_heap<T>::insert(T value)
{
    heap.push_back(value);
    heapify_up(elements++);
}

template<typename T>
T list_heap<T>::peek()
{
    return heap.front()->data;
}

template<typename T>
T *list_heap<T>::get_root()
{
    return heap.front();
}

template<typename T>
void list_heap<T>::pop()
{
    if(!heap.empty())
    {
        std::swap(heap[0],heap[elements]);
        elements--;
        heapify_down(0);
    }
}

template<typename T>
void list_heap<T>::heapify_up(int index)
{
    int i = index;
    int parent = (index - 1) / 2;

    while(i && heap[index] > heap[parent])
    {
        std::swap(heap[index],heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

template<typename T>
void list_heap<T>::heapify_down(int index)
{
    int largest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    if(left_child < elements && heap[left_child] > heap[largest])
        largest = left_child;
    if(right_child < elements && heap[right_child] > heap[largest])
        largest = right_child;

    if(largest!=index)
    {
        std::swap(heap[index],heap[largest]);
        heapify_down(largest);
    }
}

template<typename T>
void list_heap<T>::replace(int index, const T &new_value)
{
    if(!heap.empty() && index < elements)
    {
        heap[index] = new_value;
        heapify_down(index);
    }
}

template<typename T>
void list_heap<T>::remove(int index)
{
    if(!heap.empty() && index < elements)
    {
        std::swap(heap[index],heap[elements-1]);
        heap.pop_back();
        heapify_down(index);
        elements--;
    }
}

template<typename T>
size_t list_heap<T>::size()
{
    return heap.size();
}

template<typename T>
bool list_heap<T>::is_empty()
{
    return elements==0;
}

template<typename T>
void list_heap<T>::clear()
{
    elements = 0;
    heap.clear();
}

template<typename T>
void list_heap<T>::print_heap(QTreeWidget *treeWidget, QTreeWidgetItem *parent, int i)
{
    if(i < size())
    {
    QTreeWidgetItem* it = new QTreeWidgetItem;
    it->setText(0,QString::number(heap[i]));
    if(i==0)
        treeWidget->addTopLevelItem(it);
    else
        parent->addChild(it);

    print_heap(treeWidget,it,2*i+1);
    print_heap(treeWidget,it,2*i+2);
    }
}

template<typename T>
T list_heap<T>::operator[](int index)
{
    return heap.getAt(index)->data;
}

#endif // LIST_HEAP_H
