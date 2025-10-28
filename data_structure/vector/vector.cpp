#include <iostream>
#include <climits>

using namespace std;

class Vector{
    private:
        int* array_under_hood;
        int length;
        int capacity;

        void resize_array(){
            int new_capacity;
            if (this->capacity == 0){
                new_capacity = 1;
            }else{
                new_capacity = this->capacity * 2;
                int* new_array_under_hood = new int[new_capacity];
                for (int i = 0 ; i < this->length ; i++){
                    new_array_under_hood[i] = array_under_hood[i];
                }
                delete[] this->array_under_hood;
                this->array_under_hood = new_array_under_hood;
                this->capacity = new_capacity;
            }
        }

    public:
        Vector(int capacity){
            this->array_under_hood = new int[capacity];
            this->length = 0;
            this->capacity = capacity;
        }

        ~Vector(){
            delete[] this->array_under_hood;
        }

        bool push_element(int value){
            if (this->length >= this->capacity){
                this->resize_array();
            }
            this->array_under_hood[this->length] = value;
            this->length++;
            return true;
        }
};