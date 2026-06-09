#include <iostream>

using namespace std;

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
    for(int i = 0 ; i < size ; i++){
        arr[i] = arr[i+1];
    }
    size--;
    return true;
}