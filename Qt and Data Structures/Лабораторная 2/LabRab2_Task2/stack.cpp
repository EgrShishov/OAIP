#include "stack.h"

//void Stack::push(const T& data)
//{
//    Node* newNode = new Node;
//    newNode->data = data;
//    newNode->next = root;
//    root = newNode;
//}

//T Stack<T>::pop()
//{
//    if(isEmpty())
//    {
//        throw length_error("stack is empty");
//    }
//    else
//    {
//        Node* delNode = root;
//        T tmp = delNode->data;
//        root = delNode->next;
//        delete delNode;
//        return tmp;
//    }

//}

//T Stack<T>::top() const
//{

//    if(isEmpty())
//    {
//        throw length_error("stack is empty");
//    }
//    else
//    {
//        return root->data;
//    }

//}

//int Stack<T>::size()
//{
//    int size = 0;

//    Node* current;

//    for(current = top;current!=nullptr;current=current->next)
//        size++;

//    return size;
//}

//bool Stack<T>::isEmpty() const
//{
//    return root == nullptr;
//}
