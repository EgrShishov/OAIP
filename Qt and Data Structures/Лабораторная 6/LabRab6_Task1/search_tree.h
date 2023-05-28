#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H
#include "iostream"
#include <QString>
#include <queue>
#include <QDebug>
#include <QTreeWidget>
#include <QTreeWidgetItem>

template <typename T>
class Node
{
public:
    int key;
    T value;
    size_t height = -1;
    Node* left = nullptr;
    Node* right = nullptr;
    Node() {}
    Node(int key, T value) : key(key), value(value), left(nullptr), right(nullptr), height(0){}
};

template <typename T>
class search_tree
{
private:
    Node<T>* root = nullptr;
    size_t size = 0;
public:
    search_tree() : root(nullptr), size(0) {}
    ~search_tree()
    {
        if(root!=nullptr)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
        qDebug()<<"tree destructor";
    }

    void rotate_left(Node<T>* root);
    void rotate_right(Node<T>* root);
    void balance(Node<T>* root);
    size_t get_balance(Node<T>* root);
    Node<T>* get_min(Node<T>* node);
    size_t get_height(Node<T>* node);
    void update_height(Node<T>* node);
    Node<T>*& get_root();
    void insert(Node<T>*& node, int key, T value);
    Node<T>* search(Node<T>* node,int key);
    Node<T>* _delete(Node<T>* node, int key);

    void swap(Node<T>* node1,Node<T>* node2);
    void preorder_print(Node<T>* root,QString& ans);
    void preorder_print(Node<T>* root,QTreeWidget* treeWidget, QTreeWidgetItem* parent);
    void postorder_print(Node<T>* root,QString& ans);
    void postorder_print(Node<T>* root,QTreeWidget* treeWidget, QTreeWidgetItem* parent);
    void key_print(Node<T>* root,QString& ans);
    void key_print(Node<T>* root,QTreeWidget* treeWidget, QTreeWidgetItem* parent);
    void depth_print(Node<T>* root,QString& ans);
    void load_from_array(Node<T>*& root,std::vector<std::pair<int,QString>>& array);

protected:
    void deleteTree(Node<T>* root)
    {
        if(root!=nullptr)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }
};

template<typename T>
void search_tree<T>::rotate_left(Node<T>* root)
{
    swap(root,root->right);
    Node<T>* buf = root->left;
    root->left = root->right;
    root->right = root->left->right;
    root->left->right = root->left->left;
    root->left->left = buf;
    update_height(root->left);
    update_height(root);
}

template<typename T>
void search_tree<T>::rotate_right(Node<T>* root)
{
    swap(root,root->left);
    Node<T>* buf = root->right;
    root->right = root->left;
    root->left = root->right->left;
    root->right->left = root->right->right;
    root->right->right = buf;
    update_height(root->right);
    update_height(root);
}

template<typename T>
void search_tree<T>::balance(Node<T>* root)
{
    int balance = get_balance(root);
    if(balance==-2)
    {
        if(get_balance(root->left) == 1) rotate_left(root->left);
        rotate_right(root);
    }
    else if(balance==2)
    {
        if(get_balance(root->right) == -1) rotate_right(root->right);
        rotate_left(root);
    }
}

template<typename T>
size_t search_tree<T>::get_balance(Node<T>* root)
{
    return (root==nullptr)? 0 : get_height(root->right) - get_height(root->left);
}

template<typename T>
size_t search_tree<T>::get_height(Node<T>* node)
{
    return (node==nullptr)? -1 : node->height;
}

template<typename T>
void search_tree<T>::update_height(Node<T>* node)
{
    node->height = std::max(get_height(node->left) + 1,get_height(node->right)+1);
}

template<typename T>
Node<T>*& search_tree<T>::get_root()
{
    return root;
}

template<typename T>
void search_tree<T>::insert(Node<T>*& node, int key, T value)
{
    if(node==nullptr)
    {
        node = new Node(key,value);
        return;
    }
    if(key < node->key)
    {
        if(node->left == nullptr)
            node->left = new Node(key,value);
        else insert(node->left,key,value);
    }
    else if(key >= node->key)
    {
        if(node->right == nullptr)
            node->right = new Node(key,value);
        else insert(node->right,key,value);
    }
    update_height(node);
    balance(node);
    //return node;//balance(node);
}

template<typename T>
Node<T>* search_tree<T>::search(Node<T>* node, int key)
{
    if(node == nullptr)
        return nullptr;
    if(node->key == key )
        return node;
    return key < node->key ? search(node->left,key) : search(node->right,key);
}

