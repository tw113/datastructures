#ifndef QUEUE_H
#define QUEUE_H


namespace custom
{
    template <class T>
    class queue
    {
        public:

        queue()
        queue(int numCapacity);
        queue(const queue <T> & rhs);
        ~queue();

        queue <T> & operator = (const queue <T> & rhs);

        int size();
        bool empty();
        void clear();
        void capacity();
        void push(T & t);
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
    }
}
