#ifndef STACK_H
#define STACK_H

template <typename T> class Stack
{
public:
    Stack() : root(nullptr){}
    ~Stack()
    {
        while(!isEmpty())
        {
            pop();
        }
    }
    void push(const T& data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = root;
        root = newNode;
    }
    T pop()
    {
        if(isEmpty())
        {
            //throw length_error("stack is empty");
        }
        else
        {
            Node* delNode = root;
            T tmp = delNode->data;
            root = delNode->next;
            delete delNode;
            return tmp;
        }

    }

    T top() const
    {

        if(isEmpty())
        {
           //throw length_error("stack is empty");
        }
        else
        {
            return root->data;
        }

    }
    int size()
    {
        int size = 0;

        Node* current;

        for(current = root;current!=nullptr;current=current->next)
            size++;

        return size;
    }
    bool isEmpty() const
    {
        return root == nullptr;
    }
private:
    struct Node
    {
      T data;
      Node* next;
    };
    Node* root;
};


#endif // STACK_H
