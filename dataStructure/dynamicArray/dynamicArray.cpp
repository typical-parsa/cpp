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
            for (int i = 0 ; i < this->length ; i++){
                newArrayUnderHood[i] = this->arrayUnderHood[i];
            }
            delete[] this->arrayUnderHood;
            this->arrayUnderHood = newArrayUnderHood;
            this->capacity = newCapacity;
        }
};