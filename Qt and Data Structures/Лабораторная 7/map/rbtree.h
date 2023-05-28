#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <QString>
#include <stack>
#include <list>

template <typename KeyType, typename ValueType>
class Node{
public:
    std::pair<KeyType,ValueType> data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Node* next = nullptr;
    Node* prev = nullptr;
    size_t height = -1;
    Node() {}
    Node(KeyType key, ValueType value) : data(std::make_pair(key,value)), height(0){}
};

template <typename KeyType, typename ValueType>
class AVL
{
public:
    AVL();
    ~AVL();

    void insert(Node<KeyType,ValueType>*& node, KeyType key, ValueType value);
    Node<KeyType, ValueType>* remove(Node<KeyType,ValueType>* node, KeyType key);
    Node<KeyType,ValueType>* find(Node<KeyType,ValueType>* node, KeyType key);
    Node<KeyType,ValueType>*& get_root();
    Node<KeyType,ValueType>*& get_head()
    {
        return head;
    }
    Node<KeyType,ValueType>*& get_tail()
    {
        return tail;
    }
    bool contains(Node<KeyType,ValueType>* node, KeyType key);
    bool empty(){return root==nullptr;}
    void list_print()
    {
        Node<KeyType,ValueType>* _head = head;
        while(_head!=nullptr)
        {
            qDebug()<<_head->data;
            _head = _head->next;
        }
    }

    void clear() {delete_tree(root); head=nullptr;tail=nullptr;}

    void preorder_print(Node<KeyType,ValueType>* root, QString& ans)
    {
        if(root!=nullptr)
        {
        ans += root->data.second + ", ";
        preorder_print(root->left,ans);
        preorder_print(root->right,ans);
        }
    }

protected:
    void balance(Node<KeyType,ValueType>* root);
    void update_next_prev(Node<KeyType,ValueType>* node);
    size_t get_balance(Node<KeyType,ValueType>* root);
    size_t get_height(Node<KeyType,ValueType>* node);
    void update_height(Node<KeyType,ValueType>* node);
    void rotate_right(Node<KeyType,ValueType>*& node);
    void rotate_left(Node<KeyType,ValueType>*& node);
    Node<KeyType,ValueType>* get_min(Node<KeyType,ValueType>* root);
    Node<KeyType,ValueType>* get_max(Node<KeyType,ValueType>* root);
    void swap(Node<KeyType,ValueType>* node1, Node<KeyType,ValueType>* node2)
    {
        KeyType node1_key = node1->data.first;
        node1->data.first = node2->data.first;
        node2->data.first = node1_key;

        ValueType node1_value = node1->data.second;
        node1->data.second = node2->data.second;
        node2->data.second = node1_value;

    }

private:
    void delete_tree(Node<KeyType,ValueType>* root)
    {
        if(root!=nullptr)
        {
            delete_tree(root->left);
            delete_tree(root->right);
            delete root;
        }
    }
    Node<KeyType,ValueType>* root = nullptr;
    Node<KeyType,ValueType>* head = nullptr;
    Node<KeyType,ValueType>* tail = nullptr;

    template <typename U,typename V>
    friend class iterator;
    template <typename U,typename V>
    friend class list_iterator;
};

template<typename KeyType, typename ValueType>
AVL<KeyType, ValueType>::AVL()
{

}

template<typename KeyType, typename ValueType>
AVL<KeyType, ValueType>::~AVL()
{
    delete_tree(root);
}

