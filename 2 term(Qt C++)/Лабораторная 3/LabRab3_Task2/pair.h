#ifndef PAIR_H
#define PAIR_H

#include <iostream>
template <class T1,class T2>
struct pair
{

    T1 first;
    T2 second;

    pair(T1 first, T2 second) : first(first), second(second){}
    pair(){}
    //pair(pair& other) : first(other.first), second(other.second){}
//    pair(T1&& first,T2&& second) : first(std::move(first)), second(std::move(second)){}
//    pair(pair&& other) : first(std::move(other.first)), second(std::move(other.second)){}

    bool operator ==(const pair& other)
    {
        return first==other.first && second == other.second;
    }

    bool operator!=(const pair& other)
    {
        return first!=other.first && second != other.second;
    }

    void swap(const pair& other)
    {
        std::swap(first,other.first);
        std::swap(second,other.second);
    }

    bool operator >(const pair& other)
    {
        return first>other.first && second>other.second;
    }

    bool operator <(const pair& other)
    {
        return first<other.first && second<other.second;
    }

    bool operator >=(const pair& other)
    {
        return first>=other.first && second>=other.second;
    }

    bool operator <=(const pair& other)
    {
        return first<=other.first && second<=other.second;
    }

    pair<T1,T2>& operator = (pair<T1,T2>& other)
    {
        first = other.first;
        second = other.second;
        return *this;
    }

};

template <typename T1,typename T2>
pair<T1,T2> makePair(const T1& first, const T2& second)
{
    return pair<T1,T2>(first,second);
}

#endif // PAIR_H
