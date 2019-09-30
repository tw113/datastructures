#include "vector.h"

using namespace custom;

template <class T>
vector <T> :: vector()
{
    
}

template <class T>
int vector <T> :: size() 
{
    for(int i = 0; i < numElements; i++){
        cout << numElements << endl;
    }
}

template <class T>
int vector <T> :: capacity()
{
    for(int i = 0; i < numElements; i++){
        cout << numElements << endl;
    }
}

template <class T>
bool vector <T> :: empty()
{
    if(numElements == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
void vector <T> :: clear()
{
    numElements = 0;
}

template <class T>
void vector <T> :: push_back(T t)
{
    if(size() == capacity()) {
        resize(capacity() + 1);
    }

}
