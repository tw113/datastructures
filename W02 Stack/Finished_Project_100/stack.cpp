#include "stack.h"

using namespace custom;

template <class T>
stack<T>::stack() 
{
    buffer = NULL;
    numElements = 0;
    numCapacity = 0;
}

template <class T>
stack<T>::stack(int numCapacity) 
{
    buffer = NULL;
    numElements = 0;
    this->numCapacity = numCapacity;
}

template <class T>
stack<T>::stack(const stack<T> &rhs) 
{
    *this = rhs;
}

template <class T>
stack<T>::~stack() {
    delete [] buffer;
}

template <class T>
stack<T>& stack<T>::operator = (const stack<T> &rhs) 
{
    numElements = rhs.numElements;
    if (rhs.numCapacity > numElements)
    {
        numCapacity = numElements;
    }
    else
    {
        numCapacity = rhs.numCapacity;
    }
    buffer = new T[numElements];
    for (int i = 0; i < numElements; i++) {
        buffer[i] = rhs.buffer[i];
    }
    return *this;
}

template <class T>
int stack<T>::size() 
{
    return numElements;
}

template <class T>
int stack<T>::capacity() 
{
    return numCapacity;
}

template <class T>
bool stack<T>::empty() 
{
    if(size() == 0) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void stack<T>::clear() {
    if(!empty())
    {
        numElements = 0;
    }
}

template <class T>
void stack<T>::push(const T &t)
{
    if(numElements == numCapacity)
    {
        resize(numCapacity * 2);
    }
    if(numElements == 0)
    {
        resize(numCapacity + 1);
    }
    buffer[numElements++] = t;
}

template <class T>
void stack<T>::pop()
{
    if(!empty())
    {
        --numElements;
    }
}

template <class T>
T & stack<T>::top()
{
    if(!empty())
    {
        return buffer[numElements - 1];
    }
    else
    {
        throw "Error: asking for top of empty stack.";
    }
}

template <class T>
const T & stack<T>::top() const
{
    if(!empty())
    {
        return buffer[numElements - 1];
    }
    else
    {
        throw "Error: asking for top of empty stack.";
    }
}

template <class T>
void stack<T>::resize(int newCapacity)
{
    if (newCapacity == 0)
   {
      numCapacity = 0;
      numElements = 0;
      buffer = NULL;
   }
   
   if (newCapacity > 0)
   {
      T* newBuffer = new T[newCapacity];
      if (newCapacity < numElements)
         numElements = newCapacity;
      for (int i = 0; i < numElements; i++)
         newBuffer[i] = buffer[i];
      delete [] buffer;
      buffer = newBuffer;
      numCapacity = newCapacity;
   }
}