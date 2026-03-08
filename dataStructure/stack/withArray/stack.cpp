#include <iostream>
#include <climits>

using namespace std;

void printStack(int arr[], int size);
bool push(int arr[], int &size, int capacity, int value);
int pop(int arr[], int &size);

int main(){

}

void printStack(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool push(int arr[], int &size, int capacity, int value){
    if (size >= capacity){
        return false;
    }else{
        arr[size] = value;
        size++;
        return true;
    }
}

int pop(int arr[], int &size){
    if (size == 0){
        return INT_MIN;
    }else{
        size--;
        return arr[size];
    }
}