#include "hashmap.h"

template <>
QString HashMap<QString>::print_map()
{
    qDebug()<<"hashtable size" << _size;
    QString ans;
    for(int i = 0;i<_size;i++)
    {
        if(!hash_map[i].empty())
        {
            Stack<Node<QString>> tmp = hash_map[i];
            ans += "Стек # " + QString::number(i + 1) + " : ";
            while(!tmp.empty())
            {
                ans += "(" + QString::number(tmp.top().key) + " " + tmp.top().value + ")" + ", ";
                tmp.pop();
            }
            ans += '\n';
        }
    }
    return ans;
}
