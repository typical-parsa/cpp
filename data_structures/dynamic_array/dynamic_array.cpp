#include <iostream>
#include <climits>

using namespace std;

class DynamicArray{
    private:
        int* array_under_hood;
        int length;
        int capacity;

    public:
        DynamicArray(int capacity){
            if (capacity <= 0){
                this->array_under_hood = nullptr;
                this->length = 0;
                this->capacity = 0;
            }else{
                this->array_under_hood = new int[capacity];
                this->length = 0;
                this->capacity = capacity;
            }
        }

        ~DynamicArray(){
            delete[] this->array_under_hood;
        }

};