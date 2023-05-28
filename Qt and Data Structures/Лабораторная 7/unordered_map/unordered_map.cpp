#include "unordered_map.h"

//template<typename ValueType,typename HashFunc>
//class unordered_map<QString, ValueType,HashFunc>
//{
//protected:
//    unsigned int hash_function(QString key)
//    {
//        unsigned int hash = 5381;
//        for(int i=0;i<key.size();i++)
//        {
//            hash = ((hash<<5) + hash) + (unsigned int)key[i];
//        }
//        return hash % unordered_map::_size;
//    }
//};

//template<typename ValueType,typename HashFunc>
//class unordered_map<std::string, ValueType,HashFunc>
//{
//protected:
//    unsigned int hash_function(std::string key)
//    {
//        unsigned int hash = 5381;
//        for(int i=0;i<key.size();i++)
//        {
//            hash = ((hash<<5) + hash) + (unsigned int)key[i];
//        }
//        return hash % unordered_map::_size;
//    }
//};
