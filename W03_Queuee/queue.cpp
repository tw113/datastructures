#include <cstddef>
#include "queue.h"

using namespace custom;

template <class T>
queue<T> :: queue() 
{
    numPop = 0;
    numPush = 0;
    numCapacity = 0;
    buffer = NULL;
}

template <class T> 
queue<T> :: queue(int numCapacity)
{
    buffer = NULL;
    numPop = 0;
    numPush = 0;
    this->numCapacity = numCapacity;
}

template <class T>
queue<T> :: queue(const queue <T> & rhs)
{
    numPop = 0;
    numPush = 0;
    numCapacity = 0;
    *this = rhs;
}

template <class T> 
queue<T> :: ~queue()
{
    delete [] buffer;
}

template <class T>
queue<T>& queue<T> :: operator = (const queue <T> & rhs)
{
    clear();
    if(numCapacity < (rhs.numPush - rhs.numPop))
    {
        resize(rhs.numPush - rhs.numPop);
    }
    for(int i = rhs.numPop; i < rhs.numPush; i++)
    {
        push(rhs.buffer[i % rhs.numCapacity]);
    }
    return *this;
}

template <class T> 
int queue<T> :: size()
{
    return numPush - numPop;
}

template <class T>
bool queue<T> :: empty()
{
    return size() == 0;
}

template <class T>
int queue<T>::capacity()
{
   return numCapacity;
}

template <class T>
void queue<T> :: clear()
{
    numPush = 0;
    numPop = 0;
}

template <class T>
void queue<T> :: push(const T & t)
{
    if(capacity() == 0)
        resize(1);
    if(size() == capacity())
        resize(capacity() * 2);
    numPush++;
    buffer[iTail()] = t;
}

template <class T> 
void queue<T> :: pop()
{
    if(!empty())
    {
        numPop++;
    }
}

template <class T> 
T & queue<T> :: front()
{
    if(empty())
    {
        throw "Error: asking for front of empty queue.";
    }
    else
    {
        return buffer[iHead()];
    }
    
}

template <class T> 
T & queue<T> :: back()
{
    if(empty())
    {
        throw "Error: asking for back of empty queue.";
    }
    else
    {
        return buffer[iTail()];
    }
    
}

template <class T>
void queue<T> :: resize(int newCapacity)
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
        for (int i = 0; i < numElements; i++, numPop++)
            newBuffer[i] = buffer[iHead()];
        delete [] buffer;
        buffer = newBuffer;
        numCapacity = newCapacity;
        numPop = 0;
        numPush = numElements;
   }
}

template <class T>
int queue<T> :: iHead()
{
    return numPop % numCapacity;
}

template <class T> 
int queue<T> :: iTail()
{
    if(numPush != 1)
        return (numPush - 1) % numCapacity;
    else
        return 0;
}
