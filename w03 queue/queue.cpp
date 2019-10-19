#include "queue.h"
#include <cstddef>

using namespace custom;

template <class T>
queue<T> :: queue() 
{
    int numPop = 0;
    int numPush = 0;
    int numCapacity = 0;
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
    if(numCapacity < rhs.size())
    {
        resize(rhs.size());
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
    if(size() == capacity())
    {
        resize(capacity() * 2);
    }
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
        buffer = NULL;
    }
   
   if (newCapacity > 0)
   {
      T* newBuffer = new T[newCapacity];
      for (int i = 0; i < numCapacity; i++)
         newBuffer[i] = buffer[i];
      delete [] buffer;
      buffer = newBuffer;
      numCapacity = newCapacity;
      if (newCapacity < size())
         numCapacity = newCapacity;
   }
}

template <class T>
int queue<T> :: iHead()
{
    return buffer[0];
}

template <class T> 
int queue<T> :: iTail()
{
    return buffer[numPush - numPop];
}