template<typename KeyType, typename ValueType>
void AVL<KeyType, ValueType>::insert(Node<KeyType, ValueType> *& node, KeyType key, ValueType value)
{
    if(node == nullptr)
    {
        node = new Node<KeyType,ValueType>(key,value);
        head = tail = node;
        return;
    }
    else if(key < node->data.first)
    {
        if(node->left==nullptr)
        {
            node->left = new Node<KeyType,ValueType>(key,value);
            if(node==head)
            {
                head = node->left;
                node->left->next = node;
                node->prev = node->left;
            }
            else
            {
                node->left->next = node;
                node->prev->next = node->left;
                node->left->prev = node->prev;
                node->prev = node->left;
            }
        }
        else
            insert(node->left,key,value);
    }
    else if(key >= node->data.first)
    {
        if(node->right==nullptr)
        {
            node->right = new Node<KeyType,ValueType>(key,value);
            if(node==tail)
            {
                tail = node->right;
                node->right->prev = node;
                node->next = node->right;
            }
            else
            {
                node->right->prev = node;
                node->next->prev = node->right;
                node->right->next = node->next;
                node->next = node->right;
            }
        }
        else
            insert(node->right,key,value);
    }
    update_height(node);
    balance(root);

}

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType>* AVL<KeyType, ValueType>::remove(Node<KeyType, ValueType> *node, KeyType key)
{
    if(node==nullptr) return nullptr;
    else if(key < node->data.first)
        node->left = remove(node->left,key);
    else if(key > node->data.first)
        node->right = remove(node->right,key);
    else
    {
        if(node->left==nullptr && node->right==nullptr)
        {
            if (node == head)
                head = node->next;
            if (node == tail)
                tail = node->prev;
            if (node->prev != nullptr)
            {
                node->prev->next = node->next;
                node->prev = nullptr;
            }
            if (node->next != nullptr)
            {
                node->next->prev = node->prev;
                node->next = nullptr;
            }
            delete node;
            return nullptr;
        }
        if(node->left==nullptr)
        {
           Node<KeyType,ValueType>* tmp = node->right;
           if(node == head)
           {
               head = head->next;
               //if(head!=nullptr) head->prev = nullptr;
           }
           if(node == tail)
           {
               tail = node->prev;
//               if(tail!=nullptr) tail->next = nullptr;
           }
           if(node->prev!=nullptr) node->prev->next = node->next;
           if(node->next!=nullptr) node->next->prev = node->prev;
           delete node;
           return tmp;
        }
        if(node->right==nullptr)
        {
           Node<KeyType,ValueType>* tmp = node->left;
           if(node == head)
           {
               head = head->next;
               //if(head!=nullptr) head->prev = nullptr;
           }
           if(node == tail)
           {
               tail = node->prev;
               //if(tail!=nullptr) tail->next = nullptr;
           }
           if(node->prev!=nullptr) node->prev->next = node->next;
           if(node->next!=nullptr) node->next->prev = node->prev;
           delete node;
           return tmp;
        }
        Node<KeyType,ValueType>* min = get_min(node->right);
        node->data=min->data;
        node->left = min->left;
        node->right = min->right;
        remove(node->right,min->data.first);
    }
    if(node!=nullptr)
    {
        update_height(node);
        balance(node);
    }
    return node;
}

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType> *AVL<KeyType, ValueType>::find(Node<KeyType, ValueType> *node, KeyType key)
{
    if(node==nullptr) return nullptr;
    if(node->data.first == key) return node;
    return key < node->data.first ? find(node->left,key) : find(node->right,key);
}

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType> *&AVL<KeyType, ValueType>::get_root()
{
    return root;
}

template<typename KeyType, typename ValueType>
bool AVL<KeyType, ValueType>::contains(Node<KeyType, ValueType> *node, KeyType key)
{
    Node<KeyType,ValueType>* cur = root;
    while(cur!=nullptr)
    {
        if(cur->data.first==key) return true;
        else if(cur->data.first > key)
            cur = cur->left;
        else if(cur->data.first < key)
            cur = cur->right;
    }
    return false;
}

template<typename KeyType, typename ValueType>
void AVL<KeyType, ValueType>::balance(Node<KeyType, ValueType> *root)
{
    if(root==nullptr) return;
    int balance = get_balance(root);
    if(balance == -2)
    {
        if(get_balance(root->left) == 1) rotate_left(root->left);
        rotate_right(root);
    }
    else if(balance == 2)
    {
        if(get_balance(root->right) == -1) rotate_right(root->right);
        rotate_left(root);
    }
}

template<typename KeyType, typename ValueType>
void AVL<KeyType, ValueType>::update_next_prev(Node<KeyType, ValueType> *node)
{
    if(node == nullptr) return;
    if(node->right != nullptr)
    {
        Node<KeyType,ValueType>* cur = node->right;
        while(cur->left!=nullptr)
            cur = cur->left;

        node->next = cur;
        cur->prev = node;
    }
    else
        node->next = nullptr;

    if(node->left != nullptr)
    {
        Node<KeyType,ValueType>* cur = node->left;
        while(cur->right!=nullptr)
            cur = cur->right;

        node->prev = cur;
        cur->next = node;
    }
    else
        node->prev = nullptr;

    update_next_prev(node->left);
    update_next_prev(node->right);

}

template<typename KeyType, typename ValueType>
size_t AVL<KeyType, ValueType>::get_balance(Node<KeyType, ValueType> *root)
{
    return root == nullptr? 0 : get_height(root->right) - get_height(root->left);
}

template<typename KeyType, typename ValueType>
size_t AVL<KeyType, ValueType>::get_height(Node<KeyType, ValueType> *node)
{
    return node == nullptr ? -1 : node->height;
}

template<typename KeyType, typename ValueType>
void AVL<KeyType, ValueType>::update_height(Node<KeyType, ValueType> *node)
{
    node->height = std::max(get_height(node->left),get_height(node->right)) + 1;
}

