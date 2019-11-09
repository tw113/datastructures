#ifndef NODE_H
#define NODE_H

#include <cstddef>

namespace custom
{
template <class T>
struct node
{
public:
    T data;

    node();
    node(const T &t);
    node(const node<T> &rhs);
    ~node();

    node<T> *pNext;
    node<T> *pPrev;
};

// template <class T>
// node<T> *copy(const node<T> *pSource);

// template <class T>
// node<T> insert(node<T> *pNode, const T &t, bool after = false);

// template <class T>
// node<T> *find(node<T> *pHead, const T &t);

// template <class T>
// void clear(node<T> *&pHead);

// template <class T>
// node<T> *remove(const node<T> *pRemove);

template <class T>
node<T>::node()
{
    data = 0;
    pNext = NULL;
    pPrev = NULL;
}

template <class T>
node<T>::node(const T &t)
{
    data = t;
    pNext = NULL;
    pPrev = NULL;
}

template <class T>
node<T>::node(const node<T> &rhs)
{
    *this = rhs;
}

template <class T>
node<T>::~node()
{
    free(this);
}

template <class T>
node<T> * copy(node<T> *pSource)
{
    if(pSource == NULL)
        return NULL;
    
    node<T> * pDestination = new node<T>(pSource->data);
    node<T> * pSrc = pSource;
    node<T> * pDes = pDestination;

    node<T> * p = pSrc;
    while(p)
    {
        pDestination = insert(pDes, p->data, true);
        p = p->pNext;
    }
    return pDestination;
}

template <class T>
node<T> * insert(node<T> *pCurrent, const T &t, bool after = false)
{
    if(pCurrent == NULL)
    {
        throw "Error: inserting into NULL list.";
    }
    node<T> *pNew = new node<T>(*pCurrent);
    if (pCurrent != NULL && after == false)
    {
        pNew->pNext = pCurrent;
        pNew->pPrev = pCurrent->pPrev;
        pCurrent->pPrev = pNew;
        if (pNew->pPrev)
        {
            pNew->pPrev->pNext = pNew;
        }
    }
    if (pCurrent != NULL && after == true)
    {
        pNew->pNext = pCurrent;
        pNew->pPrev = pCurrent->pPrev;
        pCurrent->pNext = pNew;
        if (pNew->pNext)
        {
            pNew->pNext->pPrev = pNew;
        }
    }
    return pNew;
}

template <class T>
node<T> * find(node<T> *pHead, const T &t)
{
    for (node<T> *p = pHead; p; p = p->pNext)
    {
        if (p->data == t)
        {
            return p;
        }
    }
    return NULL;
}

template <class T>
void clear(node<T> *&pHead)
{
    if(pHead)
    {
        node<T> *pDelete = new node<T>();
        while (pHead)
        {
            pDelete = pHead;
            pHead = pHead->pNext;
            delete pDelete;
        }
    }
    else
    {
        throw "Error: freeing NULL list.";
    }
}

template <class T>
node<T> * remove(const node<T> *pRemove)
{
    node<T> * pReturn;
    if(pRemove != NULL)
    {
        if(pRemove->pPrev)
        {
            pRemove->pPrev->pNext = pRemove->pNext;
            pReturn = pRemove->pPrev;
        }
        if(pRemove->pNext)
        {
            pRemove->pNext->pPrev = pRemove->pPrev;
            pReturn = pRemove->pNext;
        }

        delete pRemove;
        return pReturn;
    }

    return pReturn;
}

} // namespace custom

#endif