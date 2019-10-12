#include "queue.h"

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
    numCapacity = rhs.numPush - rhs.numPop;
    
}

template <class T> 
int queue<T> :: size()
{
    return numPush - numPop;
}

template <T>
bool queue<T> :: empty()
{
    size() == 0;
}

template <class T>
int queue<T>::capacity() const
{
   return numCapacity;
}

template <class T>
void queue<T> :: clear()
{
    size() = 0;
}

template <class T>
queue<T> :: push(T t)
{
    if(size() == capacity())
    {
        resize(capacity() * 2)
    }
    numPush++;
    buffer[iTail()] = t;
}

template <class T> 
queue<T> :: pop()
{
    if(!empty())
    {
        numPop++;
    }
}

template <class T> 
T queue<T> :: front()
{
    if(empty())
    {
        throw "Error: asking for front of empty queue.";
    }
    else
    {
        return buff[iHead()];
    }
    
}

template <class T> 
T queue<T> :: back()
{
    if(empty())
    {
        throw "Error: asking for back of empty queue.";
    }
    else
    {
        return buffer{iTail()};
    }
    
}

template <class T>
void queue<T> :: resize(int newCapacity)
{
       if (newCapacity == 0)
   {
      numCapacity = 0;
      size() = 0;
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
         size() = newCapacity;
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
