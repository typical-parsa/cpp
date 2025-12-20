#include <iostream>
#include <climits>

using namespace std;

int main(){

}

void print_stack(int arr[], int size){
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