template<typename KeyType, typename ValueType>
void AVL<KeyType, ValueType>::rotate_right(Node<KeyType, ValueType> *&node)
{
//    swap(node,node->left);
//    Node<KeyType,ValueType>* buf = node->right;
//    node->right = node->left;
//    node->left = node->right->left;
//    node->right->left = node->right->right;
//    node->right->right = buf;

    Node<KeyType,ValueType> *ptr = node->left->right;
    node->left->right = ptr;
    ptr = ptr->left;
    ptr->left = ptr->right;

    update_height(node->right);
    update_height(node);
}

template<typename KeyType, typename ValueType>
void AVL<KeyType, ValueType>::rotate_left(Node<KeyType, ValueType> *&node)
{
//    swap(node,node->right);
//    Node<KeyType,ValueType>* buf = node->left;
//    node->left = node->right;
//    node->right = node->left->right;
//    node->left->right = node->left->left;
//    node->left->left = buf;

    Node<KeyType,ValueType> *ptr = node->right->left;
    node->right->left = node;
    node = node->right;
    node->left->right=ptr;

    update_height(node->left);
    update_height(node);
}

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType> *AVL<KeyType, ValueType>::get_min(Node<KeyType, ValueType> *root)
{
    if(root==nullptr) return nullptr;
    if(root->right==nullptr) return root;
    else return get_min(root->left);
}

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType> *AVL<KeyType, ValueType>::get_max(Node<KeyType, ValueType> *root)
{
    if(root==nullptr) return nullptr;
    if(root->left==nullptr) return root;
    else return get_max(root->right);
}

template <typename KeyType, typename ValueType>
class iterator
{
public:
    iterator(){}
    iterator(iterator& other) : root(other.root) , cur(other.cur) {}
    iterator(Node<KeyType,ValueType>* root, Node<KeyType,ValueType>* node) : root(root) , cur(node){}
    ~iterator(){}


    Node<KeyType,ValueType>* next()
    {
        Node<KeyType,ValueType>* tmp = root->left;
        std::stack<Node<KeyType,ValueType>*> nodes;
        while (tmp != nullptr)
        {
           nodes.push(tmp);
           tmp = tmp->left;
        }

        Node<KeyType,ValueType>* current = nodes.top();
        nodes.pop();

        if (current->right != nullptr)
        {
           Node<KeyType,ValueType>* node = current->right;
           while (node != nullptr)
           {
               nodes.push(node);
               node = node->left;
           }
        }

        return current;
    }
    ValueType& operator*()
    {
        if(root!=nullptr)
        return *root->data.second;
    }
    ValueType* operator->()
    {
        if(root!=nullptr)
        return root->data.second;
    }
    iterator& operator= (const iterator& other)
    {
        root = other.root;
        return *this;
    }
    bool operator==(const iterator& other)
    {
        return root==other.root && cur==other.cur;
    }
    bool operator!=(const iterator& other)
    {
        return root!=other.root || cur!=other.cur;
    }

private:
    Node<KeyType,ValueType>* root = nullptr;
    Node<KeyType,ValueType>* cur = nullptr;
};

template <typename KeyType, typename ValueType>
class list_iterator
{
public:
    list_iterator(){}
    list_iterator(Node<KeyType,ValueType>* head,Node<KeyType,ValueType>* tail,Node<KeyType,ValueType>* cur) : head(head),cur(cur),tail(tail){}
    ~list_iterator(){}

    list_iterator& operator ++()
    {
        if(cur!=nullptr)
        cur = cur->next;
        return *this;
    }
    list_iterator& operator ++(int)
    {
        list_iterator tmp = *this;
        if(cur!=nullptr)
            cur = cur->next;
        return tmp;
    }
    list_iterator& operator --()
    {
        if(cur!=nullptr)
            cur = cur->prev;
        return *this;
    }
    list_iterator& operator --(int)
    {
        list_iterator tmp = *this;
        if(cur!=nullptr)
            cur = cur->prev;
        return tmp;
    }

    bool operator ==(const list_iterator& other)
    {
        return other.cur==cur && other.head==head && other.tail==tail;
    }
    bool operator !=(const list_iterator& other)
    {
         return other.cur!=cur || other.head!=head || other.tail!=tail;
    }
    list_iterator& operator=(const list_iterator& other)
    {
        cur = other.cur;
        head = other.head;
        tail = other.tail;
    }
    Node<KeyType,ValueType>* operator ->()
    {
        if(cur!=nullptr)
            return cur;
    }
    Node<KeyType,ValueType>& operator*()
    {
        if(cur!=nullptr)
            return *cur;
    }

private:
    Node<KeyType,ValueType>* head = nullptr;
    Node<KeyType,ValueType>* tail = nullptr;
    Node<KeyType,ValueType>* cur = nullptr;
};

#endif // RBTREE_H
