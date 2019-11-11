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
    buffer = new T[0];
    iFront = 0;
    iBack = -1;
    if(numCapacity >= 0)
        this-> numCapacity = numCapacity;
    else if(numCapacity < 0)
    {
        throw "Error: deque sizes must be greater than or equal to 0.";
    }
    
}

template <class T>
deque<T> :: deque(const deque <T> & rhs)
{
    clear();
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
    numCapacity = 0;
    buffer = NULL;
    int rhsSize = rhs.iBack - rhs.iFront + 1;
        resize(rhsSize);
    for(int i = rhs.iFront; i <= iBack; i++)
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
    if(capacity() == 0)
        resize(1);
    if(size() == capacity())
        resize(capacity() * 2);
    iFront--;
    buffer[iFrontNormalize()] = t;
}

template <class T>
void deque<T> :: push_back(const T & t)
{
    if(capacity() == 0)
        resize(1);
    if(size() == capacity())
        resize(capacity() * 2);
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
        {
            newBuffer[i] = buffer[iFrontNormalize()];
            iFront++;
        }
            
        delete [] buffer;
        buffer = newBuffer;
        numCapacity = newCapacity;
        iFront = 0;
        iBack = numElements - 1;
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
    if(numCapacity > 0)
    {
        if(index >= 0)
        {
            return index % numCapacity;
        }
        else if(numCapacity < (index * -1) )
        {
            return iNormalize(numCapacity + index);
        }
        else
        {
            return numCapacity + index;
        }
    } 
    else
        throw "Error: uninitialized deque.";
    
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