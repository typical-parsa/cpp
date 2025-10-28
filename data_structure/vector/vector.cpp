#include <iostream>
#include <climits>

using namespace std;

class Vector{
    private:
        int* array_under_hood;
        int length;
        int capacity;

    public:
        Vector(int capacity){
            this->array_under_hood = new int[capacity];
            this->length = 0;
            this->capacity = capacity;
        }

        ~Vector(){
            delete[] this->array_under_hood;
        }
};