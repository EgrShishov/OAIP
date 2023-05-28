#include "list.h"

list::list()
{
    head=tail=nullptr;
    _size=0;
}
list::~list()
{
    while(head!=nullptr)
    {
        popFront();
    }

}

void list::pushFront(workshop data)
{
    Node* ptr = new Node(data);

    if(head==nullptr && tail==nullptr) head=tail=ptr;
    else
    {
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }


    qDebug()<<ptr;
}

void list::pushBack(workshop data)
{
    Node* ptr = new Node(data);

    if(head==nullptr && tail==nullptr) head=tail=ptr;
    else
    {
        ptr->prev=tail;
        tail->next=ptr;
        tail=ptr;
    }
    _size++;

    qDebug() << ptr;
}

void list::popFront()
{
    if (head==nullptr)
    {
        return;
    }

    Node* ptr = head->next;
    if(ptr!=nullptr)
    {
        ptr->prev = nullptr;
    }
    else
    {
        tail = ptr;
    }

    delete head;
    _size--;
    head = ptr;
}

void list::popBack()
{
    if (tail==nullptr)
    {
        return;
    }

    Node* ptr = head->prev;
    if(ptr!=nullptr)
    {
        ptr->next = nullptr;
    }
    else
    {
        head = ptr;
    }

    delete tail;
    tail = ptr;
}

Node* list::getAt(int index)
{
    Node* data = head;
    int n = 0;

    while(n!=index)
    {
        if(data==nullptr)
        {
            return data;
        }

        data = data->next;
        n++;

    }
    return data;
}

Node* list::operator [] (int index)
{
    return getAt(index);
}

void list::insert(int index, workshop data)
{
    Node* right = getAt(index);
    if(right==nullptr)
    {
        return pushBack(data);
    }

    Node* left=right->prev;
    if(left==nullptr)
    {
        return pushFront(data);
    }

    Node* ptr = new Node(data);

    ptr->prev=left;
    ptr->next=right;
    left->next=ptr;
    right->prev=ptr;

   qDebug()<<ptr;
}

void list::erase(int index)
{
//    Node* data = getAt(index);
//    if(data==nullptr)
//    {
//        return;
//    }

//    if(data->prev==nullptr)
//    {
//        popFront();
//        return;
//    }

//    if(data->next==nullptr)
//    {
//        popBack();
//        return;
//    }

//    Node* left = data->prev;
//    Node* right = data->next;
//    left->next=right;
//    right->prev=left;
//    _size--;

//    delete data;

    if (index == 0)
           {
               popFront();
           }
           else
           {
               Node *previous = this->head;
               for (int i = 0; i < index - 1; i++)
               {
                   previous = previous->next;
               }


               Node *toDelete = previous->next;

               previous->next = toDelete->next;

               delete toDelete;

               _size--;
           }
    //remake

}

int list::size()
{
    return _size;
}

bool list::isEmpty()
{
    return _size==0;
}

void list::clear()
{
    while(head!=nullptr)
    {
        popFront();
    }
}
