
#include <cstddef>
#include "set.h"

using namespace custom;

template <class T>
set<T>:: set()
{
    numCapacity = 0;
    numElements = 0;
    buffer = NULL;
}

template <class T>
set<T>:: set(int numCapacity)
{
    if(numCapacity >= 0)
    {
        buffer = NULL;
        numElements = 0;
        this->numCapacity = numCapacity;
        resize(numCapacity);
    }
    else
    {
        throw "Error: set sizes must be greater than or equal to 0.";
    }
}

template <class T>
set<T>:: set(const set <T> & rhs)
{
    *this = rhs;
}

template <class T>
set<T>:: ~set()
{
    delete [] buffer;
}

template <class T>
set<T>& set <T> :: operator = (const set <T> & rhs)
{

}

template <class T>
int set<T>:: size()
{
    return numElements;
}

template <class T>
bool set<T>:: empty()
{
    return size() == 0;
}

template <class T>
void set<T>:: clear()
{
    numElements = 0;
}

template <class T>
typename set<T>::iterator set<T>::find(const T & t)
{
    int iBegin = 0;
    int iEnd = size() - 1;

    while(iBegin <= iEnd)
    {
        int iMiddle = (iBegin + iEnd) / 2;
        if(t == buffer[iMiddle])
        {
            return iterator(&iMiddle);
        }
        if(t < buffer[iMiddle])
        {
            iEnd = iMiddle - 1;
        }
        else
        {
            iBegin = iMiddle + 1;
        }
    }

    return iterator(&numElements);
}

template <class T>
void set<T>:: insert(const T & t)
{
    if(buffer != NULL)
    {
        int iInsert = findIndex(t);
        if (buffer[iInsert] != t)
        {
            if(numElements == numCapacity)
            {
                if(numCapacity == 0)
                    resize(1);
                else
                    resize(numCapacity * 2);
            }
            for(int i = numElements; i < iInsert; i++)
            {
                buffer[i + 1] = buffer[i];
            }
            buffer[iInsert] = t;
            numElements++;
        }
    }
    else
    {
        resize(1);
        buffer[0] = t;
    }
}

template <class T>
typename set<T>::iterator set<T>::erase(typename set<T>::iterator it)
{
    iterator iErase = find(*it);
    if(iErase == it)
    {
        for(int i = *iErase; i < numElements; iErase++)
        {
            buffer[i] = buffer[i + 1];
        }
        numElements--;
    }
}

// UNION
template <class T>
set<T>& set <T> :: operator || (const set <T> & rhs)
{
    int iLhs = 0;
    int iRhs = 0;
    set<T> result(numElements + rhs.numElements);

    while(iLhs < numElements || iRhs < rhs.numElements)
    {
        if(iLhs == numElements)
        {
            result.insert(rhs.buffer[iRhs++]);
        }
        else if(iRhs == rhs.numElements)
        {
            result.insert(buffer[iLhs++]);
        }
        else if(buffer[iLhs] == rhs.buffer[iRhs])
        {
            result.insert(buffer[iLhs]);
            iLhs++;
            iRhs++;
        }
        else if(buffer[iLhs] < rhs.buffer[iRhs])
        {
            result.insert(buffer[iLhs++]);
        }
        else
        {
            result.insert(rhs.buffer[iRhs++]);
        }
    }

    if (result.numElements == 0)
        result.buffer = NULL;
    result.numCapacity = result.numElements;

    return result;
}

// INTERSECTION
template <class T>
set<T>& set <T> :: operator && (const set <T> & rhs)
{
    int iLhs = 0;
    int iRhs = 0;
    set<T> result(numElements + rhs.numElements);

    while(iLhs < numElements || iRhs < rhs.numElements)
    {
        if(iLhs == numElements)
        {
            result;
        }
        else if(iRhs == rhs.numElements)
        {
            result;
        }
        else if(buffer[iLhs] == rhs.buffer[iRhs])
        {
            result.insert(buffer[iLhs]);
            iLhs++;
            iRhs++;
        }
        else if(buffer[iLhs] < rhs.buffer[iRhs])
        {
            iLhs++;
        }
        else
        {
            iRhs++;
        }
    }

    return result;
}

// DIFFERENCE
template <class T>
set<T>& set <T> :: operator - (const set <T> & rhs)
{

}

template <class T>
typename set<T>::iterator set<T>::begin()
{
    return iterator(buffer);
}

template <class T>
typename set<T>::iterator set<T>::end()
{
    return iterator(buffer + numElements);
}

template <class T>
int set<T>:: findIndex(const T & t)
{
    if(size() != 0)
    {
        int iBegin = 0;
        int iEnd = size() - 1;
        
        while(iBegin <= iEnd)
        {
            int iMiddle = (iBegin + iEnd) / 2;
            if(t == buffer[iMiddle])
            {
                return iMiddle;
            }
            if(t < buffer[iMiddle])
            {
                iEnd = iMiddle - 1;
            }
            else
            {
                iBegin = iMiddle + 1;
            }
        }
    }

    return numElements;
}

template <class T>
void set<T>::resize(int newCapacity)
{
    if (newCapacity == 0)
   {
      numCapacity = 0;
      numElements = 0;
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

template <class T>
set<T>::iterator::iterator()
{
   ptr = NULL;
}

template <class T>
set<T>::iterator::iterator(T * p)
{
   ptr = p;
}

template <class T>
set<T>::iterator::iterator(const iterator & rhs)
{
   *this = rhs;
}

template <class T>
typename set<T>::iterator& set<T>::iterator::operator = (const iterator & rhs)
{
   ptr = rhs.ptr;
   return *this;
}

template <class T>
bool set<T>::iterator::operator != (const iterator & rhs) const 
{ 
   return rhs.ptr != this->ptr;
}

template <class T>
bool set<T>::iterator::operator == (const iterator & rhs) const 
{ 
   return rhs.ptr == this->ptr;
}

template <class T>
T& set<T>::iterator::operator * ()
{
   return *ptr;
}

template <class T>
typename set<T>::iterator& set<T>::iterator::operator ++ ()
{
   if (ptr != NULL) 
      ptr++;
   return *this;
}

template <class T>
typename set<T>::iterator set<T>::iterator::operator ++ (int postfix)
{
   iterator tmp(*this);
   if (ptr != NULL) 
      ptr++;
   return tmp;
}

template <class T>
typename set<T>::iterator& set<T>::iterator::operator -- ()
{
   if (ptr != NULL)
      ptr--;
   return *this;
}

template <class T>
typename set<T>::iterator set<T>::iterator::operator -- (int postfix)
{
   iterator tmp(*this);
   ptr--;
   return tmp;
}