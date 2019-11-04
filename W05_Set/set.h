#ifndef SET_H
#define SET_H

namespace custom
{
    template <class T>
    class set
    {
        public:
        T * buffer;
        int numCapacity;
        int numElements;

        void resize(int newCapacity);

        public:

        set();
        set(int numCapacity);
        set(const set <T> & rhs);
        ~set();

        set<T> & operator = (const set <T> & rhs);

        class iterator;

        int size();
        bool empty();
        void clear();
        iterator find(const T & t);
        void insert(const T & t);
        iterator erase(iterator it);
        set<T> & operator || (const set <T> & rhs);
        set<T> & operator && (const set <T> & rhs);
        set<T> & operator - (const set <T> & rhs);
        iterator begin();
        iterator end();
        int findIndex(const T & t);
    };

    template <class T>
    class set<T>::iterator
    {
        public:

            iterator();
            iterator(T * p);
            iterator(const iterator & rhs);
            iterator & operator = (const iterator & rhs);
            bool operator != (const iterator & rhs) const;
            bool operator == (const iterator & rhs) const;
            T & operator * ();
            iterator & operator ++ ();
            iterator operator ++ (int postfix);
            iterator & operator -- ();
            iterator operator -- (int postfix);
            
        public:

            T * ptr;
    
    };
}

#include "set.cpp"

#endif