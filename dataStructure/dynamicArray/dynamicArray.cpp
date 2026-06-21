#include <iostream>
#include <climits>
#include "dynamicArray.h"

using namespace std;

void dynamicArray::resize() {
    int newCapacity;
    if (this->capacity == 0){
        newCapacity = 1;
    }else{
        newCapacity = this->capacity * 2;
    }
    int* newArray = new int[newCapacity];
    for (int i = 0; i < this->length; i++) {
        newArray[i] = this->arrayUnderHood[i];
    }
    delete[] this->arrayUnderHood;
    this->arrayUnderHood = newArray;
    this->capacity = newCapacity;
}

dynamicArray::dynamicArray() {
    this->arrayUnderHood = nullptr;
    this->length = 0;
    this->capacity = 0;
}

dynamicArray::~dynamicArray() {
    delete[] this->arrayUnderHood;
    this->arrayUnderHood = nullptr;
    this->length = 0;
    this->capacity = 0;
}

void dynamicArray::printList(){
    if (this->length == 0){
        return;
    }
    for (int i = 0 ; i < this->length ; i++){
        cout << this->arrayUnderHood[i] << " ";
    }
    cout << endl;
}

bool dynamicArray::pushElement(int value) {
    if (this->length >= this->capacity) {
        resize();
    }
    this->arrayUnderHood[this->length] = value;
    this->length++;
    return true;
}

int dynamicArray::popElement() {
    if (this->length == 0){
        return INT_MIN;
    }
    int value = this->arrayUnderHood[this->length - 1];
    this->length--;
    return value;
}

int dynamicArray::atIndex(int index) {
    if (index < 0 || index >= this->length){
        return INT_MIN;
    } 
    return this->arrayUnderHood[index];
}

int dynamicArray::getSize() {
    return this->length;
}

int dynamicArray::getCapacity() {
    return this->capacity;
}

bool dynamicArray::insertAt(int index, int value) {
    if (index < 0 || index > this->length){
        return false;
    } 
    if (this->length >= this->capacity) {
        resize();
    }
    for (int i = this->length; i > index; i--) {
        this->arrayUnderHood[i] = this->arrayUnderHood[i - 1];
    }
    this->arrayUnderHood[index] = value;
    this->length++;
    return true;
}

bool dynamicArray::deleteAt(int index) {
    if (index < 0 || index >= this->length){
        return false;
    }
    for (int i = index; i < this->length - 1; i++) {
        this->arrayUnderHood[i] = this->arrayUnderHood[i + 1];
    }
    this->length--;
    return true;
}
