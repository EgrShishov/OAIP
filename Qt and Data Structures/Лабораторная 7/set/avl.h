#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <QString>

template <typename KeyType>
class Node{
public:
    KeyType key;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* next = nullptr;
    Node* prev = nullptr;
    size_t height = -1;
    Node() {}
    Node(KeyType key) : key(key), height(0){}
};

template <typename KeyType>
class AVL
{
public:
    AVL();
    ~AVL();

    void insert(Node<KeyType>*& node, KeyType key);
    Node<KeyType>* remove(Node<KeyType>* node, KeyType key);
    Node<KeyType>* find(Node<KeyType>* node, KeyType key);
    Node<KeyType>*& get_root();
    bool contains(Node<KeyType>* node, KeyType key);
    void clear() {delete_tree(root); head=nullptr; tail=nullptr;}

    void preorder_print(Node<KeyType>* root, QString& ans)
    {
        if(root!=nullptr)
        {
        ans += root->key + ", ";
        preorder_print(root->left,ans);
        preorder_print(root->right,ans);
        }
    }
    Node<KeyType>*& get_head()
    {
        return head;
    }
    Node<KeyType>*& get_tail()
    {
        return tail;
    }
    void list_print()
    {
        Node<KeyType>* _head = head;
        while(_head!=nullptr)
        {
            qDebug()<<_head->key;
            _head = _head->next;
        }
    }

protected:
    void balance(Node<KeyType>* root);
    size_t get_balance(Node<KeyType>* root);
    size_t get_height(Node<KeyType>* node);
    void update_height(Node<KeyType>* node);
    void rotate_right(Node<KeyType>*& node);
    void rotate_left(Node<KeyType>*& node);
    Node<KeyType>* get_min(Node<KeyType>* root);

private:
    void delete_tree(Node<KeyType>* root)
    {
        if(root!=nullptr)
        {
            delete_tree(root->left);
            delete_tree(root->right);
            delete root;
        }
    }
    Node<KeyType>* root = nullptr;
    Node<KeyType>* head = nullptr;
    Node<KeyType>* tail = nullptr;
};

template<typename KeyType>
AVL<KeyType>::AVL()
{

}

template<typename KeyType>
AVL<KeyType>::~AVL()
{
    delete_tree(root);
}

template<typename KeyType>
void AVL<KeyType>::insert(Node<KeyType> *& node, KeyType key)
{
    if(node == nullptr)
    {
        node = new Node<KeyType>(key);
        head = tail = node;
        return;
    }

    else if(key < node->key)
    {
        if(node->left==nullptr)
        {
            node->left = new Node<KeyType>(key);
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
            insert(node->left,key);
    }
    else if(key >= node->key)
    {
        if(node->right==nullptr)
        {
            node->right = new Node<KeyType>(key);
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
            insert(node->right,key);
    }
    update_height(node);
    balance(node);
}

template<typename KeyType>
Node<KeyType>* AVL<KeyType>::remove(Node<KeyType> *node, KeyType key)
{
    if(node==nullptr) return nullptr;
    else if(key < node->key)
        node->left = remove(node->left,key);
    else if(key > node->key)
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
           Node<KeyType>* tmp = node->right;
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
           Node<KeyType>* tmp = node->left;
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
        Node<KeyType>* min = get_min(node->right);
        node->key=min->key;
        node->left = min->left;
        node->right = min->right;
        remove(node->right,min->key);
    }
    if(node!=nullptr)
    {
        update_height(node);
        balance(node);
    }
    return node;
}

template<typename KeyType>
Node<KeyType> *AVL<KeyType>::find(Node<KeyType> *node, KeyType key)
{
    if(node==nullptr) return nullptr;
    if(node->key == key) return node;
    return key < node->key ? find(node->left,key) : find(node->right,key);
}

template<typename KeyType>
Node<KeyType> *&AVL<KeyType>::get_root()
{
    return root;
}

template<typename KeyType>
bool AVL<KeyType>::contains(Node<KeyType> *node, KeyType key)
{
    Node<KeyType>* cur = root;
    while(cur!=nullptr)
    {
        if(cur->key==key) return true;
        else if(cur->key > key)
            cur = cur->left;
        else if(cur->key < key)
            cur = cur->right;
    }
    return false;
}

template<typename KeyType>
void AVL<KeyType>::balance(Node<KeyType> *root)
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

template<typename KeyType>
size_t AVL<KeyType>::get_balance(Node<KeyType> *root)
{
    return root == nullptr? 0 : get_height(root->right) - get_height(root->left);
}

template<typename KeyType>
size_t AVL<KeyType>::get_height(Node<KeyType> *node)
{
    return node == nullptr ? -1 : node->height;
}

template<typename KeyType>
void AVL<KeyType>::update_height(Node<KeyType> *node)
{
    node->height = std::max(get_height(node->left),get_height(node->right)) + 1;
}

template<typename KeyType>
void AVL<KeyType>::rotate_right(Node<KeyType> *&node)
{
//    swap(node,node->left);
//    Node<KeyType>* buf = node->right;
//    node->right = node->left;
//    node->left = node->right->left;
//    node->right->left = node->right->right;
//    node->right->right = buf;    

    Node<KeyType> *ptr = node->left->right;
    node->left->right = ptr;
    ptr = ptr->left;
    ptr->left = ptr->right;

    update_height(node->right);
    update_height(node);
}

template<typename KeyType>
void AVL<KeyType>::rotate_left(Node<KeyType> *&node)
{
//    swap(node,node->right);
//    Node<KeyType>* buf = node->left;
//    node->left = node->right;
//    node->right = node->left->right;
//    node->left->right = node->left->left;
//    node->left->left = buf;

    Node<KeyType> *ptr = node->right->left;
    node->right->left = node;
    node = node->right;
    node->left->right=ptr;

    update_height(node->left);
    update_height(node);
}

template<typename KeyType>
Node<KeyType> *AVL<KeyType>::get_min(Node<KeyType> *root)
{
    if(root==nullptr) return nullptr;
    if(root->right==nullptr) return root;
    else return get_min(root->left);
}


template <typename KeyType>
class list_iterator
{
public:
    list_iterator(){}
    list_iterator(Node<KeyType>* head,Node<KeyType>* tail,Node<KeyType>* cur) : head(head),cur(cur),tail(tail){}
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
    Node<KeyType>* operator ->()
    {
        if(cur!=nullptr)
            return cur;
    }
    Node<KeyType>& operator*()
    {
        if(cur!=nullptr)
            return *cur;
    }

private:
    Node<KeyType>* head = nullptr;
    Node<KeyType>* tail = nullptr;
    Node<KeyType>* cur = nullptr;
};


template <typename KeyType>
class iterator
{
public:
    iterator(){}
    iterator(iterator& other) : root(other.root) , cur(other.cur) {}
    iterator(Node<KeyType>* root, Node<KeyType>* node) : root(root) , cur(node){}
    ~iterator(){}


    Node<KeyType>* next()
    {

    }
    KeyType& operator*()
    {
        if(root!=nullptr)
        return *root->key;
    }
    KeyType* operator->()
    {
        if(root!=nullptr)
        return root->key;
    }
    iterator& operator= (const iterator& other)
    {
        root = other.root;
        cur = other.cur;
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
    Node<KeyType>* root = nullptr;
    Node<KeyType>* cur = nullptr;
};

#endif // AVL_H
