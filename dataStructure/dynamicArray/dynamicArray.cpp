#include <iostream>
#include <climits>

using namespace std;

class DynamicArray{
    private:
        int* arrayUnderHood;
        int length;
        int capacity;

        void resizeArray(){
            int newCapacity;
            if (this->capacity == 0){
                newCapacity = 1;
            }else{
                newCapacity = this->capacity * 2;
            }
            int* newArrayUnderHood = new int[newCapacity];
            if (this->arrayUnderHood != nullptr){
                for(int i = 0 ; i < this->length ; i++){
                    newArrayUnderHood[i] = this->arrayUnderHood[i];
                }
                delete[] this->arrayUnderHood;
            }
            this->arrayUnderHood = newArrayUnderHood;
            this->capacity = newCapacity;
        }

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