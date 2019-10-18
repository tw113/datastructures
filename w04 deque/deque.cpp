#include "deque.h"

using namespace custom;

template <class T>
deque<T> :: deque()
{
    iFront = 0;
    iBack = -1;
    numCapacity = 0;
    buffer = NULL;
}

template <class T>        
deque<T> :: deque(int numCapacity)
{

}

template <class T>
deque<T> :: deque(const deque <T> & rhs)
{

}

template <class T>
deque<T> :: ~deque()
{
    delete [] buffer;
}

template <class T>
deque <T> & operator = (const deque <T> & rhs)
{
    clear();
    if(lhs.capacity() < rhs.size())
    {
        resize(rhs.size());
    }
    for()
}
template<class T>
int deque<T> :: size()
{
    return iBack - iFront + 1;
}

template <class T>
bool deque<T> :: empty()
{
    size() = 0;
}

template <class T>
void deque<T> :: clear()
{
    iFront = 0;
    iBack = -1;
}

template <class T>
void deque<T> :: push_front(const T & t)
{
    if(size() == capacity())
    {
        resize(capacity() * 2);
    }
    iFront++;
    buffer[iFrontNormalize()] = t;
}

template <class T>
void deque<T> :: push_back(const T & t)
{
    if(size() == capacity())
    {
        resize(capacity() * 2);
    }
    iBack++;
    buffer[iBackNormalize()] = t;
}

template <class T>
void deque<T> :: pop_front()
{
    if(empty())
    {
        throw "Error: Can not pop an empty deque.";
    }
    iFront++;
}

template <class T>
void deque<T> :: pop_back()
{
    if(empty())
    {
        throw "Error: Can not pop an empty deque.";
    }
    iBack--;
}

template <class T>
T deque<T> :: front()
{
    if(empty)
    {
        throw "Error: deque is empty.";
    }
    else
    {
        return buffer[iFrontNormalize()];
    }
    
}

template <class T>
T deque<T> :: back()
{
    if(empty())
    {
        throw "Error: deque is empty.";
    }
    else
    {
        return buffer[iBackNormalize()];
    }
    
}

template <class T>
void deque<T> :: resize(int numCapacity)
{

}

template <class T>
int deque<T> :: capacity()
{
    return numCapacity;
}

template <class T>
int deque<T> :: iFrontNormalize()
{
    return iNormalize(iFront);
}

template <class T>
int deque<T> :: iBackNormalize()
{
    return iNormalize(iBack);
}