template<typename T>
Node<T>* search_tree<T>::_delete(Node<T>* node,int key) //доделать
{
    if(node==nullptr)
        return nullptr;
    else if(key<node->key)
        node->left = _delete(node->left,key);
    else if(key>node->key)
        node->right = _delete(node->right,key);
    else
    {
        if (node->left == nullptr) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }
        Node<T>* min = get_min(node->right);
        node->key = min->key;
        node->value = min->value;
        _delete(node->right, min->key);
    }
    if(node!=nullptr)
    {
        update_height(node);
        balance(node);
    }
    return node;
}

template<typename T>
void search_tree<T>::swap(Node<T>* node1, Node<T>* node2)
{
    int node1_key = node1->key;
    node1->key = node2->key;
    node2->key = node1_key;

    T node1_value = node1->value;
    node1->value = node2->value;
    node2->value = node1_value;
}

template<typename T>
Node<T>* search_tree<T>::get_min(Node<T>* node)
{
    if(node==nullptr)
        return nullptr;
    else if(node->right==nullptr)
        return node;
    else return get_min(node->left);
}

template<typename T>
void search_tree<T>::preorder_print(Node<T>* root,QString& ans)
{
    if(root!=nullptr)
    {
        ans+=root->value + " ";
        preorder_print(root->left,ans);
        preorder_print(root->right,ans);
    }
}

template<typename T>
void search_tree<T>::preorder_print(Node<T>* root, QTreeWidget* treeWidget, QTreeWidgetItem* parent)
{
    if(root!=nullptr)
    {
        QTreeWidgetItem* it = new QTreeWidgetItem;
        it->setText(0,QString::number(root->key) + " (" + root->value + ")");
        if(parent==nullptr)
            treeWidget->addTopLevelItem(it);
        else
            parent->addChild(it);

        preorder_print(root->left,treeWidget,it);
        preorder_print(root->right,treeWidget,it);
    }
}

template<typename T>
void search_tree<T>::postorder_print(Node<T>* root,QString& ans)
{
    if(root!=nullptr)
    {
        postorder_print(root->left,ans);
        postorder_print(root->right,ans);
        ans+=root->value + " ";
    }
}

template<typename T>
void search_tree<T>::postorder_print(Node<T>* root, QTreeWidget* treeWidget, QTreeWidgetItem* parent)
{
    if(root!=nullptr)
    {
        postorder_print(root->left,treeWidget,parent);
        postorder_print(root->right,treeWidget,parent);

        QTreeWidgetItem* it = new QTreeWidgetItem(parent);
        it->setText(0,QString::number(root->key) + " (" + root->value + ")");
        if(parent==nullptr)
            treeWidget->addTopLevelItem(it);
        else
            parent->addChild(it);
    }
}

template<typename T>
void search_tree<T>::key_print(Node<T>* root,QString& ans)
{
    if(root!=nullptr)
    {
        key_print(root->left,ans);
        ans+=root->value + " ";
        key_print(root->right,ans);
    }
}

template<typename T>
void search_tree<T>::key_print(Node<T>* root, QTreeWidget* treeWidget, QTreeWidgetItem* parent)
{
    if(root!=nullptr)
    {
        key_print(root->left,treeWidget,parent);

        QTreeWidgetItem* it = new QTreeWidgetItem(parent);
        it->setText(0,QString::number(root->key) + " (" + root->value + ")");
        if(parent==nullptr)
            treeWidget->addTopLevelItem(it);
        else
            parent->addChild(it);
        key_print(root->right,treeWidget,it);
    }
}

template<typename T>
void search_tree<T>::depth_print(Node<T> *root, QString &ans)
{
    if(root==nullptr) return;
    std::queue<Node<T>*> children;
    children.push(root);

    while(!children.empty())
    {
        int size = children.size();
        for(int i=0;i<size;i++)
        {
            Node<T>* cur = children.front();
            ans += QString::number(cur->value) + ", ";
            if(cur->left != nullptr)
                children.push(cur->left);
            if(cur->right != nullptr)
                children.push(cur->right);
        }
    }

}


template <typename T>
void search_tree<T>::load_from_array(Node<T>*& root,std::vector<std::pair<int,QString>>& array)
{
    for(int i=0;i<array.size();i++)
        insert(root,array[i].first,array[i].second);
    qDebug()<<"loaded from array";
}
//Определить число узлов в дереве, в которых есть указатель только на одну ветвь.
class solution : search_tree<QString>
{
public:
    solution(){}
    ~solution(){}
    size_t solve(Node<QString>* root)
    {
     size_t ans = 0;
     if(root==nullptr) return 0;

     if((root->left==nullptr && root->right!=nullptr) || (root->left!=nullptr && root->right==nullptr))
         ans++;
     return ans + solve(root->left) + solve(root->right);
    }

};
#endif // SEARCH_TREE_H
