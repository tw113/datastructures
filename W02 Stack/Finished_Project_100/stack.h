#include <cstddef>

#ifndef STACK_H
#define STACK_H

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom {
    
    template <class T>
    class stack {
        private:
        
        T * buffer = NULL;
        int numElements;
        int numCapacity;

        public:

        friend int ::main(int argc, const char* argv[]);

        stack();
        stack(int numCapacity);
        stack(const stack <T> & rhs);
        ~stack();

        stack & operator = (const stack <T> & rhs);

        int size();
        int capacity();
        bool empty();
        void clear();

        void push(const T & t);
        void pop();
        T & top();
        const T & top() const;


        private:

        void resize(int numCapacity);
    };
}

#include "stack.cpp"

#endif