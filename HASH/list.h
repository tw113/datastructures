#ifndef LIST_H
#define LIST_H 
#include <cstddef>
                                                
      
  
  #ifdef UNIT_TESTING
    int main(int argc, const char* argv[]);
    #endif
  namespace custom
  {
  
  
  template <class T>
  class list {
    public:
    #ifdef UNIT_TESTING
    friend int ::main(int argc, const char* argv[]);
    #endif
        
      list() {init();}                                                        
      list(const list<T> &t) {init(); *this = t;}
      ~list(){clear();}
      
      class node;
      class iterator;

      list & operator = (const list<T> & rhs);

      int size();
      bool empty();
      void clear();

      T& front();
      T& back();
      void push_front(T t);
      void push_back(T t);
      void pop_front();
      void pop_back();

      void insert(iterator nodeToInsertAfter, T t);
      iterator erase(iterator t);
      iterator find(T t);
      iterator begin();
      iterator end();

      private:
      void init();
      void insertAt(node* pNow, T t, bool after = false);

      node* pHead;
      node* pTail;
      int numElements;
  };

  template <class T>
  class list<T> :: node
  {
  public:
    #ifdef UNIT_TESTING
    friend int ::main(int argc, const char* argv[]);
    #endif

    friend list;

    node() {data = 0; pNext = NULL; pPrev = NULL;}                                                        
    node(const T &t) {data = t; pNext = NULL; pPrev = NULL;}
    
  private:
    T data;
    node* pNext;
    node* pPrev;
    
  };

   template <class T>
   class list<T> :: iterator
   {
      public:
         
         #ifdef UNIT_TESTING
         friend int ::main(int argc, const char* argv[]);
         #endif

         friend list;

         iterator();
         iterator(node* p);
         iterator(const iterator & rhs);
         iterator& operator = (const iterator & rhs);
         bool operator != (const iterator & rhs) const;
         bool operator == (const iterator & rhs) const;
         T& operator * ();
         iterator & operator ++ ();
         iterator operator ++ (int postfix);
         iterator & operator -- ();
         iterator operator -- (int postfix);
        //  node* ptr;
      private:

         node* ptr;
   
   };
}
  
  #include "list.cpp"
  #endif  
