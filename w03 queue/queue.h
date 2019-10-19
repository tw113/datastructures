#ifndef QUEUE_H
#define QUEUE_H

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    template <class T>
    class queue
    {
        public:

<<<<<<< HEAD
        friend int ::main(int argc, const char* argv[]);

=======
>>>>>>> e25f1acd8ca04feda3b3333a877ad905a9e60ab7
        queue();
        queue(int numCapacity);
        queue(const queue <T> & rhs);
        ~queue();

        queue <T> & operator = (const queue <T> & rhs);

        int size();
        bool empty();
        void clear();
        int capacity();
        void push(const T & t);
        void pop();
        T & front();
        T & back();
        
        

        private:

        void resize(int numCapacity);
        int iHead();
        int iTail();

        T * buffer;
        
        int numPush;
        int numPop;
        int numCapacity;
    };
}

#include "queue.cpp"

#endif