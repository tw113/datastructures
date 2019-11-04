#include "deque.h"
#include <cstddef>

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
    buffer = NULL;
    iFront = 0;
    iBack = -1;
    this-> numCapacity = numCapacity;
}

template <class T>
deque<T> :: deque(const deque <T> & rhs)
{
    iFront = 0;
    iBack = -1;
    numCapacity = 0;
    *this = rhs;
}

template <class T>
deque<T> :: ~deque()
{
    delete [] buffer;
}

template <class T>
deque<T>& deque<T> :: operator = (const deque <T> & rhs)
{
    clear();
    if(numCapacity < rhs.size())
    {
        resize(rhs.size());
    }
    for(int i = rhs.numCapacity; i < size(); i++)
    {
        push_back(rhs.buffer[i % rhs.numCapacity]);
    }
    return *this;
}

template<class T>
int deque<T> :: size()
{
    return iBack - iFront + 1;
}

template <class T>
bool deque<T> :: empty()
{
    return size() == 0;
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
T & deque<T> :: front()
{
    if(empty())
    {
        throw "Error: deque is empty.";
    }
    else
    {
        return buffer[iFrontNormalize()];
    }
    
}

template <class T>
T & deque<T> :: back()
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
void deque<T> :: resize(int newCapacity)
{
    if (newCapacity == 0)
    {
        clear();
        numCapacity = 0;
        buffer = NULL;
    }
   
   if (newCapacity > 0)
   {
        T* newBuffer = new T[newCapacity];
        int numElements;
        if(newCapacity < size())
            numElements = newCapacity;
        else
            numElements = size();
        for (int i = 0; i < numElements; i++)
            newBuffer[i] = buffer[iFrontNormalize()];
        delete [] buffer;
        buffer = newBuffer;
        numCapacity = newCapacity;
   }
}

template <class T>
int deque<T> :: capacity()
{
    return numCapacity;
}

template <class T>
int deque<T> :: iNormalize(int index)
{
    return index % capacity();
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