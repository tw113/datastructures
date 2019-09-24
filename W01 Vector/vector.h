namespace custom {

    template <class T>
    class vector {

        public:
        class iterator {
            public:
                T * ptr = NULL;
                iterator();
                iterator(T * p);
                iterator(const iterator & rhs);
                
                iterator & iterator :: operator = (const iterator & rhs);

                bool operator == (const iterator & lhs);
                bool operator != (const iterator & lhs);

                iterator operator ++ ();
                iterator operator ++ (int postfix);

                iterator operator -- ();
                iterator operator -- (int postfix);

                T operator * ();
        }; 

        private:
            T * array = NULL;

        public:
            int numElements;
            int numCapacity;

            vector();
            vector(int numElements);
            vector(int numElements, T t);
            vector(vector & rhs);
            ~vector();

            vector & operator = (const vector & rhs);
            int size();
            int capacity();
            bool empty();
            void clear();
            void buffer();

            void push_back(T t);
            T & vector :: operator [] (int index);
            iterator begin();
            iterator end();

            void resize(int numCapacity);
    };

}