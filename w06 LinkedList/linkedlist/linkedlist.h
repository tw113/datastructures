#define LINKEDLIST_H

namespace custom
{
    template <typename T>
    class node
    {
        public:
            node();
            node(T t);
            T data;
            node<T> * pPrev;
            node<T> * pNext;
    };

}
#include "linkedlist.cpp"

#endif