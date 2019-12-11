#include "list.h"

using namespace custom;

template <class T>
void list<T> :: init(){
    pHead = NULL;
    pTail = NULL;
    numElements = 0;
}

template <class T>
list<T>& list<T>::operator = (const list <T> & rhs)
{
    clear();
    for(node* p = rhs.pHead; p; p = p->pNext)
      insertAt(pTail, p->data, true);
    return *this;
}

template <class T>
int list<T> :: size(){
   return numElements;
}

template <class T>
bool list<T> :: empty() {
    return (numElements == 0);
}

template <class T>
void list<T> :: clear(){
    node * pNow = pHead;
    while (pNow){
        node* pNew = pNow;
        pNow = pNow->pNext;
        delete pNew;
        numElements--;
    }
    pHead = NULL;
    pTail = NULL;
}

template <class T>
T& list<T> :: front() {
   if(empty())
      throw "Error: Calling front on empty list.";
   return pHead->data;
}

template <class T>
T& list<T> :: back() {
    if(empty())
      throw "Error: Calling back on empty list.";
      return pTail->data;
}

template <class T>
void list<T> :: push_front(T t){ 
   insertAt(pHead,t,false);
}

template <class T>
void list<T> :: push_back(T t){ 
   insertAt(pTail,t,true);
}

template <class T>
void list<T> :: pop_front(){ 
   if(!empty()){
      pHead = pHead->pNext;
      pHead->pPrev = NULL;
      numElements--;
   }
}

template <class T>
void list<T> :: pop_back(){ 
   if(!empty()){
      pTail = pTail->pPrev;
      pTail->pNext = NULL;
      numElements--;
   }
}

template <class T>
void list<T>::insert(iterator nodeToInsertAfter, T t){
  insertAt(nodeToInsertAfter.ptr, t, false);
}

template <class T>
 typename list<T>::iterator list<T>::erase(iterator t){
   node* pNew = t.ptr;
   if(pNew == NULL)
      return iterator(NULL);
   node* pResults = (pNew->pPrev) ? pNew->pPrev : pNew->pNext;

   if(pNew->pPrev)
      pNew->pPrev->pNext = pNew->pNext;
   if(pNew->pNext)
      pNew->pNext->pPrev = pNew->pPrev;
   if(pNew == pHead)
      pHead = pNew->pNext;
   delete pNew;
   pNew = NULL;
   return iterator(pResults);
 }

 template <class T>
 typename list<T>::iterator list<T>::find(T t){
    iterator results;
    for (node* p = pHead; p; p = p->pNext)
      if(p->data == t){
         results = iterator(p);
         break;
      }
      return results;
 }

template <class T>
 typename list<T>::iterator list<T>::begin(){
    return iterator(pHead);
 }

 template <class T>
 typename list<T>::iterator list<T>::end(){
    return iterator(pTail);
 }

 template <class T>
void list<T>::insertAt(node* pNow, T t, bool after){
    node* pNew = new node(t);
    if(empty()){
       pHead = pNew;
       pTail = pNew;
       numElements++;
       return;
    }
    if(after == false){
       if(pHead == pNow)
         pHead = pNew;
      pNew->pNext = pNow;
      pNew->pPrev = pNow->pPrev;
      pNow->pPrev = pNew;
      if(pNew->pPrev)
         pNew->pPrev->pNext = pNew;
      numElements++;
    } else {
       if(pTail == pNow)
         pTail = pNew;
      pNew->pPrev = pNow;
      pNew->pNext = pNow->pNext;
      pNow->pNext = pNew;
      if(pNew->pNext){
         pNew->pNext->pPrev = pNew;
      }
      numElements++;
    }
}

template <class T>
list<T>::iterator::iterator()
{
   ptr = NULL;
}

template <class T>
list<T>::iterator::iterator(node * p)
{
   ptr = p;
}

template <class T>
list<T>::iterator::iterator(const iterator & rhs)
{
   *this = rhs;
}

template <class T>
typename list<T>::iterator& list<T>::iterator::operator = (const iterator & rhs)
{
   ptr = rhs.ptr;
   return *this;
}

template <class T>
bool list<T>::iterator::operator != (const iterator & rhs) const 
{ 
   return rhs.ptr != this->ptr;
}

template <class T>
bool list<T>::iterator::operator == (const iterator & rhs) const 
{ 
   return rhs.ptr == this->ptr;
}

template <class T>
T& list<T>::iterator::operator * ()
{
   if (ptr == NULL)
      throw "Error: Dereferencing null node.";
   return ptr->data;

}

template <class T>
typename list<T>::iterator& list<T>::iterator::operator ++ ()
{
   if (ptr == NULL) {
       throw "Error: Incrementing null node.";
   }
   if(ptr->pNext){
       ptr = ptr->pNext;
   }
   return *this;
}

template <class T>
typename list<T>::iterator list<T>::iterator::operator ++ (int postfix)
{
   iterator tmp(*this);
   ++(*this);
   return tmp;
}

template <class T>
typename list<T>::iterator& list<T>::iterator::operator -- ()
{
  if (ptr == NULL) {
       throw "Error: Decrementing null node.";
   }
   if(ptr->pPrev){
       ptr = ptr->pPrev;
   }
   return *this;

}

template <class T>
typename list<T>::iterator list<T>::iterator::operator -- (int postfix)
{
   iterator tmp(*this);
   --(*this);
   return tmp;

}