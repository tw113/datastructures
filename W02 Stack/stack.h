#ifndef STACK_H
#define STACK_H


namespace custom 
{

    template <class T>
    class stack
    {
        public:
            stack();
            stack(int numCapacity);
            stack(stack <T> & rhs);
            ~stack();

            stack <T> & operator = (const stack <T> & rhs)
            

            int size();
            int capacity();
            bool empty();
            void clear();

            void push(const T & t);
            void pop();
            T top();

        private:
            resize(int newCapacity);

            T * buffer;
            int numElements;
            int numCapacity;


    };

}
#include "stack.cpp"

#endif