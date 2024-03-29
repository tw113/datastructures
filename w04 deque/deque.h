#ifndef DEQUE_H
#define DEQUE_H

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    template <class T>
    class deque {
    public:

        friend int main(int argc, const char* argv[]);

        T * buffer;
        int iFront;
        int iBack;
        int numCapacity;

        deque();
        deque(int numCapacity);
        deque(const deque <T> & rhs);
        ~deque();

        deque <T> & operator = (const deque <T> & rhs);

        int size();
        bool empty();
        void clear();

        void push_front(const T & t);
        void push_back(const T & t);
        void pop_front();
        void pop_back();

        T & front();
        T & back();

        void resize(int numCapacity);
        int capacity();
        int iNormalize(int index);
        int iFrontNormalize();
        int iBackNormalize();
    };
}

#include "deque.cpp"

#endif