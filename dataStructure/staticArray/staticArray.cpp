#include <iostream>

using namespace std;

void printArray(int arr[], int size);
bool append(int arr[], int &size, int capacity, int value);

int main(){
    int arr[100];
    int size = 0;
    int capacity = 100;
    append(arr, size, capacity, 1);
    append(arr, size, capacity, 2);
    printArray(arr,size);
    

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