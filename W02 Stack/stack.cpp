#include "stack.h"

using namespace custom;

// Constructors of the stack class
template <class T>
stack<T> :: stack()
{
    numCapacity = 0;
    numElements = 0;
    buffer = NULL;
}

template <class T>
stack<T> ::stack(int numCapacity)
{

}

template <class T>
stack<T> :: stack(const stack<T> & rhs)
{

}

template <class T>
stack<T> :: ~stack()
{
    delete [] buffer;
}

template <class T>
stack<T> & stack<T> :: operator = (const stack<T> & rhs)
{

}

//Stack class methods
template <class T>
int stack<T> :: size()
{
    return numElements; 
}

template <class T>
int stack<T> :: capacity()
{
    return numCapacity;
}

template <class T>
bool stack<T> :: empty()
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
void stack<T> :: clear()
{
    numElements = 0;
}

template <class T> 
void stack<T> :: push(const T & t)
{
    if(size() == capacity())
    {
        resize(capacity() + 1);
    }
    buffer[numElements++] = t;
}

template <class T>
void stack<T> :: pop()
{
    resize(--numElements);
}

template <classT>
typename stack<T> :: top()
{
    if(!empty())
    {
        return buffer[size() -1]
    }
    else
    {
        throw "Error: asking for top of empty stack.";
    }
    
}

template <class T>
void stack<T> :: resize(int newCapacity)
{
    if(newCapacity == 0)
    {
        newCapacity = 0;
        numElements = 0;
        array = NULL;
    }

    if(newCapacity > 0)
    {
        T* newBuffer = T[newCapacity]; 
        for(int i = 0; i < numElements; i++)
            newBuffer[i] = buffer[i];
        delete [] buffer;
        buffer = newBuffer;
        numCapacity = newCapacity;
        if(newCapacity < numElements)
            numCapacity = numElements;
    }

}

