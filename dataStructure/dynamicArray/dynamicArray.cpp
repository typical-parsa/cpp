#include <iostream>

using namespace std;

class dynamicArray{
    private:
        int length;
        int capacity;
        int* arrayUnderHood;

        void resize(){
            int newCapacity;
            if (this->capacity == 0){
                newCapacity = 1;
            }else{
                newCapacity = this->capacity * 2;
            }
            int* newArrayUnderHood = new int[newCapacity];
            for (int i = 0 ; i < this->size ; i++){
                newArrayUnderHood[i] = this->arrayUnderHood[i];
            }
            delete[] this->arrayUnderHood;
            this->capacity = newCapacity;
            this->arrayUnderHood = newArrayUnderHood;
        }

    public:
        dynamicArray(){
            this->length = 0;
            this->capacity = 0;
            this->arrayUnderHood = nullptr;
        }

};