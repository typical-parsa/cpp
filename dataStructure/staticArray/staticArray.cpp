#include <iostream>

using namespace std;

bool appendElement(int arr[], int &size, int capacity, int value);
bool deleteLastElement(int arr[], int &size);
bool prependElement(int arr[], int &size, int capacity, int value);
bool deleteFirstElement(int arr[], int &size);
bool insertElement(int arr[], int &size, int capacity, int value, int index);
bool deleteElement(int arr[], int &size, int index);

int main(){

}

bool appendElement(int arr[], int &size, int capacity, int value){
    if (size >= capacity){
        return false;
    }
    arr[size] = value;
    size++;
    return true;
}

bool deleteLastElement(int arr[], int &size){
    if (size == 0){
        return false;
    }
    size--;
    return true;
}

bool prependElement(int arr[], int &size, int capacity, int value){
    if (size >= capacity){
        return false;
    }
    for (int i = size ; i > 0 ; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    size++;
    return true;
}

bool deleteFirstElement(int arr[], int &size){
    if (size == 0){
        return false;
    }
    for(int i = 0 ; i < size - 1 ; i++){
        arr[i] = arr[i+1];
    }
    size--;
    return true;
}

bool insertElement(int arr[], int &size, int capacity, int value, int index){
    if (size >= capacity){
        return false;
    }else if (index < 0 || index > size){
        return false;
    }
    for (int i = size ; i > index ; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    size++;
    return true;
}

bool deleteElement(int arr[], int &size, int index){
    if (size == 0){
        return false;
    }else if (index < 0 || index >= size){
        return false;
    }
    for (int i = index ; i < size - 1 ; i++){
        arr[i] = arr[i + 1];
    }
    size--;
    return true;

}