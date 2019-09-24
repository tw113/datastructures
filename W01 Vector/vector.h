namespace custom {

    template <class T>
    class vector {

        public:
        class iterator {
            public:
                T ptr = NULL;
                iterator();
                iterator(T p);
                iterator(iterator rhs);
                
                iterator assignment(iterator it);
                bool isEquals(iterator it);
                bool isNEqual(iterator it);
                iterator increment();
                iterator decrement();
                T dereference();
        }; 

        private:
            T* array = NULL;

        public:
            int numElements;
            int numCapacity;

            vector();
            vector(int numElements);
            vector(int numElements, T t);
            //vector(vector rhs);
            ~vector();

            vector & operator = (vector rhs);
            int size();
            int capacity();
            bool empty();
            clear();
            buffer();

            push_back(T t);
            T access(int index);
            iterator begin();
            iterator end();

            resize(int numCapacity);
    };

}