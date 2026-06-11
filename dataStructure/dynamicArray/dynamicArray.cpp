#include <iostream>
#include <climits>

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

    public:
        dynamicArray(){
            this->arrayUnderHood = nullptr;
            this->length = 0;
            this->capacity = 0;
        }

        ~dynamicArray(){
            delete[] this->arrayUnderHood;
            this->length = 0;
            this->capacity = 0;
        }

        bool pushElement(int value){
            if (this->length >= this->capacity){
                this->resize();
            }
            this->arrayUnderHood[this->length] = value;
            this->length++;
            return true;
        }

        int popElement(){
            if (this->length == 0){
                return INT_MIN;
            }
            int poppedValue = this->arrayUnderHood[this->length - 1];
            this->length--;
            return true;
        }

        int atIndex(int index){
            if (this->length == 0){
                return INT_MIN;
            }
            if (index < 0 || index >= this->length){
                return INT_MIN;
            }
            return this->arrayUnderHood[index];
        }
};