#include <iostream>

using namespace std;

void printArray(int arr[], int size);
bool append(int arr[], int &size, int capacity, int value);
bool prepend(int arr[], int &size, int capacity, int value);
bool deleteLast(int arr[], int &size);
bool deleteFirst(int arr[], int &size);

int main(){
    int arr[100];
    int size = 0;
    int capacity = 100;
    prepend(arr, size, capacity, 1);
    prepend(arr, size, capacity, 2);
    printArray(arr, size);
    deleteFirst(arr, size);
    printArray(arr, size);
}

void printArray(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool append(int arr[], int &size, int capacity, int value){
    if (size >= capacity){
        return false;
    }
    arr[size] = value;
    size++;
    return true;
}

bool prepend(int arr[], int &size, int capacity, int value){
    if (size >= capacity){
        return false;
    }
    for (int i = size ; i > 0 ; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
    return true;
}

bool deleteLast(int arr[], int &size){
    if (size == 0){
        return false;
    }
    size--;
    return true;
}

bool deleteFirst(int arr[], int &size){
    if (size == 0){
        return false;
    }
    for (int i = 0 ; i < size - 1 ; i++){
        arr[i] = arr[i + i];
    }
    size--;
    return false;
}