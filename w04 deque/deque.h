#ifndef DEQUE_H
#define DEQUE_H

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    public:
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

    private:
        void resize(int numCapacity);
        int capacity();
        int iFrontNormalize();
        int iBackNormalize();

        T * buffer[];
        int iFront;
        int iBack;
        int numCapacity;




};
#include "deque.cpp"

#endif