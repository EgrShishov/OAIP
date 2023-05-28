#ifndef STACK_H
#define STACK_H
#include <QChar>
template <typename T>
class Stack
{
public:
    Stack() : root(nullptr){}
    ~Stack()
    {
        delete root;
    }

    T pop()
    {
       if(!isEmpty())
       {
           Node* delNode = root;
           T tmp = delNode->data;
           root=delNode->next;
           delete delNode;
           return tmp;
       }
    }

    T top() const
    {
        if(root!=nullptr)
        {
            return root->data;
        }
    }

    void push(const T& data)
    {
        Node* newData = new Node;
        newData->data=data;
        newData->next=root;
        root = newData;
    }

    int size()
    {
        int size = 0;

        Node* current;

        for(current = root;current!=nullptr;current=current->next)
            size++;

        return size;
    }

    bool isEmpty()
    {
       return root == nullptr;
    }

private:
    struct Node
    {
        Node* next;
        T data;
    };
    Node* root;
};

#endif // STACK_H
