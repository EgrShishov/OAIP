#ifndef LIST_H
#define LIST_H

#include <qDebug>
#include "workshop.h"

struct Node
{
    workshop data;
    Node* prev;
    Node* next;
    Node(workshop data) : data(data), next(nullptr), prev(nullptr){}
    Node(){}
};

class list
{
public:

    list();
//    list(list& List)
//    {
//        for(int i = 0; i < List.size(); i++)
//          {
//               pushBack(List[i]->data);
//           }
//    }
    ~list();

//    void operator=(list temp)
//    {
//        if(this -> head != nullptr)
//        {
//           this -> clear();
//        }
//        for(int i = 0; i < temp.size(); i++)
//        {
//            this -> pushBack(temp[i]->data);
//        }
//    }

    class iterator
    {
    public:
        iterator(){}
        iterator(Node* ptr, list* List) : ptr(ptr), List(List){}
        ~iterator(){}

        void operator++()
        {
          if (ptr) ptr = ptr->next;
        }

        Node operator*()
        {
            if (ptr)
            {
            return ptr->data;
            }
        }

        bool operator!=(const iterator& it)
        {
         return !(List == it.List && ptr == it.ptr);
        }

    private:
        Node* ptr = nullptr;
        list* List = nullptr;
    };

    void pushFront(workshop data);

    void pushBack(workshop data);

    void popFront();

    void popBack();

    Node* getAt(int index);

    Node* operator [] (int index);

    void insert(int index, workshop data);

    void erase(int index);

    int size();

    void clear();

    bool isEmpty();

    void mergeSort(list& List);

    iterator begin() { return iterator(head, this); }

    iterator end() { return iterator(tail, this); }

private:
    static void advance(Node*& node)
    {
        assert(node != nullptr);
        node = node->next;
    }


private:
    Node* head;
    Node* tail;
    int _size=0;
};

void sort();
void partition();
#endif // LIST_H
