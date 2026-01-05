#include <iostream>
#include <climits>

using namespace std;

class DynamicArray{
    private:
        int* arrayUnderHood;
        int length;
        int capacity;

    public:
        DynamicArray(int capacity){
            if (capacity <= 0){
                this->arrayUnderHood = nullptr;
                this->length = 0;
                this->capacity = 0;
            }else{
                this->arrayUnderHood = new int[capacity];
                this->length = 0;
                this->capacity = capacity;
            }
        }

        ~DynamicArray(){
            delete[] this->arrayUnderHood;
        }
};