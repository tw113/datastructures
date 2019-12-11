#ifndef HASH_H
#define HASH_H
#include "list.h"


#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom {

    template <class T>
    class Hash {

        #ifdef UNIT_TESTING
            friend int ::main(int argc, const char* argv[]);
        #endif

        public:
        Hash();
        Hash(int numBuckets);
        Hash(Hash<T>& rhs);
        ~Hash();

        Hash<T>& operator = (const Hash<T>& rhs);
        int size();
        bool empty();
        int capacity();
        bool find(T aValue, long (*h)(const T& aValue, long theBucketCount));
        void insert(T aValue, long (*h)(const T& aValue, long theBucketCount));
        void erase(T t) {
            T i = Hash(t);
            T it = table[i].find(t);
            if (it != NULL) {
                table[i].erase(it);
            }
        }
        

        list<T>** table;
        int numElements;
        int numBuckets; 

        private:
        void include(int numBuckets)
        {
            table = new list<T>*[numBuckets];
            for(int i = 0; i < numBuckets; i++)
                table[i] = new list<T>;
        }
        void clear()
        {
            for(int i = 0; i <numBuckets; i++)
            {
                delete table[i];
                table[i] = NULL;
            }
                delete[] table;
        }
    };
}

#include "hash.cpp"
#endif